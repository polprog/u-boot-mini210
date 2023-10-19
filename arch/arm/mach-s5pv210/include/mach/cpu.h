/*
 * (C) Copyright 2009 Samsung Electronics
 * Minkyu Kang <mk7.kang@samsung.com>
 * Heungjun Kim <riverful.kim@samsung.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _S5PV210_CPU_H
#define _S5PV210_CPU_H

#define S5P_CPU_NAME		"S5P"
#define S5PV210_ADDR_BASE	0xE0000000

/* S5PV210 */
#define S5PV210_PRO_ID		0xE0000000
#define S5PV210_CLOCK_BASE	0xE0100000
#define S5PV210_GPIO_BASE	0xE0200000
#define S5PV210_PWMTIMER_BASE	0xE2500000
#define S5PV210_WATCHDOG_BASE	0xE2700000
#define S5PV210_UART_BASE	0xE2900000
#define S5PV210_MMC_BASE	0xEB000000
#define S5PV210_SROMC_BASE	0xE8000000
#define S5PV210_DMC0_BASE	0xF0000000
#define S5PV210_DMC1_BASE	0xF1400000
#define S5PV210_VIC0_BASE	0xF2000000
#define S5PV210_VIC1_BASE	0xF2100000
#define S5PV210_VIC2_BASE	0xF2200000
#define SPPV210_VIC3_BASE	0xF2300000
#define S5PV210_NAND_BASE	0xB0E00000


/* S5PC100 */
#define S5PC100_PRO_ID		0xE0000000
#define S5PC100_CLOCK_BASE	0xE0100000
#define S5PC100_GPIO_BASE	0xE0300000
#define S5PC100_VIC0_BASE	0xE4000000
#define S5PC100_VIC1_BASE	0xE4100000
#define S5PC100_VIC2_BASE	0xE4200000
#define S5PC100_DMC_BASE	0xE6000000
#define S5PC100_SROMC_BASE	0xE7000000
#define S5PC100_ONENAND_BASE	0xE7100000
#define S5PC100_PWMTIMER_BASE	0xEA000000
#define S5PC100_WATCHDOG_BASE	0xEA200000
#define S5PC100_UART_BASE	0xEC000000
#define S5PC100_MMC_BASE	0xED800000


/* S5PC110 */
#define S5PC110_PRO_ID		0xE0000000
#define S5PC110_CLOCK_BASE	0xE0100000
#define S5PC110_GPIO_BASE	0xE0200000
#define S5PC110_PWMTIMER_BASE	0xE2500000
#define S5PC110_WATCHDOG_BASE	0xE2700000
#define S5PC110_UART_BASE	0xE2900000
#define S5PC110_SROMC_BASE	0xE8000000
#define S5PC110_MMC_BASE	0xEB000000
#define S5PC110_DMC0_BASE	0xF0000000
#define S5PC110_DMC1_BASE	0xF1400000
#define S5PC110_VIC0_BASE	0xF2000000
#define S5PC110_VIC1_BASE	0xF2100000
#define S5PC110_VIC2_BASE	0xF2200000
#define S5PC110_VIC3_BASE	0xF2300000
#define S5PC110_OTG_BASE	0xEC000000
#define S5PC110_PHY_BASE	0xEC100000
#define S5PC110_USB_PHY_CONTROL 0xE010E80C


#ifndef __ASSEMBLY__
#include <asm/io.h>
/* CPU detection macros */
extern unsigned int s5p_cpu_id;
extern unsigned int s5p_cpu_rev;

static inline int s5p_get_cpu_rev(void)
{
	return s5p_cpu_rev;
}

/* modif by Sourcelink */
static inline void s5p_set_cpu_id(void)
{
	int id = 0;
	s5p_cpu_id = readl(S5PV210_PRO_ID);
	s5p_cpu_rev = s5p_cpu_id & 0x000000FF;
	id = (s5p_cpu_id & 0xFFFFF000) >> 12;
	if (id == 0x43110) {
		id = s5p_cpu_id & 0x0F;
		switch (id) {
			case 0x00:
				s5p_cpu_id = 0x56210;
			break;
		
			case 0x01:
				s5p_cpu_id = 0xc100;
			break;
		
			case 0x02:
				s5p_cpu_id = 0xc111;
			break;

			default : break;
		}
	}
}

static inline char *s5p_get_cpu_name(void)
{
	return S5P_CPU_NAME;
}

#define IS_SAMSUNG_TYPE(type, id)			\
static inline int cpu_is_##type(void)			\
{							\
	return s5p_cpu_id == id ? 1 : 0;		\
}

/* add by Sourcelink */
IS_SAMSUNG_TYPE(s5pv210, 0x56210)
IS_SAMSUNG_TYPE(s5pc100, 0xc100)
IS_SAMSUNG_TYPE(s5pc110, 0xc110)

/* modif by Sourcelink */
#define SAMSUNG_BASE(device, base)				\
static inline unsigned int samsung_get_base_##device(void)	\
{								\
		return S5PV210_##base;				\
}

SAMSUNG_BASE(clock, CLOCK_BASE)
SAMSUNG_BASE(gpio, GPIO_BASE)
SAMSUNG_BASE(pro_id, PRO_ID)
SAMSUNG_BASE(mmc, MMC_BASE)
SAMSUNG_BASE(sromc, SROMC_BASE)
SAMSUNG_BASE(timer, PWMTIMER_BASE)
SAMSUNG_BASE(uart, UART_BASE)
SAMSUNG_BASE(watchdog, WATCHDOG_BASE)
/* add by Sourcelink */
SAMSUNG_BASE(dmc0,DMC0_BASE)
SAMSUNG_BASE(dmc1,DMC1_BASE)
SAMSUNG_BASE(nand,NAND_BASE)
#endif

#endif	/* _S5PC1XX_CPU_H */