#ifndef __MYBITBAND_H
#define __MYBITBAND_H	  
#include <stm32f10x.h>  
/****************************** ������ʵ�ֵļĴ���λ����ģʽ ***************************************/
// ���ñ��ļ������ԱȽϷ������Ч��׼����λ�η�ʽ���ʼĴ�������϶�BIT���ʵȷ�ʽ���ܹ�������ȫ�׿��⺯����
// һ��������ԭ������Ϊ����������������ǰ���ǰ׺b, ��⺯�����ֵ�ͬʱ��ָʾ������bitband������
// ������һ��ǿ�����ǣ������־���Ĵ�����������,�����ж�����ƼĴ���CR1��CR2��CR3����ͳһʡ��ΪCR�����ؼ����ǵڼ���CR��
// ���Զ��ڳ��õ�������RCC����һ�����ݹ��ܽ����˸��죬���罫����ʹ��ʱ�ӿ��ƹ��ɳ�bRCC_ENABLE_XXX������XXXΪ����������
// ���ڼ��䣬�����ٿ���ĳ��������������������ϵ�ϸ�ڣ��൱�ڽ�����һ��С�Ķ��η�װ��
// ����BITλ�����ƾ�������ԭ���ƣ��Ա���ղ��������ֲᡣ�Ĵ�����ַƫ������һ���û��ֲ���ʮ��������䡣
// �ġ����ǵ�λ�����������ھ�׼��Ч�ض�λ���в�������Ҳ�Ǳ�д���ļ��ĳ����㡣�����ǵ���λ���ϵ���ϲ���Ҳ�޷����⣬����ֱ�ӷ��ʼĴ���ĳ��λҲ�Ƚ��鷳��
// ������ô��εĺ궨���ƶ���ͳһ�ķ��ʸ�ʽ.
// �塢����һ��û��λ���壬ͨ�����ַ��ʵļĴ���������Ҳ����������BKP_DR1�ĺ�ָ�ʽ������з��ʣ� ����BKP_DR1��Ч����ͬ�ڼĴ���ֱ�ӷ��ʵ�BKP->DR1
// CopyRight By Warship
// Modified date: 20180916

/******************** λ�β���ͳһ��ʽ *******************************************
��BITλ���ʷ�ʽ��
		bRCC_ENABLE_RTC=1��0; 						//Ψһ����
		bTIM_CR_DIR��bTIMx)=1��0;						//��������
		bGPIO_BRR(bGPIOx,n)=1��0;							//�����������˿�

��BITλ���ʷ�ʽ��
		SET_RCC_PLLMUL(a);	д	 					//Ψһ����
		GET_RCC_PLLMUL;			��

		SET_SPI_CR_BR(bSPIx,a);	д						//��������
		GET_SPI_CR_BR(bSPIx);		��		

*************************************************************************/

//Ϊ���ٺ궨��Ĺ����������ڶ����ͬ�����裬�������������ϣ��綨ʱ��������ͨ�ŵȣ�����������Ƶĺ궨��
//ʹ�ô������ĺ꣬����bCR_CEN(bTIM1),����TIM1Ϊ��ַ��
//���¶����ͳһ��b��ͷ�Ļ�ַ�ֱ꣬��������stm32f10x.h�ж����xxx_BASE,
//Ҳ���Բ�����Щ���壬ֱ��ʹ��xxx_BASE

#define bURT1             USART1_BASE  
#define bURT2             USART2_BASE
#define bURT3             USART3_BASE
#define bURT4             UART4_BASE
#define bURT5             UART5_BASE

#define bTIM1             TIM1_BASE
#define bTIM2             TIM2_BASE
#define bTIM3             TIM3_BASE
#define bTIM4             TIM4_BASE
#define bTIM5             TIM5_BASE
#define bTIM6             TIM6_BASE
#define bTIM7             TIM7_BASE
#define bTIM8             TIM8_BASE
#define bTIM9            	TIM9_BASE
#define bTIM10            TIM10_BASE
#define bTIM11            TIM11_BASE
#define bTIM12            TIM12_BASE
#define bTIM13            TIM13_BASE
#define bTIM14            TIM14_BASE
#define bTIM15            TIM15_BASE
#define bTIM16            TIM16_BASE
#define bTIM17            TIM17_BASE

#define bSPI1							SPI1_BASE
#define bSPI2							SPI2_BASE
#define bSPI3							SPI3_BASE

#define bI2C1							I2C1_BASE
#define bI2C2							I2C2_BASE

#define bCAN1							CAN1_BASE
#define bCAN2							CAN2_BASE

#define bDMA1							DMA1_BASE
#define bDMA2							DMA2_BASE

#define bADC1							ADC1_BASE
#define bADC2							ADC2_BASE
#define bADC3							ADC3_BASE


//��BITλ����궨��
#define 	MASKb1			((uint32_t)0x00000001)
#define 	MASKb2			((uint32_t)0x00000003)
#define 	MASKb3			((uint32_t)0x00000007)
#define 	MASKb4			((uint32_t)0x0000000F)
#define 	MASKb5			((uint32_t)0x0000001F)
#define 	MASKb6			((uint32_t)0x0000003F)
#define 	MASKb7			((uint32_t)0x0000007F)
#define 	MASKb8			((uint32_t)0x000000FF)
#define 	MASKb9			((uint32_t)0x000001FF)
#define 	MASKb10			((uint32_t)0x000003FF)
#define 	MASKb11			((uint32_t)0x000007FF)
#define 	MASKb12			((uint32_t)0x00000FFF)
#define 	MASKb13			((uint32_t)0x00001FFF)
#define 	MASKb14			((uint32_t)0x00003FFF)
#define 	MASKb15			((uint32_t)0x00007FFF)
#define 	MASKb16			((uint32_t)0x0000FFFF)
#define 	MASKb17			((uint32_t)0x0001FFFF)
#define 	MASKb18			((uint32_t)0x0003FFFF)
#define 	MASKb19			((uint32_t)0x0007FFFF)
#define 	MASKb20			((uint32_t)0x000FFFFF)
#define 	MASKb21			((uint32_t)0x001FFFFF)
#define 	MASKb22			((uint32_t)0x003FFFFF)
#define 	MASKb23			((uint32_t)0x007FFFFF)
#define 	MASKb24			((uint32_t)0x00FFFFFF)
#define 	MASKb25			((uint32_t)0x01FFFFFF)
#define 	MASKb26			((uint32_t)0x03FFFFFF)
#define 	MASKb27			((uint32_t)0x07FFFFFF)
#define 	MASKb28			((uint32_t)0x0FFFFFFF)
#define 	MASKb29			((uint32_t)0x1FFFFFFF)
#define 	MASKb30			((uint32_t)0x3FFFFFFF)
#define 	MASKb31			((uint32_t)0x7FFFFFFF)
#define 	MASKb32			((uint32_t)0xFFFFFFFF)

//�Ĵ�����λ���ʺ궨�壺�������Ĵ�����ַ����ʼ����λ�����루λ����������ֵ��
//�����岻����λ��ʹ�ã������κ��ض���ַ�Ĵ洢��������
#define SET_REG_BITn(REG_ADDR,Sbit,MASKn,a)  	(MEM_ADDR(REG_ADDR)=(MEM_ADDR(REG_ADDR)&(~(MASKn<<Sbit)))|((a & MASKn)<<Sbit))
#define GET_REG_BITn(REG_ADDR,Sbit,MASKn)   	((MEM_ADDR(REG_ADDR)>>Sbit)& MASKn)

/******************************************************************************/
/*                                                                            */
/*                    PWR�Ĵ���--��Դ���ƼĴ���                               */
/*                                                                            */
/******************************************************************************/
//PWR_CR--��Դ���ƼĴ���
#define  bPWR_CR_LPDS          BIT_ADDR(PWR_BASE, 0)     //��˯���µĵ͹��ģ�PDDS=0ʱ����PDDSλЭͬ���������壺0���ڴ���ģʽ�µ�ѹ��ѹ����������1���ڴ���ģʽ�µ�ѹ��ѹ�����ڵ͹���ģʽ��
#define  bPWR_CR_PDDS          BIT_ADDR(PWR_BASE, 1)     //������˯�ߣ���LPDSλЭͬ���������壺0����CPU������˯��ʱ����ͣ��ģʽ����ѹ��״̬��LPDSλ���ƣ���1��CPU������˯��ʱ�������ģʽ��
#define  bPWR_CR_CWUF          BIT_ADDR(PWR_BASE, 2)     //�������λ��ʼ�����Ϊ0�����壺0����Ч����1��2��ϵͳʱ�����ں����WUF����λ��д��
#define  bPWR_CR_CSBF          BIT_ADDR(PWR_BASE, 3)     //�������λ��ʼ�����Ϊ0�����壺0����Ч����1�����SBF����λ��д��
#define  bPWR_CR_PVDE          BIT_ADDR(PWR_BASE, 4)     //��Դ��ѹ�������PVD��ʹ�ܡ����壺0����ֹPVD����1������PVD��
#define  bPWR_CR_DBP           BIT_ADDR(PWR_BASE, 8)     //ȡ��������д��������λֵΪ0�����壺0Ϊ��ֹд�룬1Ϊ����д�롣ע�����rtcʱ����HSE/128�����뱣��Ϊ1

//#define  PWR_CR_PLS  ����3BIT����PVD��ѹ��ֵ
#define  SET_PWR_CR_PLS(a)   SET_REG_BITn(PWR_BASE,5,MASK3,a)
//PVD��ѹ��ֵ,ʾ��������2.5V��ѹ��ֵʱʹ��SET_PWR_CR_PLS(PVD_2V5);
#define  PVD_2V2	0x000
#define  PVD_2V3	0x001
#define  PVD_2V4	0x010
#define  PVD_2V5	0x011
#define  PVD_2V6	0x100
#define  PVD_2V7	0x101
#define  PVD_2V8	0x110
#define  PVD_2V9	0x111


//PWR_CSR--��Դ����״̬�Ĵ���
#define  bPWR_CSR_WUF           BIT_ADDR(PWR_BASE+4, 0) //���ѱ�־����λ��Ӳ�����ã���ֻ����POR/PDR���ϵ�/���縴λ�������õ�Դ���ƼĴ�����PWR_CR����CWUFλ�����
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

//RCC_CR--ʱ�ӿ��ƼĴ���
#define  bRCC_CLK_HSION        BIT_ADDR(RCC_BASE, 0) //LSIʱ��: 0����,1����
#define  bRCC_CLK_HSIRDY       BIT_ADDR(RCC_BASE, 1) //LSIʱ��״̬��Ӳ������(ֻ��):0������,1����
#define  bRCC_CLK_HSEON        BIT_ADDR(RCC_BASE, 16) //HSEʱ��: 0����,1����
#define  bRCC_CLK_HSERDY       BIT_ADDR(RCC_BASE, 17) //HSEʱ��״̬��Ӳ������(ֻ��):0������,1����
#define  bRCC_CLK_HSEBYP       BIT_ADDR(RCC_BASE, 18) //�ⲿʱ����·(������)-- 0����·  1��·
#define  bRCC_CLK_CSSON     	BIT_ADDR(RCC_BASE, 19) //ϵͳʱ�Ӱ�ȫϵͳʹ��  0ʱ�Ӽ�����  1�ⲿʱ�Ӿ������������
#define  bRCC_CLK_PLLON       BIT_ADDR(RCC_BASE, 24) //PLL��Ƶ: 0����,1����
#define  bRCC_CLK_PLLRDY      BIT_ADDR(RCC_BASE, 25) //PLL��Ƶ״̬��Ӳ������(ֻ��):0������,1����
//5BIT��HSITRIM  �ڲ�����ʱ�ӵ���  ���ڲ������¶ȵȱ仯���ڲ�RC����ʱ��Ƶ�ʵ�Ӱ��.
#define  SET_RCC_CLK_HSITRIM(a)   SET_REG_BITn(RCC_BASE,3,MASKb5,a)
//8BIT��HSICAL  �ڲ�����ʱ��У׼  
#define  SET_RCC_CLK_HSICAL(a)   SET_REG_BITn(RCC_BASE,8,MASKb8,a)

//RCC_CFGR--ʱ�����üĴ���
#define  SET_RCC_CONFIG_SW(a)   SET_REG_BITn(RCC_BASE+0x04,0,MASKb2,a)
#define  bRCC_CONFIG_SW0        BIT_ADDR(RCC_BASE+0x04, 0) //ϵͳʱ��ѡ��2BIT-- 00:HSI  01:HSE
#define  bRCC_CONFIG_SW1        BIT_ADDR(RCC_BASE+0x04, 1) //                  10:PLL  11: ��Ч 
#define  bRCC_CONFIG_SW_PLL   	BIT_ADDR(RCC_BASE+0x04, 1) //SYSCLKʱ��ѡ��λ1����λʱΪѡ��PLL��Ϊϵͳʱ��Դ

//ϵͳʱ��Դָʾ,ֻ��: ����ͬ��
#define  GET_RCC_CONFIG_SW   GET_REG_BITn(RCC_BASE+0x04,2,MASKb2)
#define  bRCC_CONFIG_SWS0        BIT_ADDR(RCC_BASE+0x04, 2) 
#define  bRCC_CONFIG_SWS1        BIT_ADDR(RCC_BASE+0x04, 3) //

#define  bRCC_CONFIG_SWS_PLL   		BIT_ADDR(RCC_BASE+0x04, 3)  //SYSCLKʱ��ָʾλ1��Ϊ1ʱָʾPLL�Ѿ�Ϊϵͳʱ��Դ
#define  bRCC_CONFIG_PLLSRC       BIT_ADDR(RCC_BASE+0x04, 16) //PLL��Դѡ��, 0: HSI/2  1:HSE��PREDIV1�������
#define  bRCC_CONFIG_PLLXTPRE     BIT_ADDR(RCC_BASE+0x04, 17) //�����PLL��HSE�Ƿ��Ƶ 0:����Ƶ  1:����Ƶ
#define  bRCC_CONFIG_USBPRE       BIT_ADDR(RCC_BASE+0x04, 22) //USBԤ��Ƶ���� 0: PLL/1.5   1: PLL

//ϵͳʱ��ѡ��
#define  SET_RCC_SW(a)  SET_REG_BITn(RCC_BASE+0x04,0,MASKb2,a) 
#define  GET_RCC_SW			GET_REG_BITn(RCC_BASE+0x04,0,MASKb2)
#define  SW_HSI                     0       /*!< HSI �ڲ�����ʱ�ӱ�ѡ��Ϊϵͳʱ�� */
#define  SW_HSE                     1       /*!< HSE �ⲿ����ʱ�ӱ�ѡ��Ϊϵͳʱ�� */
#define  SW_PLL                     2       /*!< PLL ���໷�������ѡ��Ϊϵͳʱ�� */


//4BIT��HPRE����λ: ����ϵͳʱ��SYSCLK��Ƶ��AHB
///*!< HPRE BIT7:4 */
#define  SET_RCC_HPRE(a)   SET_REG_BITn(RCC_BASE+0x04,4,MASKb4,a)
#define  GET_RCC_HPRE		   GET_REG_BITn(RCC_BASE+0x04,4,MASKb4)
#define  HPRE_DIV1                  0        /*!< SYSCLK not divided */
#define  HPRE_DIV2                  1        /*!< SYSCLK divided by 2 */
#define  HPRE_DIV4                  3        /*!< SYSCLK divided by 4 */
#define  HPRE_DIV8                  4        /*!< SYSCLK divided by 8 */
#define  HPRE_DIV16                 5        /*!< SYSCLK divided by 16 */
#define  HPRE_DIV64                 6        /*!< SYSCLK divided by 64 */
#define  HPRE_DIV128                7        /*!< SYSCLK divided by 128 */
#define  HPRE_DIV256                8        /*!< SYSCLK divided by 256 */
#define  HPRE_DIV512                9        /*!< SYSCLK divided by 512 */

/*!< PPRE1 BIT10:8 ��3BIT��PPRE1����λ: ������APB1��Ԥ��Ƶ*/ 
#define  SET_RCC_HPRE1(a)   	SET_REG_BITn(RCC_BASE+0x04,8,MASKb3,a)
#define  GET_RCC_HPRE1		   	GET_REG_BITn(RCC_BASE+0x04,8,MASKb3)
//ȡֵ�������£�
#define  PPRE1_DIV1                 0        /*!< HCLK not divided */
#define  PPRE1_DIV2                 4        /*!< HCLK divided by 2 */
#define  PPRE1_DIV4                 5        /*!< HCLK divided by 4 */
#define  PPRE1_DIV8                 6        /*!< HCLK divided by 8 */
#define  PPRE1_DIV16                7        /*!< HCLK divided by 16 */

/*!< PPRE2 BIT13:11 ��3BIT��PPRE2����λ: ������APB2��Ԥ��Ƶ*/
#define  SET_RCC_HPRE2(a)   	SET_REG_BITn(RCC_BASE+0x04,11,MASKb3,a)
#define  GET_RCC_HPRE2		   	GET_REG_BITn(RCC_BASE+0x04,11,MASKb3)
//ȡֵ�������£�
#define  PPRE2_DIV1                 0        /*!< HCLK ����Ƶ */
#define  PPRE2_DIV2                 4        /*!< HCLK 2��Ƶ */
#define  PPRE2_DIV4                 5        /*!< HCLK 4��Ƶ */
#define  PPRE2_DIV8                 6        /*!< HCLK 8��Ƶ */
#define  PPRE2_DIV16                7        /*!< HCLK 16��Ƶ */

/*!< ADCPPRE BIT15:14 ������ADC��Ԥ��Ƶ */
#define  SET_RCC_ADCPRE(a)   	SET_REG_BITn(RCC_BASE+0x04,14,MASKb2,a)
#define  GET_RCC_ADCPRE		   	GET_REG_BITn(RCC_BASE+0x04,14,MASKb2)
//ȡֵ�������£�
#define  ADCPRE_DIV2                0        /*!< PCLK2 2��Ƶ */
#define  ADCPRE_DIV4                1        /*!< PCLK2 4��Ƶ */
#define  ADCPRE_DIV6                2        /*!< PCLK2 6��Ƶ */
#define  ADCPRE_DIV8                3        /*!< PCLK2 8��Ƶ */

//4BIT(BIT18:21)��PLLMUL:ѡ��PLL�ı�Ƶ��,2-16
#define  SET_RCC_PLLMUL(a)   	SET_REG_BITn(RCC_BASE+0x04,18,MASKb4,a)
#define  GET_RCC_PLLMUL		   	GET_REG_BITn(RCC_BASE+0x04,18,MASKb4)
//ȡֵ�������£�
#define  PLLMULL2                  0        /*!< PLL 2��Ƶ */
#define  PLLMULL3                  1        /*!< PLL 3��Ƶ */
#define  PLLMULL4                  2       /*!< PLL 4��Ƶ */
#define  PLLMULL5                  3        /*!< PLL 5��Ƶ */
#define  PLLMULL6                  4        /*!< PLL 6��Ƶ */
#define  PLLMULL7                  5        /*!< PLL 7��Ƶ */
#define  PLLMULL8                  6        /*!< PLL 8��Ƶ */
#define  PLLMULL9                  7        /*!< PLL 9��Ƶ */
#define  PLLMULL10                 8        /*!< PLL 10��Ƶ */
#define  PLLMULL11                 9        /*!< PLL 11��Ƶ */
#define  PLLMULL12                 10        /*!< PLL 12��Ƶ */
#define  PLLMULL13                 11        /*!< PLL 13��Ƶ */
#define  PLLMULL14                 12        /*!< PLL 14��Ƶ */
#define  PLLMULL15                 13        /*!< PLL 15��Ƶ */
#define  PLLMULL16                 14        /*!< PLL 16��Ƶ */

///*!< MCO configuration ע�ⲻͬ��оƬ�в���  3BIT��MCO����λ: ��MCU���ʱ�ӵ�ѡ����п���  */     
#define  SET_RCC_MCO(a)   	SET_REG_BITn(RCC_BASE+0x04,24,MASKb3,a)
//ȡֵ�������£�
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
#define  bRCC_ENABLE_FSMC                	 BIT_ADDR(RCC_BASE+0x14, 8)  
#define  bRCC_ENABLE_SDIO                	 BIT_ADDR(RCC_BASE+0x14, 10) 

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
//��������ƼĴ����� (RCC_BDCR) �� LSEON �� LSEBYP �� RTCSEL �� RTCEN λ���ڱ�������
//�ˣ���Щλ�ڸ�λ����д����״̬��ֻ���ڵ�Դ���ƼĴ��� (PWR_CR) �е� DBP λ�� ��1�� ���
//�ܶ���Щλ���иĶ���
#define  bRCC_CLK_LSEON                  BIT_ADDR(RCC_BASE+0x20, 0)  //LSEʱ��: 0����,1����
#define  bRCC_CLK_LSERDY                 BIT_ADDR(RCC_BASE+0x20, 1) //LSEʱ��״̬��Ӳ������(ֻ��):0������,1����
#define  bRCC_CLK_LSEBYP                 BIT_ADDR(RCC_BASE+0x20, 2) //LSEʱ��״̬��Ӳ������(ֻ��):0������,1����

#define  SET_RCC_CLK_RTCSEL(a)   	SET_REG_BITn(RCC_BASE+0x20,8,MASKb2,a)
#define  bRCC_CLK_RTCSEL0                BIT_ADDR(RCC_BASE+0x20, 8) 		//RTCʱ��Դѡ����λ��ͬ����: 00:��ʱ�� 01:LSE
#define  bRCC_CLK_RTCSEL1                BIT_ADDR(RCC_BASE+0x20, 9) 		//                      10:LSI   11: HSE/128 

#define  bRCC_ENABLE_RTC                 BIT_ADDR(RCC_BASE+0x20, 15)  	//0����RTC; 1:ʹ��RTC
#define  bRCC_RESET_BKUPDOMAIN           BIT_ADDR(RCC_BASE+0x20, 16)   	//����������λ  д1��λ 0��λδ������

//RCC_CSR�Ĵ���--״̬�����
#define  bRCC_CLK_LSION                   BIT_ADDR(RCC_BASE+0x24, 0)   	//LSIʱ��: 0����,1����
#define  bRCC_CLK_LSIRDY                  BIT_ADDR(RCC_BASE+0x24, 1)   	//LSIʱ��״̬��Ӳ������(ֻ��):0������,1����
#define  bRCC_FLG_RMVF                    BIT_ADDR(RCC_BASE+0x24, 24) 	//�����λ��־ д0��λδ����ĸ�λ��־,д1���帴λ��־
#define  bRCC_FLG_PINRSTF                 BIT_ADDR(RCC_BASE+0x24, 26)  	//���Ÿ�λ��־  Ӳ����1���дRMVFλ��0
#define  bRCC_FLG_PORRSTF                 BIT_ADDR(RCC_BASE+0x24, 27)  	//�˿ڸ�λ��־  Ӳ����1���дRMVFλ��0
#define  bRCC_FLG_SFTRSTF                 BIT_ADDR(RCC_BASE+0x24, 28)  	//�����λ��־  Ӳ����1���дRMVFλ��0
#define  bRCC_FLG_IWDGRSTF                BIT_ADDR(RCC_BASE+0x24, 29)  	//�������Ź���λ��־  Ӳ����1���дRMVFλ��0
#define  bRCC_FLG_WWDGRSTF                BIT_ADDR(RCC_BASE+0x24, 30)		//���ڿ��Ź���λ��־  Ӳ����1���дRMVFλ��0
#define  bRCC_FLG_LPWRRSTF                BIT_ADDR(RCC_BASE+0x24, 31)		//�͹��Ĺ���λ��־  Ӳ����1���дRMVFλ��0 

/******************************************************************************/
/*                                                                            */
/*                         AFIO�Ĵ���                                         */
/*                                                                            */
/******************************************************************************/

//AFIO_EVCR--�¼����ƼĴ���
#define  bAFIO_EVCR_EVOE        		BIT_ADDR(AFIO_BASE, 7) 			//�¼����ʹ��. Ϊ1ʱ,�¼���ָ���Ķ˿����(�˿���BIT6:4,������BIT3:0����)
#define  SET_AFIO_EVCR_PIN(a)   	SET_REG_BITn(AFIO_BASE,0,MASKb4,a)	//�¼����ָ��������(�˿���BIT6:4,������BIT3:0����)
#define  SET_AFIO_EVCR_PORT(a)   	SET_REG_BITn(AFIO_BASE,4,MASKb3,a)	//�¼����ָ���Ķ˿�(�˿���BIT6:4,������BIT3:0����)
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
#define  bAFIO_MAPR_TIM4_REMAP      				BIT_ADDR(AFIO_BASE+4, 12) //ֻ����100���ŷ�װ��TIM4��ͨ��1-4��ӳ��. 0����,1��ԭ����PB6/7/8/9ӳ�䵽PD12/13/14/15
#define  bAFIO_MAPR_CAN_REMAPb0      				BIT_ADDR(AFIO_BASE+4, 13) //��BIT����: 
#define  bAFIO_MAPR_CAN_REMAPb1      				BIT_ADDR(AFIO_BASE+4, 14) //
#define  bAFIO_MAPR_PD01_REMAP      				BIT_ADDR(AFIO_BASE+4, 15) //0����, 1 PD0/1�˿ڷֱ�ӳ��OSC_IN/OSC_OUT����
//�����ǲ�������������ӳ�䶨��
#define  bAFIO_MAPR_TIM5CH4_IREMAP      		BIT_ADDR(AFIO_BASE+4, 16) /*!< TIM5 Channel4 Internal Remap */
#define  bAFIO_MAPR_ADC1_ETRGINJ_REMAP      BIT_ADDR(AFIO_BASE+4, 17) /*!< ADC 1 External Trigger Injected Conversion remapping */
#define  bAFIO_MAPR_ADC1_ETRGREG_REMAP      BIT_ADDR(AFIO_BASE+4, 18) /*!< ADC 1 External Trigger Regular Conversion remapping */
#define  bAFIO_MAPR_ADC2_ETRGINJ_REMAP      BIT_ADDR(AFIO_BASE+4, 19) /*!< ADC 2 External Trigger Injected Conversion remapping */
#define  bAFIO_MAPR_ADC2_ETRGREG_REMAP      BIT_ADDR(AFIO_BASE+4, 20) /*!< ADC 2 External Trigger Regular Conversion remapping */
#define  bAFIO_MAPR_ETH_REMAP      					BIT_ADDR(AFIO_BASE+4, 21) /*!< SPI3_REMAP bit (Ethernet MAC I/O remapping) */
#define  bAFIO_MAPR_CAN2_REMAP      				BIT_ADDR(AFIO_BASE+4, 22) /*!< CAN2_REMAP bit (CAN2 I/O remapping) */
#define  bAFIO_MAPR_MII_RMII_SEL      			BIT_ADDR(AFIO_BASE+4, 23) /*!< MII_RMII_SEL bit (Ethernet MII or RMII selection) */
#define  bAFIO_MAPR_SPI3_REMAP      				BIT_ADDR(AFIO_BASE+4, 28)  /*!< SPI3_REMAP bit (SPI3 remapping) */
#define  bAFIO_MAPR_TIM2ITR1_IREMAP      		BIT_ADDR(AFIO_BASE+4, 29) /*!< TIM2ITR1_IREMAP bit (TIM2 internal trigger 1 remapping) */
#define  bAFIO_MAPR_PTP_PPS_REMAP      			BIT_ADDR(AFIO_BASE+4, 30) /*!< PTP_PPS_REMAP bit (Ethernet PTP PPS remapping) */

#define  SET_AFIO_MAPR_SWJ_CFG(a)   				SET_REG_BITn(AFIO_BASE+4,24,MASKb3,a)
//3BIT���ƴ���JTAG����(ֻд):000����ȫSWJ����λ״̬����001����ȫSWJ����û��NJTRST����
//010���ر�JATG����SW����100���ر�JATG���ر�SW������ֵ�޶���
//
//AFIO_EXTICR1-4--�ⲿ�ж����üĴ���
//4���ⲿ�ж����üĴ���EXTICR1-4, ����16���ж��ߵĶ˿���(�ֱ���4BIT����PA��PB/....../PG)��ѡ��.
#define  SET_AFIO_EXTICR(EXTI_n,a)   	SET_REG_BITn(AFIO_BASE+0x08+(EXTI_n&0x0c),(EXTI_n&0x03)<<2,MASKb4,a)
//���磺��EXTI2ΪPD2����ʹ��SET_AFIO_EXTICR(2,GPIO_D);
//***********����Ϊ���������֤�ݸ壬��ɾ��
//EXTIn		(EXTI_n&0x0c)	(EXTIn&0x03)<<2
//0				0							0
//1				0							4
//2				0							8
//3				0							C
//4				4							0
//5				4							4
//6				4							8
//7				4							C
//8				8							0
//9				8							4
//10			8							8
//11			8							C
//12			C							0
//13			C							4	
//14			C							8
//15			C							C

/******************************************************************************/
/*                                                                            */
/*                         GPIOx�Ĵ���                                        */
/*                                                                            */
/******************************************************************************/
//GPIO���й���������λ����,�����ô�ҹ㷺ʹ�õ�PAout(n)......PCin(n)�ķ�ʽ��

//��GPIO�Ķ˿�����: ÿ�߲���4BIT,���������º궨�壺
#define  SET_GPIO_CR(GPIOx_BASE,PINx,mode)   	SET_REG_BITn(GPIOx_BASE+(PINx>>3)*4,(PINx & 0x07)<<2,MASKb4,mode)
//���е�modeȡֵ���£�
//	0					ģ������ AIN
//	4					�������� IN_FLOATING
//	8					����/��������(��IPU��IPD������ֵһ����������밴Ҫ��Ԥ�ö˿�Ϊ1��0)

//	3	��2/1��	ͨ���������50MHz��2/10MHz��Out_PP
//	7	��6/5��	ͨ�ÿ�©���50MHz��2/10MHz��Out_OD
//	B ��A/9��	�����������50MHz��2/10MHz��AF_PP
//	F	��E/D��	���ÿ�©���50MHz��2/10MHz��AF_OD

//GPIO�Ķ˿�������������GPIOx_LCKR�Ĵ���,�ʺϲ���λ������ʽ,��һ��˹��ܲ�����.
#define  bGPIOA_BSRR(n)   BIT_ADDR(GPIOA_BASE+0x10, n)
#define  bGPIOB_BSRR(n)   BIT_ADDR(GPIOB_BASE+0x10, n)
#define  bGPIOC_BSRR(n)   BIT_ADDR(GPIOC_BASE+0x10, n)
#define  bGPIOD_BSRR(n)   BIT_ADDR(GPIOD_BASE+0x10, n)
#define  bGPIOE_BSRR(n)   BIT_ADDR(GPIOE_BASE+0x10, n)
#define  bGPIOF_BSRR(n)   BIT_ADDR(GPIOF_BASE+0x10, n)
#define  bGPIOG_BSRR(n)   BIT_ADDR(GPIOG_BASE+0x10, n)
#define  bGPIOA_BRR(n)   	BIT_ADDR(GPIOA_BASE+0x14, n)
#define  bGPIOB_BRR(n)   	BIT_ADDR(GPIOB_BASE+0x14, n)
#define  bGPIOC_BRR(n)   	BIT_ADDR(GPIOC_BASE+0x14, n)
#define  bGPIOD_BRR(n)   	BIT_ADDR(GPIOD_BASE+0x14, n)
#define  bGPIOE_BRR(n)   	BIT_ADDR(GPIOE_BASE+0x14, n)
#define  bGPIOF_BRR(n)   	BIT_ADDR(GPIOF_BASE+0x14, n)
#define  bGPIOG_BRR(n)   	BIT_ADDR(GPIOG_BASE+0x14, n)
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

#define  bGPIOx_IDR(m,n)   BIT_ADDR(GPIOA_BASE+0x400*m+0x08, n)  //ָ���˿ڵ�ָ��λ
#define  bGPIOx_ODR(m,n)   BIT_ADDR(GPIOA_BASE+0x400*m+0x0C, n)  //ָ���˿ڵ�ָ��λ
#define  bGPIOx_BSRR(m,n)  BIT_ADDR(GPIOA_BASE+0x400*m+0x10, n) //��λָ���˿ڵ�ָ��λ
#define  bGPIOx_BRR(m,n)   BIT_ADDR(GPIOA_BASE+0x400*m+0x14, n)  //��λָ���˿ڵ�ָ��λ

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
//USART״̬�Ĵ���SR
#define  bURT_SR_PE(USARTx_BASE) 			BIT_ADDR(USARTx_BASE+0x00, 0) //У�����Parity Error���ڽ���ģʽ�£����������żУ�����Ӳ���Ը�λ��λ��
#define  bURT_SR_FE(USARTx_BASE) 			BIT_ADDR(USARTx_BASE+0x00, 1) //֡����Framing Error������⵽ͬ����λ��������������߼�⵽�Ͽ�������λ��Ӳ����λ��
#define  bURT_SR_NE(USARTx_BASE) 			BIT_ADDR(USARTx_BASE+0x00, 2) //��������Noise Error���ڽ��յ���֡��⵽����ʱ����Ӳ���Ը�λ��λ��
#define  bURT_SR_ORE(USARTx_BASE) 		BIT_ADDR(USARTx_BASE+0x00, 3) //���ش���Overrun Error����RXNE��Ȼ�ǡ�1����ʱ�򣬵�ǰ����������λ�Ĵ����е����ݣ���Ҫ������RDR�Ĵ���ʱ��Ӳ������λ��λ�����USART_CR1�е�RXNEIEΪ��1���Ļ���������жϡ�
#define  bURT_SR_IDLE(USARTx_BASE)		BIT_ADDR(USARTx_BASE+0x00, 4) //IDLE����⵽���߿��У�����⵽���߿���ʱ����λ��Ӳ����λ�����USART_CR1�е�IDLEIEΪ��1����������жϡ�
#define  bURT_SR_RXNE(USARTx_BASE)		BIT_ADDR(USARTx_BASE+0x00, 5) //���վݼĴ����ǿգ�Receive Not Empty��������λ����λ��ʱ�򣬾�����ʾ�Ѿ������ݱ����յ��ˣ����ҿ��Զ������ˡ�ͨ����USART_DR���Խ���λ���㣬Ҳ�������λд0��ֱ�������
#define  bURT_SR_TC(USARTx_BASE) 			BIT_ADDR(USARTx_BASE+0x00, 6) //������ɣ�Transmit Complete��������λ����λ��ʱ�򣬱�ʾUSART_DR�ڵ������Ѿ�����������ˡ�������������λ���жϣ��������жϡ���λҲ���������㷽ʽ��1����USART_SR��дUSART_DR��2��ֱ�����λд0��
#define  bURT_SR_TXE(USARTx_BASE) 		BIT_ADDR(USARTx_BASE+0x00, 7) //�������ݼĴ����գ�Transmit Empty����TDR�Ĵ����е����ݱ�Ӳ��ת�Ƶ���λ�Ĵ�����ʱ�򣬸�λ��Ӳ����λ�����USART_CR1�Ĵ����е�TXEIEΪ1��������жϡ���USART_DR��д����������λ���㡣
#define  bURT_SR_LBD(USARTx_BASE) 		BIT_ADDR(USARTx_BASE+0x00, 8) //LIN�Ͽ���⣨LIN Break Detect����̽�⵽LIN�Ͽ�ʱ����λ��Ӳ���á�1����������塯0��(���λд0)�����USART_CR3�е�LBDIE = 1��������жϡ�
#define  bURT_SR_CTS(USARTx_BASE) 		BIT_ADDR(USARTx_BASE+0x00, 9)  //���������CTSEλ����nCTS����仯״̬ʱ����λ��Ӳ���øߡ�������������㡣���USART_CR3�е�CTSIEΪ��1����������жϡ�
//USART״̬�Ĵ���CR1
#define  bURT_CR_SBK(USARTx_BASE)     BIT_ADDR(USARTx_BASE+0x0C, 0)  //���ͶϿ�֡��Send Break��λ��ʹ�ø�λ�����ͶϿ��ַ�����λ������������û��������������Ӧ�����������λ����Ȼ���ڶϿ�֡��ֹͣλʱ����Ӳ������λ��λ��
#define  bURT_CR_RWU(USARTx_BASE)     BIT_ADDR(USARTx_BASE+0x0C, 1)  //���ջ��ѣ�Receiver Wakeup��λ����0������ģʽ����1����Ĭģʽ��
#define  bURT_CR_RE(USARTx_BASE)      BIT_ADDR(USARTx_BASE+0x0C, 2)  //����ʹ�ܣ�Receive Enable��λ���÷�ͬ TE��
#define  bURT_CR_TE(USARTx_BASE)      BIT_ADDR(USARTx_BASE+0x0C, 3)  //����ʹ�ܣ�Transmit Enable��λ������Ϊ1�����������ڵķ��͹��ܡ�
#define  bURT_CR_IDLEIE(USARTx_BASE)  BIT_ADDR(USARTx_BASE+0x0C, 4)  //IDLE�ж�ʹ�ܣ�IDLE Interrupt Enable��λ����0����ֹ�жϣ���1����USART_SR�е�IDLEΪ��1��ʱ������USART�жϡ�
#define  bURT_CR_RXNEIE(USARTx_BASE)  BIT_ADDR(USARTx_BASE+0x0C, 5)  //���ջ������ǿ��ж�ʹ�ܣ�Receive Non-Empty Interrupt Enable��λ�����ø�λΪ 1���� USART_SR�е� ORE ���� RXNE λΪ 1 ʱ�������������жϡ�
#define  bURT_CR_TCIE(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x0C, 6)  //��������ж�ʹ�ܣ�Transmit Complete Interrupt Enable��λ�����ø�λΪ 1���� USART_SR �е� TCλΪ 1 ʱ�������������жϡ�
#define  bURT_CR_TXEIE(USARTx_BASE)   BIT_ADDR(USARTx_BASE+0x0C, 7)  //���ͻ��������ж�ʹ�ܣ�Transmit Interrupt Enable��λ�����ø�λΪ 1���� USART_SR �е� TXE λΪ1 ʱ�������������жϡ�
#define  bURT_CR_PEIE(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x0C, 8)  //PE�ж�ʹ�ܣ�Parity Error Interrupt Enable������0����ֹ�жϣ���1����USART_SR�е�PEΪ��1��ʱ������USART�жϡ�
#define  bURT_CR_PS(USARTx_BASE)      BIT_ADDR(USARTx_BASE+0x0C, 9)   //У��λѡ��Parity Select��λ������Ϊ0��ΪżУ�飬����Ϊ��У�顣
#define  bURT_CR_PCE(USARTx_BASE)     BIT_ADDR(USARTx_BASE+0x0C, 10)  //У�����ʹ�ܣ�Parity Control Enable��λ����0�����ֹУ�飬����ʹ��У�顣
#define  bURT_CR_WAKE(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x0C, 11) //���ѣ���0�����������߻��ѣ���1������ַ��ǻ��ѡ�
#define  bURT_CR_M(USARTx_BASE)       BIT_ADDR(USARTx_BASE+0x0C, 12) //�ֳ�ѡ��λ������λΪ0��ʱ�����ô���Ϊ8���ֳ����ֹͣλ��ֹͣλ�ĸ����Ǹ���USART_CR2��[13:12]λ�����������ģ�Ĭ��Ϊ0��
#define  bURT_CR_UE(USARTx_BASE)      BIT_ADDR(USARTx_BASE+0x0C, 13) //����ʹ�ܣ�Usart Enable��λ��ͨ����λ��1����ʹ�ܴ��ڡ�����λ�����㣬��Ƶ�������ֹͣ�������Լ��ٹ��ġ�
#define  bURT_CR_OVER8(USARTx_BASE)   BIT_ADDR(USARTx_BASE+0x0C, 14)           /*!< USART Oversmapling 8-bits */
//USART״̬�Ĵ���CR2
#define  SET_URT_CR_ADD(USARTx_BASE,a)   	SET_REG_BITn(USARTx_BASE+0x10,0,MASKb5,a)
// #define  bCR2_ADD     BIT_ADDR(USARTx_BASE+0x10, 0)  //���豸��USART�ڵ��ַ(BIT 0:4��5λ)�������ڶദ����ͨ���µľ�Ĭģʽ��ʹ�õģ�ʹ�õ�ַ���������ĳ��USART�豸��

#define  bURT_CR_LBDL(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x10, 5)  //LIN�Ͽ�����ⳤ�ȣ�LIN Break Detection Length��λ����λ����ѡ����11λ����10λ�ĶϿ�����⡣
#define  bURT_CR_LBDIE(USARTx_BASE)   BIT_ADDR(USARTx_BASE+0x10, 6)  //LIN�Ͽ�������ж�ʹ�ܣ�LIN Break Detection Interrupt Enable��λ����0����ֹ�жϣ���1��ֻҪUSART_SR�Ĵ����е�LBDΪ��1���Ͳ����жϡ�
#define  bURT_CR_LBCL(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x10, 7)  //���һλʱ�����壨Last Bit Clock Pulse��λ����ͬ��ģʽ�£�ʹ�ø�λ�������Ƿ���CK�������������͵��Ǹ������ֽ�(MSB)��Ӧ��ʱ�����塣
#define  bURT_CR_CPHA(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x10, 9)  //ʱ����λ��Clock Phase��λ����ͬ��ģʽ�£������ø�λѡ��SLCK������ʱ���������λ��
#define  bURT_CR_CPOL(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x10, 10) //ʱ�Ӽ��ԣ�Clock Polarity��λ����ͬ��ģʽ�£������ø�λѡ��SLCK������ʱ������ļ��ԡ�
#define  bURT_CR_CLKEN(USARTx_BASE)   BIT_ADDR(USARTx_BASE+0x10, 11) //ʱ��ʹ�ܣ�Clock Enable��λ����λ����ʹ��CK���š�
#define  SET_URT_CR_STOP(USARTx_BASE,a)   	SET_REG_BITn(USARTx_BASE+0x10,12,MASKb2,a)
// #define  bCR2_STOP(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x10, 12) //ֹͣλ��STOP��λ����2λ��������ֹͣλ��λ����00��1��ֹͣλ��01��0.5��ֹͣλ��10��2��ֹͣλ��11��1.5��ֹͣλ��          /*!< STOP[1:0] bits (STOP bits) */
#define  bURT_CR_STOP_0(USARTx_BASE)  BIT_ADDR(USARTx_BASE+0x10, 12) //           
#define  bURT_CR_STOP_1(USARTx_BASE)  BIT_ADDR(USARTx_BASE+0x10, 13) //
#define  bURT_CR_LINEN(USARTx_BASE)   BIT_ADDR(USARTx_BASE+0x10, 14) //LINģʽʹ�ܣ�LIN Enable��λ����LINģʽ�£�������USART_CR1�Ĵ����е�SBKλ����LINͬ���Ͽ���(��13λ)���Լ����LINͬ���Ͽ�����

//USART״̬�Ĵ���CR3
#define  bURT_CR_EIE(USARTx_BASE)     BIT_ADDR(USARTx_BASE+0x14, 0)  //�����ж�ʹ�ܣ�Error Interrupt Enable��λ��
#define  bURT_CR_IREN(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x14, 1)  //����ģʽʹ�ܣ�IrDA Enable��λ��
#define  bURT_CR_IRLP(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x14, 2)  //����͹��ģ�IrDA Low-Power��λ����λ����ѡ����ͨģʽ���ǵ͹��ĺ���ģʽ��
#define  bURT_CR_HDSEL(USARTx_BASE)   BIT_ADDR(USARTx_BASE+0x14, 3)  //��˫��ѡ��Half-duplex Selection��λ��ѡ���߰�˫��ģʽ��
#define  bURT_CR_NACK(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x14, 4)  //���ܿ�NACK��Smartcard NACK��λ����0��������NACK����1������NACK��
#define  bURT_CR_SCEN(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x14, 5)  //���ܿ�ʹ�ܣ�Smartcard Enable��λ����λ����ʹ�����ܿ�ģʽ
#define  bURT_CR_DMAR(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x14, 6)  //DMA���գ�DMA Receiver��λ�� 
#define  bURT_CR_DMAT(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x14, 7)  //DMA���ͣ�DMA Transmitter��λ�� 
#define  bURT_CR_RTSE(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x14, 8)  //RTSʹ�ܣ�RTS Enable��λ�� 
#define  bURT_CR_CTSE(USARTx_BASE)    BIT_ADDR(USARTx_BASE+0x14, 9)  //CTSʹ�ܣ�CTS Enable��λ��
#define  bURT_CR_CTSIE(USARTx_BASE)   BIT_ADDR(USARTx_BASE+0x14, 10) //CTS�ж�ʹ�ܣ�CTS Interrupt Enable��λ��
#define  bURT_CR_ONEBIT(USARTx_BASE)  BIT_ADDR(USARTx_BASE+0x14, 11)  

//USART״̬�Ĵ���GTPR
#define  bURT_GTPR_PSC(USARTx_BASE)     BIT_ADDR(USARTx_BASE+0x18, 0) //Ԥ��Ƶ��ֵ��Prescaler��λ���ں�������ܿ�ģʽ������Ҫ������ܡ�
#define  bURT_GTPR_GT(USARTx_BASE)      BIT_ADDR(USARTx_BASE+0x18, 8) //����ʱ��ֵ��Guard Time��λ����λ��涨���Բ���ʱ��Ϊ��λ�ı���ʱ�䡣�����ܿ�ģʽ�£���Ҫ������ܡ�������ʱ���ȥ�󣬲Ż����÷�����ɱ�־��

/******************************************************************************/
/*                                                                            */
/*                        SPI�ӿڼĴ���                         */
/*                                                                            */
/******************************************************************************/

/*******************    SPI_CR1 �Ĵ���  ********************/
#define  bSPI_CR_CPHA(SPIx_BASE)     BIT_ADDR(SPIx_BASE+0x00, 0)  /*!< Clock Phase */
#define  bSPI_CR_CPOL(SPIx_BASE)     BIT_ADDR(SPIx_BASE+0x00, 1)            /*!< Clock Polarity */
#define  bSPI_CR_MSTR(SPIx_BASE)     BIT_ADDR(SPIx_BASE+0x00, 2)            /*!< Master Selection */

#define  SET_SPI_CR_BR(SPIx_BASE,a)   	SET_REG_BITn(SPIx_BASE,3,MASKb3,a)
//ȡֵ�������£� SPI�����ٶ�����
#define SPI_SPEED_2   	0    //SPI_SPEED_2   2��Ƶ   (SPI 36M@sys 72M) 
#define SPI_SPEED_4   	1    //SPI_SPEED_2   4��Ƶ   (SPI 18M@sys 72M)
#define SPI_SPEED_8   	2    //SPI_SPEED_8   8��Ƶ   (SPI 9M@sys 72M)
#define SPI_SPEED_16  	3    //SPI_SPEED_16  16��Ƶ  (SPI 4.5M@sys 72M)
#define SPI_SPEED_32  	4    //SPI_SPEED_32  32��Ƶ  (SPI 2.25M@sys 72M)
#define SPI_SPEED_64  	5    //SPI_SPEED_64  64��Ƶ   (SPI 1.125M@sys 72M)
#define SPI_SPEED_128  	6    //SPI_SPEED_128 128��Ƶ (SPI 562.5K@sys 72M)
#define SPI_SPEED_256 	7    //SPI_SPEED_256 256��Ƶ (SPI 281.25K@sys 72M)

#define  bSPI_CR_SPE(SPIx_BASE)      BIT_ADDR(SPIx_BASE+0x00, 6)            /*!< SPI Enable */
#define  bSPI_CR_LSBFIRST(SPIx_BASE) BIT_ADDR(SPIx_BASE+0x00, 7)            /*!< Frame Format */
#define  bSPI_CR_SSI(SPIx_BASE)      BIT_ADDR(SPIx_BASE+0x00, 8)            /*!< Internal slave select */
#define  bSPI_CR_SSM(SPIx_BASE)      BIT_ADDR(SPIx_BASE+0x00, 9)            /*!< Software slave management */
#define  bSPI_CR_RXONLY(SPIx_BASE)   BIT_ADDR(SPIx_BASE+0x00, 10)            /*!< Receive only */
#define  bSPI_CR_DFF(SPIx_BASE)      BIT_ADDR(SPIx_BASE+0x00, 11)            /*!< Data Frame Format */
#define  bSPI_CR_CRCNEXT(SPIx_BASE)  BIT_ADDR(SPIx_BASE+0x00, 12)            /*!< Transmit CRC next */
#define  bSPI_CR_CRCEN(SPIx_BASE)    BIT_ADDR(SPIx_BASE+0x00, 13)            /*!< Hardware CRC calculation enable */
#define  bSPI_CR_BIDIOE(SPIx_BASE)   BIT_ADDR(SPIx_BASE+0x00, 14)            /*!< Output enable in bidirectional mode */
#define  bSPI_CR_BIDIMODE(SPIx_BASE) BIT_ADDR(SPIx_BASE+0x00, 15)            /*!< Bidirectional data mode enable */

/*******************    SPI_CR2 �Ĵ���  ********************/
#define  bSPI_CR_RXDMAEN(SPIx_BASE)  BIT_ADDR(SPIx_BASE+0x04, 0)               /*!< Rx Buffer DMA Enable */
#define  bSPI_CR_TXDMAEN(SPIx_BASE)  BIT_ADDR(SPIx_BASE+0x04, 1)               /*!< Tx Buffer DMA Enable */
#define  bSPI_CR_SSOE(SPIx_BASE)     BIT_ADDR(SPIx_BASE+0x04, 2)               /*!< SS Output Enable */
#define  bSPI_CR_ERRIE(SPIx_BASE)    BIT_ADDR(SPIx_BASE+0x04, 4)               /*!< Error Interrupt Enable */
#define  bSPI_CR_RXNEIE(SPIx_BASE)   BIT_ADDR(SPIx_BASE+0x04, 6)               /*!< RX buffer Not Empty Interrupt Enable */
#define  bSPI_CR_TXEIE(SPIx_BASE)    BIT_ADDR(SPIx_BASE+0x04, 7)               /*!< Tx buffer Empty Interrupt Enable */

/********************    SPI_SR �Ĵ���  ********************/
#define  bSPI_SR_RXNE(SPIx_BASE)     BIT_ADDR(SPIx_BASE+0x08, 0)              /*!< Receive buffer Not Empty */
#define  bSPI_SR_TXE(SPIx_BASE)      BIT_ADDR(SPIx_BASE+0x08, 1)               /*!< Transmit buffer Empty */
#define  bSPI_SR_CHSIDE(SPIx_BASE)   BIT_ADDR(SPIx_BASE+0x08, 2)               /*!< Channel side */
#define  bSPI_SR_UDR(SPIx_BASE)      BIT_ADDR(SPIx_BASE+0x08, 3)               /*!< Underrun flag */
#define  bSPI_SR_CRCERR(SPIx_BASE)   BIT_ADDR(SPIx_BASE+0x08, 4)               /*!< CRC Error flag */
#define  bSPI_SR_MODF(SPIx_BASE)     BIT_ADDR(SPIx_BASE+0x08, 5)               /*!< Mode fault */
#define  bSPI_SR_OVR(SPIx_BASE)      BIT_ADDR(SPIx_BASE+0x08, 6)               /*!< Overrun flag */
#define  bSPI_SR_BSY(SPIx_BASE)      BIT_ADDR(SPIx_BASE+0x08, 7)               /*!< Busy flag */

/******************    SPI_I2SCFGR �Ĵ���  *****************/
#define  bSPI_I2SCFGR_CHLEN(SPIx_BASE)     BIT_ADDR(SPIx_BASE+0x1C, 0)            /*!< Channel length (number of bits per audio channel) */
#define  bSPI_I2SCFGR_DATLEN(SPIx_BASE)    BIT_ADDR(SPIx_BASE+0x1C, 1)             /*!< DATLEN[1:0] bits (Data length to be transferred) */
#define  bSPI_I2SCFGR_DATLEN_0(SPIx_BASE)  BIT_ADDR(SPIx_BASE+0x1C, 1)            /*!< Bit 0 */
#define  bSPI_I2SCFGR_DATLEN_1(SPIx_BASE)  BIT_ADDR(SPIx_BASE+0x1C, 2)            /*!< Bit 1 */

#define  bSPI_I2SCFGR_CKPOL(SPIx_BASE)     BIT_ADDR(SPIx_BASE+0x1C, 3)            /*!< steady state clock polarity */

#define  bSPI_I2SCFGR_I2SSTD(SPIx_BASE)    BIT_ADDR(SPIx_BASE+0x1C, 4)            /*!< I2SSTD[1:0] bits (I2S standard selection) */
#define  bSPI_I2SCFGR_I2SSTD_0(SPIx_BASE)  BIT_ADDR(SPIx_BASE+0x1C, 4)            /*!< Bit 0 */
#define  bSPI_I2SCFGR_I2SSTD_1(SPIx_BASE)  BIT_ADDR(SPIx_BASE+0x1C, 5)            /*!< Bit 1 */

#define  bSPI_I2SCFGR_PCMSYNC(SPIx_BASE)   BIT_ADDR(SPIx_BASE+0x1C, 7)            /*!< PCM frame synchronization */

#define  bSPI_I2SCFGR_I2SCFG(SPIx_BASE)    BIT_ADDR(SPIx_BASE+0x1C, 8)            /*!< I2SCFG[1:0] bits (I2S configuration mode) */
#define  bSPI_I2SCFGR_I2SCFG_0(SPIx_BASE)  BIT_ADDR(SPIx_BASE+0x1C, 8)            /*!< Bit 0 */
#define  bSPI_I2SCFGR_I2SCFG_1(SPIx_BASE)  BIT_ADDR(SPIx_BASE+0x1C, 9)            /*!< Bit 1 */

#define  bSPI_I2SCFGR_I2SE(SPIx_BASE)      BIT_ADDR(SPIx_BASE+0x1C, 10)            /*!< I2S Enable */
#define  bSPI_I2SCFGR_I2SMOD(SPIx_BASE)    BIT_ADDR(SPIx_BASE+0x1C, 11)            /*!< I2S mode selection */

/******************    SPI_I2SPR �Ĵ���  *******************/
#define  SET_SPI_I2SPR_I2SDIV(SPIx_BASE,a)   	SET_REG_BITn(SPIx_BASE+0x20,0,MASKb8,a)
// #define  bSPI1_I2SPR_I2SDIV      BIT_ADDR(SPI1_BASE+0x20, 0)  //����8BIT I2S ����Ԥ��Ƶ

#define  bSPI_I2SPR_ODD(SPIx_BASE)         BIT_ADDR(SPIx_BASE+0x20, 8)            /*!< Odd factor for the prescaler */
#define  bSPI_I2SPR_MCKOE(SPIx_BASE)       BIT_ADDR(SPIx_BASE+0x20, 9)            /*!< Master Clock Output Enable */


/******************************************************************************/
/*                                                                            */
/*                        TIM��ʱ���ӿڼĴ���                                  */
/*                                                                            */
/******************************************************************************/

/*******************  TIM_CR1 ���ƼĴ���  ********************/
#define   bTIM_CR_CEN(TIMx_BASE)                         BIT_ADDR(TIMx_BASE,0)            /*!< Counter enable */
#define   bTIM_CR_UDIS(TIMx_BASE)                        BIT_ADDR(TIMx_BASE,1)            /*!< Update disable */
#define   bTIM_CR_URS(TIMx_BASE)                         BIT_ADDR(TIMx_BASE,2)            /*!< Update request source */
#define   bTIM_CR_OPM(TIMx_BASE)                         BIT_ADDR(TIMx_BASE,3)            /*!< One pulse mode */
#define   bTIM_CR_DIR(TIMx_BASE)                         BIT_ADDR(TIMx_BASE,4)            /*!< ���򣬶��壺0�����������ϼ�������1�����������¼�������ע��������������Ϊ�������ģʽ�������ģʽʱ����λΪֻ�� */

#define  SET_TIM_CR_CMS(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE,5,MASKb2,a)
/*!< CMS[1:0] �������ģʽѡ�񣬶��壺00�����ض���ģʽ�����������ݷ���λ(DIR)���ϻ����¼����� */
/*!< 01��10��11���������ģʽ1��2��3����������������Ϻ����¼���������*/

#define   bTIM_CR_ARPE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x00,7)            /*!< Auto-reload preload enable */

#define  SET_TIM_CR_CKD(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE,8,MASKb2,a)
/*!< CKD[1:0] CKD[1:0]ʱ�ӷ�Ƶ���ӣ������ڶ�ʱ��ʱ��(CK_INT)Ƶ���������˲���(ETR��TIx)ʹ�õĲ���Ƶ��֮��ķ�Ƶ������ */
/*!< ���壺00��tDTS = tCK_INT����01��tDTS = 2 x tCK_INT����10��tDTS = 4 x tCK_INT��11������ */

/*******************  TIM_CR2 ���ƼĴ���  ********************/
#define   bTIM_CR_CCPC(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,0)            /*!< Capture/Compare Preloaded Control */
#define   bTIM_CR_CCUS(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,2)            /*!< Capture/Compare Control Update Selection */
#define   bTIM_CR_CCDS(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,3)            /*!< Capture/Compare DMA Selection */

#define  SET_TIM_CR_MMS(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x04,4,MASKb3,a)
/*!< MMS[2:0] bits (Master Mode Selection) */

#define   bTIM_CR_TI1S(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,7)            /*!< TI1 Selection */
#define   bTIM_CR_OIS1(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,8)            /*!< Output Idle state 1 (OC1 output) */
#define   bTIM_CR_OIS1N(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x04,9)            /*!< Output Idle state 1 (OC1N output) */
#define   bTIM_CR_OIS2(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,10)            /*!< Output Idle state 2 (OC2 output) */
#define   bTIM_CR_OIS2N(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x04,11)            /*!< Output Idle state 2 (OC2N output) */
#define   bTIM_CR_OIS3(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,12)            /*!< Output Idle state 3 (OC3 output) */
#define   bTIM_CR_OIS3N(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x04,13)            /*!< Output Idle state 3 (OC3N output) */
#define   bTIM_CR_OIS4(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x04,14)            /*!< Output Idle state 4 (OC4 output) */

/*******************  TIM_SMCR �Ĵ���  *******************/
#define  SET_TIM_SMCR_SMS(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x08,0,MASKb3,a)/*!< SMS[2:0] bits (Slave mode selection) */

#define  SET_TIM_SMCR_TS(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x08,4,MASKb3,a) /*!< TS[2:0] bits (Trigger selection) */

#define   bTIM_SMCR_MSM(TIMx_BASE)        BIT_ADDR(TIMx_BASE+0x08,7)            /*!< Master/slave mode */

#define  SET_TIM_SMCR_ETF(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x08,8,MASKb4,a)	/*!< ETF[3:0] bits (External trigger filter) */

#define  SET_TIM_SMCR_ETPS(TIMx_BASE,a)   SET_REG_BITn(TIMx_BASE+0x08,12,MASKb2,a)	  /*!< ETPS[1:0] bits (External trigger prescaler) */

#define   bTIM_SMCR_ECE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x08,14)            /*!< External clock enable */
#define   bTIM_SMCR_ETP(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x08,15)            /*!< External trigger polarity */

/*******************  TIM_DIER �Ĵ���  *******************/
#define   bTIM_DIER_UIE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x0C,0)            /*!< Update interrupt enable */
#define   bTIM_DIER_CC1IE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,1)            /*!< Capture/Compare 1 interrupt enable */
#define   bTIM_DIER_CC2IE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,2)            /*!< Capture/Compare 2 interrupt enable */
#define   bTIM_DIER_CC3IE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,3)            /*!< Capture/Compare 3 interrupt enable */
#define   bTIM_DIER_CC4IE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,4)            /*!< Capture/Compare 4 interrupt enable */
#define   bTIM_DIER_COMIE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,5)            /*!< COM interrupt enable */
#define   bTIM_DIER_TIE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x0C,6)            /*!< Trigger interrupt enable */
#define   bTIM_DIER_BIE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x0C,7)            /*!< Break interrupt enable */
#define   bTIM_DIER_UDE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x0C,8)            /*!< Update DMA request enable */
#define   bTIM_DIER_CC1DE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,9)            /*!< Capture/Compare 1 DMA request enable */
#define   bTIM_DIER_CC2DE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,10)            /*!< Capture/Compare 2 DMA request enable */
#define   bTIM_DIER_CC3DE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,11)            /*!< Capture/Compare 3 DMA request enable */
#define   bTIM_DIER_CC4DE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,12)            /*!< Capture/Compare 4 DMA request enable */
#define   bTIM_DIER_COMDE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x0C,13)            /*!< COM DMA request enable */
#define   bTIM_DIER_TDE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x0C,14)            /*!< Trigger DMA request enable */

/********************  TIM_SR ״̬�Ĵ���  ********************/
#define   bTIM_SR_UIF(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x10,0)            /*!< �����жϱ�ǣ�Ӳ����1�������0�����壺0���޸����¼���1�������жϵȴ���Ӧ�����Ĵ���������ʱ��λ��Ӳ���á�1���� */
#define   bTIM_SR_CC1IF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,1)            /*!< Capture/Compare 1 interrupt Flag */
#define   bTIM_SR_CC2IF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,2)            /*!< Capture/Compare 2 interrupt Flag */
#define   bTIM_SR_CC3IF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,3)            /*!< Capture/Compare 3 interrupt Flag */
#define   bTIM_SR_CC4IF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,4)            /*!< Capture/Compare 4 interrupt Flag */
#define   bTIM_SR_COMIF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,5)            /*!< COM interrupt Flag */
#define   bTIM_SR_TIF(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x10,6)            /*!< Trigger interrupt Flag */
#define   bTIM_SR_BIF(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x10,7)            /*!< Break interrupt Flag */
#define   bTIM_SR_CC1OF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,9)            /*!< Capture/Compare 1 Overcapture Flag */
#define   bTIM_SR_CC2OF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,10)            /*!< Capture/Compare 2 Overcapture Flag */
#define   bTIM_SR_CC3OF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,11)            /*!< Capture/Compare 3 Overcapture Flag */
#define   bTIM_SR_CC4OF(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x10,12)            /*!< Capture/Compare 4 Overcapture Flag */

/*******************  TIM_EGR �Ĵ���  ********************/
#define   bTIM_EGR_UG(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x14,0)               /*!< Update Generation */
#define   bTIM_EGR_CC1G(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x14,1)               /*!< Capture/Compare 1 Generation */
#define   bTIM_EGR_CC2G(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x14,2)               /*!< Capture/Compare 2 Generation */
#define   bTIM_EGR_CC3G(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x14,3)               /*!< Capture/Compare 3 Generation */
#define   bTIM_EGR_CC4G(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x14,4)               /*!< Capture/Compare 4 Generation */
#define   bTIM_EGR_COMG(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x14,5)               /*!< Capture/Compare Control Update Generation */
#define   bTIM_EGR_TG(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x14,6)               /*!< Trigger Generation */
#define   bTIM_EGR_BG(TIMx_BASE)                          BIT_ADDR(TIMx_BASE +0x14,7)               /*!< Break Generation */

/******************  TIM_CCMR1 �Ĵ���  *******************/
#define   bTIM_CCMR_CC1S(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x18,0)            /*!< CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define   bTIM_CCMR_CC1S_0(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,0)            /*!< Bit 0 */
#define   bTIM_CCMR_CC1S_1(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,1)            /*!< Bit 1 */

#define   bTIM_CCMR_OC1FE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,2)            /*!< Output Compare 1 Fast enable */
#define   bTIM_CCMR_OC1PE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,3)            /*!< Output Compare 1 Preload enable */

#define  SET_TIM_CCMR_OC1M(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x18,4,MASKb3,a)  /*!< OC1M[2:0] bits (Output Compare 1 Mode) */

#define   bTIM_CCMR_OC1CE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,7)            /*!< Output Compare 1Clear Enable */

#define   bTIM_CCMR_CC2S(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x18,8)            /*!< CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define   bTIM_CCMR_CC2S_0(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,8)            /*!< Bit 0 */
#define   bTIM_CCMR_CC2S_1(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,9)            /*!< Bit 1 */

#define   bTIM_CCMR_OC2FE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,10)            /*!< Output Compare 2 Fast enable */
#define   bTIM_CCMR_OC2PE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,11)            /*!< Output Compare 2 Preload enable */

#define  	SET_TIM_CCMR_OC2M(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x18,12,MASKb3,a)  /*!< OC2M[2:0] bits (Output Compare 2 Mode) */

#define   bTIM_CCMR_OC2CE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x18,15)            /*!< Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/

#define   bTIM_CCMR_IC1PSC(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,2)            /*!< IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define   bTIM_CCMR_IC1PSC_0(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x18,2)            /*!< Bit 0 */
#define   bTIM_CCMR_IC1PSC_1(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x18,3)            /*!< Bit 1 */

#define  	SET_TIM_CCMR_IC1F(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x18,4,MASKb4,a)  /*!< IC1F[3:0] bits (Input Capture 1 Filter) */

#define   bTIM_CCMR_IC2PSC(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x18,10)            /*!< IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define   bTIM_CCMR_IC2PSC_0(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x18,10)            /*!< Bit 0 */
#define   bTIM_CCMR_IC2PSC_1(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x18,11)            /*!< Bit 1 */

#define  	SET_TIM_CCMR_IC2F(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x18,12,MASKb4,a)   /*!< IC2F[3:0] bits (Input Capture 2 Filter) */

/******************    TIM_CCMR2 �Ĵ���  *******************/
#define   bTIM_CCMR_CC3S(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x1C,0)            /*!< CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define   bTIM_CCMR_CC3S_0(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,0)            /*!< Bit 0 */
#define   bTIM_CCMR_CC3S_1(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,1)            /*!< Bit 1 */

#define   bTIM_CCMR_OC3FE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,2)            /*!< Output Compare 3 Fast enable */
#define   bTIM_CCMR_OC3PE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,3)            /*!< Output Compare 3 Preload enable */

#define  	SET_TIM_CCMR_OC3M(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x1C,4,MASKb3,a)   /*!< OC3M[2:0] bits (Output Compare 3 Mode) */


#define   bTIM_CCMR_OC3CE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,7)            /*!< Output Compare 3 Clear Enable */

#define   bTIM_CCMR_CC4S(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x1C,8)            /*!< CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define   bTIM_CCMR_CC4S_0(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,8)            /*!< Bit 0 */
#define   bTIM_CCMR_CC4S_1(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,9)            /*!< Bit 1 */

#define   bTIM_CCMR_OC4FE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,10)            /*!< Output Compare 4 Fast enable */
#define   bTIM_CCMR_OC4PE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,11)            /*!< Output Compare 4 Preload enable */

#define  	SET_TIM_CCMR_OC4M(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x1C,12,MASKb3,a)   /*!< OC4M[2:0] bits (Output Compare 4 Mode) */


#define   bTIM_CCMR_OC4CE(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x1C,15)            /*!< Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/

#define   bTIM_CCMR_IC3PSC(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,2)            /*!< IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define   bTIM_CCMR_IC3PSC_0(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x1C,2)            /*!< Bit 0 */
#define   bTIM_CCMR_IC3PSC_1(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x1C,3)            /*!< Bit 1 */

#define  	SET_TIM_CCMR_IC3F(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x1C,4,MASKb4,a)    /*!< IC3F[3:0] bits (Input Capture 3 Filter) */

#define   bTIM_CCMR_IC4PSC(TIMx_BASE)                    BIT_ADDR(TIMx_BASE +0x1C,10)            /*!< IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define   bTIM_CCMR_IC4PSC_0(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x1C,10)            /*!< Bit 0 */
#define   bTIM_CCMR_IC4PSC_1(TIMx_BASE)                  BIT_ADDR(TIMx_BASE +0x1C,11)            /*!< Bit 1 */

#define  	SET_TIM_CCMR_IC4F(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x1C,12,MASKb4,a)    /*!< IC4F[3:0] bits (Input Capture 4 Filter) */


/*******************    TIM_CCER �Ĵ���  *******************/
#define   bTIM_CCER_CC1E(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,0)            /*!< Capture/Compare 1 output enable */
#define   bTIM_CCER_CC1P(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,1)            /*!< Capture/Compare 1 output Polarity */
#define   bTIM_CCER_CC1NE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,2)            /*!< Capture/Compare 1 Complementary output enable */
#define   bTIM_CCER_CC1NP(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,3)            /*!< Capture/Compare 1 Complementary output Polarity */
#define   bTIM_CCER_CC2E(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,4)            /*!< Capture/Compare 2 output enable */
#define   bTIM_CCER_CC2P(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,5)            /*!< Capture/Compare 2 output Polarity */
#define   bTIM_CCER_CC2NE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,6)            /*!< Capture/Compare 2 Complementary output enable */
#define   bTIM_CCER_CC2NP(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,7)            /*!< Capture/Compare 2 Complementary output Polarity */
#define   bTIM_CCER_CC3E(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,8)            /*!< Capture/Compare 3 output enable */
#define   bTIM_CCER_CC3P(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,9)            /*!< Capture/Compare 3 output Polarity */
#define   bTIM_CCER_CC3NE(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,10)            /*!< Capture/Compare 3 Complementary output enable */
#define   bTIM_CCER_CC3NP(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,11)            /*!< Capture/Compare 3 Complementary output Polarity */
#define   bTIM_CCER_CC4E(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,12)            /*!< Capture/Compare 4 output enable */
#define   bTIM_CCER_CC4P(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x20,13)            /*!< Capture/Compare 4 output Polarity */
#define   bTIM_CCER_CC4NP(TIMx_BASE)                      BIT_ADDR(TIMx_BASE +0x20,15)            /*!< Capture/Compare 4 Complementary output Polarity */

/*******************    TIM_CNT �Ĵ���  ********************/
#define   TIM_CNT(TIMx_BASE)           (MEM_ADDR(TIMx_BASE+0x24))    /*!< Counter Value */             

/*******************    TIM_PSC �Ĵ���  ********************/
#define   TIM_PSC(TIMx_BASE)           (MEM_ADDR(TIMx_BASE+0x28))            /*!< Prescaler Value */

/*******************    TIM_ARR �Ĵ���  ********************/
#define   TIM_ARR(TIMx_BASE)           (MEM_ADDR(TIMx_BASE+0x2C))            /*!< actual auto-reload Value */

/*******************    TIM_RCR �Ĵ���  ********************/
#define   TIM_RCR(TIMx_BASE)           (MEM_ADDR(TIMx_BASE+0x30))               /*!< Repetition Counter Value */

/*******************    TIM_CCR1 �Ĵ���  *******************/
#define   TIM_CCR1(TIMx_BASE)         (MEM_ADDR(TIMx_BASE+0x34))           /*!< Capture/Compare 1 Value */

/*******************    TIM_CCR2 �Ĵ���  *******************/
#define   TIM_CCR2(TIMx_BASE)         (MEM_ADDR(TIMx_BASE+0x38))            /*!< Capture/Compare 2 Value */

/*******************    TIM_CCR3 �Ĵ���  *******************/
#define   TIM_CCR3(TIMx_BASE)         (MEM_ADDR(TIMx_BASE+0x3C))            /*!< Capture/Compare 3 Value */

/*******************    TIM_CCR4 �Ĵ���  *******************/
#define   TIM_CCR4(TIMx_BASE)         (MEM_ADDR(TIMx_BASE+0x40))            /*!< Capture/Compare 4 Value */

/*******************    TIM_BDTR �Ĵ���  *******************/
/*!< DTG[0:7] bits (Dead-Time Generator set-up) */
#define  	SET_TIM_BDTR_DTG(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x44,0,MASKb8,a)

#define   bTIM_BDTR_LOCK(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x44,8)            /*!< LOCK[1:0] bits (Lock Configuration) */
#define   bTIM_BDTR_LOCK_0(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x44,8)            /*!< Bit 0 */
#define   bTIM_BDTR_LOCK_1(TIMx_BASE)                     BIT_ADDR(TIMx_BASE +0x44,9)            /*!< Bit 1 */

#define   bTIM_BDTR_OSSI(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x44,10)            /*!< Off-State Selection for Idle mode */
#define   bTIM_BDTR_OSSR(TIMx_BASE)                       BIT_ADDR(TIMx_BASE +0x44,11)            /*!< Off-State Selection for Run mode */
#define   bTIM_BDTR_BKE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x44,12)            /*!< Break enable */
#define   bTIM_BDTR_BKP(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x44,13)            /*!< Break Polarity */
#define   bTIM_BDTR_AOE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x44,14)            /*!< Automatic Output enable */
#define   bTIM_BDTR_MOE(TIMx_BASE)                        BIT_ADDR(TIMx_BASE +0x44,15)            /*!< Main Output enable */

/*******************    TIM_DCR �Ĵ���  ********************/
/*!< DBA�ӵ�0BIT��ʼ��5λ�� (DMA Base Address) */
#define  	SET_TIM_DCR_DBA(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x48,0,MASKb5,a)

/*!< DBL�ӵ�8BIT��ʼ��5λ�� (DMA Burst Length) */
#define  	SET_TIM_DCR_DBL(TIMx_BASE,a)   	SET_REG_BITn(TIMx_BASE+0x48,8,MASKb5,a)

/*******************    TIM_DMAR �Ĵ���  *******************/
#define   bTIM_DMAR_DMAB(TIMx_BASE)       (MEM_ADDR(TIMx_BASE+0x4C))            /*!< DMA �Ĵ��� for burst accesses */

/******************************************************************************/
/*                                                                            */
/*                           �������Ź��Ĵ���  		                             */
/*                                                                            */
/******************************************************************************/

/*******************    IWDG_KR �Ĵ���  ********************/
       
#define  IWDG_KEY					(MEM_ADDR(IWDG_BASE))/*!< Key value (ֻд, ����Ϊ0000h) */
/*******************    IWDG_PR �Ĵ���  ********************/
/*!< �ӵ�0BIT��ʼ��3λ��PR[2:0] (Ԥ��Ƶ��) */
#define  	SET_IWDG_PR(a)   	SET_REG_BITn(IWDG_BASE+0x04,0,MASKb3,a)

/*******************    IWDG_RLR �Ĵ���  *******************/
        
#define  IWDG_RL					(MEM_ADDR(IWDG_BASE+0x08)) /*!< ��װ��ֵ */
/*******************    IWDG_SR �Ĵ���  ********************/
#define  bIWDG_SR_PVU             BIT_ADDR(IWDG_BASE +0x0C,0)              /*!< ���Ź�Ԥ��Ƶֵ���� */
#define  bIWDG_SR_RVU							BIT_ADDR(IWDG_BASE +0x0C,1)							 /*!< ���Ź���������װ�ظ��� */
/******************************************************************************/
/*                                                                            */
/*                            ���ڿ��Ź��Ĵ���                    			        */
/*                                                                            */
/******************************************************************************/

/*******************    WWDG_CR �Ĵ���  ********************/
/*!< T�ӵ�0BIT��ʼ��7λ��  T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define  	SET_WWDG_CR_T(a)   	SET_REG_BITn(WWDG_BASE,0,MASKb7,a)

#define  bWWDG_CR_WDGA                        BIT_ADDR(WWDG_BASE,7)               /*!< Activation bit */

/*******************    WWDG_CFR �Ĵ���  *******************/
/*!< W�ӵ�0BIT��ʼ��7λ��  W[6:0] bits (7-bit ����ֵ) */
#define  SET_WWDG_CFR_W(a)   	SET_REG_BITn(WWDG_BASE+0x04,0,MASKb7,a)

#define  SET_WWDG_CFR_WDGTB(a)   	SET_REG_BITn(WWDG_BASE+0x04,7,MASKb2,a)	/*!< WDGTB[1:0] bits (Timer Base) */

#define  bWWDG_CFR_EWI                        BIT_ADDR(WWDG_BASE +0x04,9)            /*!< Early Wakeup Interrupt */

/*******************    WWDG_SR �Ĵ���  ********************/
      
#define  bWWDG_SR_EWIF												BIT_ADDR(WWDG_BASE +0x08,0) /*!< Early Wakeup Interrupt Flag */

/******************************************************************************/
/*                                                                            */
/*                         bxCAN���߿�����                                    */
/*                                                                            */
/******************************************************************************/

/*!< CAN ���Ƽ�״̬�Ĵ����� */
/*******************   MCR �����ƼĴ���  ********************/
#define  bCAN_MCR_INRQ(CANx_BASE)  		BIT_ADDR(CANx_BASE,0) 	 /*!< Initialization Request */
#define  bCAN_MCR_SLEEP(CANx_BASE) 		BIT_ADDR(CANx_BASE,1)            /*!< Sleep Mode Request */
#define  bCAN_MCR_TXFP(CANx_BASE)     BIT_ADDR(CANx_BASE,2)            /*!< Transmit FIFO Priority */
#define  bCAN_MCR_RFLM(CANx_BASE)     BIT_ADDR(CANx_BASE,3)            /*!< Receive FIFO Locked Mode */
#define  bCAN_MCR_NART(CANx_BASE)     BIT_ADDR(CANx_BASE,4)            /*!< No Automatic Retransmission */
#define  bCAN_MCR_AWUM(CANx_BASE)     BIT_ADDR(CANx_BASE,5)            /*!< Automatic Wakeup Mode */
#define  bCAN_MCR_ABOM(CANx_BASE)     BIT_ADDR(CANx_BASE,6)            /*!< Automatic Bus-Off Management */
#define  bCAN_MCR_TTCM(CANx_BASE)     BIT_ADDR(CANx_BASE,7)            /*!< Time Triggered Communication Mode */
#define  bCAN_MCR_RESET(CANx_BASE)    BIT_ADDR(CANx_BASE,15)            /*!< CAN software master reset */

/*******************   MSR ��״̬�Ĵ���  ********************/
#define  bCAN_MSR_INAK(CANx_BASE)     BIT_ADDR(CANx_BASE+0x004,0)            /*!< Initialization Acknowledge */
#define  bCAN_MSR_SLAK(CANx_BASE)     BIT_ADDR(CANx_BASE+0x004,1)            /*!< Sleep Acknowledge */
#define  bCAN_MSR_ERRI(CANx_BASE)     BIT_ADDR(CANx_BASE+0x004,2)            /*!< Error Interrupt */
#define  bCAN_MSR_WKUI(CANx_BASE)     BIT_ADDR(CANx_BASE+0x004,3)            /*!< Wakeup Interrupt */
#define  bCAN_MSR_SLAKI(CANx_BASE)    BIT_ADDR(CANx_BASE+0x004,4)            /*!< Sleep Acknowledge Interrupt */
#define  bCAN_MSR_TXM(CANx_BASE)      BIT_ADDR(CANx_BASE+0x004,8)            /*!< Transmit Mode */
#define  bCAN_MSR_RXM(CANx_BASE)      BIT_ADDR(CANx_BASE+0x004,9)            /*!< Receive Mode */
#define  bCAN_MSR_SAMP(CANx_BASE)     BIT_ADDR(CANx_BASE+0x004,10)            /*!< Last Sample Point */
#define  bCAN_MSR_RX(CANx_BASE)       BIT_ADDR(CANx_BASE+0x004,11)            /*!< CAN Rx Signal */

/*******************   TSR ����״̬�Ĵ���  ********************/
#define  bCAN_TSR_RQCP0(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,0)        /*!< Request Completed Mailbox0 */
#define  bCAN_TSR_TXOK0(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,1)        /*!< Transmission OK of Mailbox0 */
#define  bCAN_TSR_ALST0(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,2)        /*!< Arbitration Lost for Mailbox0 */
#define  bCAN_TSR_TERR0(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,3)        /*!< Transmission Error of Mailbox0 */
#define  bCAN_TSR_ABRQ0(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,7)        /*!< Abort Request for Mailbox0 */
#define  bCAN_TSR_RQCP1(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,8)        /*!< Request Completed Mailbox1 */
#define  bCAN_TSR_TXOK1(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,9)        /*!< Transmission OK of Mailbox1 */
#define  bCAN_TSR_ALST1(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,10)        /*!< Arbitration Lost for Mailbox1 */
#define  bCAN_TSR_TERR1(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,11)        /*!< Transmission Error of Mailbox1 */
#define  bCAN_TSR_ABRQ1(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,15)        /*!< Abort Request for Mailbox 1 */
#define  bCAN_TSR_RQCP2(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,16)        /*!< Request Completed Mailbox2 */
#define  bCAN_TSR_TXOK2(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,17)        /*!< Transmission OK of Mailbox 2 */
#define  bCAN_TSR_ALST2(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,18)        /*!< Arbitration Lost for mailbox 2 */
#define  bCAN_TSR_TERR2(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,19)        /*!< Transmission Error of Mailbox 2 */
#define  bCAN_TSR_ABRQ2(CANx_BASE)    BIT_ADDR(CANx_BASE+0x008,23)        /*!< Abort Request for Mailbox 2 */
#define  bCAN_TSR_CODE(CANx_BASE)     BIT_ADDR(CANx_BASE+0x008,24)        /*!< Mailbox Code */

#define  bCAN_TSR_TME(CANx_BASE)      BIT_ADDR(CANx_BASE+0x008,26)        /*!< TME[2:0] bits */
#define  bCAN_TSR_TME0(CANx_BASE)     BIT_ADDR(CANx_BASE+0x008,26)        /*!< Transmit Mailbox 0 Empty */
#define  bCAN_TSR_TME1(CANx_BASE)     BIT_ADDR(CANx_BASE+0x008,27)        /*!< Transmit Mailbox 1 Empty */
#define  bCAN_TSR_TME2(CANx_BASE)     BIT_ADDR(CANx_BASE+0x008,28)        /*!< Transmit Mailbox 2 Empty */

#define  bCAN_TSR_LOW(CANx_BASE)      BIT_ADDR(CANx_BASE+0x008,29)        /*!< LOW[2:0] bits */
#define  bCAN_TSR_LOW0(CANx_BASE)     BIT_ADDR(CANx_BASE+0x008,29)        /*!< Lowest Priority Flag for Mailbox 0 */
#define  bCAN_TSR_LOW1(CANx_BASE)     BIT_ADDR(CANx_BASE+0x008,30)        /*!< Lowest Priority Flag for Mailbox 1 */
#define  bCAN_TSR_LOW2(CANx_BASE)     BIT_ADDR(CANx_BASE+0x008,31)        /*!< Lowest Priority Flag for Mailbox 2 */

/*******************   RF0R ����FIFO 0�Ĵ���  *******************/
//#define  CAN_RF0R_FMP0(CANx_BASE)         ((uint8_t)0x03)               /*!< FIFO 0 ������Ŀ��ֻ����*/
#define  GET_CAN_RF0R_FMP0(CANx_BASE)   (MEM_ADDR(CANx_BASE+0x00C)&CAN_RF0R_FMP0)
#define  bCAN_RF0R_FULL0(CANx_BASE)   BIT_ADDR(CANx_BASE+0x00C,3)               /*!< FIFO 0 Full */
#define  bCAN_RF0R_FOVR0(CANx_BASE)   BIT_ADDR(CANx_BASE+0x00C,4)               /*!< FIFO 0 Overrun */
#define  bCAN_RF0R_RFOM0(CANx_BASE)   BIT_ADDR(CANx_BASE+0x00C,5)               /*!< Release FIFO 0 Output Mailbox */

/*******************   RF1R ����FIFO 1�Ĵ���  *******************/
//#define  CAN_RF1R_FMP1(CANx_BASE)         ((uint8_t)0x03)               /*!< FIFO 1 ������Ŀ��ֻ����*/
#define  GET_CAN_RF1R_FMP1(CANx_BASE)   (MEM_ADDR(CANx_BASE+0x010)&CAN_RF1R_FMP1)
#define  bCAN_RF1R_FULL1(CANx_BASE)   BIT_ADDR(CANx_BASE+0x010,3)               /*!< FIFO 1 Full */
#define  bCAN_RF1R_FOVR1(CANx_BASE)   BIT_ADDR(CANx_BASE+0x010,4)               /*!< FIFO 1 Overrun */
#define  bCAN_RF1R_RFOM1(CANx_BASE)   BIT_ADDR(CANx_BASE+0x010,5)               /*!< Release FIFO 1 Output Mailbox */

/********************   IER �ж�ʹ�ܼĴ���  *******************/
#define  bCAN_IER_TMEIE(CANx_BASE)    BIT_ADDR(CANx_BASE+0x014,0)        /*!< Transmit Mailbox Empty Interrupt Enable */
#define  bCAN_IER_FMPIE0(CANx_BASE)   BIT_ADDR(CANx_BASE+0x014,1)        /*!< FIFO Message Pending Interrupt Enable */
#define  bCAN_IER_FFIE0(CANx_BASE)    BIT_ADDR(CANx_BASE+0x014,2)        /*!< FIFO Full Interrupt Enable */
#define  bCAN_IER_FOVIE0(CANx_BASE)   BIT_ADDR(CANx_BASE+0x014,3)        /*!< FIFO Overrun Interrupt Enable */
#define  bCAN_IER_FMPIE1(CANx_BASE)   BIT_ADDR(CANx_BASE+0x014,4)        /*!< FIFO Message Pending Interrupt Enable */
#define  bCAN_IER_FFIE1(CANx_BASE)    BIT_ADDR(CANx_BASE+0x014,5)        /*!< FIFO Full Interrupt Enable */
#define  bCAN_IER_FOVIE1(CANx_BASE)   BIT_ADDR(CANx_BASE+0x014,6)        /*!< FIFO Overrun Interrupt Enable */
#define  bCAN_IER_EWGIE(CANx_BASE)    BIT_ADDR(CANx_BASE+0x014,8)        /*!< Error Warning Interrupt Enable */
#define  bCAN_IER_EPVIE(CANx_BASE)    BIT_ADDR(CANx_BASE+0x014,9)        /*!< Error Passive Interrupt Enable */
#define  bCAN_IER_BOFIE(CANx_BASE)    BIT_ADDR(CANx_BASE+0x014,10)        /*!< Bus-Off Interrupt Enable */
#define  bCAN_IER_LECIE(CANx_BASE)    BIT_ADDR(CANx_BASE+0x014,11)        /*!< Last Error Code Interrupt Enable */
#define  bCAN_IER_ERRIE(CANx_BASE)    BIT_ADDR(CANx_BASE+0x014,15)        /*!< Error Interrupt Enable */
#define  bCAN_IER_WKUIE(CANx_BASE)    BIT_ADDR(CANx_BASE+0x014,16)        /*!< Wakeup Interrupt Enable */
#define  bCAN_IER_SLKIE(CANx_BASE)    BIT_ADDR(CANx_BASE+0x014,17)        /*!< Sleep Interrupt Enable */

/********************   ESR ����״̬�Ĵ���  *******************/
#define  bCAN_ESR_EWGF(CANx_BASE)     BIT_ADDR(CANx_BASE+0x018,0)        /*!< Error Warning Flag */
#define  bCAN_ESR_EPVF(CANx_BASE)     BIT_ADDR(CANx_BASE+0x018,1)        /*!< Error Passive Flag */
#define  bCAN_ESR_BOFF(CANx_BASE)     BIT_ADDR(CANx_BASE+0x018,2)        /*!< Bus-Off Flag */
//#define  CAN_ESR_LEC	 ((uint32_t)0x00000070)        /*!< LEC[2:0] bits (Last Error Code) */
#define  SET_CAN_ESR_LEC(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x018,4,MASKb3,a)
#define  GET_CAN_ESR_LEC(CANx_BASE)   ((MEM_ADDR(CANx_BASE+0x018)&CAN_ESR_LEC)>>4)

//#define  CAN_ESR_TEC��ֻ���� ((uint32_t)0x00FF0000)        /*!< Least significant byte of the 9-bit Transmit Error Counter */
#define  GET_CAN_ESR_TEC(CANx_BASE)   ((MEM_ADDR(CANx_BASE+0x018)&CAN_ESR_TEC)>>16)
//#define  CAN_ESR_REC(CANx_BASE)��ֻ���� ((uint32_t)0xFF000000)        /*!< Receive Error Counter */
#define  GET_CAN_ESR_REC(CANx_BASE)   ((MEM_ADDR(CANx_BASE+0x018)&CAN_ESR_REC)>>24)

/*******************   BTR λʱ��Ĵ���  ********************/
//#define  CAN_BTR_BRP                          ((uint32_t)0x000003FF)        /*!< Baud Rate Prescaler */
#define  SET_CAN_BTR_BRP(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x01C,0,MASKb10,a)
//#define  CAN_BTR_TS1                        ((uint32_t)0x000F0000)        /*!< Time Segment 1 */
#define  SET_CAN_BTR_TS1(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x01C,16,MASKb4,a)
//#define  CAN_BTR_TS2                         ((uint32_t)0x00700000)        /*!< Time Segment 2 */
#define  SET_CAN_BTR_TS2(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x01C,20,MASKb3,a)

//#define  CAN_BTR_SJW                         ((uint32_t)0x03000000)        /*!< Resynchronization Jump Width */
#define  SET_CAN_BTR_SJW(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x01C,24,MASKb2,a)

#define  bCAN_BTR_LBKM                  BIT_ADDR(CANx_BASE+0x01C,30)        /*!< Loop Back Mode (Debug) */
#define  bCAN_BTR_SILM                  BIT_ADDR(CANx_BASE+0x01C,31)        /*!< Silent Mode */

/*!< ����Ĵ����� */
/******************   TI0R ���������ʶ���Ĵ���  ********************/
#define  bCAN_TI0R_TXRQ(CANx_BASE)      BIT_ADDR(CANx_BASE+0x180,0)        /*!< Transmit Mailbox Request */
#define  bCAN_TI0R_RTR(CANx_BASE)       BIT_ADDR(CANx_BASE+0x180,1)        /*!< Remote Transmission Request */
#define  bCAN_TI0R_IDE(CANx_BASE)       BIT_ADDR(CANx_BASE+0x180,2)        /*!< Identifier Extension */
//#define  CAN_TI0R_EXID                       ((uint32_t)0x001FFFF8)        /*!< Extended Identifier */

#define  SET_CAN_TI0R_EXID(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x180,3,MASKb18,a)
//#define  CAN_TI0R_STID                       ((uint32_t)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */
#define  SET_CAN_TI0R_STID(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x180,21,MASKb11,a)

/******************   TDT0R �������䳤�ȿ��Ƽ�ʱ���Ĵ���  *******************/
//#define  CAN_TDT0R_DLC                        ((uint32_t)0x0000000F)        /*!< Data Length Code */
#define  SET_CAN_TDT0R_DLC(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x184,0,MASKb4,a)

#define  bCAN_TDT0R_TGT(CANx_BASE)      BIT_ADDR(CANx_BASE+0x184,8)        /*!< Transmit Global Time */
//#define  CAN_TDT0R_TIME                      ((uint32_t)0xFFFF0000)        /*!< Message Time Stamp */
#define  SET_CAN_TDT0R_TIME(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x184,16,MASKb8,a)

/******************   TDL0R �����������ݵ��ֽڼĴ���  *******************/
#define  CAN_TDL0R(CANx_BASE)           (MEM_ADDR(CANx_BASE+0x188))/*!< Data byte 0-3 */

/******************   TDH0R �����������ݸ��ֽڼĴ���  *******************/
#define  CAN_TDH0R(CANx_BASE)           (MEM_ADDR(CANx_BASE+0x18C))/*!< Data byte 4-7 */

/*******************   TI1R ���������ʶ���Ĵ���  *******************/
#define  bCAN_TI1R_TXRQ(CANx_BASE)     BIT_ADDR(CANx_BASE+0x190,0)        /*!< Transmit Mailbox Request */
#define  bCAN_TI1R_RTR(CANx_BASE)      BIT_ADDR(CANx_BASE+0x190,1)        /*!< Remote Transmission Request */
#define  bCAN_TI1R_IDE(CANx_BASE)      BIT_ADDR(CANx_BASE+0x190,2)        /*!< Identifier Extension */
//#define  CAN_TI1R_EXID                       ((uint32_t)0x001FFFF8)        /*!< Extended Identifier */
#define  SET_CAN_TI1R_EXID(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x190,3,MASKb18,a)

//#define  CAN_TI1R_STID                       ((uint32_t)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */
#define  SET_CAN_TI1R_STID(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x190,21,MASKb11,a)

/*******************   TDT1R �������䳤�ȿ��Ƽ�ʱ���Ĵ���  ******************/
//#define  CAN_TDT1R_DLC                        ((uint32_t)0x0000000F)        /*!< Data Length Code */
#define  SET_CAN_TDT1R_DLC(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x194,0,MASKb4,a)

#define  bCAN_TDT1R_TGT                BIT_ADDR(CANx_BASE+0x194,8)        /*!< Transmit Global Time */
//#define  CAN_ TDT1R_TIME                      ((uint32_t)0xFFFF0000)        /*!< Message Time Stamp */
#define  SET_CAN_TDT1R_TIME(CANx_BASE,a)  SET_REG_BITn(CANx_BASE+0x194,16,MASKb8,a) 

/*******************   TDL1R �����������ݵ��ֽڼĴ���  ******************/
#define  CAN_TDL1R(CANx_BASE)           (MEM_ADDR(CANx_BASE+0x198))/*!< Data byte 0-3 */
/*******************   TDH1R �����������ݸ��ֽڼĴ���  ******************/
#define  CAN_TDH1R(CANx_BASE)           (MEM_ADDR(CANx_BASE+0x19C))/*!< Data byte 4-7 */

/*******************   TI2R ���������ʶ���Ĵ���  *******************/
#define  bCAN_TI2R_TXRQ(CANx_BASE)    BIT_ADDR(CANx_BASE+0x1A0,0)        /*!< Transmit Mailbox Request */
#define  bCAN_TI2R_RTR(CANx_BASE)     BIT_ADDR(CANx_BASE+0x1A0,1)        /*!< Remote Transmission Request */
#define  bCAN_TI2R_IDE(CANx_BASE)     BIT_ADDR(CANx_BASE+0x1A0,2)        /*!< Identifier Extension */
//#define  CAN_ TI2R_EXID                       ((uint32_t)0x001FFFF8)        /*!< Extended identifier */
#define  SET_CAN_TI2R_EXID(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x1A0,3,MASKb18,a)
//#define  CAN_ TI2R_STID                       ((uint32_t)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */
#define  SET_CAN_TI2R_STID(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x1A0,21,MASKb11,a)

/*******************   TDT2R �������䳤�ȿ��Ƽ�ʱ���Ĵ���  ******************/  
//#define  CAN_ TDT2R_DLC                        ((uint32_t)0x0000000F)        /*!< Data Length Code */
#define  SET_CAN_TDT2R_DLC(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x1A4,0,MASKb4,a)
#define  bCAN_TDT2R_TGT               BIT_ADDR(CANx_BASE+0x1A4,8)        /*!< Transmit Global Time */
//#define  CAN_ TDT2R_TIME                      ((uint32_t)0xFFFF0000)        /*!< Message Time Stamp */
#define  SET_CAN_TDT2R_TIME(CANx_BASE,a)   SET_REG_BITn(CANx_BASE+0x1A4,16,MASKb8,a)

/*******************   TDL2R �����������ݵ��ֽڼĴ���  ******************/
#define  CAN_TDL2R(CANx_BASE)           (MEM_ADDR(CANx_BASE+0x1A8))/*!< Data byte 0-3 */
/*******************   TDH2R �����������ݸ��ֽڼĴ���  ******************/
#define  CAN_TDH2R(CANx_BASE)           (MEM_ADDR(CANx_BASE+0x1AC))/*!< Data byte 4-7 */

/*******************   RI0R ����FIFO�����ʶ���Ĵ���  *******************/
#define  bCAN_RI0R_RTR                BIT_ADDR(CANx_BASE+0x1B0,1)        /*!< Remote Transmission Request */
#define  bCAN_RI0R_IDE                BIT_ADDR(CANx_BASE+0x1B0,2)        /*!< Identifier Extension */
//#define  CAN_RI0R_EXID                       ((uint32_t)0x001FFFF8)        /*!< Extended Identifier */
#define  GET_CAN_RI0R_EXID(CANx_BASE)   ((MEM_ADDR(CANx_BASE+0x1B0)&CAN_RI0R_EXID)>>3)
//#define  CAN_RI0R_STID                       ((uint32_t)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */
#define  GET_CAN_RI0R_STID(CANx_BASE)   ((MEM_ADDR(CANx_BASE+0x1B0)&CAN_RI0R_STID)>>21)

/*******************   RDT0R ����FIFO���䳤�ȿ��Ƽ�ʱ���Ĵ���  ******************/
//#define  CAN_RDT0R_DLC                        ((uint32_t)0x0000000F)        /*!< Data Length Code */
#define  GET_CAN_RDT0R_DLC(CANx_BASE)   (MEM_ADDR(CANx_BASE+0x1B4)&CAN_RDT0R_DLC)
//#define  CAN_RDT0R_FMI                        ((uint32_t)0x0000FF00)        /*!< Filter Match Index */
#define  GET_CAN_RDT0R_FMI(CANx_BASE)   ((MEM_ADDR(CANx_BASE+0x1B4)&CAN_RDT0R_FMI)>>8)
//#define  CAN_RDT0R_TIME                      ((uint32_t)0xFFFF0000)        /*!< Message Time Stamp */
#define  GET_CAN_RDT0R_TIME(CANx_BASE)   ((MEM_ADDR(CANx_BASE+0x1B4)&CAN_RDT0R_TIME)>>16)

/*******************   RDL0R ����FIFO�������ݵ��ֽڼĴ���  ******************/
#define  CAN_RDL0R(CANx_BASE)           (MEM_ADDR(CANx_BASE+0x1B8))/*!< Data byte 0-3 ��ֻ����*/

/*******************   RDH0R ����FIFO�������ݸ��ֽڼĴ���  ******************/
#define  CAN_RDH0R(CANx_BASE)           (MEM_ADDR(CANx_BASE+0x0x1BC))/*!< Data byte 4-7 ��ֻ����*/

/*******************   RI1R ����FIFO�����ʶ���Ĵ���  *******************/
#define  bCAN_RI1R_RTR(CANx_BASE)    BIT_ADDR(CANx_BASE+0x1C0,1)        /*!< Remote Transmission Request */
#define  bCAN_RI1R_IDE(CANx_BASE)    BIT_ADDR(CANx_BASE+0x1C0,2)        /*!< Identifier Extension */
//#define  CAN_RI1R_EXID                       ((uint32_t)0x001FFFF8)        /*!< Extended identifier */
#define  GET_CAN_RI1R_EXID(CANx_BASE,a)   ((MEM_ADDR(CANx_BASE+0x1C0)&CAN_RI1R_EXID)>>3)
//#define  CAN_RI1R_STID                       ((uint32_t)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */
#define  GET_CAN_RI1R_STID(CANx_BASE)   ((MEM_ADDR(CANx_BASE+0x1C0)&CAN_RI1R_STID)>>21)

/*******************   RDT1R ����FIFO���䳤�ȿ��Ƽ�ʱ���Ĵ���  ******************/
//#define  CAN_RDT1R_DLC                        ((uint32_t)0x0000000F)        /*!< Data Length Code */
#define  GET_CAN_RDT1R_DLC(CANx_BASE)   (MEM_ADDR(CANx_BASE+0x1C4)&CAN_RDT1R_DLC)
//#define  CAN_RDT1R_FMI                        ((uint32_t)0x0000FF00)        /*!< Filter Match Index */
#define  GET_CAN_RDT1R_FMI(CANx_BASE)   ((MEM_ADDR(CANx_BASE+0x1C4)&CAN_RDT1R_FMI)>>8)
//#define  CAN_RDT1R_TIME                      ((uint32_t)0xFFFF0000)        /*!< Message Time Stamp */
#define  GET_CAN_RDT1R_TIME(CANx_BASE)   ((MEM_ADDR(CANx_BASE+0x1C4)&CAN_RDT1R_TIME)>>16)

/*******************   RDL1R ����FIFO�������ݵ��ֽڼĴ���  ******************/
#define  CAN_RDL1R(CANx_BASE)           (MEM_ADDR(CANx_BASE+0x1C8))/*!< Data byte 0-3 ��ֻ����*/

/*******************   RDH1R ����FIFO�������ݸ��ֽڼĴ���  ******************/
#define  CAN_RDH1R(CANx_BASE)           (MEM_ADDR(CANx_BASE+0x1CC))/*!< Data byte 4-7��ֻ���� */

/*!< CAN�������� */
/*******************   FMR ���������Ĵ���  ********************/
#define  bCAN_FMR_FINIT(CANx_BASE)    BIT_ADDR(CANx_BASE+0x200,0)             /*!< Filter Init Mode */

/*******************   FM1R ������ģʽ�Ĵ���  *******************/
//#define  CAN_FM1R_FBM                        ((uint16_t)0x3FFF)            /*!< Filter Mode */
#define  bCAN_FM1R_FBM(CANx_BASE,n)   BIT_ADDR(CANx_BASE+0x204,n)


/*******************   FS1R �����������Ĵ���  *******************/
//#define  CAN_FS1R_FSC                        ((uint16_t)0x3FFF)            /*!< Filter Scale Configuration */
#define  bCAN_FS1R_FSC(CANx_BASE,n)    BIT_ADDR(CANx_BASE+0x20C,n)

/******************   FFA1R ������FIFO����Ĵ���  *******************/
//#define  CAN_FFA1R_FFA                       ((uint16_t)0x3FFF)            /*!< Filter FIFO Assignment */
#define  bCAN_FFA1R_FFA(CANx_BASE,n)   BIT_ADDR(CANx_BASE+0x214,n)


/*******************   FA1R ����������Ĵ���  *******************/
//#define  CAN_ FA1R_FACT                       ((uint16_t)0x3FFF)            /*!< Filter Active */
#define  bCAN_FA1R_FACT(CANx_BASE,n)   BIT_ADDR(CANx_BASE+0x21C,n)


/*******************   F0R1 �������Ĵ�����0  *******************/
#define  bCAN_F0R1_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x240,n)/*!< Filter bit 0-31 */
#define  bCAN_F0R2_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x244,n)/*!< Filter bit 0-31 */

/*******************   F1R1 �������Ĵ�����1  *******************/
#define  bCAN_F1R1_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x248,n)/*!< Filter bit 0-31 */
#define  bCAN_F1R2_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x24C,n)/*!< Filter bit 0-31 */

/*******************   F2R1 �������Ĵ�����2  *******************/
#define  bCAN_F2R1_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x250,n)/*!< Filter bit 0-31 */
#define  bCAN_F2R2_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x254,n)/*!< Filter bit 0-31 */

/*******************   F3R1 �������Ĵ�����3  *******************/
#define  bCAN_F3R1_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x258,n)/*!< Filter bit 0-31 */
#define  bCAN_F3R2_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x25C,n)/*!< Filter bit 0-31 */

/*******************   F4R1 �������Ĵ�����4  *******************/
#define  bCAN_F4R1_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x260,n)/*!< Filter bit 0-31 */
#define  bCAN_F4R2_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x264,n)/*!< Filter bit 0-31 */

/*******************   F5R1 �������Ĵ�����5  *******************/
#define  bCAN_F5R1_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x268,n)/*!< Filter bit 0-31 */
#define  bCAN_F5R2_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x26C,n)/*!< Filter bit 0-31 */

/*******************   F6R1 �������Ĵ�����6  *******************/
#define  bCAN_F6R1_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x270,n)/*!< Filter bit 0-31 */
#define  bCAN_F6R2_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x274,n)/*!< Filter bit 0-31 */

/*******************   F7R1 �������Ĵ�����7  *******************/
#define  bCAN_F7R1_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x278,n)/*!< Filter bit 0-31 */
#define  bCAN_F7R2_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x27C,n)/*!< Filter bit 0-31 */

/*******************   F8R1 �������Ĵ�����8  *******************/
#define  bCAN_F8R1_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x280,n)/*!< Filter bit 0-31 */
#define  bCAN_F8R2_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x284,n)/*!< Filter bit 0-31 */

/*******************   F9R1 �������Ĵ�����9  *******************/
#define  bCAN_F9R1_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x288,n)/*!< Filter bit 0-31 */
#define  bCAN_F9R2_FB(CANx_BASE,n)     BIT_ADDR(CANx_BASE+0x28C,n)/*!< Filter bit 0-31 */

/*******************   F10R1 �������Ĵ�����10  ******************/
#define  bCAN_F10R1_FB(CANx_BASE,n)    BIT_ADDR(CANx_BASE+0x290,n)/*!< Filter bit 0-31 */
#define  bCAN_F10R2_FB(CANx_BASE,n)    BIT_ADDR(CANx_BASE+0x294,n)/*!< Filter bit 0-31 */

/*******************   F11R1 �������Ĵ�����11  ******************/
#define  bCAN_F11R1_FB(CANx_BASE,n)    BIT_ADDR(CANx_BASE+0x298,n)/*!< Filter bit 0-31 */
#define  bCAN_F11R2_FB(CANx_BASE,n)    BIT_ADDR(CANx_BASE+0x29C,n)/*!< Filter bit 0-31 */

/*******************   F12R1 �������Ĵ�����12  ******************/
#define  bCAN_F12R1_FB(CANx_BASE,n)    BIT_ADDR(CANx_BASE+0x2A0,n)/*!< Filter bit 0-31 */
#define  bCAN_F12R2_FB(CANx_BASE,n)    BIT_ADDR(CANx_BASE+0x2A4,n)/*!< Filter bit 0-31 */

/*******************   F13R1 �������Ĵ�����13  ******************/
#define  bCAN_F13R1_FB(CANx_BASE,n)    BIT_ADDR(CANx_BASE+0x2A8,n)/*!< Filter bit 0-31 */
#define  bCAN_F13R2_FB(CANx_BASE,n)    BIT_ADDR(CANx_BASE+0x2AC,n)/*!< Filter bit 0-31 */

/******************************************************************************/
/*                                                                            */
/*                      I2C�ӿ�                                               */
/*                                                                            */
/******************************************************************************/

/*******************  I2C_CR1 ���ƼĴ���  ********************/
#define  bI2C_CR_PE(I2Cx_BASE)            BIT_ADDR(I2Cx_BASE +0x00,0)            /*!< Peripheral Enable */
#define  bI2C_CR_SMBUS(I2Cx_BASE )         BIT_ADDR(I2Cx_BASE +0x00,1)            /*!< SMBus Mode */
#define  bI2C_CR_SMBTYPE(I2Cx_BASE )       BIT_ADDR(I2Cx_BASE +0x00,3)            /*!< SMBus Type */
#define  bI2C_CR_ENARP(I2Cx_BASE )         BIT_ADDR(I2Cx_BASE +0x00,4)            /*!< ARP Enable */
#define  bI2C_CR_ENPEC(I2Cx_BASE )         BIT_ADDR(I2Cx_BASE +0x00,5)            /*!< PEC Enable */
#define  bI2C_CR_ENGC(I2Cx_BASE )          BIT_ADDR(I2Cx_BASE +0x00,6)            /*!< General Call Enable */
#define  bI2C_CR_NOSTRETCH(I2Cx_BASE )     BIT_ADDR(I2Cx_BASE +0x00,7)            /*!< Clock Stretching Disable (Slave mode) */
#define  bI2C_CR_START(I2Cx_BASE )         BIT_ADDR(I2Cx_BASE +0x00,8)            /*!< Start Generation */
#define  bI2C_CR_STOP(I2Cx_BASE )          BIT_ADDR(I2Cx_BASE +0x00,9)            /*!< Stop Generation */
#define  bI2C_CR_ACK(I2Cx_BASE )           BIT_ADDR(I2Cx_BASE +0x00,10)            /*!< Acknowledge Enable */
#define  bI2C_CR_POS(I2Cx_BASE )           BIT_ADDR(I2Cx_BASE +0x00,11)            /*!< Acknowledge/PEC Position (for data reception) */
#define  bI2C_CR_PEC(I2Cx_BASE )           BIT_ADDR(I2Cx_BASE +0x00,12)            /*!< Packet Error Checking */
#define  bI2C_CR_ALERT(I2Cx_BASE )         BIT_ADDR(I2Cx_BASE +0x00,13)            /*!< SMBus Alert */
#define  bI2C_CR_SWRST(I2Cx_BASE )         BIT_ADDR(I2Cx_BASE +0x00,15)            /*!< Software Reset */

/*******************  I2C_CR2 ���ƼĴ���  ********************/
/*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define  SET_I2C_CR_FREQ(CANx_BASE,a)   SET_REG_BITn(I2Cx_BASE +0x04,0,MASKb6,a)

#define  bI2C_CR_ITERREN(I2Cx_BASE )       BIT_ADDR(I2Cx_BASE +0x04,8)            /*!< Error Interrupt Enable */
#define  bI2C_CR_ITEVTEN(I2Cx_BASE )       BIT_ADDR(I2Cx_BASE +0x04,9)            /*!< Event Interrupt Enable */
#define  bI2C_CR_ITBUFEN(I2Cx_BASE )       BIT_ADDR(I2Cx_BASE +0x04,10)            /*!< Buffer Interrupt Enable */
#define  bI2C_CR_DMAEN(I2Cx_BASE )         BIT_ADDR(I2Cx_BASE +0x04,11)            /*!< DMA Requests Enable */
#define  bI2C_CR_LAST(I2Cx_BASE )          BIT_ADDR(I2Cx_BASE +0x04,12)            /*!< DMA Last Transfer */

/*******************  I2C_OAR1 �����ַ�Ĵ���  *******************/
/*!< Interface Address */
#define  SET_I2C_OAR_ADD1_7(I2Cx_BASE ,a)   SET_REG_BITn(I2Cx_BASE +0x08,1,MASKb7,a)

/*!< Interface Address */
#define  SET_I2C_OAR_ADD8_9(I2Cx_BASE ,a)   SET_REG_BITn(I2Cx_BASE +0x08,8,MASKb2,a)

#define  bI2C_OAR_ADD0                       BIT_ADDR(I2Cx_BASE +0x08,0)            /*!< Bit 0 */
#define  bI2C_OAR_ADDMODE(I2Cx_BASE )        BIT_ADDR(I2Cx_BASE +0x08,15)            /*!< Addressing Mode (Slave mode) */

/*******************  I2C_OAR2 �����ַ�Ĵ���  *******************/
#define  bI2C_OAR_ENDUAL(I2Cx_BASE )         BIT_ADDR(I2Cx_BASE +0x0C,0)               /*!< Dual addressing mode enable */
/*!< Interface address */
#define  SET_I2C_OAR_ADD2(I2Cx_BASE ,a)   SET_REG_BITn(I2Cx_BASE +0x0C,1,MASKb7,a)

/********************  I2C_DR ���ݼĴ���  ********************/
//#define  I2C_DR_DR                           ((uint8_t)0xFF)               /*!< 8-bit Data Register */
#define  I2C_DR(I2Cx_BASE)   				(MEM_ADDR(I2Cx_BASE +0x10)&I2C_DR_DR)
/*******************  I2C_SR1 ״̬�Ĵ���  ********************/
#define  bI2C_SR_SB(I2Cx_BASE )                          BIT_ADDR(I2Cx_BASE +0x14,0)            /*!< Start Bit (Master mode) */
#define  bI2C_SR_ADDR(I2Cx_BASE )                        BIT_ADDR(I2Cx_BASE +0x14,1)            /*!< Address sent (master mode)/matched (slave mode) */
#define  bI2C_SR_BTF(I2Cx_BASE )                         BIT_ADDR(I2Cx_BASE +0x14,2)            /*!< Byte Transfer Finished */
#define  bI2C_SR_ADD10(I2Cx_BASE )                       BIT_ADDR(I2Cx_BASE +0x14,3)            /*!< 10-bit header sent (Master mode) */
#define  bI2C_SR_STOPF(I2Cx_BASE )                       BIT_ADDR(I2Cx_BASE +0x14,4)            /*!< Stop detection (Slave mode) */
#define  bI2C_SR_RXNE(I2Cx_BASE )                        BIT_ADDR(I2Cx_BASE +0x14,6)            /*!< Data Register not Empty (receivers) */
#define  bI2C_SR_TXE(I2Cx_BASE )                         BIT_ADDR(I2Cx_BASE +0x14,7)            /*!< Data Register Empty (transmitters) */
#define  bI2C_SR_BERR(I2Cx_BASE )                        BIT_ADDR(I2Cx_BASE +0x14,8)            /*!< Bus Error */
#define  bI2C_SR_ARLO(I2Cx_BASE )                        BIT_ADDR(I2Cx_BASE +0x14,9)            /*!< Arbitration Lost (master mode) */
#define  bI2C_SR_AF(I2Cx_BASE )                          BIT_ADDR(I2Cx_BASE +0x14,10)            /*!< Acknowledge Failure */
#define  bI2C_SR_OVR(I2Cx_BASE )                         BIT_ADDR(I2Cx_BASE +0x14,11)            /*!< Overrun/Underrun */
#define  bI2C_SR_PECERR(I2Cx_BASE )                      BIT_ADDR(I2Cx_BASE +0x14,12)            /*!< PEC Error in reception */
#define  bI2C_SR_TIMEOUT(I2Cx_BASE )                     BIT_ADDR(I2Cx_BASE +0x14,14)            /*!< Timeout or Tlow Error */
#define  bI2C_SR_SMBALERT(I2Cx_BASE )                    BIT_ADDR(I2Cx_BASE +0x14,15)            /*!< SMBus Alert */

/*******************  I2C_SR2 ״̬�Ĵ�����ֻ����  ********************/
#define  bI2C_SR_MSL(I2Cx_BASE )                         BIT_ADDR(I2Cx_BASE +0x18,0)            /*!< Master/Slave */
#define  bI2C_SR_BUSY(I2Cx_BASE )                        BIT_ADDR(I2Cx_BASE +0x18,1)            /*!< Bus Busy */
#define  bI2C_SR_TRA(I2Cx_BASE )                         BIT_ADDR(I2Cx_BASE +0x18,2)            /*!< Transmitter/Receiver */
#define  bI2C_SR_GENCALL(I2Cx_BASE )                     BIT_ADDR(I2Cx_BASE +0x18,4)            /*!< General Call Address (Slave mode) */
#define  bI2C_SR_SMBDEFAULT(I2Cx_BASE )                  BIT_ADDR(I2Cx_BASE +0x18,5)            /*!< SMBus Device Default Address (Slave mode) */
#define  bI2C_SR_SMBHOST(I2Cx_BASE )                     BIT_ADDR(I2Cx_BASE +0x18,6)            /*!< SMBus Host Header (Slave mode) */
#define  bI2C_SR_DUALF(I2Cx_BASE )                       BIT_ADDR(I2Cx_BASE +0x18,7)            /*!< Dual Flag (Slave mode) */
//#define  I2C_SR_PEC          ((uint16_t)0xFF00)            /*!< ������У��Ĵ�����ֻ���� */
#define  GET_I2C_SR_PEC(I2Cx_BASE )  				((MEM_ADDR(I2Cx_BASE +0x18)&I2C_SR_PEC)>>8)
/*******************  I2C_CCR ʱ�ӿ��ƼĴ���  ********************/
/*!< Clock Control Register in Fast/Standard mode (Master mode) */
#define  SET_I2C_CCR_CCR(I2Cx_BASE ,a)   SET_REG_BITn(I2Cx_BASE +0x1C,0,MASKb12,a)

#define  bI2C_CCR_DUTY(I2Cx_BASE )                        BIT_ADDR(I2Cx_BASE +0x1C,14)            /*!< Fast Mode Duty Cycle */
#define  bI2C_CCR_FS(I2Cx_BASE )                          BIT_ADDR(I2Cx_BASE +0x00,15)            /*!< I2C Master Mode Selection */

/******************  I2C_TRISE�Ĵ���  *******************/
/*!< Maximum Rise Time in Fast/Standard mode (Master mode) */
#define  SET_I2C_TRISE_TRISE(I2Cx_BASE ,a)   SET_REG_BITn(I2Cx_BASE +0x20,0,MASKb6,a)

/******************************************************************************/
/*                                                                            */
/*                             DMA ������                                     */
/*                                                                            */
/******************************************************************************/
//ÿ��DMA����������ʵ�����������7���໥������DMAͨ�����
//�����ú����n��ʾDMAͨ���ţ�n=1-7
/*******************   DMA_ISR �Ĵ��� ********************/
#define  bDMA_ISR_GIF(DMAx_BASE,n)	BIT_ADDR(DMAx_BASE+0x00,n*4)     /*!< ͨ��n ȫ���жϱ�־ */
#define  bDMA_ISR_TCIF(DMAx_BASE,n)	BIT_ADDR(DMAx_BASE+0x00,n*4+1)   /*!< ͨ��n ��������жϱ�־ */
#define  bDMA_ISR_HTIF(DMAx_BASE,n)	BIT_ADDR(DMAx_BASE+0x00,n*4+2)    /*!< ͨ��n ���䵽���жϱ�־ */
#define  bDMA_ISR_TEIF(DMAx_BASE,n)	BIT_ADDR(DMAx_BASE+0x00,n*4+3)    /*!< ͨ��n ��������жϱ�־ */

/*******************   DMA_IFCR �Ĵ��� *******************/
#define  bDMA_IFCR_CGIF(DMAx_BASE,n)	BIT_ADDR(DMAx_BASE+0x04,ch*4)     /*!< ͨ��n ȫ���жϱ�־��� */
#define  bDMA_IFCR_CTCIF(DMAx_BASE,n)	BIT_ADDR(DMAx_BASE+0x04,ch*4+1)   /*!< ͨ��n ��������жϱ�־��� */
#define  bDMA_IFCR_CHTIF(DMAx_BASE,n)	BIT_ADDR(DMAx_BASE+0x04,ch*4+2)    /*!< ͨ��n ���䵽���жϱ�־��� */
#define  bDMA_IFCR_CTEIF(DMAx_BASE,n)	BIT_ADDR(DMAx_BASE+0x04,ch*4+3)    /*!< ͨ��n ��������жϱ�־��� */

/*******************   DMA_CCRx �Ĵ��� *******************/
#define  bDMA_CCRx_EN(DMAx_BASE,n)      BIT_ADDR(DMAx_BASE+0x08+n*20,0)     /*!< ͨ��n ʹ�� */
#define  bDMA_CCRx_TCIE(DMAx_BASE,n)    BIT_ADDR(DMAx_BASE+0x08+n*20,1)     /*!< ͨ��n ��������ж�ʹ�� */
#define  bDMA_CCRx_HTIE(DMAx_BASE,n)    BIT_ADDR(DMAx_BASE+0x08+n*20,2)     /*!< ͨ��n ���䵽���ж�ʹ�� */
#define  bDMA_CCRx_TEIE(DMAx_BASE,n)    BIT_ADDR(DMAx_BASE+0x08+n*20,3)     /*!< ͨ��n ��������ж�ʹ�� */
#define  bDMA_CCRx_DIR(DMAx_BASE,n)     BIT_ADDR(DMAx_BASE+0x08+n*20,4)     /*!< ͨ��n ���ݴ��䷽�� */
#define  bDMA_CCRx_CIRC(DMAx_BASE,n)    BIT_ADDR(DMAx_BASE+0x08+n*20,5)    /*!< ͨ��n ѭ��ģʽ */
#define  bDMA_CCRx_PINC(DMAx_BASE,n)    BIT_ADDR(DMAx_BASE+0x08+n*20,6)    /*!< ͨ��n �����ַ����ģʽ */
#define  bDMA_CCRx_MINC(DMAx_BASE,n)    BIT_ADDR(DMAx_BASE+0x08+n*20,7)    /*!< ͨ��n �洢����ַ����ģʽ */

#define  SET_DMA_CCRx_PSIZE(DMAx_BASE,n,a)   SET_REG_BITn(DMAx_BASE+0x08+n*20,8,MASKb2,a)
/*!< PSIZE[1:0] bits (ͨ��n �������ݿ��00: 8λ��01: 16λ��10: 32λ��) */

#define  SET_DMA_CCRx_MSIZE(DMAx_BASE,n,a)   SET_REG_BITn(DMAx_BASE+0x08+n*20,10,MASKb2,a)
/*!< MSIZE[1:0] bits (ͨ��n �洢�����ݿ��00: 8λ��01: 16λ��10: 32λ��) */

#define  SET_DMA_CCRx_PL(DMAx_BASE,n,a)   SET_REG_BITn(DMAx_BASE+0x08+n*20,12,MASKb2,a)
/*!< PL[1:0] bits(ͨ��n ���ȼ�00�͡�01�С�10�ߡ�11��ߣ�) */

#define  bDMA_CCRx_MEM2MEM(DMAx_BASE,n) BIT_ADDR(DMAx_BASE+0x08+n*20,13)    /*!< ͨ��n �洢�����洢��ģʽ */

/******************   DMA_CNDTRx �Ĵ��� ******************/
#define  DMA_CNDTRx_NDT(DMAx_BASE,n)    (MEM_ADDR(DMAx_BASE+0x0C+n*20)      /*!< ͨ��n �������ݼ��� */


/******************   DMA_CPARx �Ĵ��� *******************/
#define  DMA_CPARx_PA(DMAx_BASE,n)    (MEM_ADDR(DMAx_BASE+0x10+n*20)        /*!< ͨ��n �����ַ�Ĵ���32λ */


/******************   DMA_CMARx �Ĵ��� *******************/
#define  DMA_CMARx_MA(DMAx_BASE,n)    (MEM_ADDR(DMAx_BASE+0x14+n*20)        /*!< ͨ��n �洢����ַ�Ĵ���32λ */


/******************************************************************************/
/*                                                                            */
/*                        ADCģ��ת����                                       */
/*                                                                            */
/******************************************************************************/

/********************   ADC_SR �Ĵ��� ********************/
#define  bADC_SR_AWD(ADCx_BASE)      BIT_ADDR(ADCx_BASE+0x00,0)               /*!< ģ�⹷��־λ */
#define  bADC_SR_EOC(ADCx_BASE)      BIT_ADDR(ADCx_BASE+0x00,1)               /*!< ת��������EOC��*/
#define  bADC_SR_JEOC(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x00,2)               /*!< ע��ͨ��ת������ */
#define  bADC_SR_JSTRT(ADCx_BASE)    BIT_ADDR(ADCx_BASE+0x00,3)               /*!< ע��ͨ��������־ */
#define  bADC_SR_STRT(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x00,4)               /*!< ����ͨ��������־ */

/*******************   ADC_CR1 �Ĵ��� ********************/
/*!< AWDCH[4:0] bits (ģ�⹷���ͨ��ѡ��) */
#define  SET_ADC_CR_AWDCH(ADCx_BASE ,a)   SET_REG_BITn(ADCx_BASE+0x04,0,MASKb5,a)

#define  bADC_CR_EOCIE(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x04,5)        /*!< ת��������EOC���ж�ʹ�� */
#define  bADC_CR_AWDIE(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x04,6)        /*!< ģ�⹷�ж�ʹ�� */
#define  bADC_CR_JEOCIE(ADCx_BASE)    BIT_ADDR(ADCx_BASE+0x04,7)        /*!< ע��ͨ���ж�ʹ�� */
#define  bADC_CR_SCAN(ADCx_BASE)      BIT_ADDR(ADCx_BASE+0x04,8)        /*!< ɨ��ģʽ */
#define  bADC_CR_AWDSGL(ADCx_BASE)    BIT_ADDR(ADCx_BASE+0x04,9)        /*!< Enable the watchdog on a single channel in scan mode */
#define  bADC_CR_JAUTO(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x04,10)        /*!< Automatic injected group conversion */
#define  bADC_CR_DISCEN(ADCx_BASE)    BIT_ADDR(ADCx_BASE+0x04,11)        /*!< Discontinuous mode on regular channels */
#define  bADC_CR_JDISCEN(ADCx_BASE)   BIT_ADDR(ADCx_BASE+0x04,12)        /*!< Discontinuous mode on injected channels */

 /*!< DISCNUM[2:0] bits (���ģʽͨ������) */
#define  SET_ADC_CR_DISCNUM(ADCx_BASE ,a)   SET_REG_BITn(ADCx_BASE+0x04,13,MASKb3,a)

/*!< DUALMOD[3:0] bits (˫ADCģʽѡ��) */
#define  SET_ADC_CR_DUALMOD(ADCx_BASE ,a)   SET_REG_BITn(ADCx_BASE+0x04,16,MASKb4,a)

#define  bADC_CR_JAWDEN(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x04,22)        /*!< Analog watchdog enable on injected channels */
#define  bADC_CR_AWDEN(ADCx_BASE)      BIT_ADDR(ADCx_BASE+0x04,23)        /*!< Analog watchdog enable on regular channels */

  
/*******************   ADC_CR2 �Ĵ��� ********************/
#define  bADC_CR_ADON(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x08,0)        /*!< A/D Converter ON / OFF */
#define  bADC_CR_CONT(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x08,1)        /*!< Continuous Conversion */
#define  bADC_CR_CAL(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x08,2)        /*!< A/D Calibration */
#define  bADC_CR_RSTCAL(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x08,3)        /*!< Reset Calibration */
#define  bADC_CR_DMA(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x08,8)        /*!< Direct Memory access mode */
#define  bADC_CR_ALIGN(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x08,11)        /*!< Data Alignment */

//#define  ADC_CR2_JEXTSEL                     ((uint32_t)0x00007000)        /*!< JEXTSEL[2:0] bits (External event select for injected group) */
#define  SET_ADC_CR_JEXTSEL(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x08,12,MASKb3,a)

#define  bADC_CR_JEXTTRIG(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x08,15)        /*!< External Trigger Conversion mode for injected channels */

//#define  ADC_CR2_EXTSEL                      ((uint32_t)0x000E0000)        /*!< EXTSEL[2:0] bits (External Event Select for regular group) */
#define  SET_ADC_CR_EXTSEL(ADCx_BASE,a)    SET_REG_BITn(ADCx_BASE+0x08,17,MASKb3,a)

#define  bADC_CR_EXTTRIG(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x08,20)        /*!< External Trigger Conversion mode for regular channels */
#define  bADC_CR_JSWSTART(ADCx_BASE)    BIT_ADDR(ADCx_BASE+0x08,21)        /*!< Start Conversion of injected channels */
#define  bADC_CR_SWSTART(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x08,22)        /*!< Start Conversion of regular channels */
#define  bADC_CR_TSVREFE(ADCx_BASE)     BIT_ADDR(ADCx_BASE+0x08,23)        /*!< Temperature Sensor and VREFINT Enable */

/******************   ADC_SMPR1/2 �Ĵ��� *******************/
/* 3bits (18��ͨ�����ɶ������ò���ʱ����) */
#define  SET_ADC_SMP0(ADCx_BASE,a)   	SET_REG_BITn(ADCx_BASE+0x10,0,MASKb3,a)
#define  SET_ADC_SMP1(ADCx_BASE,a)   	SET_REG_BITn(ADCx_BASE+0x10,3,MASKb3,a)
#define  SET_ADC_SMP2(ADCx_BASE,a)   	SET_REG_BITn(ADCx_BASE+0x10,6,MASKb3,a)
#define  SET_ADC_SMP3(ADCx_BASE,a)   	SET_REG_BITn(ADCx_BASE+0x10,9,MASKb3,a)
#define  SET_ADC_SMP4(ADCx_BASE,a)   	SET_REG_BITn(ADCx_BASE+0x10,12,MASKb3,a)
#define  SET_ADC_SMP5(ADCx_BASE,a)   	SET_REG_BITn(ADCx_BASE+0x10,15,MASKb3,a)
#define  SET_ADC_SMP6(ADCx_BASE,a)   	SET_REG_BITn(ADCx_BASE+0x10,18,MASKb3,a)
#define  SET_ADC_SMP7(ADCx_BASE,a)   	SET_REG_BITn(ADCx_BASE+0x10,21,MASKb3,a)
#define  SET_ADC_SMP8(ADCx_BASE,a)   	SET_REG_BITn(ADCx_BASE+0x10,24,MASKb3,a)
#define  SET_ADC_SMP9(ADCx_BASE,a)   	SET_REG_BITn(ADCx_BASE+0x10,27,MASKb3,a)
#define  SET_ADC_SMP10(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x0C,0,MASKb3,a)
#define  SET_ADC_SMP11(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x0C,3,MASKb3,a)
#define  SET_ADC_SMP12(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x0C,6,MASKb3,a)
#define  SET_ADC_SMP13(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x0C,9,MASKb3,a)
#define  SET_ADC_SMP14(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x0C,12,MASKb3,a)
#define  SET_ADC_SMP15(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x0C,15,MASKb3,a)
#define  SET_ADC_SMP16(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x0C,18,MASKb3,a)
#define  SET_ADC_SMP17(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x0C,21,MASKb3,a)

/******************   ADC_JOFR1 �Ĵ��� *******************/
#define  ADC_JOFFSET1(ADCx_BASE)    (MEM_ADDR(ADCx_BASE +0x14))   /*!< ע��ͨ��1 ����ƫ���� */

/******************   ADC_JOFR2 �Ĵ��� *******************/
#define  ADC_JOFFSET2(ADCx_BASE)    (MEM_ADDR(ADCx_BASE +0x18))   /*!< ע��ͨ��2 ����ƫ���� */

/******************   ADC_JOFR3 �Ĵ��� *******************/
#define  ADC_JOFFSET3(ADCx_BASE)    (MEM_ADDR(ADCx_BASE +0x1C))    /*!< ע��ͨ��3 ����ƫ���� */

/******************   ADC_JOFR4 �Ĵ��� *******************/
#define  ADC_JOFFSET4(ADCx_BASE)    (MEM_ADDR(ADCx_BASE +0x20))    /*!< ע��ͨ��4 ����ƫ���� */

/*******************   ADC_HTR �Ĵ��� ********************/
#define  ADC_HT(ADCx_BASE)    (MEM_ADDR(ADCx_BASE +0x24))          /*!< ģ�⿴�Ź���ֵ���� */

/*******************   ADC_LTR �Ĵ��� ********************/
#define  ADC_LT(ADCx_BASE)    (MEM_ADDR(ADCx_BASE +0x28))          /*!< ģ�⿴�Ź���ֵ���� */

/*******************   ADC_SQR1/2/3 �Ĵ��� *******************/
/*������������У�����Ԫ�����16����ÿԪ����5BIT��ʾ��������Ӧ��ͨ����0��17 */
#define  SET_ADC_SQ1(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x34,0,MASKb5,a)
#define  SET_ADC_SQ2(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x34,5,MASKb5,a)
#define  SET_ADC_SQ3(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x34,10,MASKb5,a)
#define  SET_ADC_SQ4(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x34,15,MASKb5,a)
#define  SET_ADC_SQ5(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x34,20,MASKb5,a)
#define  SET_ADC_SQ6(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x34,25,MASKb5,a)
#define  SET_ADC_SQ7(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x30,0,MASKb5,a)
#define  SET_ADC_SQ8(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x30,5,MASKb5,a)
#define  SET_ADC_SQ9(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x30,10,MASKb5,a)
#define  SET_ADC_SQ10(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x30,15,MASKb5,a)
#define  SET_ADC_SQ11(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x30,20,MASKb5,a)
#define  SET_ADC_SQ12(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x30,25,MASKb5,a)
#define  SET_ADC_SQ13(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x2C,0,MASKb5,a)
#define  SET_ADC_SQ14(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x2C,5,MASKb5,a)
#define  SET_ADC_SQ15(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x2C,10,MASKb5,a)
#define  SET_ADC_SQ16(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x2C,15,MASKb5,a)
/*!< 4BIT��������������еĳ��ȣ�0-15�ֱ��ʾ1-16 */
#define  SET_ADC_SQR_L(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x2C,20,MASKb4,a)


/*******************   ADC_JSQR �Ĵ��� *******************/
/*!< ����ע�������У�����Ԫ�����4����ÿԪ����5BIT��ʾ��������Ӧ��ͨ����0��17 */
#define  SET_ADC_JSQ1(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x38,0,MASKb5,a)
#define  SET_ADC_JSQ2(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x38,5,MASKb5,a)
#define  SET_ADC_JSQ3(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x38,10,MASKb5,a)
#define  SET_ADC_JSQ4(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x38,15,MASKb5,a)

//#define  ADC_JSQR_JL                         ((uint32_t)0x00300000)        /*!< JL[1:0] bits (ע�������г��ȣ�0-3�ֱ��ʾ1-4) */
#define  SET_ADC_JSQR_JL(ADCx_BASE,a)   SET_REG_BITn(ADCx_BASE+0x38,20,MASKb2,a)

/*******************   ADC_JDR1 �Ĵ��� *******************/
#define  ADC_JDR1(ADCx_BASE)    (MEM_ADDR(ADCx_BASE +0x3C))			/*!< ע��ͨ��1 ���ݼĴ��� */

/*******************   ADC_JDR2 �Ĵ��� *******************/
#define  ADC_JDR2(ADCx_BASE)    (MEM_ADDR(ADCx_BASE +0x40))     /*!< ע��ͨ��2 ���ݼĴ��� */

/*******************   ADC_JDR3 �Ĵ��� *******************/
#define  ADC_JDR3(ADCx_BASE)    (MEM_ADDR(ADCx_BASE +0x44))     /*!< ע��ͨ��3 ���ݼĴ��� */

/*******************   ADC_JDR4 �Ĵ��� *******************/
#define  ADC_JDR4(ADCx_BASE)    (MEM_ADDR(ADCx_BASE +0x48))     /*!< ע��ͨ��4 ���ݼĴ��� */

/********************   ADC_DR �Ĵ��� ********************/
#define  ADC_DR(ADCx_BASE)    		(MEM_ADDR(ADCx_BASE +0x4C))        /*!< ����ͨ�� ���ݼĴ�����32λ�����е�12λΪADCת��ֵ�� */
#define  ADC_DR_ADC2(ADCx_BASE) 	((MEM_ADDR(ADCx_BASE +0x4C))>>16)  /*!< ˫ADCʱADC2 ���ݣ�ʵΪ�����Ĵ����ĸ�λ�� */
/*************************************************************************************************************************/


/******************************************************************************/
/*                                                                            */
/*                      DAC��ģת����                                         */
/*                                                                            */
/******************************************************************************/
//ע��һ��оƬֻ��һ��DAC���裬Ϊ���ݶ��DAC�������Բ���DACx����ʽ������ʱ��Ӳ���bDAC����ADC��USART������һ�¡�
#define bDAC	DAC_BASE
/********************   DAC_CR �Ĵ��� ******************00**/
#define  bDAC_CR_EN1(DACx_BASE)         BIT_ADDR(DACx_BASE+0x00,0)        /*!< DAC channel1 enable */
#define  bDAC_CR_BOFF1(DACx_BASE)       BIT_ADDR(DACx_BASE+0x00,1)        /*!< DAC channel1 output buffer disable */
#define  bDAC_CR_TEN1(DACx_BASE)        BIT_ADDR(DACx_BASE+0x00,2)        /*!< DAC channel1 Trigger enable */

/*!< TSEL1[2:0] (DAC channel1 Trigger selection) */
#define  SET_DAC_CR_TSEL1(DACx_BASE,a)	SET_REG_BITn(DACx_BASE,3,MASKb3,a)
/*!< WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable) */
#define  SET_DAC_CR_WAVE1(DACx_BASE,a)	SET_REG_BITn(DACx_BASE,6,MASKb2,a)

/*!< MAMP1[3:0] (DACͨ��1����/��ֵѡ����) */
#define  SET_DAC_CR_MAMP1(DACx_BASE,a)	SET_REG_BITn(DACx_BASE,8,MASKb4,a)

#define  bDAC_CR_DMAEN1(DACx_BASE)        BIT_ADDR(DACx_BASE+0x00,12)        /*!< DAC channel1 DMA enable */
#define  bDAC_CR_EN2(DACx_BASE)        BIT_ADDR(DACx_BASE+0x00,16)        /*!< DAC channel2 enable */
#define  bDAC_CR_BOFF2(DACx_BASE)        BIT_ADDR(DACx_BASE+0x00,17)        /*!< DAC channel2 output buffer disable */
#define  bDAC_CR_TEN2(DACx_BASE)        BIT_ADDR(DACx_BASE+0x00,18)        /*!< DAC channel2 Trigger enable */
//USB_BASE

/*!< TSEL2[2:0] (DAC channel2 Trigger selection) */
#define  SET_DAC_CR_TSEL2(DACx_BASE,a)	SET_REG_BITn(DACx_BASE,19,MASKb3,a)

/*!< WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
#define  SET_DAC_CR_WAVE2(DACx_BASE,a)	SET_REG_BITn(DACx_BASE,22,MASKb2,a)

/*!< MAMP2[3:0] (DACͨ��2����/��ֵѡ����) */
#define  SET_DAC_CR_MAMP2(DACx_BASE,a)	SET_REG_BITn(DACx_BASE,24,MASKb4,a)

#define  bDAC_CR_DMAEN2(DACx_BASE)        BIT_ADDR(DACx_BASE+0x00,28)        /*!< DAC channel2 DMA enabled */

/*****************   DAC_SWTRIGR �Ĵ��� **************04****/
#define  bDAC_SWTRIGR_SWTRIG1(DACx_BASE)        BIT_ADDR(DACx_BASE+0x04,0)               /*!< DAC channel1 software trigger */
#define  bDAC_SWTRIGR_SWTRIG2(DACx_BASE)        BIT_ADDR(DACx_BASE+0x04,1)               /*!< DAC channel2 software trigger */

/*****************   DAC_DHR12R1 �Ĵ��� ****************08**/
//#define  DAC_DHR12R1_DACC1DHR                ((uint16_t)0x0FFF)            /*!< DAC channel1 12-bit Right aligned data */
#define  SET_DAC_DHR12R1_DACC1DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x08,0,MASKb12,a)

/*****************   DAC_DHR12L1 �Ĵ��� ****************0c**/
//#define  DAC_DHR12L1_DACC1DHR                ((uint16_t)0xFFF0)            /*!< DAC channel1 12-bit Left aligned data */
#define  SET_DAC_DHR12L1_DACC1DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x0C,4,MASKb12,a)

/******************   DAC_DHR8R1 �Ĵ��� ****************10**/
//#define  DAC_DHR8R1_DACC1DHR                 ((uint8_t)0xFF)               /*!< DAC channel1 8-bit Right aligned data */
#define  SET_DAC_DHR8R1_DACC1DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x10,0,MASKb8,a)

/*****************   DAC_DHR12R2 �Ĵ��� ****************14**/
//#define  DAC_DHR12R2_DACC2DHR                ((uint16_t)0x0FFF)            /*!< DAC channel2 12-bit Right aligned data */
#define  SET_DAC_DHR12R2_DACC2DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x14,0,MASKb12,a)
/*****************   DAC_DHR12L2 �Ĵ��� ****************18**/
//#define  DAC_DHR12L2_DACC2DHR                ((uint16_t)0xFFF0)            /*!< DAC channel2 12-bit Left aligned data */
#define  SET_DAC_DHR12L2_DACC2DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x18,4,MASKb12,a)
/******************   DAC_DHR8R2 �Ĵ��� ****************1c**/
//#define  DAC_DHR8R2_DACC2DHR                 ((uint8_t)0xFF)               /*!< DAC channel2 8-bit Right aligned data */
#define  SET_DAC_DHR8R2_DACC2DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x1C,0,MASKb8,a)
/*****************   DAC_DHR12RD �Ĵ��� ****************20**/
//#define  DAC_DHR12RD_DACC1DHR                ((uint32_t)0x00000FFF)        /*!< DAC channel1 12-bit Right aligned data */
#define  SET_DAC_DHR12RD_DACC1DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x20,0,MASKb12,a)
//#define  DAC_DHR12RD_DACC2DHR                ((uint32_t)0x0FFF0000)        /*!< DAC channel2 12-bit Right aligned data */
#define  SET_DAC_DAC_DHR12RD_DACC2DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x20,16,MASKb12,a)
/*****************   DAC_DHR12LD �Ĵ��� ****************24**/
//#define  DAC_DHR12LD_DACC1DHR                ((uint32_t)0x0000FFF0)        /*!< DAC channel1 12-bit Left aligned data */
#define  SET_DAC_DHR12LD_DACC1DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x24,4,MASKb12,a)
//#define  DAC_DHR12LD_DACC2DHR                ((uint32_t)0xFFF00000)        /*!< DAC channel2 12-bit Left aligned data */
#define  SET_DAC_DHR12LD_DACC2DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x24,20,MASKb12,a)
/******************   DAC_DHR8RD �Ĵ��� ****************28**/
//#define  DAC_DHR8RD_DACC1DHR                 ((uint16_t)0x00FF)            /*!< DAC channel1 8-bit Right aligned data */
#define  SET_DAC_DHR8RD_DACC1DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x28,0,MASKb8,a)
//#define  DAC_DHR8RD_DACC2DHR                 ((uint16_t)0xFF00)            /*!< DAC channel2 8-bit Right aligned data */
#define  SET_DAC_DHR8RD_DACC2DHR(DACx_BASE,a)	SET_REG_BITn(DACx_BASE+0x28,8,MASKb8,a)

/*******************   DAC_DOR1 �Ĵ��� *****************2c**/
//#define  DAC_DOR1_DACC1DOR                   ((uint16_t)0x0FFF)            /*!< DAC channel1 data output */
#define  DAC_DOR1(DACx_BASE)				(MEM_ADDR(DACx_BASE +0x2c))
/*******************   DAC_DOR2 �Ĵ��� *****************30**/
//#define  DAC_DOR2_DACC2DOR                   ((uint16_t)0x0FFF)            /*!< DAC channel2 data output */
#define  DAC_DOR2(DACx_BASE)				(MEM_ADDR(DACx_BASE +0x30))
/********************   DAC_SR �Ĵ��� ******************34??**/
#define  bDAC_SR_DMAUDR1(DACx_BASE)        BIT_ADDR(DACx_BASE+0x34,13)        /*!< DAC channel1 DMA underrun flag */
#define  bDAC_SR_DMAUDR2(DACx_BASE)        BIT_ADDR(DACx_BASE+0x34,29)        /*!< DAC channel2 DMA underrun flag */

/******************************************************************************/
/*                                                                            */
/*                          SDIO�ӿ�                                          */
/*                                                                            */
/******************************************************************************/

/******************  SDIO_POWER �Ĵ���  ******************/
           
#define  SET_SDIO_POWER_PWRCTRL(a)	SET_REG_BITn(SDIO_BASE,0,MASKb2,a)		/*!< PWRCTRL[1:0] bits (Power supply control bits) */


/******************  SDIO_CLKCR �Ĵ���  ******************/
#define  SDIO_CLKCR_CLKDIV                   ((uint16_t)0x00FF)            
#define  SET_SDIO_CLKCR_CLKDIV(a)		SET_REG_BITn(SDIO_BASE+0x04,0,MASKb8,a)		/*!< Clock divide factor */
#define  bSDIO_CLKCR_CLKEN          BIT_ADDR(SDIO_BASE+0x04,8)            /*!< Clock enable bit */
#define  bSDIO_CLKCR_PWRSAV         BIT_ADDR(SDIO_BASE+0x04,9)            /*!< Power saving configuration bit */
#define  bSDIO_CLKCR_BYPASS         BIT_ADDR(SDIO_BASE+0x04,10)            /*!< Clock divider bypass enable bit */

#define  SET_SDIO_CLKCR_WIDBUS(a)		SET_REG_BITn(SDIO_BASE+0x04,11,MASKb2,a) /*!< WIDBUS[1:0] bits (Wide bus mode enable bit) */

#define  bSDIO_CLKCR_NEGEDGE        BIT_ADDR(SDIO_BASE+0x04,13)           /*!< SDIO_CK dephasing selection bit */
#define  bSDIO_CLKCR_HWFC_EN        BIT_ADDR(SDIO_BASE+0x04,14)           /*!< HW Flow Control enable */

/*******************  SDIO_ARG �Ĵ���  *******************/
#define  SDIO_ARG                   (MEM_ADDR(SDIO_BASE +0x08))            /*!< Command argument */

/*******************  SDIO_CMD �Ĵ���  *******************/
#define  SET_SDIO_CMD_CMDINDEX      SET_REG_BITn(SDIO_BASE+0x0C,0,MASKb6,a)            /*!< Command Index */

#define  SET_SDIO_CMD_WAITRESP      SET_REG_BITn(SDIO_BASE+0x0C,6,MASKb2,a)   /*!< WAITRESP[1:0] bits (Wait for response bits) */

#define  bSDIO_CMD_WAITINT          BIT_ADDR(SDIO_BASE+0x0C,8)            /*!< CPSM Waits for Interrupt Request */
#define  bSDIO_CMD_WAITPEND         BIT_ADDR(SDIO_BASE+0x0C,9)            /*!< CPSM Waits for ends of data transfer (CmdPend internal signal) */
#define  bSDIO_CMD_CPSMEN           BIT_ADDR(SDIO_BASE+0x0C,10)            /*!< Command path state machine (CPSM) Enable bit */
#define  bSDIO_CMD_SDIOSUSPEND      BIT_ADDR(SDIO_BASE+0x0C,11)            /*!< SD I/O suspend command */
#define  bSDIO_CMD_ENCMDCOMPL       BIT_ADDR(SDIO_BASE+0x0C,12)            /*!< Enable CMD completion */
#define  bSDIO_CMD_NIEN             BIT_ADDR(SDIO_BASE+0x0C,13)            /*!< Not Interrupt Enable */
#define  bSDIO_CMD_CEATACMD         BIT_ADDR(SDIO_BASE+0x0C,14)            /*!< CE-ATA command */

/*****************  SDIO_RESPCMD �Ĵ���  *****************/
#define  SDIO_RESPCMD       (MEM_ADDR(SDIO_BASE+0x10))               /*!< ������Ӧ�Ĵ�����ֻ����Response command index */

/******************  SDIO_RESP1 �Ĵ���  ******************/
#define  SDIO_RESP1              (MEM_ADDR(SDIO_BASE+0x14))        /*!< Card Status */

/******************  SDIO_RESP2 �Ĵ���  ******************/
#define  SDIO_RESP2              (MEM_ADDR(SDIO_BASE+0x18))        /*!< Card Status */

/******************  SDIO_RESP3 �Ĵ���  ******************/
#define  SDIO_RESP3              (MEM_ADDR(SDIO_BASE+0x1C))        /*!< Card Status */

/******************  SDIO_RESP4 �Ĵ���  ******************/
#define  SDIO_RESP4              (MEM_ADDR(SDIO_BASE+0x20))        /*!< Card Status */

/******************  SDIO_DTIMER �Ĵ���  *****************/
#define  SDIO_DTIMER              (MEM_ADDR(SDIO_BASE+0x24))        /*!< Data timeout period. */

/******************  SDIO_DLEN �Ĵ���  *******************/
#define  SDIO_DLEN              (MEM_ADDR(SDIO_BASE+0x28))        /*!< Data length value */

/******************  SDIO_DCTRL �Ĵ���  ******************/
#define  bSDIO_DCTRL_DTEN         BIT_ADDR(SDIO_BASE+0x2C,0)            /*!< Data transfer enabled bit */
#define  bSDIO_DCTRL_DTDIR        BIT_ADDR(SDIO_BASE+0x2C,1)            /*!< Data transfer direction selection */
#define  bSDIO_DCTRL_DTMODE       BIT_ADDR(SDIO_BASE+0x2C,2)            /*!< Data transfer mode selection */
#define  bSDIO_DCTRL_DMAEN        BIT_ADDR(SDIO_BASE+0x2C,3)            /*!< DMA enabled bit */

#define  SET_SDIO_DCTRL_DBLOCKSIZE    SET_REG_BITn(SDIO_BASE+0x2C,4,MASKb4,a)            /*!< DBLOCKSIZE[3:0] bits (Data block size) */

#define  bSDIO_DCTRL_RWSTART      BIT_ADDR(SDIO_BASE+0x2C,8)            /*!< Read wait start */
#define  bSDIO_DCTRL_RWSTOP       BIT_ADDR(SDIO_BASE+0x2C,9)            /*!< Read wait stop */
#define  bSDIO_DCTRL_RWMOD        BIT_ADDR(SDIO_BASE+0x2C,10)            /*!< Read wait mode */
#define  bSDIO_DCTRL_SDIOEN       BIT_ADDR(SDIO_BASE+0x2C,11)            /*!< SD I/O enable functions */

/******************  SDIO_DCOUNT �Ĵ���  *****************/
#define  SDIO_DCOUNT              (MEM_ADDR(SDIO_BASE+0x30))        /*!< Data count value */

/******************  SDIO_STA �Ĵ�����ֻ����  ********************/
#define  bSDIO_STA_CCRCFAIL      BIT_ADDR(SDIO_BASE+0x34,0)        /*!< Command response received (CRC check failed) */
#define  bSDIO_STA_DCRCFAIL      BIT_ADDR(SDIO_BASE+0x34,1)        /*!< Data block sent/received (CRC check failed) */
#define  bSDIO_STA_CTIMEOUT      BIT_ADDR(SDIO_BASE+0x34,2)        /*!< Command response timeout */
#define  bSDIO_STA_DTIMEOUT      BIT_ADDR(SDIO_BASE+0x34,3)        /*!< Data timeout */
#define  bSDIO_STA_TXUNDERR      BIT_ADDR(SDIO_BASE+0x34,4)        /*!< Transmit FIFO underrun error */
#define  bSDIO_STA_RXOVERR       BIT_ADDR(SDIO_BASE+0x34,5)        /*!< Received FIFO overrun error */
#define  bSDIO_STA_CMDREND       BIT_ADDR(SDIO_BASE+0x34,6)        /*!< Command response received (CRC check passed) */
#define  bSDIO_STA_CMDSENT       BIT_ADDR(SDIO_BASE+0x34,7)        /*!< Command sent (no response required) */
#define  bSDIO_STA_DATAEND       BIT_ADDR(SDIO_BASE+0x34,8)        /*!< Data end (data counter, SDIDCOUNT, is zero) */
#define  bSDIO_STA_STBITERR      BIT_ADDR(SDIO_BASE+0x34,9)        /*!< Start bit not detected on all data signals in wide bus mode */
#define  bSDIO_STA_DBCKEND       BIT_ADDR(SDIO_BASE+0x34,10)        /*!< Data block sent/received (CRC check passed) */
#define  bSDIO_STA_CMDACT        BIT_ADDR(SDIO_BASE+0x34,11)        /*!< Command transfer in progress */
#define  bSDIO_STA_TXACT         BIT_ADDR(SDIO_BASE+0x34,12)        /*!< Data transmit in progress */
#define  bSDIO_STA_RXACT         BIT_ADDR(SDIO_BASE+0x34,13)        /*!< Data receive in progress */
#define  bSDIO_STA_TXFIFOHE      BIT_ADDR(SDIO_BASE+0x34,14)        /*!< Transmit FIFO Half Empty: at least 8 words can be written into the FIFO */
#define  bSDIO_STA_RXFIFOHF      BIT_ADDR(SDIO_BASE+0x34,15)        /*!< Receive FIFO Half Full: there are at least 8 words in the FIFO */
#define  bSDIO_STA_TXFIFOF       BIT_ADDR(SDIO_BASE+0x34,16)        /*!< Transmit FIFO full */
#define  bSDIO_STA_RXFIFOF       BIT_ADDR(SDIO_BASE+0x34,17)        /*!< Receive FIFO full */
#define  bSDIO_STA_TXFIFOE       BIT_ADDR(SDIO_BASE+0x34,18)        /*!< Transmit FIFO empty */
#define  bSDIO_STA_RXFIFOE       BIT_ADDR(SDIO_BASE+0x34,19)        /*!< Receive FIFO empty */
#define  bSDIO_STA_TXDAVL        BIT_ADDR(SDIO_BASE+0x34,20)        /*!< Data available in transmit FIFO */
#define  bSDIO_STA_RXDAVL        BIT_ADDR(SDIO_BASE+0x34,21)        /*!< Data available in receive FIFO */
#define  bSDIO_STA_SDIOIT        BIT_ADDR(SDIO_BASE+0x34,22)        /*!< SDIO interrupt received */
#define  bSDIO_STA_CEATAEND      BIT_ADDR(SDIO_BASE+0x34,23)        /*!< CE-ATA command completion signal received for CMD61 */

/*******************  SDIO_ICR �Ĵ���  *******************/
#define  bSDIO_ICR_CCRCFAILC     BIT_ADDR(SDIO_BASE+0x38,0)        /*!< CCRCFAIL flag clear bit */
#define  bSDIO_ICR_DCRCFAILC     BIT_ADDR(SDIO_BASE+0x38,1)        /*!< DCRCFAIL flag clear bit */
#define  bSDIO_ICR_CTIMEOUTC     BIT_ADDR(SDIO_BASE+0x38,2)        /*!< CTIMEOUT flag clear bit */
#define  bSDIO_ICR_DTIMEOUTC     BIT_ADDR(SDIO_BASE+0x38,3)        /*!< DTIMEOUT flag clear bit */
#define  bSDIO_ICR_TXUNDERRC     BIT_ADDR(SDIO_BASE+0x38,4)        /*!< TXUNDERR flag clear bit */
#define  bSDIO_ICR_RXOVERRC      BIT_ADDR(SDIO_BASE+0x38,5)        /*!< RXOVERR flag clear bit */
#define  bSDIO_ICR_CMDRENDC      BIT_ADDR(SDIO_BASE+0x38,6)        /*!< CMDREND flag clear bit */
#define  bSDIO_ICR_CMDSENTC      BIT_ADDR(SDIO_BASE+0x38,7)        /*!< CMDSENT flag clear bit */
#define  bSDIO_ICR_DATAENDC      BIT_ADDR(SDIO_BASE+0x38,8)        /*!< DATAEND flag clear bit */
#define  bSDIO_ICR_STBITERRC     BIT_ADDR(SDIO_BASE+0x38,9)        /*!< STBITERR flag clear bit */
#define  bSDIO_ICR_DBCKENDC      BIT_ADDR(SDIO_BASE+0x38,10)        /*!< DBCKEND flag clear bit */
#define  bSDIO_ICR_SDIOITC       BIT_ADDR(SDIO_BASE+0x38,22)        /*!< SDIOIT flag clear bit */
#define  bSDIO_ICR_CEATAENDC     BIT_ADDR(SDIO_BASE+0x38,23)        /*!< CEATAEND flag clear bit */

/******************  SDIO_MASK �Ĵ���  *******************/
#define  bSDIO_MASK_CCRCFAILIE   BIT_ADDR(SDIO_BASE+0x3C,0)        /*!< Command CRC Fail Interrupt Enable */
#define  bSDIO_MASK_DCRCFAILIE   BIT_ADDR(SDIO_BASE+0x3C,1)        /*!< Data CRC Fail Interrupt Enable */
#define  bSDIO_MASK_CTIMEOUTIE   BIT_ADDR(SDIO_BASE+0x3C,2)        /*!< Command TimeOut Interrupt Enable */
#define  bSDIO_MASK_DTIMEOUTIE   BIT_ADDR(SDIO_BASE+0x3C,3)        /*!< Data TimeOut Interrupt Enable */
#define  bSDIO_MASK_TXUNDERRIE   BIT_ADDR(SDIO_BASE+0x3C,4)        /*!< Tx FIFO UnderRun Error Interrupt Enable */
#define  bSDIO_MASK_RXOVERRIE    BIT_ADDR(SDIO_BASE+0x3C,5)        /*!< Rx FIFO OverRun Error Interrupt Enable */
#define  bSDIO_MASK_CMDRENDIE    BIT_ADDR(SDIO_BASE+0x3C,6)        /*!< Command Response Received Interrupt Enable */
#define  bSDIO_MASK_CMDSENTIE    BIT_ADDR(SDIO_BASE+0x3C,7)        /*!< Command Sent Interrupt Enable */
#define  bSDIO_MASK_DATAENDIE    BIT_ADDR(SDIO_BASE+0x3C,8)        /*!< Data End Interrupt Enable */
#define  bSDIO_MASK_STBITERRIE   BIT_ADDR(SDIO_BASE+0x3C,9)        /*!< Start Bit Error Interrupt Enable */
#define  bSDIO_MASK_DBCKENDIE    BIT_ADDR(SDIO_BASE+0x3C,10)        /*!< Data Block End Interrupt Enable */
#define  bSDIO_MASK_CMDACTIE     BIT_ADDR(SDIO_BASE+0x3C,11)        /*!< Command Acting Interrupt Enable */
#define  bSDIO_MASK_TXACTIE      BIT_ADDR(SDIO_BASE+0x3C,12)        /*!< Data Transmit Acting Interrupt Enable */
#define  bSDIO_MASK_RXACTIE      BIT_ADDR(SDIO_BASE+0x3C,13)        /*!< Data receive acting interrupt enabled */
#define  bSDIO_MASK_TXFIFOHEIE   BIT_ADDR(SDIO_BASE+0x3C,14)        /*!< Tx FIFO Half Empty interrupt Enable */
#define  bSDIO_MASK_RXFIFOHFIE   BIT_ADDR(SDIO_BASE+0x3C,15)        /*!< Rx FIFO Half Full interrupt Enable */
#define  bSDIO_MASK_TXFIFOFIE    BIT_ADDR(SDIO_BASE+0x3C,16)        /*!< Tx FIFO Full interrupt Enable */
#define  bSDIO_MASK_RXFIFOFIE    BIT_ADDR(SDIO_BASE+0x3C,17)        /*!< Rx FIFO Full interrupt Enable */
#define  bSDIO_MASK_TXFIFOEIE    BIT_ADDR(SDIO_BASE+0x3C,18)        /*!< Tx FIFO Empty interrupt Enable */
#define  bSDIO_MASK_RXFIFOEIE    BIT_ADDR(SDIO_BASE+0x3C,19)        /*!< Rx FIFO Empty interrupt Enable */
#define  bSDIO_MASK_TXDAVLIE     BIT_ADDR(SDIO_BASE+0x3C,20)        /*!< Data available in Tx FIFO interrupt Enable */
#define  bSDIO_MASK_RXDAVLIE     BIT_ADDR(SDIO_BASE+0x3C,21)        /*!< Data available in Rx FIFO interrupt Enable */
#define  bSDIO_MASK_SDIOITIE     BIT_ADDR(SDIO_BASE+0x3C,22)        /*!< SDIO Mode Interrupt Received interrupt Enable */
#define  bSDIO_MASK_CEATAENDIE   BIT_ADDR(SDIO_BASE+0x3C,23)        /*!< CE-ATA command completion signal received Interrupt Enable */

/*****************  SDIO_FIFOCNT �Ĵ���  *****************/
#define  SDIO_FIFOCNT            (MEM_ADDR(SDIO_BASE+0x48))        /*!< Remaining number of words to be written to or read from the FIFO */

/******************  SDIO_FIFO �Ĵ���  *******************/
#define  SDIO_FIFO               (MEM_ADDR(SDIO_BASE+0x80))       /*!< Receive and transmit FIFO data */


#endif

