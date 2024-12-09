void DMA1_Channel4_IRQHandler()
{	
#ifdef USE_USART1
	if(pUSART1)
		pUSART1->DmaIrq();
#endif
#ifdef USE_I2C
#ifdef USE_I2C2
#ifdef I2C_USE_DMA
	if(pI2C2)
		pI2C2->DmaTxIRQ();
#endif
#endif
#endif
}