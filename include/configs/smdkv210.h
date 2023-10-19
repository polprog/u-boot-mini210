/*
 * (C) Copyright 2009 Samsung Electronics
 * Minkyu Kang <mk7.kang@samsung.com>
 * HeungJun Kim <riverful.kim@samsung.com>
 * Inki Dae <inki.dae@samsung.com>
 *
 * Configuation settings for the SAMSUNG SMDKC100 board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_SAMSUNG		1	/* in a SAMSUNG core */
#define CONFIG_S5P		1	/* which is in a S5P Family */
#define CONFIG_S5PV210		1	/* which is in a S5PV210 */
#define CONFIG_SMDKV210		1	/* working with SMDKV210 */

#include <asm/arch/cpu.h>		/* get chip and board defs */

#define CONFIG_ARCH_CPU_INIT

/* input clock of PLL: SMDKV210 has 24MHz input clock */
#define CONFIG_SYS_CLK_FREQ_V210	24000000

/* DRAM Base */
#define CONFIG_SYS_SDRAM_BASE		0x20000000	/* modif by Sourcelink */

/* Text Base */
#define CONFIG_SYS_TEXT_BASE		0x20000000

#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG
#define CONFIG_CMDLINE_EDITING

/*
 * Size of malloc() pool
 * 1MB = 0x100000, 0x100000 = 1024 * 1024
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (1 << 20))

/*
 * select serial console configuration
 */
#define CONFIG_SERIAL0			1	/* use SERIAL 0 on SMDKV210 */

/* PWM */
#define CONFIG_PWM			1

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_BAUDRATE			115200

/***********************************************************
 * Command definition
 ***********************************************************/
#define CONFIG_CMD_NAND 		/* modied by Sourcelink,在config_cmd_all已经定义 */
#define CONFIG_CMD_REGINFO
#undef  CONFIG_CMD_ONENAND		/* modied by Sourcelink */
#define CONFIG_CMD_MTDPARTS

#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS

/* modied by Sourcelink */
#define MTDIDS_DEFAULT		"nand0=s5p-nand"
#define MTDPARTS_DEFAULT	"mtdparts=s5p-nand:512k(bootloader)"\
				",128k@0x80000(params)"\
				",4m@0xA0000(kernel)"\
				",-(rootfs)"

#define NORMAL_MTDPARTS_DEFAULT MTDPARTS_DEFAULT

#define CONFIG_BOOTCOMMAND	"nand read 20008000 kernel; bootm 20008000"

#define CONFIG_RAMDISK_BOOT	"root=/dev/ram0 rw rootfstype=ext2" \
				" console=ttySAC0,115200n8" \
				" mem=128M"

#define CONFIG_COMMON_BOOT	"console=ttySAC0,115200n8" \
				" mem=128M " \
				" " MTDPARTS_DEFAULT

#define CONFIG_BOOTARGS	"root=/dev/mtdblock3" \
			" rootfstype=jffs2 " CONFIG_COMMON_BOOT


#define CONFIG_ENV_OVERWRITE
#define CONFIG_EXTRA_ENV_SETTINGS					\
	"ramboot=" \
		"set bootargs " CONFIG_RAMDISK_BOOT \
		" initrd=0x33000000,8M ramdisk=8192\0" \


/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_CBSIZE	256	/* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE	384	/* Print Buffer Size */
#define CONFIG_SYS_MAXARGS	16	/* max number of command args */
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
/* memtest works on */
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x5e00000)
#define CONFIG_SYS_LOAD_ADDR		CONFIG_SYS_SDRAM_BASE + 0x40000000		/* modied by Sourcelink */

/* SMDKV210 has 1 banks of DRAM, we use only one in U-Boot */
#define CONFIG_NR_DRAM_BANKS	1
#define PHYS_SDRAM_1		CONFIG_SYS_SDRAM_BASE	/* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	(1024 << 20)		/* 0x40000000, 1024 MB Bank #1 (modied by Sourcelink) */

#define CONFIG_SYS_MONITOR_BASE	0x00000000

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_NO_FLASH		1

#define CONFIG_SYS_MONITOR_LEN		(256 << 10)	/* 256 KiB */

#if !defined(CONFIG_NAND_SPL) && (CONFIG_SYS_TEXT_BASE >= 0xc0000000)
#define CONFIG_ENABLE_MMU
#endif

#ifdef CONFIG_ENABLE_MMU
#define CONFIG_SYS_MAPPED_RAM_BASE	0xc0000000
#else
#define CONFIG_SYS_MAPPED_RAM_BASE	CONFIG_SYS_SDRAM_BASE
#endif

/*-----------------------------------------------------------------------
 * Boot configuration
 */
#define CONFIG_ENV_IS_IN_NAND		1	/* add by Sourcelink */

#if 0
#define CONFIG_ENV_IS_IN_ONENAND	1
#endif

#define CONFIG_ENV_SIZE			(128 << 10)	/* 128KiB, 0x20000 */
#define CONFIG_ENV_ADDR			(512 << 10)	/* 512KiB, 0x80000 */
#define CONFIG_ENV_OFFSET		(512 << 10)	/* 512KiB, 0x80000 */

#if 0
#define CONFIG_USE_ONENAND_BOARD_INIT
#define CONFIG_SAMSUNG_ONENAND		1
#define CONFIG_SYS_ONENAND_BASE		0xE7100000
#endif

#define CONFIG_DOS_PARTITION		1

#define CONFIG_SYS_INIT_SP_ADDR		CONFIG_SYS_LOAD_ADDR 		/* modied by Sourcelink */


/*
 * Ethernet Contoller driver
 */
#ifdef CONFIG_CMD_NET			/* modied by Sourcelink */

#if 0
#define CONFIG_SMC911X         1       /* we have a SMC9115 on-board   */
#define CONFIG_SMC911X_16_BIT  1       /* SMC911X_16_BIT Mode          */
#define CONFIG_SMC911X_BASE    0x98800300      /* SMC911X Drive Base   */
#endif

/* add by Sourcelink */
#define CONFIG_DRIVER_DM9000	
#define CONFIG_DM9000_NO_SROM
#define CONFIG_DM9000_BASE	0x88000000
#define DM9000_IO		(CONFIG_DM9000_BASE)
#define DM9000_DATA		(CONFIG_DM9000_BASE + 0x4)
#define CONFIG_NET_RANDOM_ETHADDR	
#define CONFIG_LIB_RAND
#define CONFIG_ENV_SROM_BANK	1
#define CONFIG_CMD_PING

#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_IPADDR		192.168.1.120
#define CONFIG_SERVERIP		192.168.1.175

#define CONFIG_NFS_TIMEOUT	10000UL
#endif /* CONFIG_CMD_NET */

/*
 * NAND Contoller driver
 */
#ifdef CONFIG_CMD_NAND			/* add by Sourcelink */
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0xB0E00000
#define CONFIG_NAND_S5PV210
#define CONFIG_S5PV210_NAND_HWECC
#define CONFIG_SYS_NAND_ECCSIZE		512
#define CONFIG_SYS_NAND_ECCBYTES	13
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#endif

#endif	/* __CONFIG_H */
