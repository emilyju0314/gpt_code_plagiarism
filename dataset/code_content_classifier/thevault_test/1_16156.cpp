INT8U MCP_CAN::mcp2515_readRegister(const INT8U address)                                                                     
{
    INT8U ret;
    
    unsigned char buf[3] = { MCP_READ, address, 0x00 };
    spiTransfer(3, buf);
    ret = buf[2];

    return ret;
}