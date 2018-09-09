#ifndef __MYBITBAND_H
#define __MYBITBAND_H	  
#include <stm32f10x.h>  
/****************************** ������ʵ�ֵļĴ���λ����ģʽ ***************************************/
// ������ԭ������Ϊ����������������ǰ���ǰ׺b, ��⺯�����ֵ�ͬʱ��ָʾ������bitband������
// ��һ��ǿ�����ǣ������־���Ĵ�����������,����Ĵ���������λ����ǰ��ע���С�
// BITλ�����ƾ�������ԭ���ƣ��Ա����.  �Ĵ�����ַƫ������һ���û��ֲ���ʮ��������䡣
// ���ǵ�λ�����������ھ�׼��Ч�ض�λ���в������ʶ���λ���ϵ��������ʡ�ԡ�
// CopyRight By Warship
// Modified date: 20180716

//��BITλ����궨��
#define 	MASKb1			((uint16_t)0x0001)
#define 	MASKb2			((uint16_t)0x0003)
#define 	MASKb3			((uint16_t)0x0007)
#define 	MASKb4			((uint16_t)0x000F)
#define 	MASKb5			((uint16_t)0x001F)
#define 	MASKb6			((uint16_t)0x003F)
#define 	MASKb7			((uint16_t)0x007F)
#define 	MASKb8			((uint16_t)0x00FF)


/******************************************************************************/
/*                                                                            */
/*                    PWR�Ĵ���--��Դ���ƼĴ���                               */
/*                                                                            */
/******************************************************************************/
//typedef struct
//{
//  __IO uint32_t CR;
//  __IO uint32_t CSR;
//} PWR_TypeDef;

//PWR_CR--��Դ���ƼĴ���
#define  bPWR_CR_LPDS          BIT_ADDR(PWR_BASE, 0)     //��˯���µĵ͹��ģ�PDDS=0ʱ����PDDSλЭͬ���������壺0���ڴ���ģʽ�µ�ѹ��ѹ����������1���ڴ���ģʽ�µ�ѹ��ѹ�����ڵ͹���ģʽ��
#define  bPWR_CR_PDDS          BIT_ADDR(PWR_BASE, 1)     //������˯�ߣ���LPDSλЭͬ���������壺0����CPU������˯��ʱ����ͣ��ģʽ����ѹ��״̬��LPDSλ���ƣ���1��CPU������˯��ʱ�������ģʽ��
#define  bPWR_CR_CWUF          BIT_ADDR(PWR_BASE, 2)     //�������λ��ʼ�����Ϊ0�����壺0����Ч����1��2��ϵͳʱ�����ں����WUF����λ��д��
#define  bPWR_CR_CSBF          BIT_ADDR(PWR_BASE, 3)     //�������λ��ʼ�����Ϊ0�����壺0����Ч����1�����SBF����λ��д��
#define  bPWR_CR_PVDE          BIT_ADDR(PWR_BASE, 4)     //��Դ��ѹ�������PVD��ʹ�ܡ����壺0����ֹPVD����1������PVD��
#define  bPWR_CR_DBP           BIT_ADDR(PWR_BASE, 8)     //ȡ��������д��������λֵΪ0�����壺0Ϊ��ֹд�룬1Ϊ����д�롣ע�����rtcʱ����HSE/128�����뱣��Ϊ1

//#define  PWR_CR_PLS  ����3BIT����PVD��ѹ��ֵ
#define  bPWR_CR_PLS_0         BIT_ADDR(PWR_BASE, 5)     //����:  000��2.2v����001��2.3v����010��2.4v��
#define  bPWR_CR_PLS_1         BIT_ADDR(PWR_BASE, 6)     //011��2.5v����100��2.6v����101��2.7v��
#define  bPWR_CR_PLS_2         BIT_ADDR(PWR_BASE, 7)     //110��2.8v����111��2.9v��



//PWR_CSR--��Դ����״̬�Ĵ���
#define  bPWR_CSR_WUF           BIT_ADDR(PWR_BASE+4, 0)     //���ѱ�־����λ��Ӳ�����ã���ֻ����POR/PDR���ϵ�/���縴λ�������õ�Դ���ƼĴ�����PWR_CR����CWUFλ�����
                                                       //���壺0��û�л����¼�����1����WKUP�����Ϸ��������¼������RTC�����¼��� 
                                                       //ע����WKUP�����Ѿ��Ǹߵ�ƽʱ���ڣ�ͨ������EWUPλ��ʹ��WKUP����ʱ�����⵽һ�������¼�
#define  bPWR_CSR_SBF           BIT_ADDR(PWR_BASE+4, 1)     //������־λ����λ��Ӳ�����ã���ֻ����POR/PDR���ϵ�/���縴λ�������õ�Դ���ƼĴ�����PWR_CR����CSBUFλ��������壺0�����ڴ�����1���Ѵ�����
#define  bPWR_CSR_PVDO          BIT_ADDR(PWR_BASE+4, 2)     //PVDO-PVD�������PVD��PVDEλʹ�ܺ��λ����Ч�����壺0��VDD/VDDA����PLS[2-0]ѡ����PVD��ֵ����1��VDD/VDDA����PLS[2-0]ѡ����PVD��ֵ��
                                                       //ע���ڴ���ģʽ��PVD��ֹͣ����ˣ�����ģʽ���λ��ֱ������PVDEλ֮ǰ����λΪ0
#define  bPWR_CSR_EWUP          BIT_ADDR(PWR_BASE+4, 8)     //EWUPʹ��WKUP���š����壺0��WKUPΪͨ��IO����1�����ڴ�������ģʽ��WKUP���ű�ǿ��Ϊ�������������ã�WKUP�����ϵ������ؽ�ϵͳ�Ӵ���ģʽ���ѣ�


/******************************************************************************/
/*                                                                            */
/*                    EXIT�Ĵ���--�ⲿ�ж�/�¼�������(n=0-18)                  */
/*                                                                            */
/******************************************************************************/
//typedef struct
//{
//  __IO uint32_t IMR;
//  __IO uint32_t EMR;
//  __IO uint32_t RTSR;
//  __IO uint32_t FTSR;
//  __IO uint32_t SWIER;
//  __IO uint32_t PR;
//} EXTI_TypeDef;

#define  bEXTI_INT_MASK(n)									BIT_ADDR(EXTI_BASE, n)    //�ж�����:0����,1������
#define  bEXTI_EVT_MASK(n)									BIT_ADDR(EXTI_BASE+4, n)  //�¼�����:0����,1������
#define  bEXTI_TRIG_RISE(n)									BIT_ADDR(EXTI_BASE+8, n)  //�����ش���:0����,1ʹ��,�����½��ش�������
#define  bEXTI_TRIG_FALL(n)									BIT_ADDR(EXTI_BASE+12, n) //�½��ش���:0����,1ʹ��,���������ش�������
#define  bEXTI_SFT_RQST(n)								  BIT_ADDR(EXTI_BASE+16, n) //���ж�����,д1�����жϹ���,�������PR���λд1���屾λ
#define  bEXTI_INT_PENDING(n)								BIT_ADDR(EXTI_BASE+20, n) //�жϹ���,Ӳ����1,д1��0

/******************************************************************************/
/*                                                                            */
/*                         RCC�Ĵ���--��λ��ʱ�ӿ���                           */
/*                                                                            */
/******************************************************************************/
//typedef struct
//{
//  __IO uint32_t CR;
//  __IO uint32_t CFGR;
//  __IO uint32_t CIR;
//  __IO uint32_t APB2RSTR;
//  __IO uint32_t APB1RSTR;
//  __IO uint32_t AHBENR;
//  __IO uint32_t APB2ENR;
//  __IO uint32_t APB1ENR;
//  __IO uint32_t BDCR;
//  __IO uint32_t CSR;

//#ifdef STM32F10X_CL  
//  __IO uint32_t AHBRSTR;
//  __IO uint32_t CFGR2;
//#endif /* STM32F10X_CL */ 

//#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)   
//  uint32_t RESERVED0;
//  __IO uint32_t CFGR2;
//#endif /* STM32F10X_LD_VL || STM32F10X_MD_VL || STM32F10X_HD_VL */ 
//} RCC_TypeDef;

//RCC_CR--ʱ�ӿ��ƼĴ���
#define  bRCC_CLK_HSION        BIT_ADDR(RCC_BASE, 0) //LSIʱ��: 0����,1����
#define  bRCC_CLK_HSIRDY        BIT_ADDR(RCC_BASE, 1) //LSIʱ��״̬��Ӳ������(ֻ��):0������,1����
#define  bRCC_CLK_HSEON        BIT_ADDR(RCC_BASE, 16) //HSEʱ��: 0����,1����
#define  bRCC_CLK_HSERDY        BIT_ADDR(RCC_BASE, 17) //HSEʱ��״̬��Ӳ������(ֻ��):0������,1����
#define  bRCC_CLK_HSEBYP       BIT_ADDR(RCC_BASE, 18) //�ⲿʱ����·(������)-- 0����·  1��·
#define  bRCC_CLK_CSSON     BIT_ADDR(RCC_BASE, 19) //ϵͳʱ�Ӱ�ȫϵͳʹ��  0ʱ�Ӽ�����  1�ⲿʱ�Ӿ������������
#define  bRCC_CLK_PLLON       BIT_ADDR(RCC_BASE, 24) //PLL��Ƶ: 0����,1����
#define  bRCC_CLK_PLLRDY      BIT_ADDR(RCC_BASE, 25) //PLL��Ƶ״̬��Ӳ������(ֻ��):0������,1����
//���Ĵ�������5BIT��HSITRIM  �ڲ�����ʱ�ӵ���
//           8BIT��HSICAL  �ڲ�����ʱ��У׼  ���ڲ������¶ȵȱ仯���ڲ�RC����ʱ��Ƶ�ʵ�Ӱ��.

//RCC_CFGR--ʱ�����üĴ���
#define  bRCC_CONFIG_SW0        BIT_ADDR(RCC_BASE+0x04, 0) //ϵͳʱ��ѡ��2BIT-- 00:HSI  01:HSE
#define  bRCC_CONFIG_SW1        BIT_ADDR(RCC_BASE+0x04, 1) //                   10:PLL  11: ��Ч 
#define  bRCC_CONFIG_SW_PLL   	BIT_ADDR(RCC_BASE+0x04, 1)  //SYSCLKʱ��ѡ��λ1����λʱΪѡ��PLL��Ϊϵͳʱ��Դ

#define  bRCC_CONFIG_SWS0        BIT_ADDR(RCC_BASE+0x04, 2) //ϵͳʱ��Դָʾ,ֻ��: ����ͬ��
#define  bRCC_CONFIG_SWS1        BIT_ADDR(RCC_BASE+0x04, 3) //

#define  bRCC_CONFIG_SWS_PLL   		BIT_ADDR(RCC_BASE+0x04, 3)  //SYSCLKʱ��ָʾλ1��Ϊ1ʱָʾPLL�Ѿ�Ϊϵͳʱ��Դ
#define  bRCC_CONFIG_PLLSRC       BIT_ADDR(RCC_BASE+0x04, 16) //PLL��Դѡ��, 0: HSI/2  1:HSE��PREDIV1�������
#define  bRCC_CONFIG_PLLXTPRE     BIT_ADDR(RCC_BASE+0x04, 17) //�����PLL��HSE�Ƿ��Ƶ 0:����Ƶ  1:����Ƶ
#define  bRCC_CONFIG_USBPRE       BIT_ADDR(RCC_BASE+0x04, 22) //USBԤ��Ƶ���� 0: PLL/1.5   1: PLL
#define  bRCC_CONFIG_ADCPRE0      BIT_ADDR(RCC_BASE+0x04, 14) //ADC(��PLCK2)Ԥ��Ƶ2BIT����: 00: 2��Ƶ  01: 4��Ƶ
#define  bRCC_CONFIG_ADCPRE1      BIT_ADDR(RCC_BASE+0x04, 15) //                           10: 6��Ƶ  11: 8��Ƶ 


#define  SET_RCC_SW(a)   (MEM_ADDR(RCC_BASE+0x04)=(MEM_ADDR(RCC_BASE+0x04)&(~RCC_CFGR_SW))|((a&MASKb2)<<0))
//#define  RCC_CFGR_SW                         ((uint32_t)0x00000003)        /*!< SW[1:0] bits (System clock Switch) */
#define  SW_HSI                     0       /*!< HSI selected as system clock */
#define  SW_HSE                     1        /*!< HSE selected as system clock */
#define  SW_PLL                     2       /*!< PLL selected as system clock */


//4BIT��HPRE����λ: ����ϵͳʱ��SYSCLK��Ƶ��AHB
///*!< HPRE BIT7:4 */
#define  SET_RCC_HPRE(a)   (MEM_ADDR(RCC_BASE+0x04)=(MEM_ADDR(RCC_BASE+0x04)&(~RCC_CFGR_HPRE))|((a&MASKb4)<<4))
     
//#define  RCC_CFGR_HPRE                       ((uint32_t)0x000000F0)        /*!< HPRE[3:0] bits (AHB prescaler) */
#define  HPRE_DIV1                  0        /*!< SYSCLK not divided */
#define  HPRE_DIV2                  1        /*!< SYSCLK divided by 2 */
#define  HPRE_DIV4                  3        /*!< SYSCLK divided by 4 */
#define  HPRE_DIV8                  4        /*!< SYSCLK divided by 8 */
#define  HPRE_DIV16                 5        /*!< SYSCLK divided by 16 */
#define  HPRE_DIV64                 6        /*!< SYSCLK divided by 64 */
#define  HPRE_DIV128                7        /*!< SYSCLK divided by 128 */
#define  HPRE_DIV256                8        /*!< SYSCLK divided by 256 */
#define  HPRE_DIV512                9        /*!< SYSCLK divided by 512 */

///*!< PPRE1 BIT10:8 ��3BIT��PPRE1����λ: ������APB1��Ԥ��Ƶ*/           
#define  SET_RCC_HPRE1(a)   (MEM_ADDR(RCC_BASE+0x04)=(MEM_ADDR(RCC_BASE+0x04)&(~RCC_CFGR_PPRE1))|((a&MASKb3)<<8))
//#define  RCC_CFGR_PPRE1                      ((uint32_t)0x00000700)        /*!< PRE1[2:0] bits (APB1 prescaler) */
#define  PPRE1_DIV1                 0        /*!< HCLK not divided */
#define  PPRE1_DIV2                 4        /*!< HCLK divided by 2 */
#define  PPRE1_DIV4                 5        /*!< HCLK divided by 4 */
#define  PPRE1_DIV8                 6        /*!< HCLK divided by 8 */
#define  PPRE1_DIV16                7        /*!< HCLK divided by 16 */

///*!< PPRE2 BIT13:11 ��3BIT��PPRE2����λ: ������APB2��Ԥ��Ƶ*/
#define  SET_RCC_HPRE2(a)   (MEM_ADDR(RCC_BASE+0x04)=(MEM_ADDR(RCC_BASE+0x04)&(~RCC_CFGR_PPRE2))|((a&MASKb3)<<11))
//#define  RCC_CFGR_PPRE2                      ((uint32_t)0x00003800)        /*!< PRE2[2:0] bits (APB2 prescaler) */
#define  PPRE2_DIV1                 0        /*!< HCLK not divided */
#define  PPRE2_DIV2                 4        /*!< HCLK divided by 2 */
#define  PPRE2_DIV4                 5        /*!< HCLK divided by 4 */
#define  PPRE2_DIV8                 6        /*!< HCLK divided by 8 */
#define  PPRE2_DIV16                7        /*!< HCLK divided by 16 */

///*!< ADCPPRE BIT15:14 */
#define  SET_RCC_ADCPRE(a)   (MEM_ADDR(RCC_BASE+0x04)=(MEM_ADDR(RCC_BASE+0x04)&(~RCC_CFGR_ADCPRE))|((a&MASKb2)<<14))
//#define  RCC_CFGR_ADCPRE                     ((uint32_t)0x0000C000)        /*!< ADCPRE[1:0] bits (ADC prescaler) */
#define  ADCPRE_DIV2                0        /*!< PCLK2 divided by 2 */
#define  ADCPRE_DIV4                1        /*!< PCLK2 divided by 4 */
#define  ADCPRE_DIV6                2        /*!< PCLK2 divided by 6 */
#define  ADCPRE_DIV8                3        /*!< PCLK2 divided by 8 */

//4BIT(BIT18:21)��PLLMUL:ѡ��PLL�ı�Ƶ��,2-16
#define  SET_RCC_PLLMUL(a)   (MEM_ADDR(RCC_BASE+0x04)=(MEM_ADDR(RCC_BASE+0x04)&(~RCC_CFGR_PLLMULL))|((a&MASKb4)<<18))
#define  PLLMULL2                  0        /*!< PLL input clock*2 */
#define  PLLMULL3                  1        /*!< PLL input clock*3 */
#define  PLLMULL4                  2       /*!< PLL input clock*4 */
#define  PLLMULL5                  3        /*!< PLL input clock*5 */
#define  PLLMULL6                  4        /*!< PLL input clock*6 */
#define  PLLMULL7                  5        /*!< PLL input clock*7 */
#define  PLLMULL8                  6        /*!< PLL input clock*8 */
#define  PLLMULL9                  7        /*!< PLL input clock*9 */
#define  PLLMULL10                 8        /*!< PLL input clock10 */
#define  PLLMULL11                 9        /*!< PLL input clock*11 */
#define  PLLMULL12                 10        /*!< PLL input clock*12 */
#define  PLLMULL13                 11        /*!< PLL input clock*13 */
#define  PLLMULL14                 12        /*!< PLL input clock*14 */
#define  PLLMULL15                 13        /*!< PLL input clock*15 */
#define  PLLMULL16                 14        /*!< PLL input clock*16 */

///*!< MCO configuration ע�ⲻͬ��оƬ�в���  3BIT��MCO����λ: ��MCU���ʱ�ӵ�ѡ����п���  */     
#define  SET_RCC_MCO(a)   (MEM_ADDR(RCC_BASE+0x04)=(MEM_ADDR(RCC_BASE+0x04)&(~RCC_CFGR_MCO))|((a&MASKb4)<<24))
 #define  MCO_NOCLOCK               ((uint32_t)0x00)        /*!< No clock */
 #define  MCO_SYSCLK                ((uint32_t)0x04)        /*!< System clock selected as MCO source */
 #define  MCO_HSI                   ((uint32_t)0x05)        /*!< HSI clock selected as MCO source */
 #define  MCO_HSE                   ((uint32_t)0x06)        /*!< HSE clock selected as MCO source  */
 #define  MCO_PLL                   ((uint32_t)0x07)        /*!< PLL clock divided by 2 selected as MCO source */

//RCC_CIR--ʱ���жϼĴ���
#define  bRCC_INT_LSIRDYFLG      BIT_ADDR(RCC_BASE+0x08, 0) //LSI�ȶ��Ҷ�ӦIE��λʱ��Ӳ����λ,ֻ��0��Ч,1����
#define  bRCC_INT_LSERDYFLG      BIT_ADDR(RCC_BASE+0x08, 1) //LSE�ȶ��Ҷ�ӦIE��λʱ��Ӳ����λ,ֻ��0��Ч,1����
#define  bRCC_INT_HSIRDYFLG      BIT_ADDR(RCC_BASE+0x08, 2) //HSI�ȶ��Ҷ�ӦIE��λʱ��Ӳ����λ,ֻ��0��Ч,1����
#define  bRCC_INT_HSERDYFLG      BIT_ADDR(RCC_BASE+0x08, 3) //HSE�ȶ��Ҷ�ӦIE��λʱ��Ӳ����λ,ֻ��0��Ч,1����
#define  bRCC_INT_PLLRDYFLG      BIT_ADDR(RCC_BASE+0x08, 4) //PLL�����Ҷ�ӦIE��λʱ��Ӳ����λ,ֻ��0��Ч,1����
#define  bRCC_INT_CSSF           BIT_ADDR(RCC_BASE+0x08, 7) //�ⲿ����ʧЧʱ��Ӳ����λ,ֻ��0:��Ч,1�жϿ���
#define  bRCC_INT_LSIRDYIE       BIT_ADDR(RCC_BASE+0x08, 8) //LSI����   �ж�ʹ��, 0����  1ʹ��
#define  bRCC_INT_LSERDYIE       BIT_ADDR(RCC_BASE+0x08, 9) //��ͬ 
#define  bRCC_INT_HSIRDYIE       BIT_ADDR(RCC_BASE+0x08, 10)
#define  bRCC_INT_HSERDYIE       BIT_ADDR(RCC_BASE+0x08, 11)
#define  bRCC_INT_PLLRDYIE       BIT_ADDR(RCC_BASE+0x08, 12)
#define  bRCC_INT_LSIRDYCLR      BIT_ADDR(RCC_BASE+0x08, 16) //д1��������Ӧ��LSIRDYF,��ͬ
#define  bRCC_INT_LSERDYCLR      BIT_ADDR(RCC_BASE+0x08, 17)
#define  bRCC_INT_HSIRDYCLR      BIT_ADDR(RCC_BASE+0x08, 18)
#define  bRCC_INT_HSERDYCLR      BIT_ADDR(RCC_BASE+0x08, 19)
#define  bRCC_INT_PLLRDYCLR      BIT_ADDR(RCC_BASE+0x08, 20)
#define  bRCC_INT_CSSCLR         BIT_ADDR(RCC_BASE+0x08, 23)

//RCC_APB2RSTR�Ĵ���
#define  bRCC_RESET_AFIO                 	BIT_ADDR(RCC_BASE+0x0C, 0)   //0��Ч,1��λ,��ͬ
#define  bRCC_RESET_GPIOA                 BIT_ADDR(RCC_BASE+0x0C, 2)
#define  bRCC_RESET_GPIOB                 BIT_ADDR(RCC_BASE+0x0C, 3)
#define  bRCC_RESET_GPIOC                 BIT_ADDR(RCC_BASE+0x0C, 4)
#define  bRCC_RESET_GPIOD                 BIT_ADDR(RCC_BASE+0x0C, 5)
#define  bRCC_RESET_GPIOE                 BIT_ADDR(RCC_BASE+0x0C, 6)
#define  bRCC_RESET_ADC1                 	BIT_ADDR(RCC_BASE+0x0C, 9)
#define  bRCC_RESET_ADC2                 	BIT_ADDR(RCC_BASE+0x0C, 10)
#define  bRCC_RESET_TIM1                 	BIT_ADDR(RCC_BASE+0x0C, 11)
#define  bRCC_RESET_SPI1                 	BIT_ADDR(RCC_BASE+0x0C, 12)
#define  bRCC_RESET_USART1               	BIT_ADDR(RCC_BASE+0x0C, 14)

//RCC_APB1RSTR�Ĵ���
#define  bRCC_RESET_TIM2                 BIT_ADDR(RCC_BASE+0x10, 0)   //0��Ч,1��λ,��ͬ
#define  bRCC_RESET_TIM3                 BIT_ADDR(RCC_BASE+0x10, 1)
#define  bRCC_RESET_TIM4                 BIT_ADDR(RCC_BASE+0x10, 2)
#define  bRCC_RESET_WWDG                 BIT_ADDR(RCC_BASE+0x10, 11)
#define  bRCC_RESET_SPI2                 BIT_ADDR(RCC_BASE+0x10, 14)
#define  bRCC_RESET_USART2               BIT_ADDR(RCC_BASE+0x10, 17)
#define  bRCC_RESET_USART3               BIT_ADDR(RCC_BASE+0x10, 18)
#define  bRCC_RESET_I2C1                 BIT_ADDR(RCC_BASE+0x10, 21)
#define  bRCC_RESET_I2C2                 BIT_ADDR(RCC_BASE+0x10, 22)
#define  bRCC_RESET_USB                  BIT_ADDR(RCC_BASE+0x10, 23)
#define  bRCC_RESET_CAN               	 BIT_ADDR(RCC_BASE+0x10, 25)
#define  bRCC_RESET_BKP                  BIT_ADDR(RCC_BASE+0x10, 27)
#define  bRCC_RESET_PWR                  BIT_ADDR(RCC_BASE+0x10, 28)

//RCC_AHBEN�Ĵ���
#define  bRCC_ENABLE_DMA                   BIT_ADDR(RCC_BASE+0x14, 0)  //0�ر�ʱ��,1����ʱ��,��ͬ
#define  bRCC_ENABLE_SRAM                  BIT_ADDR(RCC_BASE+0x14, 2)
#define  bRCC_ENABLE_FLITF                 BIT_ADDR(RCC_BASE+0x14, 4)
#define  bRCC_ENABLE_CRC                 	 BIT_ADDR(RCC_BASE+0x14, 6)
#define  bRCC_ENABLE_FSMC                	 BIT_ADDR(RCC_BASE+0x14, 8)  //?
#define  bRCC_ENABLE_SDIO                	 BIT_ADDR(RCC_BASE+0x14, 10)  //?

//RCC_APB2ENR�Ĵ���
#define  bRCC_ENABLE_AFIO                 BIT_ADDR(RCC_BASE+0x18, 0)   //0�ر�ʱ��,1����ʱ��,��ͬ
#define  bRCC_ENABLE_GPIOA                 BIT_ADDR(RCC_BASE+0x18, 2)
#define  bRCC_ENABLE_GPIOB                BIT_ADDR(RCC_BASE+0x18, 3)
#define  bRCC_ENABLE_GPIOC                BIT_ADDR(RCC_BASE+0x18, 4)
#define  bRCC_ENABLE_GPIOD                 BIT_ADDR(RCC_BASE+0x18, 5)
#define  bRCC_ENABLE_GPIOE                 BIT_ADDR(RCC_BASE+0x18, 6)
#define  bRCC_ENABLE_GPIOF                 BIT_ADDR(RCC_BASE+0x18, 7)
#define  bRCC_ENABLE_GPIOG                 BIT_ADDR(RCC_BASE+0x18, 8)
#define  bRCC_ENABLE_ADC1                 BIT_ADDR(RCC_BASE+0x18, 9)
#define  bRCC_ENABLE_ADC2                 BIT_ADDR(RCC_BASE+0x18, 10)
#define  bRCC_ENABLE_TIM1                 BIT_ADDR(RCC_BASE+0x18, 11)
#define  bRCC_ENABLE_SPI1                 BIT_ADDR(RCC_BASE+0x18, 12)
#define  bRCC_ENABLE_USART1               BIT_ADDR(RCC_BASE+0x18, 14)

//RCC_APB1ENR�Ĵ���
#define  bRCC_ENABLE_TIM2                 BIT_ADDR(RCC_BASE+0x1C, 0)   //0�ر�ʱ��,1����ʱ��,��ͬ
#define  bRCC_ENABLE_TIM3                 BIT_ADDR(RCC_BASE+0x1C, 1)
#define  bRCC_ENABLE_TIM4                 BIT_ADDR(RCC_BASE+0x1C, 2)
#define  bRCC_ENABLE_WWDG                 BIT_ADDR(RCC_BASE+0x1C, 11)
#define  bRCC_ENABLE_SPI2                 BIT_ADDR(RCC_BASE+0x1C, 14)
#define  bRCC_ENABLE_USART2               BIT_ADDR(RCC_BASE+0x1C, 17)
#define  bRCC_ENABLE_USART3               BIT_ADDR(RCC_BASE+0x1C, 18)
#define  bRCC_ENABLE_I2C1                 BIT_ADDR(RCC_BASE+0x1C, 21)
#define  bRCC_ENABLE_I2C2                 BIT_ADDR(RCC_BASE+0x1C, 22)
#define  bRCC_ENABLE_USB                  BIT_ADDR(RCC_BASE+0x1C, 23)
#define  bRCC_ENABLE_CAN               	  BIT_ADDR(RCC_BASE+0x1C, 25)
#define  bRCC_ENABLE_BKP                  BIT_ADDR(RCC_BASE+0x1C, 27)
#define  bRCC_ENABLE_PWR                  BIT_ADDR(RCC_BASE+0x1C, 28)

//RCC_BDCR�Ĵ���--�����������
#define  bRCC_CLK_LSEON                  BIT_ADDR(RCC_BASE+0x20, 0)  //LSEʱ��: 0����,1����
#define  bRCC_CLK_LSERDY                 BIT_ADDR(RCC_BASE+0x20, 1) //LSEʱ��״̬��Ӳ������(ֻ��):0������,1����
#define  bRCC_CLK_RTCSEL0                BIT_ADDR(RCC_BASE+0x20, 24) //RTCʱ��Դѡ����λ��ͬ����: 00:��ʱ�� 01:LSE
#define  bRCC_CLK_RTCSEL1                BIT_ADDR(RCC_BASE+0x20, 26) //                      10:LSI   11: HSE/128 
#define  bRCC_ENABLE_RTC                 BIT_ADDR(RCC_BASE+0x20, 27)  //0����RTC; 1:ʹ��RTC
#define  bRCC_RESET_BKUPDOMAIN           BIT_ADDR(RCC_BASE+0x20, 28)   //����������λ  д1��λ 0��λδ������

//RCC_CSR�Ĵ���--״̬�����
#define  bRCC_CLK_LSION                   BIT_ADDR(RCC_BASE+0x24, 0)   //LSIʱ��: 0����,1����
#define  bRCC_CLK_LSIRDY                  BIT_ADDR(RCC_BASE+0x24, 1)   //LSIʱ��״̬��Ӳ������(ֻ��):0������,1����
#define  bRCC_FLG_RMVF                    BIT_ADDR(RCC_BASE+0x24, 24) //�����λ��־ д0��λδ����ĸ�λ��־,д1���帴λ��־
#define  bRCC_FLG_PINRSTF                 BIT_ADDR(RCC_BASE+0x24, 26)  //���Ÿ�λ��־  Ӳ����1���дRMVFλ��0
#define  bRCC_FLG_PORRSTF                 BIT_ADDR(RCC_BASE+0x24, 27)  //�˿ڸ�λ��־  Ӳ����1���дRMVFλ��0
#define  bRCC_FLG_SFTRSTF                 BIT_ADDR(RCC_BASE+0x24, 28)   //�����λ��־  Ӳ����1���дRMVFλ��0
#define  bRCC_FLG_IWDGRSTF                BIT_ADDR(RCC_BASE+0x24, 29)  //�������Ź���λ��־  Ӳ����1���дRMVFλ��0
#define  bRCC_FLG_WWDGRSTF                BIT_ADDR(RCC_BASE+0x24, 30)//���ڿ��Ź���λ��־  Ӳ����1���дRMVFλ��0
#define  bRCC_FLG_LPWRRSTF                BIT_ADDR(RCC_BASE+0x24, 31)//�͹��Ĺ���λ��־  Ӳ����1���дRMVFλ��0 

/******************************************************************************/
/*                                                                            */
/*                         AFIO�Ĵ���                                         */
/*                                                                            */
/******************************************************************************/
//typedef struct
//{
//  __IO uint32_t EVCR;
//  __IO uint32_t MAPR;
//  __IO uint32_t EXTICR[4];
//  uint32_t RESERVED0;
//  __IO uint32_t MAPR2;  
//} AFIO_TypeDef;
//AFIO_EVCR--�¼����ƼĴ���
#define  bAFIO_EVCR_EVOE        BIT_ADDR(AFIO_BASE, 7) //�¼����ʹ��. Ϊ1ʱ,�¼���ָ���Ķ˿����(�˿���BIT6:4,������BIT3:0����)
#define  bAFIO_MAPR_SPI1_REMAP        BIT_ADDR(AFIO_BASE+4, 0) //0���� ��1ʱSPI1ԭPA4/PA5/PA6/PA7�ֱ�ӳ�䵽PA15/PB3/PB4/PB5
#define  bAFIO_MAPR_I2C1_REMAP        BIT_ADDR(AFIO_BASE+4, 1) //0���� ��1ʱI2C1ԭPB6/PB7�ֱ�ӳ�䵽PB8/PB9
#define  bAFIO_MAPR_USART1_REMAP        BIT_ADDR(AFIO_BASE+4, 2) //0���� ��1ʱUSART1ԭPA9/PA10�ֱ�ӳ�䵽PB6/PB7
#define  bAFIO_MAPR_USART2_REMAP        BIT_ADDR(AFIO_BASE+4, 3) //0���� ��1ʱUSART2ԭPA0/1/2/3/4�ֱ�ӳ�䵽PD3/4/5/6/7
#define  bAFIO_MAPR_USART3_REMAPb0      BIT_ADDR(AFIO_BASE+4, 4) //��BIT����: 00���� 01������ӳ�� 10δ�� 11����ӳ��
#define  bAFIO_MAPR_USART3_REMAPb1      BIT_ADDR(AFIO_BASE+4, 5) //
#define  bAFIO_MAPR_TIM1_REMAPb0      BIT_ADDR(AFIO_BASE+4, 6) //��BIT����: 00���� 01������ӳ�� 10δ�� 11����ӳ��
#define  bAFIO_MAPR_TIM1_REMAPb1      BIT_ADDR(AFIO_BASE+4, 7) //
#define  bAFIO_MAPR_TIM2_REMAPb0      BIT_ADDR(AFIO_BASE+4, 8) //��BIT����: 00���� 01������ӳ�� 10������ӳ�� 11����ӳ��
#define  bAFIO_MAPR_TIM2_REMAPb1      BIT_ADDR(AFIO_BASE+4, 9) //
#define  bAFIO_MAPR_TIM3_REMAPb0      BIT_ADDR(AFIO_BASE+4, 10) //��BIT����: 00���� 01δ�� 10������ӳ�� 11��ȫ��ӳ��
#define  bAFIO_MAPR_TIM3_REMAPb1      BIT_ADDR(AFIO_BASE+4, 11) //
#define  bAFIO_MAPR_TIM4_REMAP      BIT_ADDR(AFIO_BASE+4, 12) //ֻ����100���ŷ�װ��TIM4��ͨ��1-4��ӳ��. 0����,1��ԭ����PB6/7/8/9ӳ�䵽PD12/13/14/15
#define  bAFIO_MAPR_CAN_REMAPb0      BIT_ADDR(AFIO_BASE+4, 13) //��BIT����: 
#define  bAFIO_MAPR_CAN_REMAPb1      BIT_ADDR(AFIO_BASE+4, 14) //
#define  bAFIO_MAPR_PD01_REMAP      BIT_ADDR(AFIO_BASE+4, 15) //0����, 1 PD0/1�˿ڷֱ�ӳ��OSC_IN/OSC_OUT����
#define  bAFIO_MAPR_SWJ_CFGb0      BIT_ADDR(AFIO_BASE+4, 24) //3BIT���ƴ���JTAG����(ֻд):000����ȫSWJ����λ״̬����001����ȫSWJ����û��NJTRST����
#define  bAFIO_MAPR_SWJ_CFGb1      BIT_ADDR(AFIO_BASE+4, 25) //010���ر�JATG����SW����100���ر�JATG���ر�SW������ֵ�޶���
#define  bAFIO_MAPR_SWJ_CFGb2      BIT_ADDR(AFIO_BASE+4, 26) //
//��Щ������,���ܶ�BIT16/17/18/19/20��ӳ�䶨��(�ֱ��ӦTIM5/ADC1/ADC2�����Ź���),������Ҫ��ʱ����ֲᲢ��Ӻ�
//AFIO����һ����Ҫ������:����4���ⲿ�ж����üĴ���EXTICR1-4, ����16���ж��ߵĶ˿���(�ֱ���4BIT����PA��PB/....../PG)��ѡ��,����ʹ��λ��������,����.

/******************************************************************************/
/*                                                                            */
/*                         GPIOx�Ĵ���                                        */
/*                                                                            */
/******************************************************************************/
//#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
//#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
//#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
//#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
//#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
//#define GPIOF_BASE            (APB2PERIPH_BASE + 0x1C00)
//#define GPIOG_BASE            (APB2PERIPH_BASE + 0x2000)
//typedef struct
//{
//  __IO uint32_t CRL; //0x00
//  __IO uint32_t CRH; //0x04
//  __IO uint32_t IDR; //0x08
//  __IO uint32_t ODR; //0x0C
//  __IO uint32_t BSRR;//0x10
//  __IO uint32_t BRR; //0x14
//  __IO uint32_t LCKR;//0x18
//} GPIO_TypeDef;
//ע�ⲻͬ��GPIOx�ǻ����ڲ�ͬ�Ļ�ַ�ϵ�, ��ͬ�Ļ�ַ��GPIOA_BASE/GPIOB_BASE�ȵ�������.
//GPIO��λ����,�����ô�ҹ㷺ʹ�õ�PAout(n)......PCin(n)�ķ�ʽ
//��GPIO�Ķ˿�����: ÿ�߲���4BIT,��̫��ʹ��λ��������,����.
//GPIO�Ķ˿�������������GPIOx_LCKR�Ĵ���,�ʺϲ���λ������ʽ,��һ��˹��ܲ�����.
#define  bGPIOA_BSRR(n)   BIT_ADDR(GPIOA_BASE+0x10, n)
#define  bGPIOB_BSRR(n)   BIT_ADDR(GPIOB_BASE+0x10, n)
#define  bGPIOC_BSRR(n)   BIT_ADDR(GPIOC_BASE+0x10, n)
#define  bGPIOD_BSRR(n)   BIT_ADDR(GPIOD_BASE+0x10, n)
#define  bGPIOE_BSRR(n)   BIT_ADDR(GPIOE_BASE+0x10, n)
#define  bGPIOF_BSRR(n)   BIT_ADDR(GPIOF_BASE+0x10, n)
#define  bGPIOG_BSRR(n)   BIT_ADDR(GPIOG_BASE+0x10, n)
#define  bGPIOA_BRR(n)   BIT_ADDR(GPIOA_BASE+0x14, n)
#define  bGPIOB_BRR(n)   BIT_ADDR(GPIOB_BASE+0x14, n)
#define  bGPIOC_BRR(n)   BIT_ADDR(GPIOC_BASE+0x14, n)
#define  bGPIOD_BRR(n)   BIT_ADDR(GPIOD_BASE+0x14, n)
#define  bGPIOE_BRR(n)   BIT_ADDR(GPIOE_BASE+0x14, n)
#define  bGPIOF_BRR(n)   BIT_ADDR(GPIOF_BASE+0x14, n)
#define  bGPIOG_BRR(n)   BIT_ADDR(GPIOG_BASE+0x14, n)
#define  bGPIOA_LOCK(n)   BIT_ADDR(GPIOA_BASE+0x18, n)
#define  bGPIOB_LOCK(n)   BIT_ADDR(GPIOB_BASE+0x18, n)
#define  bGPIOC_LOCK(n)   BIT_ADDR(GPIOC_BASE+0x18, n)
#define  bGPIOD_LOCK(n)   BIT_ADDR(GPIOD_BASE+0x18, n)
#define  bGPIOE_LOCK(n)   BIT_ADDR(GPIOE_BASE+0x18, n)
#define  bGPIOF_LOCK(n)   BIT_ADDR(GPIOF_BASE+0x18, n)
#define  bGPIOG_LOCK(n)   BIT_ADDR(GPIOG_BASE+0x18, n)
#define  bGPIOA_LOCKKEY   BIT_ADDR(GPIOA_BASE+0x18, 16)
#define  bGPIOB_LOCKKEY   BIT_ADDR(GPIOB_BASE+0x18, 16)
#define  bGPIOC_LOCKKEY   BIT_ADDR(GPIOC_BASE+0x18, 16)
#define  bGPIOD_LOCKKEY   BIT_ADDR(GPIOD_BASE+0x18, 16)
#define  bGPIOE_LOCKKEY   BIT_ADDR(GPIOE_BASE+0x18, 16)
#define  bGPIOF_LOCKKEY   BIT_ADDR(GPIOF_BASE+0x18, 16)
#define  bGPIOG_LOCKKEY   BIT_ADDR(GPIOG_BASE+0x18, 16)

#define  bGPIOx_BSRR(m,n)  BIT_ADDR(GPIOA_BASE+0x400*m+0x10, n) //��λָ���˿ڵ�ָ��λ
#define  bGPIOx_BRR(m,n)   BIT_ADDR(GPIOA_BASE+0x400*m+0x14, n)  //��λָ���˿ڵ�ָ��λ
#define  bGPIOx_ODR(m,n)   BIT_ADDR(GPIOA_BASE+0x400*m+0x0C, n)  //ָ���˿ڵ�ָ��λ
#define  bGPIOx_IDR(m,n)   BIT_ADDR(GPIOA_BASE+0x400*m+0x08, n)  //ָ���˿ڵ�ָ��λ



/******************************************************************************/
/*                                                                            */
/*                         BKP�Ĵ���                                          */
/*                                                                            */
/******************************************************************************/
//ǰ10���Ĵ�����ȫ��Ϊ�û�����ʹ��,��ַΪ:BKP_BASE+0x04��BKP_BASE+0x28,ÿ���Ĵ���ռ��4�ֽڿռ�,��һ����,��ֻ�е�16λ��Ч.
//��ֱ�������к�ָ�������з��ʣ� BKP_DR1��ͬ��BKP->DR1
#define  BKP_DR1  			MEM_ADDR(BKP_BASE+0x04)
#define  BKP_DR2  			MEM_ADDR(BKP_BASE+0x08)
#define  BKP_DR3  			MEM_ADDR(BKP_BASE+0x0C)
#define  BKP_DR4  			MEM_ADDR(BKP_BASE+0x10)
#define  BKP_DR5  			MEM_ADDR(BKP_BASE+0x14)
#define  BKP_DR6  			MEM_ADDR(BKP_BASE+0x18)
#define  BKP_DR7  			MEM_ADDR(BKP_BASE+0x1C)
#define  BKP_DR8  			MEM_ADDR(BKP_BASE+0x20)
#define  BKP_DR9  			MEM_ADDR(BKP_BASE+0x24)
#define  BKP_DR10  			MEM_ADDR(BKP_BASE+0x28)
//��Щ�Ĵ������ᱻϵͳ��λ����Դ��λ��������������λ
//ע��Ժ󱸼Ĵ�����д��������ʹ��PWR��BKP��ʱ�ӣ���bRCC_ENABLE_PWR=1;bRCC_ENABLE_BKP=1; 
//����ȡ���󱸼Ĵ���д������bPWR_CR_DBP=1;  		
//�Ժ󱸼Ĵ����Ķ��������������㣬��ʱ�ɶ���		

//BKP_RTCCR��RTCʱ��У׼�Ĵ�����
//BIT6:0 CALУ׼ֵ����ʾ��ÿ2��20�η���ʱ�������ڽ��ж��ٸ����屻���������������RTC����У׼����1000000/��2��20�η���������ʱ�ӣ����ñ�����0-121ppm
#define  bBKP_RTCCR_CCO        BIT_ADDR(BKP_BASE+0x2C, 7) //CCOУ׼ʱ����������壺0����Ӱ�죩��1����λ��1������������������64��Ƶ���RTCʱ�ӡ�
                                                         //  ��CCOλ��1ʱ������ر������⣩ע��vdd�ϵ磬��λ���
#define  bBKP_RTCCR_ASOE       BIT_ADDR(BKP_BASE+0x2C, 8) //����������ӻ������壨����ASOSλ����λ����λ����RTC���ӻ������������TAMPER���š�
                                                         // ������Ϊ1��RTCʱ�����ڡ���λʱ���ܿ���TAMPER���ܣ�
#define  bBKP_RTCCR_ASOS       BIT_ADDR(BKP_BASE+0x2C, 9) //���ӻ��������������ASOEλ��ASOSλ������ѡ����TAMPER�������������RTC�����廹�����������źţ�
                                                         //���壺0�����RTC�������壩��1����������壩ע��������λ���
//BKP_CR���ݿ��ƼĴ���
#define  bBKP_CR_TPE        BIT_ADDR(BKP_BASE+0x30, 0) //TPAL������TAMPER������Ч��ƽ��0���TAMPER�Ÿߵ�ƽ����������� 1���TAMPER�ŵ͵�ƽ�����������
#define  bBKP_CR_TPAL       BIT_ADDR(BKP_BASE+0x30, 1) //TPE�������ּ��TAMPER���š����壺0��TAMPER��Ϊ��ͨIO����1��������⣩
//BKP_CR���ݿ���/״̬�Ĵ���
#define  bBKP_CSR_CTE        BIT_ADDR(BKP_BASE+0x34, 0) //CTE����������¼���ֻ��д�룬����ֵΪ0�����壺0����Ч��1�����TEF�������¼���־������λ����������
#define  bBKP_CSR_CTI        BIT_ADDR(BKP_BASE+0x34, 1) //CTI����������жϣ�ֻ��д�룬����ֵΪ0�����壺0����Ч��1������������жϺ�TIF�������жϱ�־��
#define  bBKP_CSR_TPIE       BIT_ADDR(BKP_BASE+0x34, 2) //��������TAMPER�����жϡ�����0����ֹ�������жϣ���1������BKP_CR�Ĵ���TPEλҲ������1��
#define  bBKP_CSR_TEF        BIT_ADDR(BKP_BASE+0x34, 8) //TEF�����¼���־��Ӳ����λ��ͨ����CTEλд1������˱�־λ�����壺0���������¼�����1���������¼���
#define  bBKP_CSR_TIF        BIT_ADDR(BKP_BASE+0x34, 9) //TIF�����жϱ�־��������������¼���TPIEΪ1ʱ����ΪӲ����1��ͨ����CTIλд1�������־λ��ͬʱҲ����жϣ���
                                                       //���TPIE���������λҲ�ᱻ�����

/******************************************************************************/
/*                                                                            */
/*                         RTC�Ĵ���                                          */
/*                                                                            */
/******************************************************************************/
//RTC���ƼĴ�����λRTC_CRH
#define  bRTC_CRH_SECIE        BIT_ADDR(RTC_BASE+0x00, 0) //SECIE�������ж�λ�����壺0�������жϣ���1�������жϣ�
#define  bRTC_CRH_ALRIE        BIT_ADDR(RTC_BASE+0x00, 1)  //ALRIE���������ж�λ�����壺0�������жϣ���1�������жϣ�
#define  bRTC_CRH_OWIE         BIT_ADDR(RTC_BASE+0x00, 2) //OWIE��������ж�λ�����壺0�������жϣ���1�������жϣ�
//RTC���ƼĴ�����λRTC_CRL
#define  bRTC_CRL_SECF        BIT_ADDR(RTC_BASE+0x04, 0)  //���־,Ӳ���á�1��ͬʱRTC��������1�����,�˱�־Ϊ�ֱ��ʿɱ�̵�RTC�������ṩһ�������Ե��ź�(ͨ��Ϊ1��)��
#define  bRTC_CRL_ALRF        BIT_ADDR(RTC_BASE+0x04, 1) //Ӳ����1,ֻ��������塯0�����Դ�λд��1������Ч�ģ����壺0�������ӣ���1�������ӣ�
#define  bRTC_CRL_OWF         BIT_ADDR(RTC_BASE+0x04, 2) //OWF�����־����Ӳ���á�1�������RTC_CRH�Ĵ�����OWIE=1��������жϡ���λֻ��������塯0����
#define  bRTC_CRL_RSF        BIT_ADDR(RTC_BASE+0x04, 3)  //RSF�Ĵ���ͬ����־��ÿ��RTC_CNT�Ĵ�����RTC_DIV�Ĵ�����������»��塯0��ʱ����λ��Ӳ���á�1������APB1��λ��//��APB1ʱ��ֹͣ�󣬴�λ����������塯0����Ҫ�����κεĶ�����֮ǰ���û��������ȴ���λ��Ӳ���á�1������ȷ��RTC_CNT��RTC_ALR��RTC_PRL�Ѿ���ͬ����
#define  bRTC_CRL_CNF        BIT_ADDR(RTC_BASE+0x04, 4) //CNF���ñ�־����λ����������á�1���Խ�������ģʽ���Ӷ�������RTC_CNT��RTC_ALR��RTC_PRL�Ĵ���д�����ݡ�ֻ�е�//��λ�ڱ��á�1��������������塯0���󣬲Ż�ִ��д���������壺0���˳�����ģʽ(��ʼ����RTC�Ĵ���)��1����������ģʽ��
#define  bRTC_CRL_RTOFF      BIT_ADDR(RTC_BASE+0x04, 5) //RTC�����رգ�ֻ��λ��RTCģ��������λ��ָʾ����Ĵ������е����һ�β�����״̬��ָʾ�����Ƿ���ɡ�����λ
//Ϊ��0�������ʾ�޷����κε�RTC�Ĵ�������д���������壺0����һ�ζ�RTC�Ĵ�����д�������ڽ��У���1����һ�ζ�RTC�Ĵ�����д�����Ѿ���ɣ�
//����,RTC�Ĵ�������Ԥ��Ƶװ�ؼĴ���/Ԥ��Ƶ�����Ĵ���/32λ��RTC������/32λ�����Ӽ�����, ��Щ�����˽���λ����,ֱ�Ӱ��������д.

/******************************************************************************/
/*                                                                            */
/*         USART�Ĵ���                                   											*/
/*                                                                            */
/******************************************************************************/
//#define USART1_BASE           (APB2PERIPH_BASE + 0x3800)  //ע��˵�ַ������ĵ�ַ������
//#define USART2_BASE           (APB1PERIPH_BASE + 0x4400)
//#define USART3_BASE           (APB1PERIPH_BASE + 0x4800)
//#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00)
//#define UART5_BASE            (APB1PERIPH_BASE + 0x5000)

//typedef struct
//{
//  __IO uint16_t SR;  //0x00
//  uint16_t  RESERVED0;
//  __IO uint16_t DR;  //0x04
//  uint16_t  RESERVED1;
//  __IO uint16_t BRR; //0x08
//  uint16_t  RESERVED2;
//  __IO uint16_t CR1; //0x0C
//  uint16_t  RESERVED3;
//  __IO uint16_t CR2; //0x10
//  uint16_t  RESERVED4;
//  __IO uint16_t CR3; //0x14
//  uint16_t  RESERVED5;
//  __IO uint16_t GTPR; //0x18
//  uint16_t  RESERVED6;
//} USART_TypeDef;

//USART״̬�Ĵ���SR
#define  bUSART1_SR_PE 			BIT_ADDR(USART1_BASE+0x00, 0) //У�����Parity Error���ڽ���ģʽ�£����������żУ�����Ӳ���Ը�λ��λ��
#define  bUSART1_SR_FE 			BIT_ADDR(USART1_BASE+0x00, 1) //֡����Framing Error������⵽ͬ����λ��������������߼�⵽�Ͽ�������λ��Ӳ����λ��
#define  bUSART1_SR_NE 			BIT_ADDR(USART1_BASE+0x00, 2) //��������Noise Error���ڽ��յ���֡��⵽����ʱ����Ӳ���Ը�λ��λ��
#define  bUSART1_SR_ORE 		BIT_ADDR(USART1_BASE+0x00, 3) //���ش���Overrun Error����RXNE��Ȼ�ǡ�1����ʱ�򣬵�ǰ����������λ�Ĵ����е����ݣ���Ҫ������RDR�Ĵ���ʱ��Ӳ������λ��λ�����USART_CR1�е�RXNEIEΪ��1���Ļ���������жϡ�
#define  bUSART1_SR_IDLE		BIT_ADDR(USART1_BASE+0x00, 4) //IDLE����⵽���߿��У�����⵽���߿���ʱ����λ��Ӳ����λ�����USART_CR1�е�IDLEIEΪ��1����������жϡ�
#define  bUSART1_SR_RXNE		BIT_ADDR(USART1_BASE+0x00, 5) //���վݼĴ����ǿգ�Receive Not Empty��������λ����λ��ʱ�򣬾�����ʾ�Ѿ������ݱ����յ��ˣ����ҿ��Զ������ˡ�ͨ����USART_DR���Խ���λ���㣬Ҳ�������λд0��ֱ�������
#define  bUSART1_SR_TC 			BIT_ADDR(USART1_BASE+0x00, 6) //������ɣ�Transmit Complete��������λ����λ��ʱ�򣬱�ʾUSART_DR�ڵ������Ѿ�����������ˡ�������������λ���жϣ��������жϡ���λҲ���������㷽ʽ��1����USART_SR��дUSART_DR��2��ֱ�����λд0��
#define  bUSART1_SR_TXE 		BIT_ADDR(USART1_BASE+0x00, 7) //�������ݼĴ����գ�Transmit Empty����TDR�Ĵ����е����ݱ�Ӳ��ת�Ƶ���λ�Ĵ�����ʱ�򣬸�λ��Ӳ����λ�����USART_CR1�Ĵ����е�TXEIEΪ1��������жϡ���USART_DR��д����������λ���㡣
#define  bUSART1_SR_LBD 		BIT_ADDR(USART1_BASE+0x00, 8) //LIN�Ͽ���⣨LIN Break Detect����̽�⵽LIN�Ͽ�ʱ����λ��Ӳ���á�1����������塯0��(���λд0)�����USART_CR3�е�LBDIE = 1��������жϡ�
#define  bUSART1_SR_CTS 		BIT_ADDR(USART1_BASE+0x00, 9)  //���������CTSEλ����nCTS����仯״̬ʱ����λ��Ӳ���øߡ�������������㡣���USART_CR3�е�CTSIEΪ��1����������жϡ�
//USART״̬�Ĵ���CR1
#define  bUSART1_CR1_SBK     BIT_ADDR(USART1_BASE+0x0C, 0)  //���ͶϿ�֡��Send Break��λ��ʹ�ø�λ�����ͶϿ��ַ�����λ������������û��������������Ӧ�����������λ����Ȼ���ڶϿ�֡��ֹͣλʱ����Ӳ������λ��λ��
#define  bUSART1_CR1_RWU     BIT_ADDR(USART1_BASE+0x0C, 1)  //���ջ��ѣ�Receiver Wakeup��λ����0������ģʽ����1����Ĭģʽ��
#define  bUSART1_CR1_RE      BIT_ADDR(USART1_BASE+0x0C, 2)  //����ʹ�ܣ�Receive Enable��λ���÷�ͬ TE��
#define  bUSART1_CR1_TE      BIT_ADDR(USART1_BASE+0x0C, 3)  //����ʹ�ܣ�Transmit Enable��λ������Ϊ1�����������ڵķ��͹��ܡ�
#define  bUSART1_CR1_IDLEIE  BIT_ADDR(USART1_BASE+0x0C, 4)  //IDLE�ж�ʹ�ܣ�IDLE Interrupt Enable��λ����0����ֹ�жϣ���1����USART_SR�е�IDLEΪ��1��ʱ������USART�жϡ�
#define  bUSART1_CR1_RXNEIE  BIT_ADDR(USART1_BASE+0x0C, 5)  //���ջ������ǿ��ж�ʹ�ܣ�Receive Non-Empty Interrupt Enable��λ�����ø�λΪ 1���� USART_SR�е� ORE ���� RXNE λΪ 1 ʱ�������������жϡ�
#define  bUSART1_CR1_TCIE    BIT_ADDR(USART1_BASE+0x0C, 6)  //��������ж�ʹ�ܣ�Transmit Complete Interrupt Enable��λ�����ø�λΪ 1���� USART_SR �е� TCλΪ 1 ʱ�������������жϡ�
#define  bUSART1_CR1_TXEIE   BIT_ADDR(USART1_BASE+0x0C, 7)  //���ͻ��������ж�ʹ�ܣ�Transmit Interrupt Enable��λ�����ø�λΪ 1���� USART_SR �е� TXE λΪ1 ʱ�������������жϡ�
#define  bUSART1_CR1_PEIE    BIT_ADDR(USART1_BASE+0x0C, 8)  //PE�ж�ʹ�ܣ�Parity Error Interrupt Enable������0����ֹ�жϣ���1����USART_SR�е�PEΪ��1��ʱ������USART�жϡ�
#define  bUSART1_CR1_PS      BIT_ADDR(USART1_BASE+0x0C, 9)   //У��λѡ��Parity Select��λ������Ϊ0��ΪżУ�飬����Ϊ��У�顣
#define  bUSART1_CR1_PCE     BIT_ADDR(USART1_BASE+0x0C, 10)  //У�����ʹ�ܣ�Parity Control Enable��λ����0�����ֹУ�飬����ʹ��У�顣
#define  bUSART1_CR1_WAKE    BIT_ADDR(USART1_BASE+0x0C, 11) //���ѣ���0�����������߻��ѣ���1������ַ��ǻ��ѡ�
#define  bUSART1_CR1_M       BIT_ADDR(USART1_BASE+0x0C, 12) //�ֳ�ѡ��λ������λΪ0��ʱ�����ô���Ϊ8���ֳ����ֹͣλ��ֹͣλ�ĸ����Ǹ���USART_CR2��[13:12]λ�����������ģ�Ĭ��Ϊ0��
#define  bUSART1_CR1_UE      BIT_ADDR(USART1_BASE+0x0C, 13) //����ʹ�ܣ�Usart Enable��λ��ͨ����λ��1����ʹ�ܴ��ڡ�����λ�����㣬��Ƶ�������ֹͣ�������Լ��ٹ��ġ�
#define  bUSART1_CR1_OVER8   BIT_ADDR(USART1_BASE+0x0C, 14)           /*!< USART Oversmapling 8-bits */
//USART״̬�Ĵ���CR2
#define  SET_USART1_CR2_ADD(a)   (MEM_ADDR(USART1_BASE+0x10)=(MEM_ADDR(USART1_BASE+0x10)&(~USART_CR2_ADD))|((a&MASKb5)<<0))
// #define  bUSART1_CR2_ADD     BIT_ADDR(USART1_BASE+0x10, 0)  //���豸��USART�ڵ��ַ(BIT 0:4��5λ)�������ڶദ����ͨ���µľ�Ĭģʽ��ʹ�õģ�ʹ�õ�ַ���������ĳ��USART�豸��
#define  bUSART1_CR2_LBDL    BIT_ADDR(USART1_BASE+0x10, 5)  //LIN�Ͽ�����ⳤ�ȣ�LIN Break Detection Length��λ����λ����ѡ����11λ����10λ�ĶϿ�����⡣
#define  bUSART1_CR2_LBDIE   BIT_ADDR(USART1_BASE+0x10, 6)  //LIN�Ͽ�������ж�ʹ�ܣ�LIN Break Detection Interrupt Enable��λ����0����ֹ�жϣ���1��ֻҪUSART_SR�Ĵ����е�LBDΪ��1���Ͳ����жϡ�
#define  bUSART1_CR2_LBCL    BIT_ADDR(USART1_BASE+0x10, 7)  //���һλʱ�����壨Last Bit Clock Pulse��λ����ͬ��ģʽ�£�ʹ�ø�λ�������Ƿ���CK�������������͵��Ǹ������ֽ�(MSB)��Ӧ��ʱ�����塣
#define  bUSART1_CR2_CPHA    BIT_ADDR(USART1_BASE+0x10, 9)  //ʱ����λ��Clock Phase��λ����ͬ��ģʽ�£������ø�λѡ��SLCK������ʱ���������λ��
#define  bUSART1_CR2_CPOL    BIT_ADDR(USART1_BASE+0x10, 10) //ʱ�Ӽ��ԣ�Clock Polarity��λ����ͬ��ģʽ�£������ø�λѡ��SLCK������ʱ������ļ��ԡ�
#define  bUSART1_CR2_CLKEN   BIT_ADDR(USART1_BASE+0x10, 11) //ʱ��ʹ�ܣ�Clock Enable��λ����λ����ʹ��CK���š�
#define  SET_USART1_CR2_STOP(a)   (MEM_ADDR(USART1_BASE+0x10)=(MEM_ADDR(USART1_BASE+0x10)&(~USART_CR2_STOP))|((a&MASKb2)<<12))
// #define  bUSART1_CR2_STOP    BIT_ADDR(USART1_BASE+0x10, 12) //ֹͣλ��STOP��λ����2λ��������ֹͣλ��λ����00��1��ֹͣλ��01��0.5��ֹͣλ��10��2��ֹͣλ��11��1.5��ֹͣλ��          /*!< STOP[1:0] bits (STOP bits) */
#define  bUSART1_CR2_STOP_0  BIT_ADDR(USART1_BASE+0x10, 12) //           
#define  bUSART1_CR2_STOP_1  BIT_ADDR(USART1_BASE+0x10, 13) //
#define  bUSART1_CR2_LINEN   BIT_ADDR(USART1_BASE+0x10, 14) //LINģʽʹ�ܣ�LIN Enable��λ����LINģʽ�£�������USART_CR1�Ĵ����е�SBKλ����LINͬ���Ͽ���(��13λ)���Լ����LINͬ���Ͽ�����

//USART״̬�Ĵ���CR3
#define  bUSART1_CR3_EIE     BIT_ADDR(USART1_BASE+0x14, 0)  //�����ж�ʹ�ܣ�Error Interrupt Enable��λ��
#define  bUSART1_CR3_IREN    BIT_ADDR(USART1_BASE+0x14, 1)  //����ģʽʹ�ܣ�IrDA Enable��λ��
#define  bUSART1_CR3_IRLP    BIT_ADDR(USART1_BASE+0x14, 2)  //����͹��ģ�IrDA Low-Power��λ����λ����ѡ����ͨģʽ���ǵ͹��ĺ���ģʽ��
#define  bUSART1_CR3_HDSEL   BIT_ADDR(USART1_BASE+0x14, 3)  //��˫��ѡ��Half-duplex Selection��λ��ѡ���߰�˫��ģʽ��
#define  bUSART1_CR3_NACK    BIT_ADDR(USART1_BASE+0x14, 4)  //���ܿ�NACK��Smartcard NACK��λ����0��������NACK����1������NACK��
#define  bUSART1_CR3_SCEN    BIT_ADDR(USART1_BASE+0x14, 5)  //���ܿ�ʹ�ܣ�Smartcard Enable��λ����λ����ʹ�����ܿ�ģʽ
#define  bUSART1_CR3_DMAR    BIT_ADDR(USART1_BASE+0x14, 6)  //DMA���գ�DMA Receiver��λ�� 
#define  bUSART1_CR3_DMAT    BIT_ADDR(USART1_BASE+0x14, 7)  //DMA���ͣ�DMA Transmitter��λ�� 
#define  bUSART1_CR3_RTSE    BIT_ADDR(USART1_BASE+0x14, 8)  //RTSʹ�ܣ�RTS Enable��λ�� 
#define  bUSART1_CR3_CTSE    BIT_ADDR(USART1_BASE+0x14, 9)  //CTSʹ�ܣ�CTS Enable��λ��
#define  bUSART1_CR3_CTSIE   BIT_ADDR(USART1_BASE+0x14, 10) //CTS�ж�ʹ�ܣ�CTS Interrupt Enable��λ��
#define  bUSART1_CR3_ONEBIT  BIT_ADDR(USART1_BASE+0x14, 11)  

//USART״̬�Ĵ���GTPR
#define  bUSART1_GTPR_PSC     BIT_ADDR(USART1_BASE+0x18, 0) //Ԥ��Ƶ��ֵ��Prescaler��λ���ں�������ܿ�ģʽ������Ҫ������ܡ�
#define  bUSART1_GTPR_GT      BIT_ADDR(USART1_BASE+0x18, 8) //����ʱ��ֵ��Guard Time��λ����λ��涨���Բ���ʱ��Ϊ��λ�ı���ʱ�䡣�����ܿ�ģʽ�£���Ҫ������ܡ�������ʱ���ȥ�󣬲Ż����÷�����ɱ�־��

/******************************************************************************/
/*                                                                            */
/*                        SPI�ӿڼĴ���                         */
/*                                                                            */
/******************************************************************************/
//#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
//#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800)
//#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00)

//���У�DR_DR��CRCPR_CRCPOLY��RXCRCR_RXCRC��TXCRCR_TXCRCΪ16λ�Ĵ�����������λ����

//typedef struct
//{
//  __IO uint16_t CR1;  //0x00
//  uint16_t  RESERVED0;
//  __IO uint16_t CR2;  //0x04
//  uint16_t  RESERVED1;
//  __IO uint16_t SR;   //0x08
//  uint16_t  RESERVED2;
//  __IO uint16_t DR;  //0x0C
//  uint16_t  RESERVED3;
//  __IO uint16_t CRCPR; //0x10
//  uint16_t  RESERVED4;
//  __IO uint16_t RXCRCR; //0x14 
//  uint16_t  RESERVED5;
//  __IO uint16_t TXCRCR; //0x18
//  uint16_t  RESERVED6; 
//  __IO uint16_t I2SCFGR; //0x1C
//  uint16_t  RESERVED7; 
//  __IO uint16_t I2SPR; //0x20
//  uint16_t  RESERVED8;  
//} SPI_TypeDef;

/*******************  Bit definition for SPI_CR1 register  ********************/
#define  bSPI1_CR1_CPHA     BIT_ADDR(SPI1_BASE+0x00, 0)  /*!< Clock Phase */
#define  bSPI1_CR1_CPOL     BIT_ADDR(SPI1_BASE+0x00, 1)            /*!< Clock Polarity */
#define  bSPI1_CR1_MSTR     BIT_ADDR(SPI1_BASE+0x00, 2)            /*!< Master Selection */

// SPI�����ٶ�����
//SpeedSet:
#define SPI_SPEED_2   	0    //SPI_SPEED_2   2��Ƶ   (SPI 36M@sys 72M) 
#define SPI_SPEED_4   	1    //SPI_SPEED_2   4��Ƶ   (SPI 18M@sys 72M)
#define SPI_SPEED_8   	2    //SPI_SPEED_8   8��Ƶ   (SPI 9M@sys 72M)
#define SPI_SPEED_16  	3    //SPI_SPEED_16  16��Ƶ  (SPI 4.5M@sys 72M)
#define SPI_SPEED_32  	4    //SPI_SPEED_32  32��Ƶ  (SPI 2.25M@sys 72M)
#define SPI_SPEED_64  	5    //SPI_SPEED_64  64��Ƶ   (SPI 1.125M@sys 72M)
#define SPI_SPEED_128  	6    //SPI_SPEED_128 128��Ƶ (SPI 562.5K@sys 72M)
#define SPI_SPEED_256 	7    //SPI_SPEED_256 256��Ƶ (SPI 281.25K@sys 72M)

#define  SET_SPI1_CR1_BR(a)   (MEM_ADDR(SPI1_BASE)=(MEM_ADDR(SPI1_BASE)&(~SPI_CR1_BR))|((a&MASKb3)<<3))
//   #define  bSPI1_CR1_BR       BIT_ADDR(SPI1_BASE+0x00, 3)            /*!< BR[2:0] bits (Baud Rate Control) */

#define  bSPI1_CR1_SPE      BIT_ADDR(SPI1_BASE+0x00, 6)            /*!< SPI Enable */
#define  bSPI1_CR1_LSBFIRST BIT_ADDR(SPI1_BASE+0x00, 7)            /*!< Frame Format */
#define  bSPI1_CR1_SSI      BIT_ADDR(SPI1_BASE+0x00, 8)            /*!< Internal slave select */
#define  bSPI1_CR1_SSM      BIT_ADDR(SPI1_BASE+0x00, 9)            /*!< Software slave management */
#define  bSPI1_CR1_RXONLY   BIT_ADDR(SPI1_BASE+0x00, 10)            /*!< Receive only */
#define  bSPI1_CR1_DFF      BIT_ADDR(SPI1_BASE+0x00, 11)            /*!< Data Frame Format */
#define  bSPI1_CR1_CRCNEXT  BIT_ADDR(SPI1_BASE+0x00, 12)            /*!< Transmit CRC next */
#define  bSPI1_CR1_CRCEN    BIT_ADDR(SPI1_BASE+0x00, 13)            /*!< Hardware CRC calculation enable */
#define  bSPI1_CR1_BIDIOE   BIT_ADDR(SPI1_BASE+0x00, 14)            /*!< Output enable in bidirectional mode */
#define  bSPI1_CR1_BIDIMODE BIT_ADDR(SPI1_BASE+0x00, 15)            /*!< Bidirectional data mode enable */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define  bSPI1_CR2_RXDMAEN  BIT_ADDR(SPI1_BASE+0x04, 0)               /*!< Rx Buffer DMA Enable */
#define  bSPI1_CR2_TXDMAEN  BIT_ADDR(SPI1_BASE+0x04, 1)               /*!< Tx Buffer DMA Enable */
#define  bSPI1_CR2_SSOE     BIT_ADDR(SPI1_BASE+0x04, 2)               /*!< SS Output Enable */
#define  bSPI1_CR2_ERRIE    BIT_ADDR(SPI1_BASE+0x04, 4)               /*!< Error Interrupt Enable */
#define  bSPI1_CR2_RXNEIE   BIT_ADDR(SPI1_BASE+0x04, 6)               /*!< RX buffer Not Empty Interrupt Enable */
#define  bSPI1_CR2_TXEIE    BIT_ADDR(SPI1_BASE+0x04, 7)               /*!< Tx buffer Empty Interrupt Enable */

/********************  Bit definition for SPI_SR register  ********************/
#define  bSPI1_SR_RXNE     BIT_ADDR(SPI1_BASE+0x08, 0)              /*!< Receive buffer Not Empty */
#define  bSPI1_SR_TXE      BIT_ADDR(SPI1_BASE+0x08, 1)               /*!< Transmit buffer Empty */
#define  bSPI1_SR_CHSIDE   BIT_ADDR(SPI1_BASE+0x08, 2)               /*!< Channel side */
#define  bSPI1_SR_UDR      BIT_ADDR(SPI1_BASE+0x08, 3)               /*!< Underrun flag */
#define  bSPI1_SR_CRCERR   BIT_ADDR(SPI1_BASE+0x08, 4)               /*!< CRC Error flag */
#define  bSPI1_SR_MODF     BIT_ADDR(SPI1_BASE+0x08, 5)               /*!< Mode fault */
#define  bSPI1_SR_OVR      BIT_ADDR(SPI1_BASE+0x08, 6)               /*!< Overrun flag */
#define  bSPI1_SR_BSY      BIT_ADDR(SPI1_BASE+0x08, 7)               /*!< Busy flag */

/******************  Bit definition for SPI_I2SCFGR register  *****************/
#define  bSPI1_I2SCFGR_CHLEN     BIT_ADDR(SPI1_BASE+0x1C, 0)            /*!< Channel length (number of bits per audio channel) */

#define  bSPI1_I2SCFGR_DATLEN    BIT_ADDR(SPI1_BASE+0x1C, 1)             /*!< DATLEN[1:0] bits (Data length to be transferred) */
#define  bSPI1_I2SCFGR_DATLEN_0  BIT_ADDR(SPI1_BASE+0x1C, 1)            /*!< Bit 0 */
#define  bSPI1_I2SCFGR_DATLEN_1  BIT_ADDR(SPI1_BASE+0x1C, 2)            /*!< Bit 1 */

#define  bSPI1_I2SCFGR_CKPOL     BIT_ADDR(SPI1_BASE+0x1C, 3)            /*!< steady state clock polarity */

#define  bSPI1_I2SCFGR_I2SSTD    BIT_ADDR(SPI1_BASE+0x1C, 4)            /*!< I2SSTD[1:0] bits (I2S standard selection) */
#define  bSPI1_I2SCFGR_I2SSTD_0  BIT_ADDR(SPI1_BASE+0x1C, 4)            /*!< Bit 0 */
#define  bSPI1_I2SCFGR_I2SSTD_1  BIT_ADDR(SPI1_BASE+0x1C, 5)            /*!< Bit 1 */

#define  bSPI1_I2SCFGR_PCMSYNC   BIT_ADDR(SPI1_BASE+0x1C, 7)            /*!< PCM frame synchronization */

#define  bSPI1_I2SCFGR_I2SCFG    BIT_ADDR(SPI1_BASE+0x1C, 8)            /*!< I2SCFG[1:0] bits (I2S configuration mode) */
#define  bSPI1_I2SCFGR_I2SCFG_0  BIT_ADDR(SPI1_BASE+0x1C, 8)            /*!< Bit 0 */
#define  bSPI1_I2SCFGR_I2SCFG_1  BIT_ADDR(SPI1_BASE+0x1C, 9)            /*!< Bit 1 */

#define  bSPI1_I2SCFGR_I2SE      BIT_ADDR(SPI1_BASE+0x1C, 10)            /*!< I2S Enable */
#define  bSPI1_I2SCFGR_I2SMOD    BIT_ADDR(SPI1_BASE+0x1C, 11)            /*!< I2S mode selection */

/******************  Bit definition for SPI_I2SPR register  *******************/
#define  SET_SPI1_I2SPR_I2SDIV(a)   (MEM_ADDR(SPI1_BASE+0x20)=(MEM_ADDR(SPI1_BASE+0x20)&(~SPI_I2SPR_I2SDIV))|((a&MASKb8)<<0))
// #define  bSPI1_I2SPR_I2SDIV      BIT_ADDR(SPI1_BASE+0x20, 0)  //����8BIT I2S ����Ԥ��Ƶ

#define  bSPI1_I2SPR_ODD         BIT_ADDR(SPI1_BASE+0x20, 8)            /*!< Odd factor for the prescaler */
#define  bSPI1_I2SPR_MCKOE       BIT_ADDR(SPI1_BASE+0x20, 9)            /*!< Master Clock Output Enable */


/*******************  Bit definition for SPI_CR1 register  ********************/
#define  bSPI2_CR1_CPHA     BIT_ADDR(SPI2_BASE+0x00, 0)  /*!< Clock Phase */
#define  bSPI2_CR1_CPOL     BIT_ADDR(SPI2_BASE+0x00, 1)            /*!< Clock Polarity */
#define  bSPI2_CR1_MSTR     BIT_ADDR(SPI2_BASE+0x00, 2)            /*!< Master Selection */

#define  SET_SPI2_CR1_BR(a)   (MEM_ADDR(SPI2_BASE)=(MEM_ADDR(SPI2_BASE)&(~SPI_CR1_BR))|((a&MASKb3)<<3))
//  #define  bSPI2_CR1_BR       BIT_ADDR(SPI2_BASE+0x00, 3)            /*!< BR[2:0] bits (Baud Rate Control) */

#define  bSPI2_CR1_SPE      BIT_ADDR(SPI2_BASE+0x00, 6)            /*!< SPI Enable */
#define  bSPI2_CR1_LSBFIRST BIT_ADDR(SPI2_BASE+0x00, 7)            /*!< Frame Format */
#define  bSPI2_CR1_SSI      BIT_ADDR(SPI2_BASE+0x00, 8)            /*!< Internal slave select */
#define  bSPI2_CR1_SSM      BIT_ADDR(SPI2_BASE+0x00, 9)            /*!< Software slave management */
#define  bSPI2_CR1_RXONLY   BIT_ADDR(SPI2_BASE+0x00, 10)            /*!< Receive only */
#define  bSPI2_CR1_DFF      BIT_ADDR(SPI2_BASE+0x00, 11)            /*!< Data Frame Format */
#define  bSPI2_CR1_CRCNEXT  BIT_ADDR(SPI2_BASE+0x00, 12)            /*!< Transmit CRC next */
#define  bSPI2_CR1_CRCEN    BIT_ADDR(SPI2_BASE+0x00, 13)            /*!< Hardware CRC calculation enable */
#define  bSPI2_CR1_BIDIOE   BIT_ADDR(SPI2_BASE+0x00, 14)            /*!< Output enable in bidirectional mode */
#define  bSPI2_CR1_BIDIMODE BIT_ADDR(SPI2_BASE+0x00, 15)            /*!< Bidirectional data mode enable */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define  bSPI2_CR2_RXDMAEN  BIT_ADDR(SPI2_BASE+0x04, 0)               /*!< Rx Buffer DMA Enable */
#define  bSPI2_CR2_TXDMAEN  BIT_ADDR(SPI2_BASE+0x04, 1)               /*!< Tx Buffer DMA Enable */
#define  bSPI2_CR2_SSOE     BIT_ADDR(SPI2_BASE+0x04, 2)               /*!< SS Output Enable */
#define  bSPI2_CR2_ERRIE    BIT_ADDR(SPI2_BASE+0x04, 4)               /*!< Error Interrupt Enable */
#define  bSPI2_CR2_RXNEIE   BIT_ADDR(SPI2_BASE+0x04, 6)               /*!< RX buffer Not Empty Interrupt Enable */
#define  bSPI2_CR2_TXEIE    BIT_ADDR(SPI2_BASE+0x04, 7)               /*!< Tx buffer Empty Interrupt Enable */

/********************  Bit definition for SPI_SR register  ********************/
#define  bSPI2_SR_RXNE     BIT_ADDR(SPI2_BASE+0x08, 0)              /*!< Receive buffer Not Empty */
#define  bSPI2_SR_TXE      BIT_ADDR(SPI2_BASE+0x08, 1)               /*!< Transmit buffer Empty */
#define  bSPI2_SR_CHSIDE   BIT_ADDR(SPI2_BASE+0x08, 2)               /*!< Channel side */
#define  bSPI2_SR_UDR      BIT_ADDR(SPI2_BASE+0x08, 3)               /*!< Underrun flag */
#define  bSPI2_SR_CRCERR   BIT_ADDR(SPI2_BASE+0x08, 4)               /*!< CRC Error flag */
#define  bSPI2_SR_MODF     BIT_ADDR(SPI2_BASE+0x08, 5)               /*!< Mode fault */
#define  bSPI2_SR_OVR      BIT_ADDR(SPI2_BASE+0x08, 6)               /*!< Overrun flag */
#define  bSPI2_SR_BSY      BIT_ADDR(SPI2_BASE+0x08, 7)               /*!< Busy flag */

/******************  Bit definition for SPI_I2SCFGR register  *****************/
#define  bSPI2_I2SCFGR_CHLEN     BIT_ADDR(SPI2_BASE+0x1C, 0)            /*!< Channel length (number of bits per audio channel) */


/******************************************************************************/
/*                                                                            */
/*                        TIM��ʱ���ӿڼĴ���                                  */
/*                                                                            */
/******************************************************************************/
//typedef struct
//{
//  __IO uint16_t CR1;    //0x00
//  uint16_t  RESERVED0;
//  __IO uint16_t CR2;		//0x04
//  uint16_t  RESERVED1;
//  __IO uint16_t SMCR;		//0x08
//  uint16_t  RESERVED2;
//  __IO uint16_t DIER;		//0x0C
//  uint16_t  RESERVED3;
//  __IO uint16_t SR;			//0x10
//  uint16_t  RESERVED4;
//  __IO uint16_t EGR;		//0x14
//  uint16_t  RESERVED5;
//  __IO uint16_t CCMR1;	//0x18
//  uint16_t  RESERVED6;
//  __IO uint16_t CCMR2;	//0x1C
//  uint16_t  RESERVED7;
//  __IO uint16_t CCER;		//0x20
//  uint16_t  RESERVED8;
//  __IO uint16_t CNT;		//0x24
//  uint16_t  RESERVED9;
//  __IO uint16_t PSC;		//0x28
//  uint16_t  RESERVED10;
//  __IO uint16_t ARR;		//0x2C
//  uint16_t  RESERVED11;
//  __IO uint16_t RCR;		//0x30
//  uint16_t  RESERVED12;
//  __IO uint16_t CCR1;		//0x34
//  uint16_t  RESERVED13;
//  __IO uint16_t CCR2;		//0x38
//  uint16_t  RESERVED14;
//  __IO uint16_t CCR3;		//0x3C
//  uint16_t  RESERVED15;
//  __IO uint16_t CCR4;		//0x40
//  uint16_t  RESERVED16;
//  __IO uint16_t BDTR;		//0x44
//  uint16_t  RESERVED17;
//  __IO uint16_t DCR;		//0x48
//  uint16_t  RESERVED18;
//  __IO uint16_t DMAR;		//0x4C
//  uint16_t  RESERVED19;
//}TIM_TypeDef;

#define bTimer1             (APB2PERIPH_BASE + 0x2C00)
#define bTimer2             (APB1PERIPH_BASE + 0x0000)
#define bTimer3             (APB1PERIPH_BASE + 10)
#define bTimer4             (APB1PERIPH_BASE + 11)
#define bTimer5             (APB1PERIPH_BASE + 0x0C00)
#define bTimer6             (APB1PERIPH_BASE + 12)
#define bTimer7             (APB1PERIPH_BASE + 0x1400)
#define bTimer8             (APB2PERIPH_BASE + 0x3400)


//����һ���µĳ��Է�ʽ�� ���ٺ궨��Ĺ�������ʹ������bCR1_CEN(Timer1) �����ã�Timer1Ϊ������ַ��
// #define  bCR1_CEN(TIMx_BASE)                   BIT_ADDR(TIMx_BASE+0x00,0)            /*!< Counter enable */
/*******************  TIM_CR1 ���ƼĴ���  ********************/
#define   CR1_CEN(TIMx_BASE)                         BIT_ADDR(TIMx_BASE +0x00,0)            /*!< Counter enable */
#define   CR1_UDIS(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x00,1)            /*!< Update disable */
#define   CR1_URS(TIMx_BASE)                         BIT_ADDR(TIMx_BASE +0x00,2)            /*!< Update request source */
#define   CR1_OPM(TIMx_BASE)                         BIT_ADDR(TIMx_BASE +0x00,3)            /*!< One pulse mode */
#define   CR1_DIR(TIMx_BASE)                         BIT_ADDR(TIMx_BASE +0x00,4)            /*!< ���򣬶��壺0�����������ϼ�������1�����������¼�������ע��������������Ϊ�������ģʽ�������ģʽʱ����λΪֻ�� */

#define 	SET_CR1_CMS(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x00)=(MEM_ADDR(TIMx_BASE+0x00)&(~TIM_CR1_CMS))|((a&0x03)<<5))
//  #define   CR1_CMS(TIMx_BASE)                         BIT_ADDR(TIMx_BASE +0x00,5)        /*!< CMS[1:0] �������ģʽѡ�񣬶��壺00�����ض���ģʽ�����������ݷ���λ(DIR)���ϻ����¼����� */
#define   CR1_CMS_0(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x00,5)            /*!< 01��10��11���������ģʽ1��2��3����������������Ϻ����¼���������*/
#define   CR1_CMS_1(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x00,6)            /*!<  */

#define   CR1_ARPE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x00,7)            /*!< Auto-reload preload enable */

#define 	SET_CR1_CKD(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x00)=(MEM_ADDR(TIMx_BASE+0x00)&(~TIM_CR1_CKD))|((a&0x03)<<8))
//  #define   CR1_CKD(TIMx_BASE)                         BIT_ADDR(TIMx_BASE +0x00,8)            /*!< CKD[1:0] CKD[1:0]ʱ�ӷ�Ƶ���ӣ������ڶ�ʱ��ʱ��(CK_INT)Ƶ���������˲���(ETR��TIx)ʹ�õĲ���Ƶ��֮��ķ�Ƶ������ */
#define   CR1_CKD_0(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x00,8)            /*!< ���壺00��tDTS = tCK_INT����01��tDTS = 2 x tCK_INT����10��tDTS = 4 x tCK_INT��11������ */
#define   CR1_CKD_1(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x00,9)            /*!< Bit 1 */

/*******************  TIM_CR2 ���ƼĴ���  ********************/
#define   CR2_CCPC(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,0)            /*!< Capture/Compare Preloaded Control */
#define   CR2_CCUS(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,2)            /*!< Capture/Compare Control Update Selection */
#define   CR2_CCDS(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,3)            /*!< Capture/Compare DMA Selection */

#define 	SET_CR2_MMS(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x04)=(MEM_ADDR(TIMx_BASE+0x04)&(~TIM_CR2_MMS))|((a&MASKb3)<<4))
//  #define   CR2_MMS(TIMx_BASE)                         BIT_ADDR(TIMx_BASE +0x04,4)            /*!< MMS[2:0] bits (Master Mode Selection) */

#define   CR2_TI1S(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,7)            /*!< TI1 Selection */
#define   CR2_OIS1(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,8)            /*!< Output Idle state 1 (OC1 output) */
#define   CR2_OIS1N(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x04,9)            /*!< Output Idle state 1 (OC1N output) */
#define   CR2_OIS2(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,10)            /*!< Output Idle state 2 (OC2 output) */
#define   CR2_OIS2N(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x04,11)            /*!< Output Idle state 2 (OC2N output) */
#define   CR2_OIS3(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,12)            /*!< Output Idle state 3 (OC3 output) */
#define   CR2_OIS3N(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x04,13)            /*!< Output Idle state 3 (OC3N output) */
#define   CR2_OIS4(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,14)            /*!< Output Idle state 4 (OC4 output) */

/*******************  Bit definition for TIM_SMCR register  *******************/
#define 	SET_SMCR_SMS(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x08)=(MEM_ADDR(TIMx_BASE+0x08)&(~TIM_SMCR_SMS))|((a&MASKb3)<<0))
//  #define   SMCR_SMS(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x08,0)            /*!< SMS[2:0] bits (Slave mode selection) */

#define 	SET_SMCR_TS(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x08)=(MEM_ADDR(TIMx_BASE+0x08)&(~TIM_SMCR_TS))|((a&MASKb3)<<4))
//  #define   SMCR_TS(TIMx_BASE)                         BIT_ADDR(TIMx_BASE +0x08,4)            /*!< TS[2:0] bits (Trigger selection) */

#define   SMCR_MSM(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x08,7)            /*!< Master/slave mode */

#define 	SET_SMCR_ETF(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x08)=(MEM_ADDR(TIMx_BASE+0x08)&(~TIM_SMCR_ETF))|((a&MASKb4)<<8))
//  #define   SMCR_ETF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x08,8)            /*!< ETF[3:0] bits (External trigger filter) */

#define 	SET_SMCR_ETPS(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x08)=(MEM_ADDR(TIMx_BASE+0x08)&(~TIM_SMCR_ETPS))|((a&MASKb2)<<12))
//  #define   SMCR_ETPS(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x08,12)            /*!< ETPS[1:0] bits (External trigger prescaler) */

#define   SMCR_ECE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x08,14)            /*!< External clock enable */
#define   SMCR_ETP(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x08,15)            /*!< External trigger polarity */

/*******************  Bit definition for TIM_DIER register  *******************/
#define   DIER_UIE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x0C,0)            /*!< Update interrupt enable */
#define   DIER_CC1IE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,1)            /*!< Capture/Compare 1 interrupt enable */
#define   DIER_CC2IE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,2)            /*!< Capture/Compare 2 interrupt enable */
#define   DIER_CC3IE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,3)            /*!< Capture/Compare 3 interrupt enable */
#define   DIER_CC4IE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,4)            /*!< Capture/Compare 4 interrupt enable */
#define   DIER_COMIE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,5)            /*!< COM interrupt enable */
#define   DIER_TIE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x0C,6)            /*!< Trigger interrupt enable */
#define   DIER_BIE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x0C,7)            /*!< Break interrupt enable */
#define   DIER_UDE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x0C,8)            /*!< Update DMA request enable */
#define   DIER_CC1DE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,9)            /*!< Capture/Compare 1 DMA request enable */
#define   DIER_CC2DE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,10)            /*!< Capture/Compare 2 DMA request enable */
#define   DIER_CC3DE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,11)            /*!< Capture/Compare 3 DMA request enable */
#define   DIER_CC4DE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,12)            /*!< Capture/Compare 4 DMA request enable */
#define   DIER_COMDE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,13)            /*!< COM DMA request enable */
#define   DIER_TDE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x0C,14)            /*!< Trigger DMA request enable */

/********************  TIM_SR ״̬�Ĵ���  ********************/
#define   SR_UIF(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x10,0)            /*!< �����жϱ�ǣ�Ӳ����1�������0�����壺0���޸����¼���1�������жϵȴ���Ӧ�����Ĵ���������ʱ��λ��Ӳ���á�1���� */
#define   SR_CC1IF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,1)            /*!< Capture/Compare 1 interrupt Flag */
#define   SR_CC2IF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,2)            /*!< Capture/Compare 2 interrupt Flag */
#define   SR_CC3IF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,3)            /*!< Capture/Compare 3 interrupt Flag */
#define   SR_CC4IF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,4)            /*!< Capture/Compare 4 interrupt Flag */
#define   SR_COMIF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,5)            /*!< COM interrupt Flag */
#define   SR_TIF(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x10,6)            /*!< Trigger interrupt Flag */
#define   SR_BIF(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x10,7)            /*!< Break interrupt Flag */
#define   SR_CC1OF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,9)            /*!< Capture/Compare 1 Overcapture Flag */
#define   SR_CC2OF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,10)            /*!< Capture/Compare 2 Overcapture Flag */
#define   SR_CC3OF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,11)            /*!< Capture/Compare 3 Overcapture Flag */
#define   SR_CC4OF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,12)            /*!< Capture/Compare 4 Overcapture Flag */

/*******************  Bit definition for TIM_EGR register  ********************/
#define   EGR_UG(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x14,0)               /*!< Update Generation */
#define   EGR_CC1G(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x14,1)               /*!< Capture/Compare 1 Generation */
#define   EGR_CC2G(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x14,2)               /*!< Capture/Compare 2 Generation */
#define   EGR_CC3G(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x14,3)               /*!< Capture/Compare 3 Generation */
#define   EGR_CC4G(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x14,4)               /*!< Capture/Compare 4 Generation */
#define   EGR_COMG(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x14,5)               /*!< Capture/Compare Control Update Generation */
#define   EGR_TG(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x14,6)               /*!< Trigger Generation */
#define   EGR_BG(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x14,7)               /*!< Break Generation */

/******************  Bit definition for TIM_CCMR1 register  *******************/
#define   CCMR1_CC1S(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x18,0)            /*!< CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define   CCMR1_CC1S_0(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,0)            /*!< Bit 0 */
#define   CCMR1_CC1S_1(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,1)            /*!< Bit 1 */

#define   CCMR1_OC1FE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,2)            /*!< Output Compare 1 Fast enable */
#define   CCMR1_OC1PE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,3)            /*!< Output Compare 1 Preload enable */

#define 	SET_CCMR1_OC1M(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x18)=(MEM_ADDR(TIMx_BASE+0x18)&(~TIM_CCMR1_OC1M))|((a&0x07)<<4))
//  #define   CCMR1_OC1M(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x18,4)            /*!< OC1M[2:0] bits (Output Compare 1 Mode) */

#define   CCMR1_OC1CE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,7)            /*!< Output Compare 1Clear Enable */

#define   CCMR1_CC2S(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x18,8)            /*!< CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define   CCMR1_CC2S_0(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,8)            /*!< Bit 0 */
#define   CCMR1_CC2S_1(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,9)            /*!< Bit 1 */

#define   CCMR1_OC2FE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,10)            /*!< Output Compare 2 Fast enable */
#define   CCMR1_OC2PE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,11)            /*!< Output Compare 2 Preload enable */

#define 	SET_CCMR1_OC2M(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x18)=(MEM_ADDR(TIMx_BASE+0x18)&(~TIM_CCMR1_OC2M))|((a&0x07)<<12))
//  #define   CCMR1_OC2M(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x18,12)            /*!< OC2M[2:0] bits (Output Compare 2 Mode) */

#define   CCMR1_OC2CE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,15)            /*!< Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/

#define   CCMR1_IC1PSC(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,2)            /*!< IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define   CCMR1_IC1PSC_0(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x18,2)            /*!< Bit 0 */
#define   CCMR1_IC1PSC_1(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x18,3)            /*!< Bit 1 */

#define 	SET_CCMR1_IC1F(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x18)=(MEM_ADDR(TIMx_BASE+0x18)&(~TIM_CCMR1_IC1F))|((a&0x0F)<<4))
//  #define   CCMR1_IC1F(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x18,4)            /*!< IC1F[3:0] bits (Input Capture 1 Filter) */

#define   CCMR1_IC2PSC(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,10)            /*!< IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define   CCMR1_IC2PSC_0(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x18,10)            /*!< Bit 0 */
#define   CCMR1_IC2PSC_1(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x18,11)            /*!< Bit 1 */

#define 	SET_CCMR1_IC2F(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x18)=(MEM_ADDR(TIMx_BASE+0x18)&(~TIM_CCMR1_IC2F))|((a&0x0F)<<12))
//  #define   CCMR1_IC2F(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x18,12)            /*!< IC2F[3:0] bits (Input Capture 2 Filter) */

/******************  Bit definition for TIM_CCMR2 register  *******************/
#define   CCMR2_CC3S(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x1C,0)            /*!< CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define   CCMR2_CC3S_0(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,0)            /*!< Bit 0 */
#define   CCMR2_CC3S_1(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,1)            /*!< Bit 1 */

#define   CCMR2_OC3FE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,2)            /*!< Output Compare 3 Fast enable */
#define   CCMR2_OC3PE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,3)            /*!< Output Compare 3 Preload enable */

#define 	SET_CCMR2_OC3M(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x1C)=(MEM_ADDR(TIMx_BASE+0x1C)&(~TIM_CCMR2_OC3M))|((a&0x07)<<4))
//  #define   CCMR2_OC3M(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x1C,4)            /*!< OC3M[2:0] bits (Output Compare 3 Mode) */


#define   CCMR2_OC3CE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,7)            /*!< Output Compare 3 Clear Enable */

#define   CCMR2_CC4S(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x1C,8)            /*!< CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define   CCMR2_CC4S_0(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,8)            /*!< Bit 0 */
#define   CCMR2_CC4S_1(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,9)            /*!< Bit 1 */

#define   CCMR2_OC4FE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,10)            /*!< Output Compare 4 Fast enable */
#define   CCMR2_OC4PE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,11)            /*!< Output Compare 4 Preload enable */

#define 	SET_CCMR2_OC4M(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x1C)=(MEM_ADDR(TIMx_BASE+0x1C)&(~TIM_CCMR2_OC4M))|((a&0x07)<<12))
//  #define   CCMR2_OC4M(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x1C,12)            /*!< OC4M[2:0] bits (Output Compare 4 Mode) */


#define   CCMR2_OC4CE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,15)            /*!< Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/

#define   CCMR2_IC3PSC(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,2)            /*!< IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define   CCMR2_IC3PSC_0(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x1C,2)            /*!< Bit 0 */
#define   CCMR2_IC3PSC_1(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x1C,3)            /*!< Bit 1 */

#define 	SET_CCMR2_IC3F(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x1C)=(MEM_ADDR(TIMx_BASE+0x1C)&(~TIM_CCMR2_IC3F))|((a&0x0f)<<4))
//  #define   CCMR2_IC3F(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x1C,4)            /*!< IC3F[3:0] bits (Input Capture 3 Filter) */

#define   CCMR2_IC4PSC(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,10)            /*!< IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define   CCMR2_IC4PSC_0(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x1C,10)            /*!< Bit 0 */
#define   CCMR2_IC4PSC_1(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x1C,11)            /*!< Bit 1 */

#define 	SET_CCMR2_IC4F(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x1C)=(MEM_ADDR(TIMx_BASE+0x1C)&(~TIM_CCMR2_IC4F))|((a&0x0f)<<12))
//#define   CCMR2_IC4F(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x1C,12)            /*!< IC4F[3:0] bits (Input Capture 4 Filter) */


/*******************  Bit definition for TIM_CCER register  *******************/
#define   CCER_CC1E(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,0)            /*!< Capture/Compare 1 output enable */
#define   CCER_CC1P(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,1)            /*!< Capture/Compare 1 output Polarity */
#define   CCER_CC1NE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,2)            /*!< Capture/Compare 1 Complementary output enable */
#define   CCER_CC1NP(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,3)            /*!< Capture/Compare 1 Complementary output Polarity */
#define   CCER_CC2E(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,4)            /*!< Capture/Compare 2 output enable */
#define   CCER_CC2P(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,5)            /*!< Capture/Compare 2 output Polarity */
#define   CCER_CC2NE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,6)            /*!< Capture/Compare 2 Complementary output enable */
#define   CCER_CC2NP(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,7)            /*!< Capture/Compare 2 Complementary output Polarity */
#define   CCER_CC3E(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,8)            /*!< Capture/Compare 3 output enable */
#define   CCER_CC3P(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,9)            /*!< Capture/Compare 3 output Polarity */
#define   CCER_CC3NE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,10)            /*!< Capture/Compare 3 Complementary output enable */
#define   CCER_CC3NP(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,11)            /*!< Capture/Compare 3 Complementary output Polarity */
#define   CCER_CC4E(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,12)            /*!< Capture/Compare 4 output enable */
#define   CCER_CC4P(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,13)            /*!< Capture/Compare 4 output Polarity */
#define   CCER_CC4NP(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,15)            /*!< Capture/Compare 4 Complementary output Polarity */

/*******************  Bit definition for TIM_CNT register  ********************/
#define   CNT_CNT(TIMx_BASE)           (MEM_ADDR(TIMx_BASE+0x24))    /*!< Counter Value */             

/*******************  Bit definition for TIM_PSC register  ********************/
#define   PSC_PSC(TIMx_BASE)           (MEM_ADDR(TIMx_BASE+0x28))            /*!< Prescaler Value */

/*******************  Bit definition for TIM_ARR register  ********************/
#define   ARR_ARR(TIMx_BASE)           (MEM_ADDR(TIMx_BASE+0x2C))            /*!< actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  ********************/
#define   RCR_REP(TIMx_BASE)           (MEM_ADDR(TIMx_BASE+0x30))               /*!< Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  *******************/
#define   CCR1_CCR1(TIMx_BASE)         (MEM_ADDR(TIMx_BASE+0x34))           /*!< Capture/Compare 1 Value */

/*******************  Bit definition for TIM_CCR2 register  *******************/
#define   CCR2_CCR2(TIMx_BASE)         (MEM_ADDR(TIMx_BASE+0x38))            /*!< Capture/Compare 2 Value */

/*******************  Bit definition for TIM_CCR3 register  *******************/
#define   CCR3_CCR3(TIMx_BASE)         (MEM_ADDR(TIMx_BASE+0x3C))            /*!< Capture/Compare 3 Value */

/*******************  Bit definition for TIM_CCR4 register  *******************/
#define   CCR4_CCR4(TIMx_BASE)         (MEM_ADDR(TIMx_BASE+0x40))            /*!< Capture/Compare 4 Value */

/*******************  Bit definition for TIM_BDTR register  *******************/
/*!< DTG[0:7] bits (Dead-Time Generator set-up) */
#define 	SET_BDTR_DTG(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x44)=(MEM_ADDR(TIMx_BASE+0x44)&(~TIM_BDTR_DTG))|((a&MASKb8)<<0))

#define   BDTR_LOCK(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x44,8)            /*!< LOCK[1:0] bits (Lock Configuration) */
#define   BDTR_LOCK_0(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x44,8)            /*!< Bit 0 */
#define   BDTR_LOCK_1(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x44,9)            /*!< Bit 1 */

#define   BDTR_OSSI(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x44,10)            /*!< Off-State Selection for Idle mode */
#define   BDTR_OSSR(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x44,11)            /*!< Off-State Selection for Run mode */
#define   BDTR_BKE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x44,12)            /*!< Break enable */
#define   BDTR_BKP(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x44,13)            /*!< Break Polarity */
#define   BDTR_AOE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x44,14)            /*!< Automatic Output enable */
#define   BDTR_MOE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x44,15)            /*!< Main Output enable */

/*******************  Bit definition for TIM_DCR register  ********************/
/*!< DBA�ӵ�0BIT��ʼ��5λ�� (DMA Base Address) */
#define 	SET_DCR_DBA(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x48)=(MEM_ADDR(TIMx_BASE+0x48)&(~TIM_DCR_DBA))|((a&MASKb5)<<0))
/*!< DBL�ӵ�8BIT��ʼ��5λ�� (DMA Burst Length) */
#define 	SET_DCR_DBL(TIMx_BASE,a)   (MEM_ADDR(TIMx_BASE+0x48)=(MEM_ADDR(TIMx_BASE+0x48)&(~TIM_DCR_DBL))|((a&MASKb5)<<8))


/*******************  Bit definition for TIM_DMAR register  *******************/
#define   DMAR_DMAB(TIMx_BASE)       (MEM_ADDR(TIMx_BASE+0x4C))            /*!< DMA register for burst accesses */

/*************************************************************************************************************************/
#endif

