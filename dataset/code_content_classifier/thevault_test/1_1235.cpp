int32_t SerialPort::receiveChar()
{
	int32_t returnChar = -1;
	if( pgUart->readable() ){
    	returnChar = (int32_t) pgUart->getc();
    }
    return returnChar;
}