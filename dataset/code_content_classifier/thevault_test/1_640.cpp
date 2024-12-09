void CC3000_UsynchCallback(long lEventType, char * data, unsigned char length)
{

  if (lEventType == HCI_EVNT_WLAN_ASYNC_SIMPLE_CONFIG_DONE)
  {
    ulSmartConfigFinished = 1;
    ucStopSmartConfig     = 1;  
  }
  
  if (lEventType == HCI_EVNT_WLAN_UNSOL_CONNECT)
  {
    ulCC3000Connected = 1;
    TM_DEBUG("connected\n\r");
  }
  
  if (lEventType == HCI_EVNT_WLAN_UNSOL_DISCONNECT)
  {   
    ulCC3000Connected = 0;
    ulCC3000DHCP      = 0;
    ulCC3000DHCP_configured = 0;
    printOnce = 1;
    
    TM_DEBUG("disconnected\n\r");

    digitalWrite(ConnLED, LOW);
    // digitalWrite(ErrorLED, HIGH);
  }
  
  if (lEventType == HCI_EVNT_WLAN_UNSOL_DHCP)
  {

    TM_DEBUG("dhcp\n\r");
    // Notes: 
    // 1) IP config parameters are received swapped
    // 2) IP config parameters are valid only if status is OK, i.e. ulCC3000DHCP becomes 1
    
    // only if status is OK, the flag is set to 1 and the addresses are valid
    if ( *(data + NETAPP_IPCONFIG_MAC_OFFSET) == 0)
    {
      //sprintf( (char*)pucCC3000_Rx_Buffer,"IP:%d.%d.%d.%d\f\r", data[3],data[2], data[1], data[0] );

      ulCC3000DHCP = 1;

      TM_DEBUG("DHCP Connected with IP: %hhu.%hhu.%hhu.%hhu\n\r", (unsigned char) data[3], (unsigned char) data[2], (unsigned char) data[1], (unsigned char) data[0]);

      digitalWrite(ConnLED, HIGH);
    }
    else
    {
      ulCC3000DHCP = 0;
      TM_DEBUG("DHCP failed\n\r");
      digitalWrite(ConnLED, LOW);
    }
  }
  
  if (lEventType == HCI_EVENT_CC3000_CAN_SHUT_DOWN)
  {
    OkToDoShutDown = 1;
  }
}