dvector DevsVectorInfo::jitterInitVals(random_number_generator& rng, double jitFrac){
    if (debug){
        rpt::echo<<"--in DevsVectorInfo::jitterInitVals"<<endl;
        rpt::echo<<"initVals   = "<<initVals<<endl;
    }
    dvector vp = 1.0*initVals;
    if (phase>0){
        if (debug) rpt::echo<<"lower = "<<lower<<tb<<"upper = "<<upper<<endl;
        vp = BoundedVectorInfo::jitterInitVals(rng,jitFrac);
        if (debug) rpt::echo<<"vp         = "<<vp<<endl;
        vp -= mean(vp);//ensure sum of devs = 0
        if (debug) rpt::echo<<"vp-mean(vp) = "<<vp<<endl<<"sum(vpp) = "<<sum(vp)<<endl;
        if (max(fabs(vp))>max(fabs(lower),fabs(upper))) {
            double rescl = max(fabs(lower),fabs(upper))/max(fabs(vp));
            if (debug) rpt::echo<<"rescaling using "<<rescl<<endl;
            vp *= rescl;//rescale to within bounds
        }        
    }
    if (debug) {
        rpt::echo<<"final vp = "<<vp<<endl;
        rpt::echo<<"------------"<<endl;
    }
    return vp;
}