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
#include "motor.h"

int16_t rxbuf=0,cx=160;//openmv横向分辨率是320，cx=160代表此时检测到的黑线在中间
int16_t baseSpeed=15;
int16_t speedL=0,speedR=0;
float kp=0.5;

void motor_ctrl(void);

int main(void)
{
    SYSCFG_DL_init();
    NVIC_ClearPendingIRQ(UART_OPENMV_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_OPENMV_INST_INT_IRQN);

    while(DL_GPIO_readPins(GPIO_BUTTON_PORT,GPIO_BUTTON_PIN_1_PIN));
    DL_UART_transmitDataBlocking(UART_OPENMV_INST, 'S');//向openmv发送start信号

    delay_cycles((32000000));

    set_speed(0,baseSpeed);
    set_speed(1,baseSpeed);
    motor_on();

    while (1) {
        motor_ctrl();
    }
}
//控制轮子的速度在0-30之间
void motor_ctrl(void)
{
    speedL=baseSpeed+(cx-160)*kp;
    speedR=baseSpeed-(cx-160)*kp;
    if(speedL>30)
    {
        speedL=30;
    }
    else if(speedL<0)
    {
        speedL=0;
    }

    if(speedR>30)
    {
        speedR=30;
    }
    else if(speedR<0)
    {
        speedR=0;
    }
    set_speed(0,speedL);
    set_speed(1,speedR);
}

void UART_OPENMV_INST_IRQHandler(void)
{
    uint8_t gData;
    switch(DL_UART_Main_getPendingInterrupt(UART_OPENMV_INST))
    {
        case DL_UART_MAIN_IIDX_RX:
            gData=DL_UART_receiveDataBlocking(UART_OPENMV_INST);
            if(gData=='S')//收到openmv发送的stop信号
            {
                motor_off();
                DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_PIN_0_PIN);
            }
            else if(gData=='f')//收到包头
            {
                rxbuf=0;
            }
            else if(gData=='l')//收到包尾
            {
                cx=rxbuf;
            }
            else
            {
                rxbuf=10*rxbuf+(gData-'0');//发送的字符是ASCII码形式，需要减去一个'0'位
            }
            break;
        default:
        break;
    }
}