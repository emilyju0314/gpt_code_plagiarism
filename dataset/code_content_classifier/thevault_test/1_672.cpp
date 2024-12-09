bool DaySchedule::save(){
    size_t offset = dow*BYTES_PER_DAY;
    EEPROM.update(offset, getSize());
    for(unsigned char i = 0; i < NB_PTS_MAX; i++){
        EEPROM.update(offset + 3*i + 1, ptHour[i]);
        EEPROM.update(offset + 3*i + 2, ptMin[i]);
        EEPROM.update(offset + 3*i + 3, ptDC[i]);
    }
    
}