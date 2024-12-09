double HarvestStrategies::HCR2_MaleRamp(double MMB, double aveMMB, int rampID){
    //Define look up table for ramps
    double slopes[] = {5.0/75.0, 10.0/75.0, 15.0/75.0, 17.5/75.0};
    double intercepts[] = {0.0333, 0.01675, 0.0, -0.075};
    
    double maleRatio = MMB/aveMMB;
    double xp = 0;
    if (maleRatio < 0.25){
        return 0;
    } else if (maleRatio >= 1.0){
        maleRatio = 1;
    }
    xp = maleRatio*slopes[rampID -1]+intercepts[rampID -1];
    
    double TAC = MMB*xp;
    
    return TAC;
}