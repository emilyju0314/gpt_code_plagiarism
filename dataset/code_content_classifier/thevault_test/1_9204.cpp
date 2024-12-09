dvar3_array PopProjector::project(dvariable dirF, dvar3_array& n_msz, ostream& cout){
    if (debug) cout<<"starting PopProjector::project(dirF, n_msz)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    n1_msz.initialize();
    n2_msz.initialize();
    n3_msz.initialize();
    n4_msz.initialize();
    n5_msz.initialize();
    //if (debug){PopDyInfo::debug=1; CatchInfo::debug=1;}
    if (dtF<=dtM){ //fisheries occur BEFORE molting/growth/maturity 
        if (debug) cout<<"dtF(<=dtM) = "<<dtF<<endl;
        //apply natural mortality BEFORE fisheries
        n1_msz = pPI->applyNM(dtF, n_msz,cout);
        //if (debug) cout<<1<<endl;
        //apply fisheries
        n2_msz = pCI->applyFM(dirF, n1_msz,cout);
        //if (debug) cout<<2<<endl;
        //apply natural mortality after fisheries but before molting/growth
        if (dtF==dtM){
            n3_msz = n2_msz;
            //if (debug) cout<<3<<endl;
        } else {
            n3_msz = pPI->applyNM(dtM-dtF, n2_msz,cout);
            //if (debug) cout<<4<<endl;
        }        
        //apply molting/growth
        n4_msz = pPI->applyMG(n3_msz,cout);
        //if (debug) cout<<5<<endl;
        //apply natural mortality AFTER molting/growth
        n5_msz = pPI->applyNM(1.0-dtM, n4_msz,cout);
        //if (debug) cout<<6<<endl;
        
        //calculate mature biomass-at-mating from pre-molting/growth abundance
        matBio = pPI->calcMatureBiomass(n3_msz,cout);
        //if (debug) cout<<7<<endl;
    } else { //fisheries occur AFTER molting/growth/maturity 
        if (debug) cout<<"dtM<dtF"<<endl;
        //apply natural mortality BEFORE molting/growth
        n1_msz = pPI->applyNM(dtM, n_msz,cout);        
        //apply molting/growth
        n2_msz = pPI->applyMG(n1_msz,cout);
        //apply natural mortality after molting/growth but before fisheries
        if (dtF==dtM){
            n3_msz = n2_msz;
        } else {
            n3_msz = pPI->applyNM(dtF-dtM, n2_msz,cout);
        }
        //apply fisheries
        n4_msz = pCI->applyFM(dirF, n3_msz,cout);
        //apply natural mortality AFTER fisheries
        n5_msz = pPI->applyNM(1.0-dtF, n4_msz,cout);
        
        //calculate mature biomass-at-mating from pre-molting/growth abundance
        matBio = pPI->calcMatureBiomass(n1_msz,cout);
    }
    
    if (debug){
        cout<<"n_msz  = "<<&n_msz<<endl;
        cout<<"n1_msz = "<<&n1_msz<<endl;
        cout<<"n2_msz = "<<&n2_msz<<endl;
        cout<<"n3_msz = "<<&n3_msz<<endl;
        cout<<"n4_msz = "<<&n4_msz<<endl;
        cout<<"n5_msz = "<<&n5_msz<<endl;
        cout<<"------n0_msz = "<<endl; wts::print(n_msz, cout,1);
        cout<<"------n1_msz = "<<endl; wts::print(n1_msz,cout,1);
        for (int f=1;f<=nFsh;f++){
            cout<<"----fishery = "<<f<<endl;
            cout<<"----hmF = "<<pCI->hm_f(f)<<endl;
            cout<<"------cpF_msz = "<<endl; wts::print(pCI->cpF_fmsz(f),cout,1);
            cout<<"------rmF_msz = "<<endl; wts::print(pCI->rmF_fmsz(f),cout,1);
            cout<<"------dmF_msz = "<<endl; wts::print(pCI->dmF_fmsz(f),cout,1);
//            cout<<"------cpN_msz = "<<endl; wts::print(pCI->cpN_fmsz(f),cout,1);
//            cout<<"------rmN_msz = "<<endl; wts::print(pCI->rmN_fmsz(f),cout,1);
//            cout<<"------dmN_msz = "<<endl; wts::print(pCI->dmN_fmsz(f),cout,1);
        }//f
        cout<<"------n2_msz = "<<endl; wts::print(n2_msz,cout,1);
        cout<<"------n3_msz = "<<endl; wts::print(n3_msz,cout,1);
        cout<<"------n4_msz = "<<endl; wts::print(n4_msz,cout,1);
        cout<<"------n5_msz = "<<endl; wts::print(n5_msz,cout,1);
    }
//    if (debug){PopDyInfo::debug=0; CatchInfo::debug=0;}
    if (debug) cout<<"finished PopProjector::project(dirF, n_msz)"<<endl;   
    RETURN_ARRAYS_DECREMENT();
    return 1.0*n5_msz;
}