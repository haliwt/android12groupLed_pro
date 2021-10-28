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
static uint8_t level_color;
static uint8_t level_rgb;
static uint8_t outputBuf[MAX_BUFFER_SIZE];
static uint8_t transferSize;


static void setLevel_PWM_Color(uint8_t level);
static void setLevel_PWM_RGB(uint8_t level);

//static void TIM2_SetCompare_1(TIM_HandleTypeDef* TIMx, uint16_t Compare1);


//static void TIM2_SetCompare_2(TIM_HandleTypeDef* TIMx, uint16_t Compare2);
//static void TIM2_SetCompare_2(TIM_HandleTypeDef* TIMx, uint16_t Compare2);
//static void TIM2_SetCompare_3(TIM_HandleTypeDef* TIMx, uint16_t Compare2);
//static void TIM2_SetCompare_4(TIM_HandleTypeDef* TIMx, uint16_t Compare2);

//static void Color_C505_Switch(uint8_t onvalue);

static void Color_730_Switch(uint8_t onvalue);

static void Color_415_Switch(uint8_t onvalue);

static  void Color_850_Switch(uint8_t onvalue);

static void Color_940_Switch(uint8_t onvalue);

static void Color_White_Switch(uint8_t onvalue);

static void Color_595_Switch(uint8_t onvalue);

//static void Color_450_Switch(uint8_t onvalue);

static void Color_365_Switch(uint8_t onvalue);
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
/**********************************************************
	*
	*Function Name:void Color_C505_Switch(uint8_t onvalue)
	*Function: turn on or off color c505 LED 
	*Input Ref: turn on or off value
	*Return Ref: NO 
	*
**********************************************************/
void Color_C505_Switch(uint8_t onvalue)
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


void Color_450_Switch(uint8_t onvalue)
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
				
			    lamp_t.sortLamp = noclolr; 
           break;

		   case c_505://PB1 [0] ---oled "UV365"---A
			    lamp_t.sortLamp = c_505; 
				
			
               
				//TxData(1);
		        TxData(9);
                
           break;

		   case c_730://PA6---oled menu "Violet" {1}
				lamp_t.sortLamp = c_730;
				
				
				TxData(2);
				
           break;

			case c_415: //"Blue2"
				 lamp_t.sortLamp = c_415;
				
			
					TxData(3);
				break;

			case c_850: //"Cyan"
			 	 lamp_t.sortLamp = c_850;
			
					TxData(4);
				break;

			 case c_940://"Green"
				lamp_t.sortLamp = c_940;
				TxData(5);
             break;

			 case c_white: //"Orange"
				lamp_t.sortLamp = c_white;
				TxData(6);
             break;

			 case c_595://PB8->R620 
				
			    lamp_t.sortLamp = c_595;
				TxData(7);
            break;
			
		  
		    case c_450://"640"
		    	  lamp_t.sortLamp = c_450;
				  TxData(8);
            break;
		
			case c_365: //PB6 ->R690
			
			  lamp_t.sortLamp = c_365;
			  TxData(9);
			     
			break;

			case c_rgb: //PA12 ->IR740
			   
				lamp_t.sortLamp = c_rgb;
				TxData(10);
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
		
		 	case noclolr:
		 
		       Color_ALL_TurnOff();
			 
		 
		 	break;
		
			case c_505://PB1 [0] ---oled "UV365"---A
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
				TxData(0x8);
           break;

		   	case c_730://PA6---oled menu "Violet" {1}
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
				TxData(0x22);
           	break;

			case c_415: //"Blue2"
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
				TxData(0x33);
				break;

			case c_850: //"Cyan"
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
				 TxData(0x44);
				break;

			 case c_940://"Green"
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

			 case c_white: //"Orange"
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

			 case c_595://PB8->R620
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

			case c_rgb: //PA12 ->IR740
				Color_C505_Switch(OFF);
				Color_730_Switch(OFF);
				Color_415_Switch(OFF);
			 	Color_850_Switch(OFF);
			 	Color_940_Switch(OFF);
			    Color_White_Switch(OFF);
			    Color_595_Switch(OFF);
				Color_450_Switch(OFF);
				Color_365_Switch(OFF);
				
				Color_RGB_Switch(ON);
			   
			
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
	if(hasLedOn)
	{
		if(lamp_t.pwm_color == 1 && lamp_t.pwm_rgb == 0 ){
			if(dir=='1')	// adj +
				{
					level_color+=LEVEL_STEP;
					if(level_color>LEVEL_MAX ) level_color=LEVEL_MAX ;
				}
				else	// adj -
				{
                    if (level_color < LEVEL_MIN+LEVEL_STEP)
                               level_color= LEVEL_MIN;
					else level_color -=LEVEL_STEP;
                    
								
				}
			setLevel_PWM_Color(level_color);
		}
		if(lamp_t.pwm_rgb == 1){
			if(dir=='1')	// adj +
				{
					level_rgb+=LEVEL_STEP;
					if(level_rgb>LEVEL_MAX ) level_rgb=LEVEL_MAX ;
				}
				else	// adj -
				{
                    if (level_rgb < LEVEL_MIN+LEVEL_STEP)
                               level_rgb = LEVEL_MIN;
					else level_rgb -=LEVEL_STEP;
                    
								
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
static void setLevel_PWM_Color(uint8_t level)
{
  	uint16_t pwmValue;
	if(level<LEVEL_MIN)level=LEVEL_MIN;
	
    pwmValue =(level)*LEVEL_PWM_STEP;// level * LEVEL_PWM_STEP;
	
    if(pwmValue > LEVEL_PWM_MAX){
		pwmValue= LEVEL_PWM_MAX;
    }
    
	 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	 TIM2_SetCompare_1(&htim2, pwmValue);
}
/*************************************************************************
 	*
	*Function Name:static void setLevel_PWMA(uint8_t level)
	*Function : hight voltagle
	*Input Ref: NO
	*Output Ref:No
	*
******************************************************************************/
static void setLevel_PWM_RGB(uint8_t level)
{
   	uint16_t pwmValue;
	if(level<LEVEL_MIN)level=LEVEL_MIN;
	
    pwmValue =(level)*LEVEL_PWM_STEP;// level * LEVEL_PWM_STEP;
	
    if(pwmValue > LEVEL_PWM_MAX){
		pwmValue= LEVEL_PWM_MAX;
    }
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1) ;  //2.the second turn on Enable
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3) ;  //2.the second turn on Enable
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4) ;  //2.the second turn on Enable
    TIM2_SetCompare_1(&htim2,pwmValue);
	TIM2_SetCompare_3(&htim2,pwmValue);
	TIM2_SetCompare_4(&htim2,pwmValue);
	
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
