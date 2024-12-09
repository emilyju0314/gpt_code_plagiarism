double BoundedNumberInfo::jitterInitVal(random_number_generator& rng, double jitFrac){
    double vp = initVal;
    if (phase>0){
        //double d = upper-lower;
        double r = rng.better_rand();
        //vp = min(max(lower+0.0001*d,initVal+wts::min(1.0,jitFrac)*(r-0.5)*d),upper-0.0001*d);
        vp = tcsam::jitterIt(initVal, lower, upper, jitFrac, r);
    }
    return vp;
}