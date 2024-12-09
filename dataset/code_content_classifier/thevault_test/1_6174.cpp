int SendMessage(YAPOCMessage out_msg)
{
    outCommandPort.Content() = out_msg;
    outCommandPort.Write();
    
    printf("Sending command type = %d\n ",out_msg.type);
  

  return 1;
  }