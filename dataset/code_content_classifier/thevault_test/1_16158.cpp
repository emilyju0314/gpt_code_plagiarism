void MCP_CAN::mcp2515_setRegister(const INT8U address, const INT8U value)
{
    unsigned char buf[3] = { MCP_WRITE, address, value };
    spiTransfer(3, buf);
}