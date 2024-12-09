void MCP_CAN::mcp2515_modifyRegister(const INT8U address, const INT8U mask, const INT8U data)
{
    unsigned char buf[4] = { MCP_BITMOD, address, mask, data };
    spiTransfer(4, buf);
}