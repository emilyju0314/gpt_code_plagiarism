double HarvestStrategies::HCR1_FemaleRamp(double MFB, double aveMFB, double MMB){
    double femRatio = MFB/aveMFB;
    double xp;
    double TAC;
    if (femRatio < 0.25){
        xp = 0;
    } else if (femRatio >= 1.0){
        xp = 0.2;
    } else{
        xp = femRatio*0.2;
    }
    TAC = MMB*xp;
    return TAC;
}