bool MCP_CAN::setupSpi()
{
#ifdef __arm__
	int result_spi = wiringPiSPISetup(spi_channel, spi_baudrate);
    printf("Started SPI : %d\n", result_spi);
    if (result_spi < 0) {
        return false;
    }
    nanosleep((const struct timespec[]){{0, 500000L}}, NULL);
    return true;
#else
    printf("Can't use SPI on non-ARM processor");
    return false;
#endif
}