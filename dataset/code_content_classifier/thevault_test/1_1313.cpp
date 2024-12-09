bool APDS9930::setProximityIntLowThreshold(uint16_t threshold)
{
    uint8_t lo;
    uint8_t hi;
    hi = threshold >> 8;
    lo = threshold & 0x00FF;

    if( !wireWriteDataByte(APDS9930_PILTL, lo) ) {
        return false;
    }
    if( !wireWriteDataByte(APDS9930_PILTH, hi) ) {
        return false;
    }
    
    return true;
}