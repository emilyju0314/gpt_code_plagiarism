void MCP_CAN::spiTransfer(uint8_t byte_number, unsigned char *buf)
{
#ifdef __arm__
    wiringPiSPIDataRW(spi_channel, buf, byte_number);
    nanosleep(&delay_spi_can, (struct timespec *)NULL); 
#endif
}