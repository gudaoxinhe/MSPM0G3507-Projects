/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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

#include "ti_msp_dl_config.h"

volatile int32_t Front_Right_Count=0;
volatile int32_t Front_Left_Count=0;
volatile int32_t Back_Right_Count=0;
volatile int32_t Back_Left_Count=0;
int main(void)
{
    SYSCFG_DL_init();
    NVIC_EnableIRQ(GPIO_Encoder_GPIOB_INT_IRQN);
    NVIC_EnableIRQ(GPIO_Encoder_GPIOA_INT_IRQN);
    while (1) {
    }
}
void GROUP1_IRQHandler(void)
{
    uint32_t gpioA=DL_GPIO_getEnabledInterruptStatus(GPIOA,GPIO_Encoder_PIN_Front_Right_A_PIN|GPIO_Encoder_PIN_Back_Right_A_PIN);
    uint32_t gpioB=DL_GPIO_getEnabledInterruptStatus(GPIOB,GPIO_Encoder_PIN_Front_Left_A_PIN|GPIO_Encoder_PIN_Back_Left_A_PIN);
    if(gpioA&GPIO_Encoder_PIN_Front_Right_A_PIN)
    {
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_Front_Right_B_PORT,GPIO_Encoder_PIN_Front_Right_B_PIN))//A上升沿B高电平，编码器反转
        {
            Front_Right_Count--;
        }
        else {
            Front_Right_Count++;
        }
        DL_GPIO_clearInterruptStatus(GPIOA, GPIO_Encoder_PIN_Front_Right_A_PIN);
    }
    if(gpioA&GPIO_Encoder_PIN_Back_Right_A_PIN)
    {
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_Back_Right_B_PORT,GPIO_Encoder_PIN_Back_Right_B_PIN))//A上升沿B高电平，编码器反转
        {
            Back_Right_Count--;
        }
        else {
            Back_Right_Count++;
        }
        DL_GPIO_clearInterruptStatus(GPIOA, GPIO_Encoder_PIN_Back_Right_A_PIN);
    }
    if(gpioB&GPIO_Encoder_PIN_Front_Left_A_PIN)
    {
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_Front_Left_B_PORT,GPIO_Encoder_PIN_Front_Left_B_PIN))//A上升沿B高电平，编码器反转
        {
            Front_Left_Count--;
        }
        else {
           Front_Left_Count++;
        }
        DL_GPIO_clearInterruptStatus(GPIOB, GPIO_Encoder_PIN_Front_Left_A_PIN);
    }
     if(gpioB&GPIO_Encoder_PIN_Back_Left_A_PIN)
    {
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_Back_Left_B_PORT,GPIO_Encoder_PIN_Back_Left_B_PIN))//A上升沿B高电平，编码器反转
        {
            Back_Left_Count--;
        }
        else {
           Back_Left_Count++;
        }
        DL_GPIO_clearInterruptStatus(GPIOB, GPIO_Encoder_PIN_Back_Left_A_PIN);
    }
}