adstring SelFcns::getSelFcnID(int id){
    if (debug) cout<<"Starting SelFcns::getSelFcnID("<<id<<")"<<endl;
    adstring str = "";
    switch(id){
        case ID_ASCLOGISTIC: 
            if (debug) cout<<"SelFcn = "<<STR_ASCLOGISTIC<<endl;
            return STR_ASCLOGISTIC;
        case ID_ASCLOGISTICLN50: 
            if (debug) cout<<"SelFcn = "<<STR_ASCLOGISTICLN50<<endl;
            return STR_ASCLOGISTICLN50;
        case ID_ASCLOGISTIC5095: 
            if (debug) cout<<"SelFcn = "<<STR_ASCLOGISTIC5095<<endl;
            return STR_ASCLOGISTIC5095;
        case ID_ASCLOGISTIC50LN95: 
            if (debug) cout<<"SelFcn = "<<STR_ASCLOGISTIC50LN95<<endl;
            return STR_ASCLOGISTIC50LN95;
        case ID_ASCLOGISTICLN50LN95: 
            if (debug) cout<<"SelFcn = "<<STR_ASCLOGISTICLN50LN95<<endl;
            return STR_ASCLOGISTICLN50LN95;
        case ID_DBLLOGISTIC: 
            if (debug) cout<<"SelFcn = "<<STR_DBLLOGISTIC<<endl;
            return STR_DBLLOGISTIC;
        case ID_DBLLOGISTICLND50: 
            if (debug) cout<<"SelFcn = "<<STR_DBLLOGISTICLND50<<endl;
            return STR_DBLLOGISTICLND50;
        case ID_DBLLOGISTIC5095: 
            if (debug) cout<<"SelFcn = "<<STR_DBLLOGISTIC5095<<endl;
            return STR_DBLLOGISTIC5095;
        case ID_DBLLOGISTIC50LN95: 
            if (debug) cout<<"SelFcn = "<<STR_DBLLOGISTIC50LN95<<endl;
            return STR_DBLLOGISTIC50LN95;
        case ID_DBLLOGISTICLN50LN95: 
            if (debug) cout<<"SelFcn = "<<STR_DBLLOGISTICLN50LN95<<endl;
            return STR_DBLLOGISTICLN50LN95;
        case ID_ASCLOGISTIC5099: 
            if (debug) cout<<"SelFcn = "<<STR_ASCLOGISTIC5099<<endl;
            return STR_ASCLOGISTIC5099;
        case ID_ASCLOGISTIC95LN50: 
            if (debug) cout<<"SelFcn = "<<STR_ASCLOGISTIC95LN50<<endl;
            return STR_ASCLOGISTIC95LN50;
        case ID_ASCNORMAL: 
            if (debug) cout<<"SelFcn = "<<STR_ASCNORMAL<<endl;
            return STR_ASCNORMAL;
        case ID_DBLNORMAL4: 
            if (debug) cout<<"SelFcn = "<<STR_DBLNORMAL4<<endl;
            return STR_DBLNORMAL4;
        case ID_DBLNORMAL6: 
            if (debug) cout<<"SelFcn = "<<STR_DBLNORMAL6<<endl;
            return STR_DBLNORMAL6;
        case ID_NONPARAMETRIC: 
            if (debug) cout<<"SelFcn = "<<STR_NONPARAMETRIC<<endl;
            return STR_NONPARAMETRIC;
        default:
        {
            cout<<endl;
            cout<<"Invalid id for SelFcns.getSelFcnID(id)"<<endl;
            cout<<"id was "<<id<<"."<<endl;
            cout<<"Aborting..."<<endl;
            exit(-1);
        }
    }
    return str;
}