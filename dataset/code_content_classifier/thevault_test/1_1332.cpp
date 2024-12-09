bool APDS9930::clearProximityInt()
{
    if( !wireWriteByte(CLEAR_PROX_INT) ) {
        return false;
    }
    
    return true;
}