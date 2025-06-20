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
#include "stdio.h"
#include "string.h"

//volatile uint8_t TXdata=128;
char txBuf[100];
void BT_SendString(char *str);
void openMV_SendString(char *str);
int main(void)
{
    SYSCFG_DL_init();

    while (1) {
//        printf("Hello %d\r\n",TXdata);
//        sprintf(txBuf,"MSPM0G%d\r\n",3507);
//        SendString(txBuf);
        BT_SendString("BT");
        openMV_SendString("openMV");//引脚配置不是通过仿真器发送到串口的
        delay_cycles(32000000);//延时1s
    }
}
void BT_SendString(char *str)
{
    while(*str!='\0')
    {
        DL_UART_Main_transmitDataBlocking(UART_BT_INST,*str++);
    }
}
void openMV_SendString(char *str)
{
    while(*str!='\0')
    {
        DL_UART_Main_transmitDataBlocking(UART_openMV_INST,*str++);
    }
}
// int fputc(int c, FILE* stream)
// {
//     DL_UART_Main_transmitDataBlocking(UART_0_INST, c);//具有阻塞功能的发送函数，等待发送完再执行下一次操作
//     return c;
// }
// int fputs(const char* restrict s, FILE* restrict stream)
// {
//     uint16_t i,len;
//     len=strlen(s);
//     for(i=0;i<len;i++)
//     {
//         DL_UART_Main_transmitDataBlocking(UART_0_INST,s[i]);
//     }
//     return len;
// }
// int puts(const char* s)
// {
//     int count=fputs(s,stdout);
//     count+=fputs("\n",stdout);
//     return count;
// }
