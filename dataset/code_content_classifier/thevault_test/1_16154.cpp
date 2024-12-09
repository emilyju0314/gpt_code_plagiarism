bool MCP_CAN::canReadData()
{
#ifdef __arm__
    return !digitalRead(gpio_can_interrupt);
#else
    return false;
#endif
}