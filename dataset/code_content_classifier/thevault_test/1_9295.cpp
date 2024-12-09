double HarvestStrategies::HCR23_MaleRamp_ModSurvEst(double MMB, double aveMMB){
    //Define look up table for ramps
    double slope = (10.0/75.0);
    double intercept = 0.01675;
    
    double maleRatio = MMB/aveMMB;
    double xp = 0;
    if (maleRatio < 0.25){
        return 0;
    } else if (maleRatio >= 1.0){
        maleRatio = 1;
    }
    xp = maleRatio*slope+intercept;
    
    double TAC = MMB*xp;
    
    return TAC;
}