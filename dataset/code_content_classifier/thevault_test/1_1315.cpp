bool APDS9930::setProximityIntHighThreshold(uint16_t threshold)
{
    uint8_t lo;
    uint8_t hi;
    hi = threshold >> 8;
    lo = threshold & 0x00FF;

    if( !wireWriteDataByte(APDS9930_PIHTL, lo) ) {
        return false;
    }
    if( !wireWriteDataByte(APDS9930_PIHTH, hi) ) {
        return false;
    }
    
    return true;
}