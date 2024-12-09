dvector BoundedVectorInfo::jitterInitVals(random_number_generator& rng, double jitFrac){
    dvector vp = 1.0*initVals;
    if (phase>0){
        double d = upper-lower;
        for (int i=1;i<=N;i++){
            double r = rng.better_rand();
            //vp(i) = min(max(lower+0.0001*d,initVals(i)+wts::min(1.0,jitFrac)*(r-0.5)*d),upper-0.0001*d);
            vp(i) = tcsam::jitterIt(initVals(i), lower, upper, jitFrac, r);
        }
    }
    return vp;
}