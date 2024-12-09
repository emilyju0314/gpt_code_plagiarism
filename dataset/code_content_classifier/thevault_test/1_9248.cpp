dvector BoundedVectorInfo::drawInitVals(random_number_generator& rng, double vif){
    if (debug) rpt::echo<<"starting BoundedVectorInfo::drawInitVals(random_number_generator& rng) for "<<name<<endl;
    dvector smpl  = 1.0*initVals;
    if (resample&&(phase>0)&&(pMPI->canSample())) {
        for (int i=1;i<=N;i++) smpl(i) = pMPI->drawSample(rng,priorParams,priorConsts);
    }
    if (debug) {
        rpt::echo<<phase<<tb<<pMPI->canSample()<<endl;
        rpt::echo<<"initVals: "<<initVals<<endl<<"samples: "<<smpl<<endl;
        rpt::echo<<"finished BoundedVectorInfo::drawInitVals(random_number_generator& rng) for "<<name<<endl;
    }
    return smpl;
}