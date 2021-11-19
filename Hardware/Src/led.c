#include "led.h"
#include "gpio.h"
#include "tim.h"
#include "main.h"
#include "usart.h"

#define MAX_BUFFER_SIZE    8

volatile uint8_t transOngoingFlag;
LAMP_T lamp_t;

static uint8_t lastOnLed = 0xff;
static uint8_t hasLedOn;

static uint8_t level_rgb;
static uint8_t outputBuf[MAX_BUFFER_SIZE];
static uint8_t transferSize;


static void setLevel_PWM_Color(uint16_t level);
static void setLevel_PWM_RGB(uint16_t level);

//static void TIM2_SetCompare_1(TIM_HandleTypeDef* TIMx, uint16_t Compare1);


//static void TIM2_SetCompare_2(TIM_HandleTypeDef* TIMx, uint16_t Compare2);
//static void TIM2_SetCompare_2(TIM_HandleTypeDef* TIMx, uint16_t Compare2);
//static void TIM2_SetCompare_3(TIM_HandleTypeDef* TIMx, uint16_t Compare2);
//static void TIM2_SetCompare_4(TIM_HandleTypeDef* TIMx, uint16_t Compare2);

static void Color_C505_Switch(uint8_t onvalue);

static void Color_730_Switch(uint8_t onvalue);

static void Color_415_Switch(uint8_t onvalue);

static  void Color_850_Switch(uint8_t onvalue);

static void Color_940_Switch(uint8_t onvalue);

static void Color_White_Switch(uint8_t onvalue);

static void Color_595_Switch(uint8_t onvalue);

static void Color_450_Switch(uint8_t onvalue);

static void Color_365_Switch(uint8_t onvalue);

static void Color_NoCombination_Off(void);

static void Color_Red_Switch(uint8_t onvalue);
static void Color_Green_Switch(uint8_t onvalue);
static void Color_Blue_Switch(uint8_t onvalue);
static void Color_RGB_Switch(uint8_t onvalue);


/**********************************************************
	*
	*Function Name:void Color_ALL_TurnOff(void)
	*Function: turn  off color  LED 
	*Input Ref: NO
	*Return Ref: NO 
	*
**********************************************************/
void Color_ALL_TurnOff(void)
{
	/*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, COLOR_595_EN_Pin|COLOR_450_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(COLOR_365_EN_GPIO_Port, COLOR_365_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, COLOR_C_505_EN_Pin|COLOR_730_EN_Pin|COLOR_415_EN_Pin|COLOR_850_EN_Pin
                          |COLOR_940_EN_Pin|GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, COLOR_W_EN_Pin|GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_8, GPIO_PIN_RESET);
              HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_2) ;  //2.the second turn on Enable
              HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1) ;  //2.the second turn on Enable
			  HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_3) ;  //2.the second turn on Enable
			  HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_4) ;  //2.the second turn on Enable
			  TIM2_SetCompare_1(&htim2, 0); //duty cycle 50%= 80*50% =40
			  TIM2_SetCompare_2(&htim2, 0); //duty cycle 50%= 80*50% =40
			  TIM2_SetCompare_3(&htim2, 0);
			  TIM2_SetCompare_4(&htim2, 0);
	
}
/**************************************************************************
	*
	*Function Name:TunrOff_AllLamp(void)
	*Function: turn off all lamp 
	*Input Ref: NO
	*Return Ref: NO 
	*
***************************************************************************/
void TunrOff_AllLamp(void)
{
  lamp_t.sortLamp = nocolor; 
}
/**********************************************************
	*
	*Function Name:void Color_C505_Switch(uint8_t onvalue)
	*Function: turn on or off color c505 LED 
	*Input Ref: turn on or off value
	*Return Ref: NO 
	*
**********************************************************/
static void Color_C505_Switch(uint8_t onvalue)
{
      switch(onvalue){
		 
		 case 0:
		    HAL_GPIO_WritePin(COLOR_C_505_EN_GPIO_Port, COLOR_C_505_EN_Pin, GPIO_PIN_RESET);
		 break;
		 
		 case 1:
		 	HAL_GPIO_WritePin(COLOR_C_505_EN_GPIO_Port, COLOR_C_505_EN_Pin, GPIO_PIN_SET);
		 break;
		 
		 default:
		 
		 break;
		 
	 }

}

static void Color_730_Switch(uint8_t onvalue)
{
      switch(onvalue){
		 
		 case OFF:
		    HAL_GPIO_WritePin(COLOR_730_EN_GPIO_Port, COLOR_730_EN_Pin, GPIO_PIN_RESET);
		 break;
		 
		 case ON:
		 	HAL_GPIO_WritePin(COLOR_730_EN_GPIO_Port, COLOR_730_EN_Pin, GPIO_PIN_SET);
		 break;
		 
		 default:
		 
		 break;
		 
	 }

}

static void Color_415_Switch(uint8_t onvalue)
{
      switch(onvalue){
		 
		 case OFF:
		    HAL_GPIO_WritePin(COLOR_415_EN_GPIO_Port, COLOR_415_EN_Pin, GPIO_PIN_RESET);
		 break;
		 
		 case ON:
		 	HAL_GPIO_WritePin(COLOR_415_EN_GPIO_Port, COLOR_415_EN_Pin, GPIO_PIN_SET);
		 break;
		 
		 default:
		 
		 break;
		 
	 }

}


static void Color_850_Switch(uint8_t onvalue)
{
      switch(onvalue){
		 
		 case OFF:
		    HAL_GPIO_WritePin(COLOR_850_EN_GPIO_Port, COLOR_850_EN_Pin, GPIO_PIN_RESET);
		 break;
		 
		 case ON:
		 	HAL_GPIO_WritePin(COLOR_850_EN_GPIO_Port, COLOR_850_EN_Pin, GPIO_PIN_SET);
		 break;
		 
		 default:
		 
		 break;
		 
	 }

}


static void Color_940_Switch(uint8_t onvalue)
{
      switch(onvalue){
		 
		 case OFF:
		    HAL_GPIO_WritePin(COLOR_940_EN_GPIO_Port, COLOR_940_EN_Pin, GPIO_PIN_RESET);
		 break;
		 
		 case ON:
		 	HAL_GPIO_WritePin(COLOR_940_EN_GPIO_Port, COLOR_940_EN_Pin, GPIO_PIN_SET);
		 break;
		 
		 default:
		 
		 break;
		 
	 }

}


static void Color_White_Switch(uint8_t onvalue)
{
      switch(onvalue){
		 
		 case OFF:
		    HAL_GPIO_WritePin(COLOR_W_EN_GPIO_Port, COLOR_W_EN_Pin, GPIO_PIN_RESET);
		 break;
		 
		 case ON:
		 	HAL_GPIO_WritePin(COLOR_W_EN_GPIO_Port, COLOR_W_EN_Pin, GPIO_PIN_SET);
		 break;
		 
		 default:
		 
		 break;
		 
	 }

}


static void Color_595_Switch(uint8_t onvalue)
{
      switch(onvalue){
		 
		 case OFF:
		    HAL_GPIO_WritePin(COLOR_595_EN_GPIO_Port, COLOR_595_EN_Pin, GPIO_PIN_RESET);
		 break;
		 
		 case ON:
		 	HAL_GPIO_WritePin(COLOR_595_EN_GPIO_Port, COLOR_595_EN_Pin, GPIO_PIN_SET);
		 break;
		 
		 default:
		 
		 break;
		 
	 }

}


static void Color_450_Switch(uint8_t onvalue)
{
     switch(onvalue){
		 
		 case OFF:
		    HAL_GPIO_WritePin(COLOR_450_EN_GPIO_Port, COLOR_450_EN_Pin, GPIO_PIN_RESET);
		 break;
		 
		 case ON:
		 	HAL_GPIO_WritePin(COLOR_450_EN_GPIO_Port, COLOR_450_EN_Pin, GPIO_PIN_SET);
		 break;
		 
		 default:
		 
		 break;
		 
	 }

}


static void Color_365_Switch(uint8_t onvalue)
{
     switch(onvalue){
		 
		 case OFF:
		    HAL_GPIO_WritePin(COLOR_365_EN_GPIO_Port, COLOR_365_EN_Pin, GPIO_PIN_RESET);
		 break;
		 
		 case ON:
		 	HAL_GPIO_WritePin(COLOR_365_EN_GPIO_Port,COLOR_365_EN_Pin, GPIO_PIN_SET);
		 break;
		 
		 default:
		 
		 break;
		 
	 }

}
/*****************************************************************************************************
 * *
 *Function Name: Color_Red_Switch(uint8_t onvalue)
 *Function:
 *Input Ref: 1--on,0-off
 *Return Ref:
 *
 *
******************************************************************************************************/
static void Color_Red_Switch(uint8_t onvalue)
{
	
	switch(onvalue){
		
		case OFF:
		     
			  HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_3) ;  //2.color red PWM 
	          TIM2_SetCompare_3(&htim2, 0);
			 
		break;
		
		case ON:
		      
			HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3) ;  //2.color red PWM 
			TIM2_SetCompare_3(&htim2,40);
			  
		break;
		
		default:
		
		break;
		}
}
/*****************************************************************************************************
 * *
 *Function Name: Color_Green_Switch(uint8_t onvalue)
 *Function:
 *Input Ref: 1--on,0-off
 *Return Ref:
 *
 *
******************************************************************************************************/
static void Color_Green_Switch(uint8_t onvalue)
{
	
	switch(onvalue){
		
		case OFF:
		 
			  HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_4) ;  // color green PWM
			
			  TIM2_SetCompare_4(&htim2, 0);
		break;
		
		case ON:
		     
			  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4) ;  //2.color green PWM
			  TIM2_SetCompare_4(&htim2,40);
		break;
		
		default:
		
		break;
		}
}
/*****************************************************************************************************
 * *
 *Function Name: Color_Blue_Switch(uint8_t onvalue)
 *Function:
 *Input Ref: 1--on,0-off
 *Return Ref:
 *
 *
******************************************************************************************************/
static void Color_Blue_Switch(uint8_t onvalue)
{
	
	switch(onvalue){
		
		case OFF:
		      HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1) ;  // color blue PWM
			
			  TIM2_SetCompare_1(&htim2, 0); //duty cycle 50%= 80*50% =40
			 
		break;
		
		case ON:
		    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1) ;  // color blue PWM
	        TIM2_SetCompare_1(&htim2,40);
			
		break;
		
		default:
		
		break;
		}
}
/*********************************************************************
 * *
 *Function Name:static void Color_NoCombination_Off(void)
 *Function:
 *Input Ref: NO
 *Return Ref:NO
 *
*********************************************************************/
static void Color_NoCombination_Off(void)
{
	Color_C505_Switch(OFF);
	Color_730_Switch(OFF);
	Color_415_Switch(OFF);
	Color_850_Switch(OFF);
	Color_940_Switch(OFF);
	Color_White_Switch(OFF);
	Color_595_Switch(OFF);
	Color_450_Switch(OFF);
	Color_365_Switch(OFF);
	
	
}
/*****************************************************************************************************
 * *
 *Function Name: Color_Blue_Switch(uint8_t onvalue)
 *Function:
 *Input Ref: 1--on,0-off
 *Return Ref:
 *
 *
******************************************************************************************************/
static void Color_RGB_Switch(uint8_t onvalue)
{
	switch(onvalue){
		
		case OFF:
		      HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1) ;  //2.the second turn on Enable
			  HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_3) ;  //2.the second turn on Enable
			  HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_4) ;  //2.the second turn on Enable
			  TIM2_SetCompare_1(&htim2, 0); //duty cycle 50%= 80*50% =40
			  TIM2_SetCompare_3(&htim2, 0);
			  TIM2_SetCompare_4(&htim2, 0);
		break;
		
		case ON:
		      HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1) ;  //2.the second turn on Enable
			  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3) ;  //2.the second turn on Enable
			  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4) ;  //2.the second turn on Enable
			  TIM2_SetCompare_1(&htim2,40);
			  TIM2_SetCompare_3(&htim2,40);
			  TIM2_SetCompare_4(&htim2,40);
		break;
		
		default:
		
		break;
		}
}
/*************************************************************************
 	*
	*Function Name: void LedOnOff(void)
	*Function : Turn On LEDAxx LED
	*Input Ref: receive UART of data
	*Output Ref:No
	*
******************************************************************************/
void LedOnOff(uint8_t ledNum,uint8_t onOff)
{
  // uint8_t temp;
    if((lastOnLed !=ledNum)||(onOff ==0)){

        //turn off all led 
        Color_ALL_TurnOff();

   }
   if(onOff){

	   lastOnLed = ledNum;
	   hasLedOn =1;
	  
	  
	   switch(ledNum){

		   case 0://PA7-'White'->newPCB WT.EDIT 2021.08.26 //PA11---[5]---oled "white" oled {0}  //group
				
			    lamp_t.pwm_color=1;
			    lamp_t.pwm_rgb=0;
			    lamp_t.sortLamp = c_595;
				lamp_t.lamp_blue=0;
				lamp_t.lamp_green=0;
				lamp_t.lamp_red =0; 
		
           break;

		   case 0x01:// [1]
		        lamp_t.pwm_color=1;
			    lamp_t.pwm_rgb=0;
			    lamp_t.sortLamp = c_450; 
				lamp_t.lamp_blue=0;
				lamp_t.lamp_green=0;
				lamp_t.lamp_red =0;
           break;

		   case 0x02:// "blue"
		    lamp_t.pwm_color=0; //judge that ifnot R G B of adjust brightness
			lamp_t.lamp_blue=1;
			lamp_t.pwm_rgb=1;
			lamp_t.sortLamp = c_blue;
			lamp_t.pwm_red=0;
			lamp_t.pwm_green=0;
			lamp_t.pwm_blue=1;				
           break;

		  case 0x03: //3
			    lamp_t.pwm_color=1;
			  	lamp_t.pwm_rgb=0;
				lamp_t.sortLamp = c_365;
				lamp_t.lamp_blue=0;
				lamp_t.lamp_green=0;
				lamp_t.lamp_red =0;
				break;

			case 0x04: //4
				lamp_t.pwm_color=1;
			  	lamp_t.pwm_rgb=0;
			 	lamp_t.sortLamp = c_415;
				lamp_t.lamp_blue=0;
				lamp_t.lamp_green=0;
				lamp_t.lamp_red =0;
		
				break;
			
			case 0x05:
				lamp_t.pwm_color=1;
			  	lamp_t.pwm_rgb=0;
			 	lamp_t.sortLamp = c_white;
				lamp_t.lamp_blue=0;
				lamp_t.lamp_green=0;
				lamp_t.lamp_red =0;
			break;

			 case 0x06:// "green"
			 	 lamp_t.pwm_color=0;
				 lamp_t.lamp_green=1;
			     lamp_t.pwm_rgb=1;
				lamp_t.sortLamp = c_green;
				lamp_t.pwm_red=0;
			  	lamp_t.pwm_green=1;
			  	lamp_t.pwm_blue=0;
			
             break;

			 case 0x07: //7
			     lamp_t.pwm_color=1;
			     lamp_t.pwm_rgb=0;
				lamp_t.sortLamp = c_505;
				lamp_t.lamp_blue=0;
				lamp_t.lamp_green=0;
				lamp_t.lamp_red =0;
             break;

			 case 0x09://9
				lamp_t.pwm_color=1;
			    lamp_t.pwm_rgb=0;
			    lamp_t.sortLamp = c_730;
				lamp_t.lamp_blue=0;
				lamp_t.lamp_green=0;
				lamp_t.lamp_red =0;
            break;
			
			case 0x0A://
				lamp_t.pwm_color=1;
			    lamp_t.pwm_rgb=0;
			    lamp_t.sortLamp = c_940;
				lamp_t.lamp_blue=0;
				lamp_t.lamp_green=0;
				lamp_t.lamp_red =0;
            break;
			
			case 0x0B://
				lamp_t.pwm_color=1;
			    lamp_t.pwm_rgb=0;
			    lamp_t.sortLamp = c_850;
				lamp_t.lamp_blue=0;
				lamp_t.lamp_green=0;
				lamp_t.lamp_red =0;
            break;
			
		  
		    case 0xE:// "red"
		    	 
			  lamp_t.pwm_color=0; //
			  lamp_t.lamp_red=1;
			  lamp_t.pwm_rgb=1;
			  lamp_t.sortLamp = c_red;
			  lamp_t.pwm_red=1;
			  lamp_t.pwm_green=0;
			  lamp_t.pwm_blue=0;
				 
            break;
		
			
		
			
			default:
			
			break;

			
	   }
	  
   }
}
/*************************************************************************
 	*
	*Function Name: void LedOnOff(void)
	*Function : Turn On LEDAxx LED
	*Input Ref: receive UART of data
	*Output Ref:No
	*
******************************************************************************/
void RunCommand(void)
{
	switch(lamp_t.sortLamp){
		
		 	case nocolor:
		 	  lamp_t.pwm_color=0;
			  lamp_t.pwm_rgb=0;
		
			  lamp_t.lamp_red=0;
			  lamp_t.lamp_green=0;
			  lamp_t.lamp_blue=0;
			  
			  
			  lamp_t.pwm_red=0;
			  lamp_t.pwm_green=0;
			  lamp_t.pwm_blue=0;
		      Color_ALL_TurnOff();
			 
		 
		 	break;
		
			case c_505://1
				Color_RGB_Switch(OFF);
				Color_365_Switch(OFF);
				Color_450_Switch(OFF); 
				Color_595_Switch(OFF);
				Color_White_Switch(OFF);
				Color_940_Switch(OFF);
				Color_850_Switch(OFF);
				Color_415_Switch(OFF);
			   	Color_730_Switch(OFF);
				HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
       			TIM2_SetCompare_2(&htim2, 40);
                Color_C505_Switch(ON);
				//TxData(0x8);
           break;

		   	case c_730://2
			   Color_RGB_Switch(OFF);
			   	Color_365_Switch(OFF);
			   Color_450_Switch(OFF); 
			   Color_595_Switch(OFF);
			   Color_White_Switch(OFF);
			   	Color_940_Switch(OFF);
			   Color_850_Switch(OFF);
			   Color_415_Switch(OFF);
		        Color_C505_Switch(OFF);
				HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
       			TIM2_SetCompare_2(&htim2, 40);
				Color_730_Switch(ON);
				//TxData(0x22);
           	break;

			case c_415: //3
				Color_RGB_Switch(OFF);
				Color_365_Switch(OFF);
				Color_450_Switch(OFF); 
				Color_595_Switch(OFF);
				Color_White_Switch(OFF);
				Color_940_Switch(OFF);
				Color_850_Switch(OFF);
				Color_C505_Switch(OFF);
				Color_730_Switch(OFF);
				HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
       			TIM2_SetCompare_2(&htim2, 40);
				Color_415_Switch(ON);
			//	TxData(0x33);
				break;

			case c_850: //4
				Color_RGB_Switch(OFF);
				Color_365_Switch(OFF);
				Color_450_Switch(OFF); 
				Color_595_Switch(OFF);
				Color_White_Switch(OFF);
			     Color_940_Switch(OFF);
				Color_C505_Switch(OFF);
				Color_730_Switch(OFF);
				Color_415_Switch(OFF);
				HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
       			TIM2_SetCompare_2(&htim2, 40);
			 	Color_850_Switch(ON);
				// TxData(0x44);
				break;

			 case c_940://5
			 	Color_RGB_Switch(OFF);
			 	Color_365_Switch(OFF);
			 	Color_450_Switch(OFF); 
			    Color_595_Switch(OFF);
			 	Color_White_Switch(OFF);
			    Color_C505_Switch(OFF);
				Color_730_Switch(OFF);
				Color_415_Switch(OFF);
			 	Color_850_Switch(OFF);
			 	 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
       			TIM2_SetCompare_2(&htim2, 40);
				Color_940_Switch(ON);
             break;

			 case c_white: //6
			  Color_RGB_Switch(OFF);
			 	Color_365_Switch(OFF);
			 	Color_450_Switch(OFF); 
			     Color_595_Switch(OFF);
			    Color_C505_Switch(OFF);
				Color_730_Switch(OFF);
				Color_415_Switch(OFF);
			 	Color_850_Switch(OFF);
			 	Color_940_Switch(OFF);
			 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
       			TIM2_SetCompare_2(&htim2, 40);
			 	Color_White_Switch(ON);
				
             break;

			 case c_595://7
			 	Color_RGB_Switch(OFF);
			 	Color_365_Switch(OFF);
			 	Color_450_Switch(OFF); 
				Color_C505_Switch(OFF);
				Color_730_Switch(OFF);
				Color_415_Switch(OFF);
			 	Color_850_Switch(OFF);
			 	Color_940_Switch(OFF);
			    Color_White_Switch(OFF);
				HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
       			TIM2_SetCompare_2(&htim2, 40);
				Color_595_Switch(ON);
			   
            break;
			
		   //LEDB -The second group 
		    case c_450://"640"
			    Color_RGB_Switch(OFF);
			 	Color_365_Switch(OFF);
			    Color_C505_Switch(OFF);
				Color_730_Switch(OFF);
				Color_415_Switch(OFF);
			 	Color_850_Switch(OFF);
			 	Color_940_Switch(OFF);
			    Color_White_Switch(OFF);
			    Color_595_Switch(OFF);
				
				 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
       			TIM2_SetCompare_2(&htim2, 40);
				Color_450_Switch(ON);
		    	 
            break;
			//low votalge
			case c_365: //PB6 ->R690
				Color_RGB_Switch(OFF);
				Color_C505_Switch(OFF);
				Color_730_Switch(OFF);
				Color_415_Switch(OFF);
			 	Color_850_Switch(OFF);
			 	Color_940_Switch(OFF);
			    Color_White_Switch(OFF);
			    Color_595_Switch(OFF);
				 Color_450_Switch(OFF);
				 
				 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
       			 TIM2_SetCompare_2(&htim2, 40);
				 Color_365_Switch(ON);
			 break;

			case c_red: //PA12 ->IR740
				Color_NoCombination_Off();
				Color_Red_Switch(ON);
				if(lamp_t.lamp_green==1){
				   Color_Green_Switch(ON);
				}
				if(lamp_t.lamp_blue==1){
				  Color_Blue_Switch(ON);
				}
			   
			
			break;
			
			case c_green: //PA12 ->IR740
				Color_NoCombination_Off();
			
				Color_Green_Switch(ON);
				if(lamp_t.lamp_red==1){
				   Color_Red_Switch(ON);
				}
				if(lamp_t.lamp_blue==1){
				  Color_Blue_Switch(ON);
				}
			   
			
			break;
			case c_blue: //PA12 ->IR740
				Color_NoCombination_Off();
				
				Color_Blue_Switch(ON);
				if(lamp_t.lamp_green==1){
				   Color_Green_Switch(ON);
				}
				if(lamp_t.lamp_red==1){
				  Color_Red_Switch(ON);
				}
			   
			
			break;
			
			
			case 0x20: //adjust --
			  AdjustBrightness(lamp_t.lamp_brigtness);
			
			
			break;
			
		
			
			default:
			
			break;
		}
	
}
/*************************************************************************
 	*
	*Function Name:void AdjustBrightness(uint8_t dir)
	*Function : 
	*Input Ref: NO
	*Output Ref:No
	*
******************************************************************************/
void AdjustBrightness(uint8_t dir)
{
	static int16_t level_red,level_green,level_blue,level_color;
	if(hasLedOn)
	{
		if(lamp_t.pwm_color == 1 && lamp_t.pwm_rgb !=1){
			if(dir=='1')	// adj +
				{
					level_color+=LEVEL_STEP;
					if(level_color>LEVEL_PWM_MAX) level_color=LEVEL_PWM_MAX ;
				}
				else	// adj -
				{
                    if (level_color < LEVEL_PWM_MIN || level_color==0 )
                               level_color= LEVEL_PWM_MIN;
					else level_color -=LEVEL_STEP;
                    
					if (level_color < LEVEL_PWM_MIN || level_color==0 )
                               level_color= LEVEL_PWM_MIN;
								
				}
			setLevel_PWM_Color(level_color);
		}
		
		if(lamp_t.pwm_rgb==1 && lamp_t.pwm_color !=1){
			
			if(dir=='1')	// adj +
				{
					if(lamp_t.pwm_red==1){
						level_red+=LEVEL_PWM_STEP;
						if(level_red>LEVEL_PWM_MAX) level_red=LEVEL_PWM_MAX ;
						lamp_t.pwm_redValue = level_red;
						//lamp_t.pwm_redValue = level_rgb;
					}
					else if(lamp_t.pwm_green==1){
						level_green+=LEVEL_PWM_STEP;
						if(level_green>LEVEL_PWM_MAX ) level_green=LEVEL_PWM_MAX ;
						lamp_t.pwm_greenValue = level_green;
						
					}
					else if(lamp_t.pwm_blue==1){
						level_blue+=LEVEL_PWM_STEP;
						if(level_blue>LEVEL_PWM_MAX ) level_blue=LEVEL_PWM_MAX;
						lamp_t.pwm_blueValue = level_blue;
						
					}
				}
				else	// adj -
				{
                    if(lamp_t.pwm_red==1){
						if (level_red < LEVEL_MIN|| level_red ==0)
								level_red= LEVEL_PWM_MIN;
						else level_red -=LEVEL_PWM_STEP;
						
						if (level_red < LEVEL_MIN|| level_red ==0)
								level_red= LEVEL_PWM_MIN;
						lamp_t.pwm_redValue = level_red;
					}
					else if(lamp_t.pwm_green==1){
						if (level_green < LEVEL_MIN || level_green ==0)
								level_green= LEVEL_PWM_MIN;
						else level_green -=LEVEL_STEP;
						
						if (level_green < LEVEL_MIN || level_green ==0)
								level_green= LEVEL_PWM_MIN;
						lamp_t.pwm_greenValue = level_green;
						
					}
					else if(lamp_t.pwm_blue==1){
						if (level_blue < LEVEL_MIN || level_blue == 0)
								level_blue= LEVEL_PWM_MIN;
						else level_blue -=LEVEL_PWM_STEP;
						
						if (level_blue < LEVEL_MIN || level_blue == 0)
								level_blue= LEVEL_PWM_MIN;
						lamp_t.pwm_blueValue = level_blue;
						
						
					}
                    
								
				}
			  setLevel_PWM_RGB(level_rgb);
			
		}
		
	}
}
/*************************************************
 	*
	*Function Name:static void setLevel_PWMA(uint8_t level)
	*Function : hight voltagle
	*Input Ref: NO
	*Output Ref:No
	*
**************************************************/
static void setLevel_PWM_Color(uint16_t level)
{
  
	 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	 TIM2_SetCompare_2(&htim2, level);
}
/*************************************************************************
 	*
	*Function Name:static void setLevel_PWMA(uint8_t level)
	*Function : hight voltagle
	*Input Ref: NO
	*Output Ref:No
	*
******************************************************************************/
static void setLevel_PWM_RGB(uint16_t level)
{
   	
    if(lamp_t.pwm_red ==1){
		
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3) ;  //2.pwm red 
	    TIM2_SetCompare_3(&htim2,lamp_t.pwm_redValue);
		
	}
	else if(lamp_t.pwm_green==1){
	
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4) ;  //pwm green 
		TIM2_SetCompare_4(&htim2,lamp_t.pwm_greenValue);
		
	}
	else if(lamp_t.pwm_blue==1){
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1) ;  // pwm blue
	
		TIM2_SetCompare_1(&htim2,lamp_t.pwm_blueValue);
	
		
	}
	
}
/*************************************************************************
 	*
	*Function Name:
	*Function : 
	*Input Ref: NO
	*Output Ref:No
	*
******************************************************************************/
void TIM2_SetCompare_1(TIM_HandleTypeDef* TIMx, uint16_t Compare2)
{
	TIMx->Instance->CCR1 = Compare2;
	
}

void TIM2_SetCompare_2(TIM_HandleTypeDef* TIMx, uint16_t Compare2)
{
	TIMx->Instance->CCR2 = Compare2;
}

void TIM2_SetCompare_3(TIM_HandleTypeDef* TIMx, uint16_t Compare2)
{
	TIMx->Instance->CCR3 = Compare2;
}

void TIM2_SetCompare_4(TIM_HandleTypeDef* TIMx, uint16_t Compare2)
{
	TIMx->Instance->CCR4 = Compare2;
}


/****************************************************************************************************
	**
	*Function Name:static void selectFilter(uint8_t index)
	*Function: Control Motor Board run command "RUN"
	*Input Ref:filter numbers
	*Return Ref:NO
	*
****************************************************************************************************/
void TxData(uint8_t index)
{
  

	outputBuf[0]=index+0x30;	// change to ascii number for decimal number 0~9
	//for(i=3;i<6;i++) crc ^= outputBuf[i];
	//outputBuf[i]=crc;
	transferSize=1;
	if(transferSize)
	{
		while(transOngoingFlag); //UART interrupt transmit flag ,disable one more send data.
		transOngoingFlag=1;
		HAL_UART_Transmit_IT(&huart1,outputBuf,transferSize);
	}
}

/********************************************************************************
**
*Function Name:void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
*Function :UART callback function  for UART interrupt for transmit data
*Input Ref: structure UART_HandleTypeDef pointer
*Return Ref:NO
*
*******************************************************************************/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart==&huart1)
	{
		transOngoingFlag=0; //UART Transmit interrupt flag =0 ,RUN
	}
	
}
