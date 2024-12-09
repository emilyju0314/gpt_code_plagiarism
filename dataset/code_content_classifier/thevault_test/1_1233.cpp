bool SerialPort::transmitBuffer(const char *pBuf)
{
	unsigned long result = 0;
    if(pgUart->writeable())
    {
    	printf("--> %s \r\n", pBuf);
    	result = pgUart->printf("%s\r\n",pBuf);
    	if (!result)
        {
            printf ("Transmit failed !!! \r\n");
        }
    }
    return (bool) result;
}