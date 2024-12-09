bool APDS9930::disablePower()
{
    if( !setMode(POWER, 0) ) {
        return false;
    }
    
    return true;
}