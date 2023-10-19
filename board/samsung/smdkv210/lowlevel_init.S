/*
 * Copyright (C) 2009 Samsung Electronics
 * Kyungmin Park <kyungmin.park@samsung.com>
 * Minkyu Kang <mk7.kang@samsung.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <asm/arch/cpu.h>

//modif by polprog
	
#define ELFIN_UART0_OFFSET		0x0000
#define ELFIN_UART1_OFFSET		0x0400
#define ELFIN_UART2_OFFSET		0x0800
#define ELFIN_UART3_OFFSET		0x0c00

	
#if defined(CONFIG_SERIAL0)
#define ELFIN_UART_CONSOLE_BASE (S5PV210_UART_BASE + ELFIN_UART0_OFFSET)
#elif defined(CONFIG_SERIAL1)
#define ELFIN_UART_CONSOLE_BASE (S5PV210_UART_BASE + ELFIN_UART1_OFFSET)
#elif defined(CONFIG_SERIAL2)
#define ELFIN_UART_CONSOLE_BASE (S5PV210_UART_BASE + ELFIN_UART2_OFFSET)
#elif defined(CONFIG_SERIAL3)
#define ELFIN_UART_CONSOLE_BASE (S5PV210_UART_BASE + ELFIN_UART3_OFFSET)
#else
#define ELFIN_UART_CONSOLE_BASE (S5PV210_UART_BASE + ELFIN_UART0_OFFSET)
#endif

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

#define ELFIN_GPIO_BASE			0xE0200000
#define GPA0CON_OFFSET 			0x000 
#define GPA1CON_OFFSET 			0x020

	
// end modif by polprog
/* modif by Sourcelink */

.globl lowlevel_init
lowlevel_init:
	mov	r9, lr

#ifdef CONFIG_SPL_BUILD
	bl	clock_init		/* 时钟初始化 */
	bl	ddr_init		/* DDR初始化 */
#endif
	ldr	r0, =0xE0200000
	ldr	r1, =0X22222222
	str	r1, [r0]
	mov	pc, r9		/* 返回 */

/*
 * uart_asm_init: Initialize UART in asm mode, 115200bps fixed.
 * void uart_asm_init(void)
 */
uart_asm_init:

	/* set GPIO(GPA) to enable UART */
	@ GPIO setting for UART
	ldr	r0, =ELFIN_GPIO_BASE
	ldr	r1, =0x22222222
	str   	r1, [r0, #GPA0CON_OFFSET]

	ldr     r1, =0x2222
	str     r1, [r0, #GPA1CON_OFFSET]

	// HP V210 use. SMDK not use.
#if defined(CONFIG_VOGUES)
	mov    r1, #(0x1<<8)
	str    r1, [r0, #GPC0CON_OFFSET]

	mov    r1, #0x4
	str    r1, [r0, #GPC0DAT_OFFSET]
#endif

	ldr	r0, =ELFIN_UART_CONSOLE_BASE	@0xEC000000 -- wrong
	mov	r1, #0x0
	str	r1, [r0, #UFCON_OFFSET]
	str	r1, [r0, #UMCON_OFFSET]

	mov	r1, #0x3
	str	r1, [r0, #ULCON_OFFSET]

	ldr	r1, =0x3c5
	str	r1, [r0, #UCON_OFFSET]

	ldr	r1, =UART_UBRDIV_VAL
	str	r1, [r0, #UBRDIV_OFFSET]

	ldr	r1, =UART_UDIVSLOT_VAL
	str	r1, [r0, #UDIVSLOT_OFFSET]

	ldr	r1, =0x4f4f4f4f
	str	r1, [r0, #UTXH_OFFSET]		@'O'

	mov	pc, lr
