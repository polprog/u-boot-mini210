/*
 *  Copyright (C) 2008-2009 Samsung Electronics
 *  Minkyu Kang <mk7.kang@samsung.com>
 *  Kyungmin Park <kyungmin.park@samsung.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/sromc.h>
#include <asm/arch/clock.h>	/* add by Sourcelink */
#include <asm/arch/dmc.h>	/* add by Sourcelink */
#include <asm/arch/nand_reg.h>	/* add by Sourcelink */
#include <netdev.h>

#ifndef CONFIG_SPL_BUILD	/* add by Sourcelink */

DECLARE_GLOBAL_DATA_PTR;

/*
 * Miscellaneous platform dependent initialisations
 */
#if 0
static void smc9115_pre_init(void)
{
	u32 smc_bw_conf, smc_bc_conf;

	/* gpio configuration GPK0CON */
	gpio_cfg_pin(S5PV210_GPIO_K00 + CONFIG_ENV_SROM_BANK, S5P_GPIO_FUNC(2));

	/* Ethernet needs bus width of 16 bits */
	smc_bw_conf = SMC_DATA16_WIDTH(CONFIG_ENV_SROM_BANK);
	smc_bc_conf = SMC_BC_TACS(0x0) | SMC_BC_TCOS(0x4) | SMC_BC_TACC(0xe)
			| SMC_BC_TCOH(0x1) | SMC_BC_TAH(0x4)
			| SMC_BC_TACP(0x6) | SMC_BC_PMC(0x0);

	/* Select and configure the SROMC bank */
	s5p_config_sromc(CONFIG_ENV_SROM_BANK, smc_bw_conf, smc_bc_conf);
}
#endif

static void dm9000_pre_init(void)
{
	u32 smc_bw_conf, smc_bc_conf;
	/* Ethernet needs bus width of 16 bits */
	smc_bw_conf = SMC_DATA16_WIDTH(CONFIG_ENV_SROM_BANK) | SMC_BYTE_ADDR_MODE(CONFIG_ENV_SROM_BANK);
	smc_bc_conf = SMC_BC_TACS(0x0) | SMC_BC_TCOS(0x1) | SMC_BC_TACC(0x2)
			| SMC_BC_TCOH(0x1) | SMC_BC_TAH(0x0)
			| SMC_BC_TACP(0x0) | SMC_BC_PMC(0x0);

	/* Select and configure the SROMC bank */
	s5p_config_sromc(CONFIG_ENV_SROM_BANK, smc_bw_conf, smc_bc_conf);
}

int board_init(void)
{
	dm9000_pre_init();

	gd->bd->bi_arch_number = MACH_TYPE_SMDKV210;
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + 0x100;

	return 0;
}

int dram_init(void)
{
	gd->ram_size = get_ram_size((long *)PHYS_SDRAM_1, PHYS_SDRAM_1_SIZE);

	return 0;
}

void dram_init_banksize(void)
{
	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size = PHYS_SDRAM_1_SIZE;
}

#ifdef CONFIG_DISPLAY_BOARDINFO
int checkboard(void)
{
	printf("Board:\tSMDKV210\n");
	return 0;
}
#endif

int board_eth_init(bd_t *bis)
{
	int rc = 0;
	/* add by Sourcelink */
	rc = dm9000_initialize(bis);
	return rc;
}

#else	/* CONFIG_SPL_BUILD (add by Sourcelink) */

void clock_init(void)
{	
	u32 val = 0;
	
	struct s5pv210_clock *const clock = (struct s5pv210_clock *)samsung_get_base_clock();
	
	/* 1.设置PLL锁定值 */
	writel(0xFFFF, &clock->apll_lock);
	writel(0xFFFF, &clock->mpll_lock);
	writel(0xFFFF, &clock->epll_lock);
	writel(0xFFFF, &clock->vpll_lock);
	
	/* 2.设置PLL的PMS值(使用芯片手册推荐的值)，并使能PLL */
	/*	 	P	  	    M   		  S		     EN	*/
	writel((3  << 8) | (125 << 16) | (1 << 0) | (1 << 31), &clock->apll_con0);	/* FOUT_APLL = 1000MHz */
	writel((12 << 8) | (667 << 16) | (1 << 0) | (1 << 31), &clock->mpll_con); 	/* FOUT_MPLL = 667MHz */
	writel((3  << 8) | (48  << 16) | (2 << 0) | (1 << 31), &clock->epll_con0);	/* FOUT_EPLL = 96MHz */
	writel((6  << 8) | (108 << 16) | (3 << 0) | (1 << 31), &clock->vpll_con);	/* FOUT_VPLL = 54MHz */
	
	/* 3.等待PLL锁定 */
	while (!(readl(&clock->apll_con0) & (1 << 29)));
	while (!(readl(&clock->mpll_con) & (1 << 29)));
	while (!(readl(&clock->apll_con0) & (1 << 29)));
	while (!(readl(&clock->epll_con0) & (1 << 29)));
	while (!(readl(&clock->vpll_con) & (1 << 29)));

	/* 
	** 4.设置系统时钟源，选择PLL为时钟输出 */
	/* MOUT_MSYS = SCLKAPLL = FOUT_APLL = 1000MHz
	** MOUT_DSYS = SCLKMPLL = FOUT_MPLL = 667MHz
	** MOUT_PSYS = SCLKMPLL = FOUT_MPLL = 667MHz
	** ONENAND = HCLK_PSYS
	*/
	writel((1 << 0) | (1 << 4) | (1 << 8) | (1 << 12), &clock->src0);
	
	/* 4.设置其他模块的时钟源 */

	/* 6.设置系统时钟分频值 */
	val = 	(0 << 0)  |	/* APLL_RATIO = 0, freq(ARMCLK) = MOUT_MSYS / (APLL_RATIO + 1) = 1000MHz */
			(4 << 4)  |	/* A2M_RATIO = 4, freq(A2M) = SCLKAPLL / (A2M_RATIO + 1) = 200MHz */
			(4 << 8)  |	/* HCLK_MSYS_RATIO = 4, freq(HCLK_MSYS) = ARMCLK / (HCLK_MSYS_RATIO + 1) = 200MHz */
			(1 << 12) |	/* PCLK_MSYS_RATIO = 1, freq(PCLK_MSYS) = HCLK_MSYS / (PCLK_MSYS_RATIO + 1) = 100MHz */
			(3 << 16) | /* HCLK_DSYS_RATIO = 3, freq(HCLK_DSYS) = MOUT_DSYS / (HCLK_DSYS_RATIO + 1) = 166MHz */
			(1 << 20) | /* PCLK_DSYS_RATIO = 1, freq(PCLK_DSYS) = HCLK_DSYS / (PCLK_DSYS_RATIO + 1) = 83MHz */
			(4 << 24) |	/* HCLK_PSYS_RATIO = 4, freq(HCLK_PSYS) = MOUT_PSYS / (HCLK_PSYS_RATIO + 1) = 133MHz */
			(1 << 28);	/* PCLK_PSYS_RATIO = 1, freq(PCLK_PSYS) = HCLK_PSYS / (PCLK_PSYS_RATIO + 1) = 66MHz */
	writel(val, &clock->div0);
	
	/* 7.设置其他模块的时钟分频值 */
}

void ddr_init(void)
{
	struct s5pv210_dmc0 *const dmc0 = (struct s5pv210_dmc0 *)samsung_get_base_dmc0();
	struct s5pv210_dmc1 *const dmc1 = (struct s5pv210_dmc1 *)samsung_get_base_dmc1();
	
	/* DMC0 */
	writel(0x00101000, &dmc0->phycontrol0);
	writel(0x00101002, &dmc0->phycontrol0);			/* DLL on */
	writel(0x00000086, &dmc0->phycontrol1);
	writel(0x00101003, &dmc0->phycontrol0);			/* DLL start */
	
	while ((readl(&dmc0->phystatus) & 0x7) != 0x7); 	/* wait DLL locked */

	writel(0x0FFF2350, &dmc0->concontrol);			/* Auto Refresh Counter should be off */
	writel(0x00202430, &dmc0->memcontrol);			/* Dynamic power down should be off */
	writel(0x20E01323, &dmc0->memconfig0);
	
	writel(0xFF000000, &dmc0->prechconfig);
	writel(0xFFFF00FF, &dmc0->pwrdnconfig);
	
	writel(0x00000618, &dmc0->timingaref);			/* 7.8us * 200MHz = 1560 = 0x618  */
	writel(0x19233309, &dmc0->timingrow);
	writel(0x23240204, &dmc0->timingdata);
	writel(0x09C80232, &dmc0->timingpower);
	
	writel(0x07000000, &dmc0->directcmd);			/* NOP */
	writel(0x01000000, &dmc0->directcmd);			/* PALL */
	writel(0x00020000, &dmc0->directcmd);			/* EMRS2 */
	writel(0x00030000, &dmc0->directcmd);			/* EMRS3 */
	writel(0x00010400, &dmc0->directcmd);			/* EMRS enable DLL */
	writel(0x00000542, &dmc0->directcmd);			/* DLL reset */
	writel(0x01000000, &dmc0->directcmd); 			/* PALL */
	writel(0x05000000, &dmc0->directcmd);			/* auto refresh */
	writel(0x05000000, &dmc0->directcmd);			/* auto refresh */
	writel(0x00000442, &dmc0->directcmd);			/* DLL unreset */
	writel(0x00010780, &dmc0->directcmd);			/* OCD default */
	writel(0x00010400, &dmc0->directcmd);			/* OCD exit */
	
	writel(0x0FF02030, &dmc0->concontrol);			/* auto refresh on */
	writel(0xFFFF00FF, &dmc0->pwrdnconfig);
	writel(0x00202400, &dmc0->memcontrol);

	/* DMC1 */
	writel(0x00101000, &dmc1->phycontrol0);
	writel(0x00101002, &dmc1->phycontrol0);			/* DLL on */
	writel(0x00000086, &dmc1->phycontrol1);
	writel(0x00101003, &dmc1->phycontrol0);			/* DLL start */

	while ((readl(&dmc1->phystatus) & 0x7) != 0x7); 	/* wait DLL locked */

	writel(0x0FFF2350, &dmc1->concontrol);			/* Auto Refresh Counter should be off */
	writel(0x00202430, &dmc1->memcontrol);			/* Dynamic power down should be off */
	writel(0x40E01323, &dmc1->memconfig0);
	
	writel(0xFF000000, &dmc1->prechconfig);
	writel(0xFFFF00FF, &dmc1->pwrdnconfig);
	
	writel(0x00000618, &dmc1->timingaref);			/* 7.8us * 200MHz = 1560 = 0x618  */
	writel(0x19233309, &dmc1->timingrow);
	writel(0x23240204, &dmc1->timingdata);
	writel(0x09C80232, &dmc1->timingpower);
	
	writel(0x07000000, &dmc1->directcmd);			/* NOP */
	writel(0x01000000, &dmc1->directcmd);			/* PALL */
	writel(0x00020000, &dmc1->directcmd);			/* EMRS2 */
	writel(0x00030000, &dmc1->directcmd);			/* EMRS3 */
	writel(0x00010400, &dmc1->directcmd);			/* EMRS enable DLL */
	writel(0x00000542, &dmc1->directcmd);			/* DLL reset */
	writel(0x01000000, &dmc1->directcmd); 			/* PALL */
	writel(0x05000000, &dmc1->directcmd);			/* auto refresh */
	writel(0x05000000, &dmc1->directcmd);			/* auto refresh */
	writel(0x00000442, &dmc1->directcmd);			/* DLL unreset */
	writel(0x00010780, &dmc1->directcmd);			/* OCD default */
	writel(0x00010400, &dmc1->directcmd);			/* OCD exit */
	
	writel(0x0FF02030, &dmc1->concontrol);			/* auto refresh on */
	writel(0xFFFF00FF, &dmc1->pwrdnconfig);
	writel(0x00202400, &dmc1->memcontrol);
}

/* Added by polprog */
#define ELFIN_UART_BASE			0XE2900000

#define ELFIN_UART0		(ELFIN_UART_BASE + 0x0000)
#define ELFIN_UART1		(ELFIN_UART_BASE + 0x0400)
#define ELFIN_UART2		(ELFIN_UART_BASE + 0x0800)
#define ELFIN_UART3		(ELFIN_UART_BASE + 0x0c00)

#define ULCON_OFFSET			0x00
#define UCON_OFFSET			0x04
#define UFCON_OFFSET			0x08
#define UMCON_OFFSET			0x0C
#define UTRSTAT_OFFSET			0x10
#define UERSTAT_OFFSET			0x14
#define UFSTAT_OFFSET			0x18
#define UMSTAT_OFFSET			0x1C
#define UTXH_OFFSET			0x20
#define URXH_OFFSET			0x24
#define UBRDIV_OFFSET			0x28
#define UDIVSLOT_OFFSET			0x2C
#define UINTP_OFFSET			0x30
#define UINTSP_OFFSET			0x34
#define UINTM_OFFSET			0x38

#define UTRSTAT_TX_EMPTY		BIT2
#define UTRSTAT_RX_READY		BIT0
#define UART_ERR_MASK			0xF

#define __REG(base, offset)  ((volatile int*) (base+offset))

void copy_bl2_to_ram(void)
{
/*
** ch:  通道
** sb:  起始块
** bs:  块大小
** dst: 目的地
** i: 	是否初始化
*/
#define CopySDMMCtoMem(ch, sb, bs, dst, i) \
	(((unsigned char(*)(int, unsigned int, unsigned short, unsigned int*, unsigned char))\
	(*((unsigned int *)0xD0037F98)))(ch, sb, bs, dst, i))

#define MP0_1CON (*(volatile unsigned int*)0xE02002E0)
#define MP0_3CON (*(volatile unsigned int*)0xE0200320)
#define MP0_6CON (*(volatile unsigned int*)0xE0200380)

/* Nand Flash Configuration Register */
#define AddrCycle	1 	/* 5address cycle */
#define PageSize	0 	/* 2KBytes/Page */
#define MLCFlash	0	/* slc NAND Flash */
#define TWRPH1		1	/* (0+1) * 7.5ns > 5ns */
#define TWRPH0		2 	/* (1+1) * 7.5ns > 12ns */
#define TACLS		1	/* 7.5ns * 2 > 12ns */

/* Control Register */
#define MODE		1	/* Enable Nand Flash Controller */
#define Reg_nCE0	1	/* Disable chip select */

#define NF8_ReadPage_Adv(a,b,c)	(((int(*)(unsigned int,unsigned int,unsigned char *))(*((unsigned int *)0xD0037F90)))(a,b,c))

	unsigned int bl2Size = 400 * 1024; 	/* 350k */
	unsigned int OM = *(volatile unsigned int *)(0xE0000004);		/* om Register */
	OM &= 0X1F;		/* get low 5bit */

	if (OM == 0x2) {
		
		unsigned int cfg = 0;
		struct s5pv210_nand *nand_reg = (struct s5pv210_nand *)(struct s5pv210_nand *)samsung_get_base_nand();
		
		/* init hardware */
		cfg = ((AddrCycle << 1) | (PageSize << 2) | (MLCFlash << 3) | (TWRPH1 << 4) | (TWRPH0 << 8) | (TACLS << 12) | (0x1 << 23));
		writel(cfg, &nand_reg->nfconf);
		
		writel((Reg_nCE0 << 1) | (MODE << 0), &nand_reg->nfcont);

		/* set select chip */
		MP0_1CON &= ~(0x00000F00);
		MP0_1CON |= (3 << 8);
		/* cle,ale,we,re,r/b1 */
		MP0_3CON &= ~(0x000FFFFF);
		MP0_3CON |= 0X00022222;
		/* data */
		MP0_6CON = 0x22222222;
		
		int i = 0;
		int pages = bl2Size / 2048; 	/* get pages */
		int offset = 0x4000 /2048;	/* u-boot.bin offset pages address */
		unsigned char *p = (unsigned char *)CONFIG_SYS_SDRAM_BASE;
		for (; i < pages; i++) {
			NF8_ReadPage_Adv(offset / 64, offset % 64, p);
			p += 2048;
			offset += 1;
		}
	
	} else if (OM == 0xC) {

		unsigned int V210_SDMMC_BASE = *(volatile unsigned int *)(0xD0037488);	// V210_SDMMC_BASE
		unsigned char ch = 0;
	
		/* 参考S5PV210手册7.9.1 SD/MMC REGISTER MAP */
		if (V210_SDMMC_BASE == 0xEB000000)		// 通道0
			ch = 0;
		else if (V210_SDMMC_BASE == 0xEB200000)		// 通道2
			ch = 2;
	
		CopySDMMCtoMem(ch, 32, 800, (unsigned int *)CONFIG_SYS_SDRAM_BASE, 0);
	}
}

#endif	/* CONFIG_SPL_BUILD (add by Sourcelink) */
