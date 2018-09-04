//�����һ��4*4����������ֱ��4�����������20�������ķ���

//��PD3��PD4��PD5��PD6Ϊ��ֱͨ���˿ڵ��ĸ������������ҷ������

//4*4����ʽ�������Ӳ�����ӣ�
//��PD8��PD9��PD10��PD11Ϊ����ʽ���̵İ������루Ϊ�����ȡ����4��IO�ھ�������Ϊ�������źţ�
//��PD12��PD13��PD14��PD15Ϊ����ʽ���̵�ɨ���������4��IO�����⣩

#define KeyNumMax					20			//Ӳ��ʵ�尴������4*4+4=20��
typedef	u32 KeyS_Type;//����״̬��Ϊ32λ��������

#define KEY_OUT_LINE_NULL	GPIOD->BRR = 0x0f<<12	/*����������*/
#define KEY_OUT_LINE1		GPIOD->BSRR = 0x01<<12	/*ɨ�������һ��*/
#define KEY_OUT_LINE2		GPIOD->BSRR = 0x02<<12	/*ɨ������ڶ���*/
#define KEY_OUT_LINE3		GPIOD->BSRR = 0x04<<12	/*ɨ�����������*/
#define KEY_OUT_LINE4		GPIOD->BSRR = 0x08<<12	/*ɨ�����������*/

#define KEY_IN		(GPIOD->IDR&(GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11))/*ɨ������ֵ*/
#define KEY_IN0		(KEY_IN>>8)	/*��ȡ������λ���Ͷˣ�������PD0��3�Ļ��͸��򵥣�������λ�ˣ�*/


//����Ӳ�����˿�λ��
#define KB_RIGHT_IN  	PDin(3)//��ȡ����0 
#define KB_DOWN_IN  	PDin(4)//��ȡ����1 
#define KB_LEFT_IN  	PDin(5)//��ȡ����2 
#define KB_UP_IN 	PDin(6)//��ȡ����3 


//20��Ӳ��ʵ�尴���ı�ţ���̬������˳��λ���
#define KB_RIGHT 		0
#define KB_DOWN  		1
#define KB_LEFT  		2 
#define KB_UP 			3
#define KB_NUM1 		4
#define KB_NUM2 		5
#define KB_NUM3 		6
#define KB_BACK 		7//�˸��
#define KB_NUM4 		8
#define KB_NUM5			9
#define KB_NUM6 		10
#define KB_SPACE 		11//�ո��
#define KB_NUM7 		12
#define KB_NUM8 		13
#define KB_NUM9 		14
#define KB_ESC	 		15
#define KB_XING 		16//*�ż�
#define KB_NUM0 		17
#define KB_JING 		18//#�ż�
#define KB_ENTER 		19//�س���
//***************�������ݿ�д��key.h �ļ���********


//*************** key.c �ļ���Ӧ���� ********
//������ʼ������
void KEY_Init(void) //IO��ʼ��
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

	/* PD8,9,10,11��������*/
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;		// ��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50Mʱ���ٶ�
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	/* PD12,13,14,15����ɨ�����*/
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50Mʱ���ٶ�
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	/* PD3,4,5,6��������,��Ӧ�ĸ������*/
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		//��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50Mʱ���ٶ�
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}


//Ӳ����������
//������20��Ϊ���������֧��32�������ڼ��ٵ�ϵͳ KeyS_Type�ɶ���Ϊu16��u8��
KeyS_Type GetHalKeyCode(void)
{
	KeyS_Type ktmp=0;
	if(!KB_RIGHT_IN) 	ktmp|=1<<KB_RIGHT;
	if(!KB_DOWN_IN) 	ktmp|=1<<KB_DOWN;
	if(!KB_LEFT_IN) 	ktmp|=1<<KB_LEFT;
	if(!KB_UP_IN) 		ktmp|=1<<KB_UP;
		//ɨ������ʽ����
	KEY_OUT_LINE_NULL;
	KEY_OUT_LINE1;
	ktmp |= KEY_IN0<<4;		//����ֱ��KEY_IN>>4

	KEY_OUT_LINE_NULL;
	KEY_OUT_LINE2;
	ktmp |= KEY_IN0<<8;		//����ֱ��KEY_IN

	KEY_OUT_LINE_NULL;
	KEY_OUT_LINE3;
	ktmp |= KEY_IN0<<12;		//����ֱ��KEY_IN<<4

	KEY_OUT_LINE_NULL;
	KEY_OUT_LINE4;
	ktmp |= KEY_IN0<<16;		//����ֱ��KEY_IN<<8

	return ktmp;
}
