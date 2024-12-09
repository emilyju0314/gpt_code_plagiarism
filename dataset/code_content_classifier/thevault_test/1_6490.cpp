void KMANET::setup_InitialtransmitTime(void)
{
	printf("%s %s %d\n",__func__,__FILE__,__LINE__);
  volatile uint8_t k=0;
  // to reset the network data at begining
  NetworkTimeOffset=0;

  prev_actualHellotxtime=(unsigned long)ACTUALHELLO_FRAME_TIME;
  prev_actualNBRlisttxtime=(unsigned long)ACTUALNBRLIST_FRAME_TIME;
  prev_actualMPRlisttxtime=(unsigned long)ACTUALMPRLIST_FRAME_TIME;
  hoprandaccess_window_msec=(unsigned long)HOP_RANDACCESSWINDOW_TIME;
        
  for(k=0;k<TOTAL_OF_NODE;k++)
  {
    clear_Buffer(rxDataMACHelloFrame[k].rawdata,HELLO_FRAME_BYTESIZE);
    clear_Buffer(rxDataNBRlistFrame[k].rawdata,NBRLIST_FRAME_BYTESIZE);
    clear_Buffer(rxDataMPRlistFrame[k].rawdata,MPRLIST_FRAME_BYTESIZE);
  }
  
  if(txDataMACHelloFrame.format.senderNodeID ==0x00)//control using myTransmit time for only Node 0 to send first radio packet.
  {
    myTransmitTime=0;
   // FlexiTimer2::set(1, transmitInterrupt); //  set the transmission for node 0
   // FlexiTimer2::start();
    
  //  transmitInterrupt();// do first transmit packet in a network
  }
  else
  {
    myTransmitTime=0xFFFFFFFE;
   // FlexiTimer2::set(0xFFFFFFFE, transmitInterrupt); // never start the transmission for node other than node 0
   // FlexiTimer2::start();
  } 
}