#ifndef __LED_H__
#define __LED_H__
#include "main.h"

#define LEVEL_DEFAULT	  14
#define LEVEL_MIN		   2//
#define LEVEL_MAX        10
#define LEVEL_ZERO        0
#define LEVEL_STEP		  3 ////WT.EDIT 2021.05.31
#define LEVEL_PWM_STEP   10
#define LEVEL_PWM_MAX	  80//

extern volatile uint8_t transOngoingFlag;
typedef enum{OFF,ON}Onoff;
typedef enum{nocolor,c_595=0x30,c_450=0x31,c_blue=0x32,c_365=0x33,c_415=0x34,c_white=0x35,c_green=0x36,
	          c_505=0x37,c_730=0x39,c_940=0x3a,c_850=0x3b,c_red=0x3e}sortColor;

typedef struct{
    
    uint8_t sortLamp;
    uint8_t runCmd;
    uint8_t pwm_color;
    uint8_t pwm_red;
    uint8_t pwm_green;
    uint8_t pwm_blue;
    uint8_t pwm_rgb;
    uint8_t lamp_brigtness;
    uint8_t lamp_red;
    uint8_t lamp_green;
    uint8_t lamp_blue;
    
}LAMP_T;

extern LAMP_T lamp_t;

//void Color_C505_Switch(uint8_t onvalue);
//void Color_450_Switch(uint8_t onvalue);
void Color_ALL_TurnOff(void);

void LedOnOff(uint8_t ledNum,uint8_t onOff);
void RunCommand(void);
void AdjustBrightness(uint8_t dir);
void TxData(uint8_t index);
void TIM2_SetCompare_1(TIM_HandleTypeDef* TIMx, uint16_t Compare2);
void TIM2_SetCompare_2(TIM_HandleTypeDef* TIMx, uint16_t Compare2);
void TIM2_SetCompare_3(TIM_HandleTypeDef* TIMx, uint16_t Compare2);
void TIM2_SetCompare_4(TIM_HandleTypeDef* TIMx, uint16_t Compare2);
void TunrOff_AllLamp(void);

#endif 
