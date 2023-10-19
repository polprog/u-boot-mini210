/*
 * Copyright (C) 2009 Samsung Electronics
 * Minkyu Kang <mk7.kang@samsung.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <common.h>
#include <fdtdec.h>
#include <asm/io.h>
#include <asm/arch/clk.h>

DECLARE_GLOBAL_DATA_PTR;

/* modied by Sourcelink */
/* Default is s5pv210 */
unsigned int s5p_cpu_id = 0x56210;
/* Default is EVT1 */
unsigned int s5p_cpu_rev = 1;

#ifdef CONFIG_ARCH_CPU_INIT
int arch_cpu_init(void)
{
	s5p_set_cpu_id();

	return 0;
}
#endif

u32 get_device_type(void)
{
	return s5p_cpu_id;
}

#ifdef CONFIG_DISPLAY_CPUINFO
int print_cpuinfo(void)
{
	char buf[32];

	const char *cpu_model;
	int len;

	/* For SoC with no real CPU ID in naming convention. */
	cpu_model = fdt_getprop(gd->fdt_blob, 0, "cpu-model", &len);
		
	/* modied by Sourcelink */
	printf("CPU : %sV210@%sMHz \n", s5p_get_cpu_name(), strmhz(buf, get_arm_clk()));

	return 0;
}
#endif
