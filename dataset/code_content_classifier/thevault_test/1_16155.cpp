void MCP_CAN::mcp2515_reset(void)                                      
{
    unsigned char cmd[1] = { MCP_RESET }; 
    spiTransfer(1, cmd);

    nanosleep((const struct timespec[]){{0, 10000L}}, NULL);
}