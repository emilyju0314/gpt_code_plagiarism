bool APDS9930::clearAmbientLightInt()
{
    if( !wireWriteByte(CLEAR_ALS_INT) ) {
        return false;
    }
    
    return true;
}