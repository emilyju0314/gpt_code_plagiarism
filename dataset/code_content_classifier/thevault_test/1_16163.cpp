MCP_CAN::MCP_CAN(int spi_channel, int spi_baudrate, INT8U gpio_can_interrupt)
{
    this->spi_channel = spi_channel;
    this->spi_baudrate = spi_baudrate;
    this->gpio_can_interrupt = gpio_can_interrupt;
    
    delay_spi_can.tv_sec = 0;
    delay_spi_can.tv_nsec = 5000L; // wait 5 microseconds between 2 spi transfers
}