bool DaySchedule::changeDay(const unsigned char day){
    if( day >= 7 ){
        return false;
    }
    size_t offset = day*BYTES_PER_DAY;
    unsigned char n = EEPROM.read(offset);
    
    // If the size we read is higher than NB_PTS_MAX we consider the memory
    // as unitialized
    if(n > NB_PTS_MAX){
        setSize(0);
    }else{
        setSize(n);    
    }
    
    // Read memory
    for(unsigned char i = 0; i < getSize(); i++){
        ptHour[i] = EEPROM.read(offset + 3*i + 1);
        ptMin[i] = EEPROM.read(offset + 3*i + 2);
        ptDC[i] = EEPROM.read(offset + 3*i + 3);
    }
    for(unsigned char i = getSize(); i < NB_PTS_MAX; i++){
        ptHour[i] = 0;
        ptMin[i] = 0;
        ptDC[i] = 0;
    }
    dow = day;
    
    // Loads last point of previous day with > 0 points
    unsigned int counter = 0, i = dow-1;
    while(EEPROM.read(i*BYTES_PER_DAY) == 0 || counter <= 7){
        i--;
        counter++;
        if(i > 6){       // if we underflow
            i = 6;
        }
    } // i now contains the previous DOW with at least 1 point (if counter <= 6)
    
    if(counter > 7){ // There is no point in the schedule
        prevD = prevH = prevM = prevDC = 0;
        nextD = nextH = nextM = nextDC = 0;
        return true;
    }
    
    // Load value of prev point
    prevD = i;
    n = EEPROM.read(i*BYTES_PER_DAY);
    prevH = EEPROM.read(i*BYTES_PER_DAY + 3*(n-1) + 1);
    prevM = EEPROM.read(i*BYTES_PER_DAY + 3*(n-1) + 2);
    prevDC = EEPROM.read(i*BYTES_PER_DAY + 3*(n-1) + 3);
    
    // Load first point of next day with > 0 points
    i = dow+1;
    while(EEPROM.read(i*BYTES_PER_DAY) == 0){
        i = (i+1)%7;
    } 
    
    // Load value of next point
    nextD = i;
    nextH = EEPROM.read(i*BYTES_PER_DAY + 1);
    nextM = EEPROM.read(i*BYTES_PER_DAY + 2);
    nextDC = EEPROM.read(i*BYTES_PER_DAY + 3);
    
    return true;
}