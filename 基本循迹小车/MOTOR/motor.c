#include "motor.h"
void motor_on(void)
{
    DL_GPIO_setPins(GPIO_MOTOR_PIN_FSTBY_PORT, GPIO_MOTOR_PIN_FSTBY_PIN);//启动电机STBY引脚必须为高电平
    DL_GPIO_setPins(GPIO_MOTOR_PIN_BSTBY_PORT, GPIO_MOTOR_PIN_BSTBY_PIN);
}

void motor_off(void)
{
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FSTBY_PORT, GPIO_MOTOR_PIN_FSTBY_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_BSTBY_PORT, GPIO_MOTOR_PIN_BSTBY_PIN);

    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL1_PORT,GPIO_MOTOR_PIN_FL1_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL2_PORT,GPIO_MOTOR_PIN_FL2_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR1_PORT,GPIO_MOTOR_PIN_FR1_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR2_PORT,GPIO_MOTOR_PIN_FR2_PIN);

    DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL1_PORT,GPIO_MOTOR_PIN_BL1_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL2_PORT,GPIO_MOTOR_PIN_BL2_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR1_PORT,GPIO_MOTOR_PIN_BR1_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR2_PORT,GPIO_MOTOR_PIN_BR2_PIN);
}
//side=0为左侧，side=1为右侧
void set_speed(uint8_t side,int8_t duty)
{
    uint32_t CompareValue=0;
    if(side==0)
    {
        if(duty<0)//电机反转
        {
            CompareValue=3199-3199*(-duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST,CompareValue,GPIO_PWM_MOTOR_C0_IDX);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FL1_PORT, GPIO_MOTOR_PIN_FL1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL2_PORT, GPIO_MOTOR_PIN_FL2_PIN);//根据电机接线情况再做调整

            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST,CompareValue,GPIO_PWM_MOTOR_C2_IDX);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_BL1_PORT, GPIO_MOTOR_PIN_BL1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL2_PORT, GPIO_MOTOR_PIN_BL2_PIN);//根据电机接线情况再做调整
        }
        else if(duty>0)//电机正转
        {
            CompareValue=3199+3199*(-duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST,CompareValue,GPIO_PWM_MOTOR_C0_IDX);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL1_PORT, GPIO_MOTOR_PIN_FL1_PIN);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FL2_PORT, GPIO_MOTOR_PIN_FL2_PIN);//根据电机接线情况再做调整

            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST,CompareValue,GPIO_PWM_MOTOR_C2_IDX);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL1_PORT, GPIO_MOTOR_PIN_BL1_PIN);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_BL2_PORT, GPIO_MOTOR_PIN_BL2_PIN);//根据电机接线情况再做调整
        }
        else
        {
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL1_PORT,GPIO_MOTOR_PIN_FL1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL2_PORT,GPIO_MOTOR_PIN_FL2_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL1_PORT,GPIO_MOTOR_PIN_BL1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL2_PORT,GPIO_MOTOR_PIN_BL2_PIN);
        }
    }
    else 
    {
        if(duty<0)//电机反转
        {
            CompareValue=3199-3199*(-duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST,CompareValue,GPIO_PWM_MOTOR_C1_IDX);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FR1_PORT, GPIO_MOTOR_PIN_FR1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR2_PORT, GPIO_MOTOR_PIN_FR2_PIN);//根据电机接线情况再做调整

            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST,CompareValue,GPIO_PWM_MOTOR_C3_IDX);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_BR1_PORT, GPIO_MOTOR_PIN_BR1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR2_PORT, GPIO_MOTOR_PIN_BR2_PIN);//根据电机接线情况再做调整
        }
        else if(duty>0)//电机正转
        {
            CompareValue=3199+3199*(-duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST,CompareValue,GPIO_PWM_MOTOR_C1_IDX);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR1_PORT, GPIO_MOTOR_PIN_FR1_PIN);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FR2_PORT, GPIO_MOTOR_PIN_FR2_PIN);//根据电机接线情况再做调整

            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST,CompareValue,GPIO_PWM_MOTOR_C3_IDX);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR1_PORT, GPIO_MOTOR_PIN_BR1_PIN);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_BR2_PORT, GPIO_MOTOR_PIN_BR2_PIN);//根据电机接线情况再做调整
        }
        else
        {
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR1_PORT,GPIO_MOTOR_PIN_FR1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR2_PORT,GPIO_MOTOR_PIN_FR2_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR1_PORT,GPIO_MOTOR_PIN_BR1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR2_PORT,GPIO_MOTOR_PIN_BR2_PIN);
        }
    }
}