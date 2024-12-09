Data
SipVia::encode() const
{
    Data ret;
    
    ret = VIA;
    
    ret+= SP;

    
    //construct the sent-protocol
    Data sentprotocol = getprotoName();
    sentprotocol+= "/";
    sentprotocol+= DEFAULT_VERSION;
    sentprotocol+= "/";
    sentprotocol+= getTransport();
    sentprotocol+= SP; 
   
    ret += sentprotocol;
    ret +=getHost();
    Data pport = Data(getPort());
    if (pport.length() > 0)
    {
        ret+= ":";
        ret+= pport;
    }
    ret+= formOtherparms(); 
    ret+= CRLF;
      
    return ret;
}