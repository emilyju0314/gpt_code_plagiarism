bool DaySchedule::delPoint(const unsigned char pos){
    if( pos >= getSize() ){
        return false;
    }
    
    // Shifts the remaining points
    for(unsigned char i = pos; i < getSize()-1; i++){
        ptHour[i] = ptHour[i+1];
        ptMin[i] = ptMin[i+1];
        ptDC[i] = ptDC[i+1];
    }
    
    //Sets the last point to zeros
    ptHour[getSize()-1] = 0;
    ptMin[getSize()-1] = 0;
    ptDC[getSize()-1] = 0;
    
    //Update size
    setSize(getSize()-1);
    
    return save();
}