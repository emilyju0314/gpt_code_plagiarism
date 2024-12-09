void TBControl::stepXY() {
    unsigned long time = micros();
    int diffx = time - pxtime;
    int diffy = time - pytime; 
    bool xstep = abs(diffx) > xtime;
    bool ystep = abs(diffy) > ytime;

    if (xstep) {
        xaxis->stepBegin();
    }
    if (ystep) {
        yaxis->stepBegin();
    }

    if (xstep) {
        xaxis->stepEnd();
    }

    if (ystep) {
        yaxis->stepEnd();
    }

    unsigned long etime = micros();
    if (xstep) {
        pxtime = etime;
    }
    if (ystep) {
        pytime = etime; 
    }
}