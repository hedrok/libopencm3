/** @defgroup dcmi_defines DCMI Defines

@brief <b>Defined Constants and Types for the STM32F4xx DCMI </b>

@ingroup STM32F4xx_defines

@version 1.0.0

@date 23 July 2013

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_DCMI_H
#define LIBOPENCM3_DCMI_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/**@{*/

/* --- Convenience macros -------------------------------------------------- */

/* DCMI register base addresses (for convenience) */
/*****************************************************************************/
/** @defgroup dcmi_reg_base DCMI register base address
@ingroup dcmi_defines

@{*/
#define DCMI		DCMI_BASE
/**@}*/

/* --- DCMI registers ------------------------------------------------------- */

/* Control register 1 (DCMI_CR) */
#define DCMI_CR		MMIO32(DCMI_BASE + 0x00)

/* Status register (DCMI_SR) */
#define DCMI_SR		MMIO32(DCMI_BASE + 0x04)

/* Raw interrupt status register (DCMI_RIS) */
#define DCMI_RIS	MMIO32(DCMI_BASE + 0x08)

/* Interrupt enable register (DCMI_IER) */
#define DCMI_IER	MMIO32(DCMI_BASE + 0x0c)

/* Masked interrupt status register (DCMI_MIS) */
#define DCMI_MIS	MMIO32(DCMI_BASE + 0x10)

/* Interrupt clear register (DCMI_ICR) */
#define DCMI_ICR	MMIO32(DCMI_BASE + 0x14)

/* Embedded synchronization code register (DCMI_ESCR) */
#define DCMI_ESCR	MMIO32(DCMI_BASE + 0x18)

/* Embedded synchronization unmask register (DCMI_ESUR) */
#define DCMI_ESUR	MMIO32(DCMI_BASE + 0x1c)

/* Crop window start (DCMI_CWSTRT) */
#define DCMI_CWSTRT	MMIO32(DCMI_BASE + 0x20)

/* Crop window size (DCMI_CWSIZE) */
#define DCMI_CWSIZE	MMIO32(DCMI_BASE + 0x24)

/* Data register(DCMI_DR) */
#define DCMI_DR		MMIO32(DCMI_BASE + 0x28)

/* --- DCMI_CR values ------------------------------------------------------- */

/* Note: Bits 31:15 are reserved, and set to 0 by hardware. */

/* ENABLE: DCMI enable*/
#define DCMI_CR_ENABLE		(1 << 14)

/* Note: Bits 13:12 are reserved, and set to 0 by hardware. */

/****************************************************************************/
/** @defgroup dcmi_cr_edm DCMI_CR EDM[1:0] Extended data mode
@ingroup dcmi_defines

@{*/
/* EDM[1:0]: Extended data mode */
#define DCMI_CR_EDM_8BIT_DATA		(0x0 << 10)
#define DCMI_CR_EDM_10BIT_DATA		(0x1 << 10)
#define DCMI_CR_EDM_12BIT_DATA		(0x2 << 10)
#define DCMI_CR_EDM_14BIT_DATA		(0x3 << 10)
#define DCMI_CR_EDM_MASK		(0x3 << 10)
/**@}*/

/****************************************************************************/
/** @defgroup dcmi_cr_fcfr DCMI_CR FCRC[1:0] Frame capture rate control
@ingroup dcmi_defines

@{*/
/* FCRC[1:0]: Frame capture rate control */
#define DCMI_CR_FCRC_ALL_FRAMES		(0x0 << 8)
#define DCMI_CR_FCRC_ALTERNATE_FRAMES	(0x1 << 8)
#define DCMI_CR_FCRC_ONE_IN_4_FRAMES	(0x2 << 8)
#define DCMI_CR_FCRC_MASK		(0x3 << 8)
/**@}*/

/* VSPOL: Vertical synchronization polarity.
   0 - VSYNC active low, 1 - VSYNC active high */
#define DCMI_CR_VSPOL			(1 << 7)
#define DCMI_CR_VSPOL_ACTIVE_LOW	0
#define DCMI_CR_VSPOL_ACTIVE_HIGH	1

/* HSPOL: Hertical synchronization polarity. */
#define DCMI_CR_HSPOL			(1 << 6)
#define DCMI_CR_HSPOL_ACTIVE_LOW	0
#define DCMI_CR_HSPOL_ACTIVE_HIGH	1

/* PCKPOL: Pixel clock polarity.
   0 falling edge active, 1 - rising edge active */
#define DCMI_CR_PCKPOL			(1 << 5)
#define DCMI_CR_PCKPOL_FALLING_EDGE	0
#define DCMI_CR_PCKPOL_RISING_EDGE	1


/* ESS: Embedded synchronization select */
#define DCMI_CR_ESS		(1 << 4)

/* JPEG: JPEG format */
#define DCMI_CR_JPEG		(1 << 3)

/* CROP: Crop feature */
#define DCMI_CR_CROP		(1 << 2)

/* CM: Capture mode */
#define DCMI_CR_CM		(1 << 1)
#define DCMI_CR_CONTINUOUS_GRAB	0
#define DCMI_CR_SNAPSHOT	1

/* CAPTURE: Capture enable */
#define DCMI_CR_CAPTURE		(1 << 0)

/* --- DCMI_SR values ------------------------------------------------------- */

/* Note: Bits 31:3 are reserved, and set to 0 by hardware. */

/* FNE: FIFO not empty */
#define DCMI_SR_FNE		(1 << 2)

/* VSYNC: frame synchronization */
#define DCMI_SR_VSYNC			(1 << 1)
#define DCMI_SR_VSYNC_ACTIVE_FRAME	0
#define DCMI_SR_VSYNC_BETWEEN_FRAMES	1

/* HSYNC: line synchronization */
#define DCMI_SR_HSYNC			(1 << 0)
#define DCMI_SR_HSYNC_ACTIVE_LINE	0
#define DCMI_SR_HSYNC_BETWEEN_LINES	1

/* --- DCMI_RIS values ------------------------------------------------------- */

/* Note: Bits 31:5 are reserved, and set to 0 by hardware. */

/* LINE_RIS: Line raw interrupt status */
#define DCMI_RIS_LINE_RIS		(1 << 4)

/* VSYNC_RIS: ERR raw interrupt status */
#define DCMI_RIS_VSYNC_RIS		(1 << 3)

/* ERR_RIS: Synchronization error raw interrupt status */
#define DCMI_RIS_ERR_RIS		(1 << 2)

/* OVR_RIS: Overrun raw interrupt status */
#define DCMI_RIS_OVR_RIS		(1 << 1)

/* FRAME_RIS: Capture complete raw interrupt status */
#define DCMI_RIS_FRAME_RIS		(1 << 0)

/* --- DCMI_IER values ------------------------------------------------------- */

/* Note: Bits 31:5 are reserved, and set to 0 by hardware. */

/* LINE_IE: Line interrupt enable */
#define DCMI_IER_LINE_IE		(1 << 4)

/* VSYNC_IE: ERR interrupt enable */
#define DCMI_IER_VSYNC_IE		(1 << 3)

/* ERR_IE: Synchronization error interrupt enable */
#define DCMI_IER_ERR_IE			(1 << 2)

/* OVR_IE: Overrun interrupt enable */
#define DCMI_IER_OVR_IE			(1 << 1)

/* FRAME_IE: Capture complete interrupt enable */
#define DCMI_IER_FRAME_IE		(1 << 0)

/* --- DCMI_MIS values ------------------------------------------------------- */

/* Note: Bits 31:5 are reserved, and set to 0 by hardware. */

/* LINE_MIS: Line masked interrupt status */
#define DCMI_MIS_LINE_MIS		(1 << 4)

/* VSYNC_MIS: ERR masked interrupt status */
#define DCMI_MIS_VSYNC_MIS		(1 << 3)

/* ERR_MIS: Synchronization error masked interrupt status */
#define DCMI_MIS_ERR_MIS		(1 << 2)

/* OVR_MIS: Overrun masked interrupt status */
#define DCMI_MIS_OVR_MIS		(1 << 1)

/* FRAME_MIS: Capture complete masked interrupt status */
#define DCMI_MIS_FRAME_MIS		(1 << 0)

/* --- DCMI_ICR values ------------------------------------------------------- */

/* Note: Bits 31:5 are reserved, and set to 0 by hardware. */

/* LINE_ISC: Line interrupt status clear */
#define DCMI_ICR_LINE_ISC		(1 << 4)

/* VSYNC_ISC: ERR interrupt status clear */
#define DCMI_ICR_VSYNC_ISC		(1 << 3)

/* ERR_ISC: Synchronization error interrupt status clear */
#define DCMI_ICR_ERR_ISC		(1 << 2)

/* OVR_ISC: Overrun interrupt status clear */
#define DCMI_ICR_OVR_ISC		(1 << 1)

/* FRAME_ISC: Capture complete interrupt status clear */
#define DCMI_ICR_FRAME_ISC		(1 << 0)

/* --- DCMI_ESCR values ------------------------------------------------------- */

/* FEC: Frame end delimeter code */
#define DCMI_ESCR_FEC			(1 << 24)
#define DCMI_ESCR_FEC_MASK		(0xff << 24)

/* LEC: Line end delimeter code */
#define DCMI_ESCR_LEC			(1 << 16)
#define DCMI_ESCR_LEC_MASK		(0xff << 16)

/* LSC: Line start delimeter code */
#define DCMI_ESCR_LSC			(1 << 8)
#define DCMI_ESCR_LSC_MASK		(0xff << 8)

/* FSC: Frame start delimeter code */
#define DCMI_ESCR_FSC			(1 << 0)
#define DCMI_ESCR_FSC_MASK		(0xff << 0)

/* --- DCMI_ESUR values ------------------------------------------------------- */

/* FEU: Frame end delimeter unmask */
#define DCMI_ESUR_FEU			(1 << 24)
#define DCMI_ESUR_FEU_MASK		(0xff << 24)

/* LEU: Line end delimeter unmask */
#define DCMI_ESUR_LEU			(1 << 16)
#define DCMI_ESUR_LEU_MASK		(0xff << 16)

/* LSU: Line start delimeter unmask */
#define DCMI_ESUR_LSU			(1 << 8)
#define DCMI_ESUR_LSU_MASK		(0xff << 8)

/* FSU: Frame start delimeter unmask */
#define DCMI_ESUR_FSU			(1 << 0)
#define DCMI_ESUR_FSU_MASK		(0xff << 0)

/* --- DCMI_CWSTRT values ------------------------------------------------------- */

/* VST: Vertical start line count */
#define DCMI_CWSTRT_VST			(1 << 16)
#define DCMI_CWSTRT_VST_MASK		(0xfff << 16)

/* HOFFCNT: Horizontal offset count */
#define DCMI_CWSTRT_HOFFCNT		(1 << 0)
#define DCMI_CWSTRT_HOFFCNT_MASK	(0x1fff << 0)

/* --- DCMI_CWSIZE values ------------------------------------------------------- */

/* VLINE: Vertical line count */
#define DCMI_CWSIZE_VLINE		(1 << 16)
#define DCMI_CWSIZE_VLINE_MASK		(0x1fff << 24)

/* CAPCNT: Capture count (number of pixels in line) */
#define DCMI_CWSIZE_CAPCNT		(1 << 0)
#define DCMI_CWSIZE_CAPCNT_MASK		(0x1fff << 0)

/* --- DCMI_DR values ------------------------------------------------------- */

/* DR[31:24]: Byte 3 */
/* DR[31:24]: Byte 2 */
/* DR[31:24]: Byte 1 */
/* DR[31:24]: Byte 0 */

/* --- DCMI function prototypes---------------------------------------------- */

//BEGIN_DECLS
//
//END_DECLS

#endif
/**@}*/
