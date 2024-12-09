void DMA1_Channel7_IRQHandler()
{	
#ifdef USE_USART2
	if(pUSART2)
		pUSART2->DmaIrq();
#endif

#ifdef USE_I2C
#ifdef USE_I2C1
#ifdef I2C_USE_DMA
	if(pI2C1)
		pI2C1->DmaRxIRQ();
#endif
#endif
#endif
}