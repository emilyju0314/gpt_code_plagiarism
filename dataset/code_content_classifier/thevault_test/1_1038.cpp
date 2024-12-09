void SaveIOToLog(char *ip,char *io)
{
	return;

    char   str[256]; 
    
    memset(str, 0x0, 256); 
    
    sprintf(str,"%s -> %s",ip,io);
    
    SaveMsgToLog("I/O   ",str);
}