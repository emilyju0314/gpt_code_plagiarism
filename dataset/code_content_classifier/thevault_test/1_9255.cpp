dvector DevsVectorInfo::drawInitVals(random_number_generator& rng, double vif){
    if (debug) rpt::echo<<"starting DevsVectorInfo::drawInitVals(random_number_generator& rng) for "<<name<<endl;
    dvector smpl = initVals;
    if (phase>0){
        smpl = BoundedVectorInfo::drawInitVals(rng,vif);
        smpl -= mean(smpl);//ensure sum of devs = 0
        if (max(fabs(smpl))>max(fabs(lower),fabs(upper))) smpl *= max(fabs(lower),fabs(upper))/max(fabs(smpl));
    }
    if (debug) {
        rpt::echo<<phase<<tb<<pMPI->canSample()<<endl;
        rpt::echo<<"initVals: "<<initVals<<endl<<"samples: "<<smpl<<endl;
        rpt::echo<<"finished DevsVectorInfo::drawInitVals(random_number_generator& rng) for "<<name<<endl;
    }
    return smpl;
}