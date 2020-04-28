#include "main.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x.h"
#include "stm32f30x_rcc.h"
#include "stm32f30x_adc.h"

	uint32_t i = 0;
	uint16_t calibration_value;
	uint16_t ADC1ConvertedValue1;
	uint16_t ADC1ConvertedValue2;
	uint32_t vysledekMiliVolty;
	
int main(void)
{
	GPIO_InitTypeDef         GPIO_InitStructure;
	ADC_CommonInitTypeDef    ADC_CommonInitStructure;
	ADC_InitTypeDef          ADC_InitStructure;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ADC12, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  RCC_ADCCLKConfig(RCC_ADC12PLLCLK_Div1);
	
	ADC_StructInit(&ADC_InitStructure);
	
	ADC_VoltageRegulatorCmd(ADC1, ENABLE);
	
	for (i = 0; i < 0xffff; i++);
	for (i = 0; i < 0xffff; i++);
	
	ADC_SelectCalibrationMode(ADC1, ADC_CalibrationMode_Single);
	ADC_StartCalibration(ADC1);
	
	while(ADC_GetCalibrationStatus(ADC1) != RESET);
	calibration_value = ADC_GetCalibrationValue(ADC1);
	
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Clock = ADC_Clock_AsynClkMode;
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_DMAMode = ADC_DMAMode_OneShot;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = 0;
	ADC_CommonInit(ADC1, &ADC_CommonInitStructure);
	
	ADC_InitStructure.ADC_ContinuousConvMode = ADC_ContinuousConvMode_Enable;
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ExternalTrigConvEvent = ADC_ExternalTrigConvEvent_0;
	ADC_InitStructure.ADC_ExternalTrigEventEdge = ADC_ExternalTrigEventEdge_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_OverrunMode = ADC_OverrunMode_Disable;
	ADC_InitStructure.ADC_AutoInjMode = ADC_AutoInjec_Disable;
	ADC_InitStructure.ADC_NbrOfRegChannel = 2;
	ADC_Init(ADC1, &ADC_InitStructure);
	
	ADC_VrefintCmd(ADC1, ENABLE);
	ADC_TempSensorCmd(ADC1, ENABLE);
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1,          1, ADC_SampleTime_601Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_TempSensor, 2, ADC_SampleTime_601Cycles5);
	
	ADC_Cmd(ADC1, ENABLE);
	
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_RDY));
	
	ADC_StartConversion(ADC1);

	
    while (1)
    {
			while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
			ADC1ConvertedValue1 = ADC_GetConversionValue(ADC1);
			
			while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
			ADC1ConvertedValue2 = ADC_GetConversionValue(ADC1);
			
			vysledekMiliVolty = (ADC1ConvertedValue1*3300)/4095;
    }
}

