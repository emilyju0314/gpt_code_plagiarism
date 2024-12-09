float CSLModel::GarbageCollection (float, float, int, void*)
{
    UPDATE_CYCLE_NUM;               // DEBUG only: Store current cycle number in glob.xpCycleNum
    const float now = GetMiscNetwTime();
    // loop all models
    for (auto& p: glob.mapCSLModels) {
        CSLModel& mdl = p.second;
        // loaded, but reference counter zero, and timeout reached
        if (mdl.GetObjState() == OLS_AVAILABLE &&
            mdl.GetRefCnt() == 0 &&
            now - mdl.refZeroTs > GARBAGE_COLLECTION_TIMEOUT)
            // unload the object
            mdl.Unload();
    }
    
    return GARBAGE_COLLECTION_PERIOD;
}