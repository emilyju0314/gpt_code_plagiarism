void MCP_CAN::mcp2515_setRegisterS(const INT8U address, const INT8U values[], const INT8U n)
{
    INT8U i;
    
    int buf_size = 2 + n;
    unsigned char buf[buf_size];
    buf[0] = MCP_WRITE;
    buf[1] = address;
    for (i = 0; i < n ; ++i) {
        buf[i+2] = values[i];
    }

    spiTransfer(buf_size, buf);
}