bool APDS9930::clearAllInts()
{
    if( !wireWriteByte(CLEAR_ALL_INTS) ) {
        return false;
    }
    
    return true;
}