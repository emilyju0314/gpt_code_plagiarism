void MongoMutex::lockedExclusively() {
        Client& c = cc();
        curopGotLock(&c); // hopefully lockStatus replaces one day
        c.lockStatus.global = clcimpl::LockedExclusive;
        _minfo.entered(); // hopefully eliminate one day 
    }