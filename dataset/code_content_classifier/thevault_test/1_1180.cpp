ExcludeAllWrites::ExcludeAllWrites() : 
        lk(cc().lockStatus.excluder, d.writeExcluder), 
        gslk()
    {
        LOG(3) << "ExcludeAllWrites" << endl;
        wassert( !d.dbMutex.isWriteLocked() );
    }