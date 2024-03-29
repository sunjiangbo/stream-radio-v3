/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               TouchPanel.h
** Descriptions:            The TouchPanel application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-11-7
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

#ifndef _TOUCHPANEL_H_
#define _TOUCHPANEL_H_

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"

/* Private typedef -----------------------------------------------------------*/
typedef	struct POINT 
{
   uint16_t x;
   uint16_t y;
}Coordinate;


typedef struct Matrix 
{						
long double An,  
            Bn,     
            Cn,   
            Dn,    
            En,    
            Fn,     
            Divider ;
} Matrix ;

/* Private variables ---------------------------------------------------------*/
extern Coordinate ScreenSample[3];
extern Coordinate DisplaySample[3];
extern Matrix matrix ;
extern Coordinate  display ;

/* Private define ------------------------------------------------------------*/
/* ADͨ��ѡ�������ֺ͹����Ĵ��� */
#define	CHX 	        0x90 	/* ͨ��Y+��ѡ������� */	
#define	CHY 	        0xd0	/* ͨ��X+��ѡ������� */

#define SSPSR_RNE       2
#define SSPSR_BSY       4

/* bit-frequency = PCLK / CPSR */
#define SPI_SPEED_4MHz    25 	  /* 4MHz */
#define SPI_SPEED_2MHz    50 	  /* 2MHz */
#define SPI_SPEED_400kHz  250	  /* 400kHz */


#define TP_CS(a)	if (a)	\
					LPC_GPIO0->FIOSET = (1<<6);\
					else		\
					LPC_GPIO0->FIOCLR = (1<<6)

#define TP_INT_IN   ( LPC_GPIO2->FIOPIN & (1<<13) ) 

/* Private function prototypes -----------------------------------------------*/				
void TP_Init(void);	
Coordinate *Read_Ads7846(void);
void TouchPanel_Calibrate(void);
void DrawCross(uint16_t Xpos,uint16_t Ypos);
void TP_DrawPoint(uint16_t Xpos,uint16_t Ypos);
uint8_t setCalibrationMatrix( Coordinate * displayPtr,Coordinate * screenPtr,Matrix * matrixPtr);
uint8_t getDisplayPoint(Coordinate * displayPtr,Coordinate * screenPtr,Matrix * matrixPtr );

#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/


