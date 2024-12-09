dvar_vector SelFcns::calcSelFcn(int id,dvector& z, dvar_vector& params, double fsZ){
    RETURN_ARRAYS_INCREMENT();
    if (debug) cout<<"Starting SelFcns::calcSelFcns(...) id: "<<id<<endl;
    dvar_vector s(z.indexmin(),z.indexmax());
    s.initialize();
    switch (id){
        case ID_ASCLOGISTIC:         {s=asclogistic(z,params,fsZ);         break;}
        case ID_ASCLOGISTICLN50:     {s=asclogisticLn50(z,params,fsZ);     break;}
        case ID_ASCLOGISTIC5095:     {s=asclogistic5095(z,params,fsZ);     break;}
        case ID_ASCLOGISTIC50LN95:   {s=asclogistic50Ln95(z,params,fsZ);   break;}
        case ID_ASCLOGISTICLN50LN95: {s=asclogisticLn50Ln95(z,params,fsZ); break;}
        case ID_DBLLOGISTIC:         {s=dbllogistic(z,params,fsZ);         break;}
        case ID_DBLLOGISTICLND50:    {s=dbllogisticLnD50(z,params,fsZ);    break;}
        case ID_DBLLOGISTIC5095:     {s=dbllogistic5095(z,params,fsZ);     break;}
        case ID_DBLLOGISTIC50LN95:   {s=dbllogistic50Ln95(z,params,fsZ);   break;}
        case ID_DBLLOGISTICLN50LN95: {s=dbllogisticLn50Ln95(z,params,fsZ); break;}
        case ID_ASCLOGISTIC5099:     {s=asclogistic5099(z,params,fsZ);     break;}
        case ID_ASCLOGISTIC95LN50:   {s=asclogistic95Ln50(z,params,fsZ);   break;}
        case ID_ASCNORMAL:           {s=ascnormal(z,params,fsZ);           break;}
        case ID_DBLNORMAL4:          {s=dblnormal4(z,params,fsZ);          break;}
        case ID_DBLNORMAL6:          {s=dblnormal6(z,params,fsZ);          break;}
        case ID_NONPARAMETRIC:       {s=nonparametric(z,params,fsZ);       break;}
        default:
        {
            cout<<"Invalid id for SelFcns.calcSelFcn(id,...)";
            cout<<"id was "<<id<<"."<<endl;
            cout<<"Aborting..."<<endl;
            exit(-1);
        }
    }
    if (debug) cout<<"Finished SelFcns::calcSelFcns(...) id: "<<id<<endl;
    RETURN_ARRAYS_DECREMENT();
    return s;
}