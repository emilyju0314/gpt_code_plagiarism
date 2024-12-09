void yield()
{
    somethingTriggeredYield++;
    //Serial.println("yield"); // this will cause a infinite loop
    if (yieldCB != NULL)
        yieldCB();
    //
}