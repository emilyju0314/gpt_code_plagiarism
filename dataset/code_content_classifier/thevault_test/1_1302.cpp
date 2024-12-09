bool APDS9930::init()
{
    uint8_t id;

    /* Initialize I2C */
    Wire.begin();
     
    /* Read ID register and check against known values for APDS-9930 */
    if( !wireReadDataByte(APDS9930_ID, id) ) {
        Serial.println(F("ID read"));
        return false;
    }
    if( !(id == APDS9930_ID_1 || id == APDS9930_ID_2) ) {
        Serial.println(F("ID check"));
        Serial.println(String("ID is ") + String(id, HEX));
        //return false;
    }
     
    /* Set ENABLE register to 0 (disable all features) */
    if( !setMode(ALL, OFF) ) {
        Serial.println(F("Regs off"));
        return false;
    }
    
    /* Set default values for ambient light and proximity registers */
    if( !wireWriteDataByte(APDS9930_ATIME, DEFAULT_ATIME) ) {
        return false;
    }
    if( !wireWriteDataByte(APDS9930_WTIME, DEFAULT_WTIME) ) {
        return false;
    }
    if( !wireWriteDataByte(APDS9930_PPULSE, DEFAULT_PPULSE) ) {
        return false;
    }
    if( !wireWriteDataByte(APDS9930_POFFSET, DEFAULT_POFFSET) ) {
        return false;
    }
    if( !wireWriteDataByte(APDS9930_CONFIG, DEFAULT_CONFIG) ) {
        return false;
    }
    if( !setLEDDrive(DEFAULT_PDRIVE) ) {
        return false;
    }
    if( !setProximityGain(DEFAULT_PGAIN) ) {
        return false;
    }
    if( !setAmbientLightGain(DEFAULT_AGAIN) ) {
        return false;
    }
    if( !setProximityDiode(DEFAULT_PDIODE) ) {
        return false;
    }
    if( !setProximityIntLowThreshold(DEFAULT_PILT) ) {
        return false;
    }
    if( !setProximityIntHighThreshold(DEFAULT_PIHT) ) {
        return false;
    }
    if( !setLightIntLowThreshold(DEFAULT_AILT) ) {
        return false;
    }
    if( !setLightIntHighThreshold(DEFAULT_AIHT) ) {
        return false;
    }
    if( !wireWriteDataByte(APDS9930_PERS, DEFAULT_PERS) ) {
        return false;
    }

    return true;
}