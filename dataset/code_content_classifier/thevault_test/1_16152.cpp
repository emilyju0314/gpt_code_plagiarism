bool MCP_CAN::setupInterruptGpio()
{
#ifdef __arm__
    int result = wiringPiSetupGpio();
    if (!result) {
        printf("Gpio started\n");
    }
    else {
        printf("Gpio startup fail\n");
        return false;
    }
    
    pinMode(gpio_can_interrupt, INPUT);
    nanosleep((const struct timespec[]){{0, 500000L}}, NULL);
    return true;
#else
    printf("Can't use GPIO on non-ARM processor");
    return false;
#endif
}