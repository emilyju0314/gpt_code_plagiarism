bool DaySchedule::addPoint(const point pt){
    //If the list is full we return false
    if(getSize() == NB_PTS_MAX){
        return false;
    }
    
    //Search for the correct position
    unsigned char i = 0;
    while( (pt.h < ptHour[i]) && (i < getSize()) ){
        i++;
    }
    while( (pt.m < ptMin[i]) && (i < getSize()) ){
        i++;
    }
    
    //Add the point
    if(pt.m == ptMin[i]){
        ptDC[i] = pt.dc;
    }else{
        unsigned char tmp1 = 0, tmp2 = 0;
        
        //Hours
        tmp1 = ptHour[i];
        ptHour[i] = pt.h;
        for(unsigned char j = i; j < getSize()-1; j++){
            tmp2 = ptHour[j+1];
            ptHour[j+1] = tmp1;
            tmp1 = tmp2;
        }
        
        //Minutes
        tmp1 = ptMin[i];
        ptMin[i] = pt.m;
        for(unsigned char j = i; j < getSize()-1; j++){
            tmp2 = ptMin[j+1];
            ptMin[j+1] = tmp1;
            tmp1 = tmp2;
        }
        
        //Duty Cycles
        tmp1 = ptDC[i];
        ptDC[i] = pt.dc;
        for(unsigned char j = i; j < getSize()-1; j++){
            tmp2 = ptDC[j+1];
            ptDC[j+1] = tmp1;
            tmp1 = tmp2;
        }
        
        setSize(getSize()+1);
    }
    return save();
}