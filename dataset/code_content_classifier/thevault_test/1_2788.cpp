void usb_handler(void)
{
    if(USB_Readable)
    {
      usart_buffer[usart_index] = usb_receive();
      if(usart_buffer[usart_index] == NULL || usart_buffer[usart_index] == ENTER_KEY)
      { //indicate that a full message has been sent
        if(usart_buffer[0] == '?' && usart_buffer[1] == 's')
        {
          for(int x = 0 ; x < 30 ; x++)
          {
            usart_buffer[x] = usart_buffer[2+x];
          }
          speed_desired = static_cast<float>(atof(usart_buffer));
          
          dtostrf(speed_desired,5,4,dummy_buffer);    //Atmel doesn't allow for floats to be printed -> dtostrf turns the float into a String based on the set size
          sprintf(usart_buffer,"!s%s\r",dummy_buffer); //afterwards the string can be filled with additional commands
          usb_transmitString(usart_buffer);        //
          
        }
        usart_index = 0;
      }
      else
      {
        usart_index++;
      }
    }
}