/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000




/* Defines for PIN_Front_Left_A: GPIOB.18 with pinCMx 44 on package pin 15 */
#define GPIO_Encoder_PIN_Front_Left_A_PORT                               (GPIOB)
// pins affected by this interrupt request:["PIN_Front_Left_A","PIN_Back_Left_A"]
#define GPIO_Encoder_GPIOB_INT_IRQN                             (GPIOB_INT_IRQn)
#define GPIO_Encoder_GPIOB_INT_IIDX             (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_Encoder_PIN_Front_Left_A_IIDX                  (DL_GPIO_IIDX_DIO18)
#define GPIO_Encoder_PIN_Front_Left_A_PIN                       (DL_GPIO_PIN_18)
#define GPIO_Encoder_PIN_Front_Left_A_IOMUX                      (IOMUX_PINCM44)
/* Defines for PIN_Front_Left_B: GPIOA.17 with pinCMx 39 on package pin 10 */
#define GPIO_Encoder_PIN_Front_Left_B_PORT                               (GPIOA)
#define GPIO_Encoder_PIN_Front_Left_B_PIN                       (DL_GPIO_PIN_17)
#define GPIO_Encoder_PIN_Front_Left_B_IOMUX                      (IOMUX_PINCM39)
/* Defines for PIN_Front_Right_A: GPIOA.16 with pinCMx 38 on package pin 9 */
#define GPIO_Encoder_PIN_Front_Right_A_PORT                              (GPIOA)
// pins affected by this interrupt request:["PIN_Front_Right_A","PIN_Back_Right_A"]
#define GPIO_Encoder_GPIOA_INT_IRQN                             (GPIOA_INT_IRQn)
#define GPIO_Encoder_GPIOA_INT_IIDX             (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_Encoder_PIN_Front_Right_A_IIDX                 (DL_GPIO_IIDX_DIO16)
#define GPIO_Encoder_PIN_Front_Right_A_PIN                      (DL_GPIO_PIN_16)
#define GPIO_Encoder_PIN_Front_Right_A_IOMUX                     (IOMUX_PINCM38)
/* Defines for PIN_Front_Right_B: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GPIO_Encoder_PIN_Front_Right_B_PORT                              (GPIOA)
#define GPIO_Encoder_PIN_Front_Right_B_PIN                      (DL_GPIO_PIN_15)
#define GPIO_Encoder_PIN_Front_Right_B_IOMUX                     (IOMUX_PINCM37)
/* Defines for PIN_Back_Left_A: GPIOB.19 with pinCMx 45 on package pin 16 */
#define GPIO_Encoder_PIN_Back_Left_A_PORT                                (GPIOB)
#define GPIO_Encoder_PIN_Back_Left_A_IIDX                   (DL_GPIO_IIDX_DIO19)
#define GPIO_Encoder_PIN_Back_Left_A_PIN                        (DL_GPIO_PIN_19)
#define GPIO_Encoder_PIN_Back_Left_A_IOMUX                       (IOMUX_PINCM45)
/* Defines for PIN_Back_Left_B: GPIOA.22 with pinCMx 47 on package pin 18 */
#define GPIO_Encoder_PIN_Back_Left_B_PORT                                (GPIOA)
#define GPIO_Encoder_PIN_Back_Left_B_PIN                        (DL_GPIO_PIN_22)
#define GPIO_Encoder_PIN_Back_Left_B_IOMUX                       (IOMUX_PINCM47)
/* Defines for PIN_Back_Right_A: GPIOA.24 with pinCMx 54 on package pin 25 */
#define GPIO_Encoder_PIN_Back_Right_A_PORT                               (GPIOA)
#define GPIO_Encoder_PIN_Back_Right_A_IIDX                  (DL_GPIO_IIDX_DIO24)
#define GPIO_Encoder_PIN_Back_Right_A_PIN                       (DL_GPIO_PIN_24)
#define GPIO_Encoder_PIN_Back_Right_A_IOMUX                      (IOMUX_PINCM54)
/* Defines for PIN_Back_Right_B: GPIOA.18 with pinCMx 40 on package pin 11 */
#define GPIO_Encoder_PIN_Back_Right_B_PORT                               (GPIOA)
#define GPIO_Encoder_PIN_Back_Right_B_PIN                       (DL_GPIO_PIN_18)
#define GPIO_Encoder_PIN_Back_Right_B_IOMUX                      (IOMUX_PINCM40)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);



#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
