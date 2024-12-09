bool APDS9930::enablePower()
{
    if( !setMode(POWER, 1) ) {
        return false;
    }
    
    return true;
}