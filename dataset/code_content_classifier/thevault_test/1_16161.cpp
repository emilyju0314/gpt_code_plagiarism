INT8U MCP_CAN::mcp2515_readStatus(void)                             
{
    INT8U i;
    
    unsigned char buf[2] = { MCP_READ_STATUS, 0x00 };
    spiTransfer(2, buf);
    i = buf[1];
    
    return i;
}