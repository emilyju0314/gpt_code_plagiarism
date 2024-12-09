void MCP_CAN::mcp2515_readRegisterS(const INT8U address, INT8U values[], const INT8U n)
{
    INT8U i;

    int buf_size = 2 + n; 
    unsigned char buf[buf_size] = { 0x00 };
    buf[0] = MCP_READ;
    buf[1] = address;

    spiTransfer(buf_size, buf);

    // mcp2515 has auto-increment of address-pointer
    for (i = 0 ; i < n ; ++i) {
        values[i] = buf[i+2];
    }
}