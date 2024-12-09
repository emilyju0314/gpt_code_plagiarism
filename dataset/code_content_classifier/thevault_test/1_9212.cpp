double NumberInfo::drawInitVal(random_number_generator& rng, double vif){
    if (debug) rpt::echo<<"starting NumberInfo::drawSample(random_number_generator& rng, vif)"<<this<<endl;
    double smpl  = initVal;
    if (resample&&(phase>0)&&(pMPI->canSample())) {
        smpl = pMPI->drawSample(rng,priorParams,priorConsts);
    }
    if (debug) {
        rpt::echo<<phase<<tb<<pMPI->canSample()<<tb<<initVal<<tb<<smpl<<endl;
        rpt::echo<<"finished NumberInfo::drawSample(random_number_generator& rng,vif)"<<this<<endl;
    }
    return smpl;
}