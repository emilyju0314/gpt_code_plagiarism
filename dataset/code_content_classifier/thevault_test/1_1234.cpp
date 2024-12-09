uint32_t SerialPort::receiveBuffer (char *pBuf, uint32_t lenBuf)
{
	unsigned long result = 0;
    if(pgUart->readable()){
    	result = pgUart->scanf("%s",pBuf);
        if (!result){
            printf ("[serial->receiveBuffer] Receive failed !!!.\r\n");
        }
    }
    return (uint32_t) result;
}