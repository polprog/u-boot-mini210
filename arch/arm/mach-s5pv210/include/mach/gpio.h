/*
 * (C) Copyright 2009 Samsung Electronics
 * Minkyu Kang <mk7.kang@samsung.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __ASM_ARCH_GPIO_H
#define __ASM_ARCH_GPIO_H

#ifndef __ASSEMBLY__
struct s5p_gpio_bank {
	unsigned int	con;
	unsigned int	dat;
	unsigned int	pull;
	unsigned int	drv;
	unsigned int	pdn_con;
	unsigned int	pdn_pull;
	unsigned char	res1[8];
};

/* A list of valid GPIO numbers for the asm-generic/gpio.h interface */
enum S5PV210_gpio_pin {
	S5PV210_GPIO_A00,
	S5PV210_GPIO_A01,
	S5PV210_GPIO_A02,
	S5PV210_GPIO_A03,
	S5PV210_GPIO_A04,
	S5PV210_GPIO_A05,
	S5PV210_GPIO_A06,
	S5PV210_GPIO_A07,
	S5PV210_GPIO_A10,
	S5PV210_GPIO_A11,
	S5PV210_GPIO_A12,
	S5PV210_GPIO_A13,
	S5PV210_GPIO_A14,
	S5PV210_GPIO_A15,
	S5PV210_GPIO_A16,
	S5PV210_GPIO_A17,
	S5PV210_GPIO_B0,
	S5PV210_GPIO_B1,
	S5PV210_GPIO_B2,
	S5PV210_GPIO_B3,
	S5PV210_GPIO_B4,
	S5PV210_GPIO_B5,
	S5PV210_GPIO_B6,
	S5PV210_GPIO_B7,
	S5PV210_GPIO_C0,
	S5PV210_GPIO_C1,
	S5PV210_GPIO_C2,
	S5PV210_GPIO_C3,
	S5PV210_GPIO_C4,
	S5PV210_GPIO_C5,
	S5PV210_GPIO_C6,
	S5PV210_GPIO_C7,
	S5PV210_GPIO_D0,
	S5PV210_GPIO_D1,
	S5PV210_GPIO_D2,
	S5PV210_GPIO_D3,
	S5PV210_GPIO_D4,
	S5PV210_GPIO_D5,
	S5PV210_GPIO_D6,
	S5PV210_GPIO_D7,
	S5PV210_GPIO_E00,
	S5PV210_GPIO_E01,
	S5PV210_GPIO_E02,
	S5PV210_GPIO_E03,
	S5PV210_GPIO_E04,
	S5PV210_GPIO_E05,
	S5PV210_GPIO_E06,
	S5PV210_GPIO_E07,
	S5PV210_GPIO_E10,
	S5PV210_GPIO_E11,
	S5PV210_GPIO_E12,
	S5PV210_GPIO_E13,
	S5PV210_GPIO_E14,
	S5PV210_GPIO_E15,
	S5PV210_GPIO_E16,
	S5PV210_GPIO_E17,
	S5PV210_GPIO_F00,
	S5PV210_GPIO_F01,
	S5PV210_GPIO_F02,
	S5PV210_GPIO_F03,
	S5PV210_GPIO_F04,
	S5PV210_GPIO_F05,
	S5PV210_GPIO_F06,
	S5PV210_GPIO_F07,
	S5PV210_GPIO_F10,
	S5PV210_GPIO_F11,
	S5PV210_GPIO_F12,
	S5PV210_GPIO_F13,
	S5PV210_GPIO_F14,
	S5PV210_GPIO_F15,
	S5PV210_GPIO_F16,
	S5PV210_GPIO_F17,
	S5PV210_GPIO_F20,
	S5PV210_GPIO_F21,
	S5PV210_GPIO_F22,
	S5PV210_GPIO_F23,
	S5PV210_GPIO_F24,
	S5PV210_GPIO_F25,
	S5PV210_GPIO_F26,
	S5PV210_GPIO_F27,
	S5PV210_GPIO_F30,
	S5PV210_GPIO_F31,
	S5PV210_GPIO_F32,
	S5PV210_GPIO_F33,
	S5PV210_GPIO_F34,
	S5PV210_GPIO_F35,
	S5PV210_GPIO_F36,
	S5PV210_GPIO_F37,
	S5PV210_GPIO_G00,
	S5PV210_GPIO_G01,
	S5PV210_GPIO_G02,
	S5PV210_GPIO_G03,
	S5PV210_GPIO_G04,
	S5PV210_GPIO_G05,
	S5PV210_GPIO_G06,
	S5PV210_GPIO_G07,
	S5PV210_GPIO_G10,
	S5PV210_GPIO_G11,
	S5PV210_GPIO_G12,
	S5PV210_GPIO_G13,
	S5PV210_GPIO_G14,
	S5PV210_GPIO_G15,
	S5PV210_GPIO_G16,
	S5PV210_GPIO_G17,
	S5PV210_GPIO_G20,
	S5PV210_GPIO_G21,
	S5PV210_GPIO_G22,
	S5PV210_GPIO_G23,
	S5PV210_GPIO_G24,
	S5PV210_GPIO_G25,
	S5PV210_GPIO_G26,
	S5PV210_GPIO_G27,
	S5PV210_GPIO_G30,
	S5PV210_GPIO_G31,
	S5PV210_GPIO_G32,
	S5PV210_GPIO_G33,
	S5PV210_GPIO_G34,
	S5PV210_GPIO_G35,
	S5PV210_GPIO_G36,
	S5PV210_GPIO_G37,
	S5PV210_GPIO_I0,
	S5PV210_GPIO_I1,
	S5PV210_GPIO_I2,
	S5PV210_GPIO_I3,
	S5PV210_GPIO_I4,
	S5PV210_GPIO_I5,
	S5PV210_GPIO_I6,
	S5PV210_GPIO_I7,
	S5PV210_GPIO_J00,
	S5PV210_GPIO_J01,
	S5PV210_GPIO_J02,
	S5PV210_GPIO_J03,
	S5PV210_GPIO_J04,
	S5PV210_GPIO_J05,
	S5PV210_GPIO_J06,
	S5PV210_GPIO_J07,
	S5PV210_GPIO_J10,
	S5PV210_GPIO_J11,
	S5PV210_GPIO_J12,
	S5PV210_GPIO_J13,
	S5PV210_GPIO_J14,
	S5PV210_GPIO_J15,
	S5PV210_GPIO_J16,
	S5PV210_GPIO_J17,
	S5PV210_GPIO_J20,
	S5PV210_GPIO_J21,
	S5PV210_GPIO_J22,
	S5PV210_GPIO_J23,
	S5PV210_GPIO_J24,
	S5PV210_GPIO_J25,
	S5PV210_GPIO_J26,
	S5PV210_GPIO_J27,
	S5PV210_GPIO_J30,
	S5PV210_GPIO_J31,
	S5PV210_GPIO_J32,
	S5PV210_GPIO_J33,
	S5PV210_GPIO_J34,
	S5PV210_GPIO_J35,
	S5PV210_GPIO_J36,
	S5PV210_GPIO_J37,
	S5PV210_GPIO_J40,
	S5PV210_GPIO_J41,
	S5PV210_GPIO_J42,
	S5PV210_GPIO_J43,
	S5PV210_GPIO_J44,
	S5PV210_GPIO_J45,
	S5PV210_GPIO_J46,
	S5PV210_GPIO_J47,
	S5PV210_GPIO_K00,
	S5PV210_GPIO_K01,
	S5PV210_GPIO_K02,
	S5PV210_GPIO_K03,
	S5PV210_GPIO_K04,
	S5PV210_GPIO_K05,
	S5PV210_GPIO_K06,
	S5PV210_GPIO_K07,
	S5PV210_GPIO_K10,
	S5PV210_GPIO_K11,
	S5PV210_GPIO_K12,
	S5PV210_GPIO_K13,
	S5PV210_GPIO_K14,
	S5PV210_GPIO_K15,
	S5PV210_GPIO_K16,
	S5PV210_GPIO_K17,
	S5PV210_GPIO_K20,
	S5PV210_GPIO_K21,
	S5PV210_GPIO_K22,
	S5PV210_GPIO_K23,
	S5PV210_GPIO_K24,
	S5PV210_GPIO_K25,
	S5PV210_GPIO_K26,
	S5PV210_GPIO_K27,
	S5PV210_GPIO_K30,
	S5PV210_GPIO_K31,
	S5PV210_GPIO_K32,
	S5PV210_GPIO_K33,
	S5PV210_GPIO_K34,
	S5PV210_GPIO_K35,
	S5PV210_GPIO_K36,
	S5PV210_GPIO_K37,
	S5PV210_GPIO_L00,
	S5PV210_GPIO_L01,
	S5PV210_GPIO_L02,
	S5PV210_GPIO_L03,
	S5PV210_GPIO_L04,
	S5PV210_GPIO_L05,
	S5PV210_GPIO_L06,
	S5PV210_GPIO_L07,
	S5PV210_GPIO_L10,
	S5PV210_GPIO_L11,
	S5PV210_GPIO_L12,
	S5PV210_GPIO_L13,
	S5PV210_GPIO_L14,
	S5PV210_GPIO_L15,
	S5PV210_GPIO_L16,
	S5PV210_GPIO_L17,
	S5PV210_GPIO_L20,
	S5PV210_GPIO_L21,
	S5PV210_GPIO_L22,
	S5PV210_GPIO_L23,
	S5PV210_GPIO_L24,
	S5PV210_GPIO_L25,
	S5PV210_GPIO_L26,
	S5PV210_GPIO_L27,
	S5PV210_GPIO_L30,
	S5PV210_GPIO_L31,
	S5PV210_GPIO_L32,
	S5PV210_GPIO_L33,
	S5PV210_GPIO_L34,
	S5PV210_GPIO_L35,
	S5PV210_GPIO_L36,
	S5PV210_GPIO_L37,
	S5PV210_GPIO_L40,
	S5PV210_GPIO_L41,
	S5PV210_GPIO_L42,
	S5PV210_GPIO_L43,
	S5PV210_GPIO_L44,
	S5PV210_GPIO_L45,
	S5PV210_GPIO_L46,
	S5PV210_GPIO_L47,
	S5PV210_GPIO_H00,
	S5PV210_GPIO_H01,
	S5PV210_GPIO_H02,
	S5PV210_GPIO_H03,
	S5PV210_GPIO_H04,
	S5PV210_GPIO_H05,
	S5PV210_GPIO_H06,
	S5PV210_GPIO_H07,
	S5PV210_GPIO_H10,
	S5PV210_GPIO_H11,
	S5PV210_GPIO_H12,
	S5PV210_GPIO_H13,
	S5PV210_GPIO_H14,
	S5PV210_GPIO_H15,
	S5PV210_GPIO_H16,
	S5PV210_GPIO_H17,
	S5PV210_GPIO_H20,
	S5PV210_GPIO_H21,
	S5PV210_GPIO_H22,
	S5PV210_GPIO_H23,
	S5PV210_GPIO_H24,
	S5PV210_GPIO_H25,
	S5PV210_GPIO_H26,
	S5PV210_GPIO_H27,
	S5PV210_GPIO_H30,
	S5PV210_GPIO_H31,
	S5PV210_GPIO_H32,
	S5PV210_GPIO_H33,
	S5PV210_GPIO_H34,
	S5PV210_GPIO_H35,
	S5PV210_GPIO_H36,
	S5PV210_GPIO_H37,

	S5PV210_GPIO_MAX_PORT
};

enum s5pc110_gpio_pin {
	S5PC110_GPIO_A00,
	S5PC110_GPIO_A01,
	S5PC110_GPIO_A02,
	S5PC110_GPIO_A03,
	S5PC110_GPIO_A04,
	S5PC110_GPIO_A05,
	S5PC110_GPIO_A06,
	S5PC110_GPIO_A07,
	S5PC110_GPIO_A10,
	S5PC110_GPIO_A11,
	S5PC110_GPIO_A12,
	S5PC110_GPIO_A13,
	S5PC110_GPIO_A14,
	S5PC110_GPIO_A15,
	S5PC110_GPIO_A16,
	S5PC110_GPIO_A17,
	S5PC110_GPIO_B0,
	S5PC110_GPIO_B1,
	S5PC110_GPIO_B2,
	S5PC110_GPIO_B3,
	S5PC110_GPIO_B4,
	S5PC110_GPIO_B5,
	S5PC110_GPIO_B6,
	S5PC110_GPIO_B7,
	S5PC110_GPIO_C00,
	S5PC110_GPIO_C01,
	S5PC110_GPIO_C02,
	S5PC110_GPIO_C03,
	S5PC110_GPIO_C04,
	S5PC110_GPIO_C05,
	S5PC110_GPIO_C06,
	S5PC110_GPIO_C07,
	S5PC110_GPIO_C10,
	S5PC110_GPIO_C11,
	S5PC110_GPIO_C12,
	S5PC110_GPIO_C13,
	S5PC110_GPIO_C14,
	S5PC110_GPIO_C15,
	S5PC110_GPIO_C16,
	S5PC110_GPIO_C17,
	S5PC110_GPIO_D00,
	S5PC110_GPIO_D01,
	S5PC110_GPIO_D02,
	S5PC110_GPIO_D03,
	S5PC110_GPIO_D04,
	S5PC110_GPIO_D05,
	S5PC110_GPIO_D06,
	S5PC110_GPIO_D07,
	S5PC110_GPIO_D10,
	S5PC110_GPIO_D11,
	S5PC110_GPIO_D12,
	S5PC110_GPIO_D13,
	S5PC110_GPIO_D14,
	S5PC110_GPIO_D15,
	S5PC110_GPIO_D16,
	S5PC110_GPIO_D17,
	S5PC110_GPIO_E00,
	S5PC110_GPIO_E01,
	S5PC110_GPIO_E02,
	S5PC110_GPIO_E03,
	S5PC110_GPIO_E04,
	S5PC110_GPIO_E05,
	S5PC110_GPIO_E06,
	S5PC110_GPIO_E07,
	S5PC110_GPIO_E10,
	S5PC110_GPIO_E11,
	S5PC110_GPIO_E12,
	S5PC110_GPIO_E13,
	S5PC110_GPIO_E14,
	S5PC110_GPIO_E15,
	S5PC110_GPIO_E16,
	S5PC110_GPIO_E17,
	S5PC110_GPIO_F00,
	S5PC110_GPIO_F01,
	S5PC110_GPIO_F02,
	S5PC110_GPIO_F03,
	S5PC110_GPIO_F04,
	S5PC110_GPIO_F05,
	S5PC110_GPIO_F06,
	S5PC110_GPIO_F07,
	S5PC110_GPIO_F10,
	S5PC110_GPIO_F11,
	S5PC110_GPIO_F12,
	S5PC110_GPIO_F13,
	S5PC110_GPIO_F14,
	S5PC110_GPIO_F15,
	S5PC110_GPIO_F16,
	S5PC110_GPIO_F17,
	S5PC110_GPIO_F20,
	S5PC110_GPIO_F21,
	S5PC110_GPIO_F22,
	S5PC110_GPIO_F23,
	S5PC110_GPIO_F24,
	S5PC110_GPIO_F25,
	S5PC110_GPIO_F26,
	S5PC110_GPIO_F27,
	S5PC110_GPIO_F30,
	S5PC110_GPIO_F31,
	S5PC110_GPIO_F32,
	S5PC110_GPIO_F33,
	S5PC110_GPIO_F34,
	S5PC110_GPIO_F35,
	S5PC110_GPIO_F36,
	S5PC110_GPIO_F37,
	S5PC110_GPIO_G00,
	S5PC110_GPIO_G01,
	S5PC110_GPIO_G02,
	S5PC110_GPIO_G03,
	S5PC110_GPIO_G04,
	S5PC110_GPIO_G05,
	S5PC110_GPIO_G06,
	S5PC110_GPIO_G07,
	S5PC110_GPIO_G10,
	S5PC110_GPIO_G11,
	S5PC110_GPIO_G12,
	S5PC110_GPIO_G13,
	S5PC110_GPIO_G14,
	S5PC110_GPIO_G15,
	S5PC110_GPIO_G16,
	S5PC110_GPIO_G17,
	S5PC110_GPIO_G20,
	S5PC110_GPIO_G21,
	S5PC110_GPIO_G22,
	S5PC110_GPIO_G23,
	S5PC110_GPIO_G24,
	S5PC110_GPIO_G25,
	S5PC110_GPIO_G26,
	S5PC110_GPIO_G27,
	S5PC110_GPIO_G30,
	S5PC110_GPIO_G31,
	S5PC110_GPIO_G32,
	S5PC110_GPIO_G33,
	S5PC110_GPIO_G34,
	S5PC110_GPIO_G35,
	S5PC110_GPIO_G36,
	S5PC110_GPIO_G37,
	S5PC110_GPIO_I0,
	S5PC110_GPIO_I1,
	S5PC110_GPIO_I2,
	S5PC110_GPIO_I3,
	S5PC110_GPIO_I4,
	S5PC110_GPIO_I5,
	S5PC110_GPIO_I6,
	S5PC110_GPIO_I7,
	S5PC110_GPIO_J00,
	S5PC110_GPIO_J01,
	S5PC110_GPIO_J02,
	S5PC110_GPIO_J03,
	S5PC110_GPIO_J04,
	S5PC110_GPIO_J05,
	S5PC110_GPIO_J06,
	S5PC110_GPIO_J07,
	S5PC110_GPIO_J10,
	S5PC110_GPIO_J11,
	S5PC110_GPIO_J12,
	S5PC110_GPIO_J13,
	S5PC110_GPIO_J14,
	S5PC110_GPIO_J15,
	S5PC110_GPIO_J16,
	S5PC110_GPIO_J17,
	S5PC110_GPIO_J20,
	S5PC110_GPIO_J21,
	S5PC110_GPIO_J22,
	S5PC110_GPIO_J23,
	S5PC110_GPIO_J24,
	S5PC110_GPIO_J25,
	S5PC110_GPIO_J26,
	S5PC110_GPIO_J27,
	S5PC110_GPIO_J30,
	S5PC110_GPIO_J31,
	S5PC110_GPIO_J32,
	S5PC110_GPIO_J33,
	S5PC110_GPIO_J34,
	S5PC110_GPIO_J35,
	S5PC110_GPIO_J36,
	S5PC110_GPIO_J37,
	S5PC110_GPIO_J40,
	S5PC110_GPIO_J41,
	S5PC110_GPIO_J42,
	S5PC110_GPIO_J43,
	S5PC110_GPIO_J44,
	S5PC110_GPIO_J45,
	S5PC110_GPIO_J46,
	S5PC110_GPIO_J47,
	S5PC110_GPIO_MP010,
	S5PC110_GPIO_MP011,
	S5PC110_GPIO_MP012,
	S5PC110_GPIO_MP013,
	S5PC110_GPIO_MP014,
	S5PC110_GPIO_MP015,
	S5PC110_GPIO_MP016,
	S5PC110_GPIO_MP017,
	S5PC110_GPIO_MP020,
	S5PC110_GPIO_MP021,
	S5PC110_GPIO_MP022,
	S5PC110_GPIO_MP023,
	S5PC110_GPIO_MP024,
	S5PC110_GPIO_MP025,
	S5PC110_GPIO_MP026,
	S5PC110_GPIO_MP027,
	S5PC110_GPIO_MP030,
	S5PC110_GPIO_MP031,
	S5PC110_GPIO_MP032,
	S5PC110_GPIO_MP033,
	S5PC110_GPIO_MP034,
	S5PC110_GPIO_MP035,
	S5PC110_GPIO_MP036,
	S5PC110_GPIO_MP037,
	S5PC110_GPIO_MP040,
	S5PC110_GPIO_MP041,
	S5PC110_GPIO_MP042,
	S5PC110_GPIO_MP043,
	S5PC110_GPIO_MP044,
	S5PC110_GPIO_MP045,
	S5PC110_GPIO_MP046,
	S5PC110_GPIO_MP047,
	S5PC110_GPIO_MP050,
	S5PC110_GPIO_MP051,
	S5PC110_GPIO_MP052,
	S5PC110_GPIO_MP053,
	S5PC110_GPIO_MP054,
	S5PC110_GPIO_MP055,
	S5PC110_GPIO_MP056,
	S5PC110_GPIO_MP057,
	S5PC110_GPIO_MP060,
	S5PC110_GPIO_MP061,
	S5PC110_GPIO_MP062,
	S5PC110_GPIO_MP063,
	S5PC110_GPIO_MP064,
	S5PC110_GPIO_MP065,
	S5PC110_GPIO_MP066,
	S5PC110_GPIO_MP067,
	S5PC110_GPIO_MP070,
	S5PC110_GPIO_MP071,
	S5PC110_GPIO_MP072,
	S5PC110_GPIO_MP073,
	S5PC110_GPIO_MP074,
	S5PC110_GPIO_MP075,
	S5PC110_GPIO_MP076,
	S5PC110_GPIO_MP077,
	S5PC110_GPIO_MP100,
	S5PC110_GPIO_MP101,
	S5PC110_GPIO_MP102,
	S5PC110_GPIO_MP103,
	S5PC110_GPIO_MP104,
	S5PC110_GPIO_MP105,
	S5PC110_GPIO_MP106,
	S5PC110_GPIO_MP107,
	S5PC110_GPIO_MP110,
	S5PC110_GPIO_MP111,
	S5PC110_GPIO_MP112,
	S5PC110_GPIO_MP113,
	S5PC110_GPIO_MP114,
	S5PC110_GPIO_MP115,
	S5PC110_GPIO_MP116,
	S5PC110_GPIO_MP117,
	S5PC110_GPIO_MP120,
	S5PC110_GPIO_MP121,
	S5PC110_GPIO_MP122,
	S5PC110_GPIO_MP123,
	S5PC110_GPIO_MP124,
	S5PC110_GPIO_MP125,
	S5PC110_GPIO_MP126,
	S5PC110_GPIO_MP127,
	S5PC110_GPIO_MP130,
	S5PC110_GPIO_MP131,
	S5PC110_GPIO_MP132,
	S5PC110_GPIO_MP133,
	S5PC110_GPIO_MP134,
	S5PC110_GPIO_MP135,
	S5PC110_GPIO_MP136,
	S5PC110_GPIO_MP137,
	S5PC110_GPIO_MP140,
	S5PC110_GPIO_MP141,
	S5PC110_GPIO_MP142,
	S5PC110_GPIO_MP143,
	S5PC110_GPIO_MP144,
	S5PC110_GPIO_MP145,
	S5PC110_GPIO_MP146,
	S5PC110_GPIO_MP147,
	S5PC110_GPIO_MP150,
	S5PC110_GPIO_MP151,
	S5PC110_GPIO_MP152,
	S5PC110_GPIO_MP153,
	S5PC110_GPIO_MP154,
	S5PC110_GPIO_MP155,
	S5PC110_GPIO_MP156,
	S5PC110_GPIO_MP157,
	S5PC110_GPIO_MP160,
	S5PC110_GPIO_MP161,
	S5PC110_GPIO_MP162,
	S5PC110_GPIO_MP163,
	S5PC110_GPIO_MP164,
	S5PC110_GPIO_MP165,
	S5PC110_GPIO_MP166,
	S5PC110_GPIO_MP167,
	S5PC110_GPIO_MP170,
	S5PC110_GPIO_MP171,
	S5PC110_GPIO_MP172,
	S5PC110_GPIO_MP173,
	S5PC110_GPIO_MP174,
	S5PC110_GPIO_MP175,
	S5PC110_GPIO_MP176,
	S5PC110_GPIO_MP177,
	S5PC110_GPIO_MP180,
	S5PC110_GPIO_MP181,
	S5PC110_GPIO_MP182,
	S5PC110_GPIO_MP183,
	S5PC110_GPIO_MP184,
	S5PC110_GPIO_MP185,
	S5PC110_GPIO_MP186,
	S5PC110_GPIO_MP187,
	S5PC110_GPIO_MP200,
	S5PC110_GPIO_MP201,
	S5PC110_GPIO_MP202,
	S5PC110_GPIO_MP203,
	S5PC110_GPIO_MP204,
	S5PC110_GPIO_MP205,
	S5PC110_GPIO_MP206,
	S5PC110_GPIO_MP207,
	S5PC110_GPIO_MP210,
	S5PC110_GPIO_MP211,
	S5PC110_GPIO_MP212,
	S5PC110_GPIO_MP213,
	S5PC110_GPIO_MP214,
	S5PC110_GPIO_MP215,
	S5PC110_GPIO_MP216,
	S5PC110_GPIO_MP217,
	S5PC110_GPIO_MP220,
	S5PC110_GPIO_MP221,
	S5PC110_GPIO_MP222,
	S5PC110_GPIO_MP223,
	S5PC110_GPIO_MP224,
	S5PC110_GPIO_MP225,
	S5PC110_GPIO_MP226,
	S5PC110_GPIO_MP227,
	S5PC110_GPIO_MP230,
	S5PC110_GPIO_MP231,
	S5PC110_GPIO_MP232,
	S5PC110_GPIO_MP233,
	S5PC110_GPIO_MP234,
	S5PC110_GPIO_MP235,
	S5PC110_GPIO_MP236,
	S5PC110_GPIO_MP237,
	S5PC110_GPIO_MP240,
	S5PC110_GPIO_MP241,
	S5PC110_GPIO_MP242,
	S5PC110_GPIO_MP243,
	S5PC110_GPIO_MP244,
	S5PC110_GPIO_MP245,
	S5PC110_GPIO_MP246,
	S5PC110_GPIO_MP247,
	S5PC110_GPIO_MP250,
	S5PC110_GPIO_MP251,
	S5PC110_GPIO_MP252,
	S5PC110_GPIO_MP253,
	S5PC110_GPIO_MP254,
	S5PC110_GPIO_MP255,
	S5PC110_GPIO_MP256,
	S5PC110_GPIO_MP257,
	S5PC110_GPIO_MP260,
	S5PC110_GPIO_MP261,
	S5PC110_GPIO_MP262,
	S5PC110_GPIO_MP263,
	S5PC110_GPIO_MP264,
	S5PC110_GPIO_MP265,
	S5PC110_GPIO_MP266,
	S5PC110_GPIO_MP267,
	S5PC110_GPIO_MP270,
	S5PC110_GPIO_MP271,
	S5PC110_GPIO_MP272,
	S5PC110_GPIO_MP273,
	S5PC110_GPIO_MP274,
	S5PC110_GPIO_MP275,
	S5PC110_GPIO_MP276,
	S5PC110_GPIO_MP277,
	S5PC110_GPIO_MP280,
	S5PC110_GPIO_MP281,
	S5PC110_GPIO_MP282,
	S5PC110_GPIO_MP283,
	S5PC110_GPIO_MP284,
	S5PC110_GPIO_MP285,
	S5PC110_GPIO_MP286,
	S5PC110_GPIO_MP287,
	S5PC110_GPIO_H00,
	S5PC110_GPIO_H01,
	S5PC110_GPIO_H02,
	S5PC110_GPIO_H03,
	S5PC110_GPIO_H04,
	S5PC110_GPIO_H05,
	S5PC110_GPIO_H06,
	S5PC110_GPIO_H07,
	S5PC110_GPIO_H10,
	S5PC110_GPIO_H11,
	S5PC110_GPIO_H12,
	S5PC110_GPIO_H13,
	S5PC110_GPIO_H14,
	S5PC110_GPIO_H15,
	S5PC110_GPIO_H16,
	S5PC110_GPIO_H17,
	S5PC110_GPIO_H20,
	S5PC110_GPIO_H21,
	S5PC110_GPIO_H22,
	S5PC110_GPIO_H23,
	S5PC110_GPIO_H24,
	S5PC110_GPIO_H25,
	S5PC110_GPIO_H26,
	S5PC110_GPIO_H27,
	S5PC110_GPIO_H30,
	S5PC110_GPIO_H31,
	S5PC110_GPIO_H32,
	S5PC110_GPIO_H33,
	S5PC110_GPIO_H34,
	S5PC110_GPIO_H35,
	S5PC110_GPIO_H36,
	S5PC110_GPIO_H37,

	S5PC110_GPIO_MAX_PORT
};

struct gpio_info {
	unsigned int reg_addr;	/* Address of register for this part */
	unsigned int max_gpio;	/* Maximum GPIO in this part */
};

#define S5PV210_GPIO_NUM_PARTS	1
static struct gpio_info S5PV210_gpio_data[S5PV210_GPIO_NUM_PARTS] = {
	{ S5PV210_GPIO_BASE, S5PV210_GPIO_MAX_PORT },
};

#define S5PC110_GPIO_NUM_PARTS	1
static struct gpio_info s5pc110_gpio_data[S5PC110_GPIO_NUM_PARTS] = {
	{ S5PC110_GPIO_BASE, S5PC110_GPIO_MAX_PORT },
};

static inline struct gpio_info *get_gpio_data(void)
{
	if (cpu_is_s5pv210())
		return S5PV210_gpio_data;
	else if (cpu_is_s5pc110())
		return s5pc110_gpio_data;

	return NULL;
}

static inline unsigned int get_bank_num(void)
{
	if (cpu_is_s5pv210())
		return S5PV210_GPIO_NUM_PARTS;
	else if (cpu_is_s5pc110())
		return S5PC110_GPIO_NUM_PARTS;

	return 0;
}

/*
 * This structure helps mapping symbolic GPIO names into indices from
 * exynos5_gpio_pin/exynos5420_gpio_pin enums.
 *
 * By convention, symbolic GPIO name is defined as follows:
 *
 * g[p]<bank><set><bit>, where
 *   p is optional
 *   <bank> - a single character bank name, as defined by the SOC
 *   <set> - a single digit set number
 *   <bit> - bit number within the set (in 0..7 range).
 *
 * <set><bit> essentially form an octal number of the GPIO pin within the bank
 * space. On the 5420 architecture some banks' sets do not start not from zero
 * ('d' starts from 1 and 'j' starts from 4). To compensate for that and
 * maintain flat number space withoout holes, those banks use offsets to be
 * deducted from the pin number.
 */
struct gpio_name_num_table {
	char bank;		/* bank name symbol */
	u8 bank_size;		/* total number of pins in the bank */
	char bank_offset;	/* offset of the first bank's pin */
	unsigned int base;	/* index of the first bank's pin in the enum */
};

#define GPIO_PER_BANK 8
#define GPIO_ENTRY(name, base, top, offset) { name, top - base, offset, base }
static const struct gpio_name_num_table S5PV210_gpio_table[] = {
	GPIO_ENTRY('a', S5PV210_GPIO_A00, S5PV210_GPIO_B0, 0),
	GPIO_ENTRY('b', S5PV210_GPIO_B0, S5PV210_GPIO_C0, 0),
	GPIO_ENTRY('c', S5PV210_GPIO_C0, S5PV210_GPIO_D0, 0),
	GPIO_ENTRY('d', S5PV210_GPIO_D0, S5PV210_GPIO_E00, 0),
	GPIO_ENTRY('e', S5PV210_GPIO_E00, S5PV210_GPIO_F00, 0),
	GPIO_ENTRY('f', S5PV210_GPIO_F00, S5PV210_GPIO_G00, 0),
	GPIO_ENTRY('g', S5PV210_GPIO_G00, S5PV210_GPIO_I0, 0),
	GPIO_ENTRY('i', S5PV210_GPIO_I0, S5PV210_GPIO_J00, 0),
	GPIO_ENTRY('j', S5PV210_GPIO_J00, S5PV210_GPIO_K00, 0),
	GPIO_ENTRY('k', S5PV210_GPIO_K00, S5PV210_GPIO_L00, 0),
	GPIO_ENTRY('l', S5PV210_GPIO_L00, S5PV210_GPIO_H00, 0),
	GPIO_ENTRY('h', S5PV210_GPIO_H00, S5PV210_GPIO_MAX_PORT, 0),
	{ 0 }
};

static const struct gpio_name_num_table s5pc110_gpio_table[] = {
	GPIO_ENTRY('a', S5PC110_GPIO_A00, S5PC110_GPIO_B0, 0),
	GPIO_ENTRY('b', S5PC110_GPIO_B0, S5PC110_GPIO_C00, 0),
	GPIO_ENTRY('c', S5PC110_GPIO_C00, S5PC110_GPIO_D00, 0),
	GPIO_ENTRY('d', S5PC110_GPIO_D00, S5PC110_GPIO_E00, 0),
	GPIO_ENTRY('e', S5PC110_GPIO_E00, S5PC110_GPIO_F00, 0),
	GPIO_ENTRY('f', S5PC110_GPIO_F00, S5PC110_GPIO_G00, 0),
	GPIO_ENTRY('g', S5PC110_GPIO_G00, S5PC110_GPIO_I0, 0),
	GPIO_ENTRY('i', S5PC110_GPIO_I0, S5PC110_GPIO_J00, 0),
	GPIO_ENTRY('j', S5PC110_GPIO_J00, S5PC110_GPIO_MP010, 0),
	GPIO_ENTRY('h', S5PC110_GPIO_H00, S5PC110_GPIO_MAX_PORT, 0),
	{ 0 }
};

/* functions */
void gpio_cfg_pin(int gpio, int cfg);
void gpio_set_pull(int gpio, int mode);
void gpio_set_drv(int gpio, int mode);
void gpio_set_rate(int gpio, int mode);
int s5p_gpio_get_pin(unsigned gpio);

/* GPIO pins per bank  */
#define GPIO_PER_BANK 8
#endif

/* Pin configurations */
#define S5P_GPIO_INPUT	0x0
#define S5P_GPIO_OUTPUT	0x1
#define S5P_GPIO_IRQ	0xf
#define S5P_GPIO_FUNC(x)	(x)

/* Pull mode */
#define S5P_GPIO_PULL_NONE	0x0
#define S5P_GPIO_PULL_DOWN	0x1
#define S5P_GPIO_PULL_UP	0x2

/* Drive Strength level */
#define S5P_GPIO_DRV_1X	0x0
#define S5P_GPIO_DRV_3X	0x1
#define S5P_GPIO_DRV_2X	0x2
#define S5P_GPIO_DRV_4X	0x3
#define S5P_GPIO_DRV_FAST	0x0
#define S5P_GPIO_DRV_SLOW	0x1

#endif
