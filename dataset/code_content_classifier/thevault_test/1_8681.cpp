double pairwiseUnwrap(double phase1, double phase2){
    while(fabs(phase1-phase2) > M_PI){
        
        if(phase1 > phase2 + M_PI){
            phase1 = phase1 - 2*M_PI;
        }
        else if (phase1 < phase2 - M_PI){
            phase1 = phase1 + 2*M_PI;
        }
        else{
            break;
        }
        
    }
    double result = phase1 - phase2;
    return result;
}