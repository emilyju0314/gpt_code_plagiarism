void CSLObj::XPObjLoadedCB (XPLMObjectRef inObject,
                            void *        inRefcon)
{
    // This is a plugin entry function, so we try to catch all exceptions
    try {
        // the refcon is a pointer to a pair object created just for us
        pairOfStrTy* p = reinterpret_cast<pairOfStrTy*>(inRefcon);
    
        // try finding the CSL model object in the global map
        mapCSLModelTy::iterator cslIter;
        CSLModel* pCsl = CSLModelByKey(p->first, &cslIter);
        if (!pCsl) {
            // CSL model not found in global map -> release the X-Plane object right away
            LOG_MSG(logERR, ERR_OBJ_NOT_FOUND, p->first.c_str());
            if (inObject)
                XPLMUnloadObject(inObject);
        }
        else
        {
            // find the object by path
            listCSLObjTy::iterator iter = std::find_if(pCsl->listObj.begin(),
                                                       pCsl->listObj.end(),
                                                       [p](const CSLObj& o)
                                                       { return o.path == p->second; });
        
            // found?
            if (iter != pCsl->listObj.end()) {
                // Loading succeeded -> save the object and state
                LOG_ASSERT(iter->GetObjState() == OLS_LOADING);
                if (inObject) {
                    iter->xpObj      = inObject;
                    iter->xpObjState = OLS_AVAILABLE;
                    LOG_MSG(logDEBUG, DEBUG_OBJ_LOADED,
                            iter->cslKey.c_str(), StripXPSysDir(iter->path).c_str());
                }
                // Loading of CSL object failed! -> remove the entire CSL model
                // so we don't try again and don't use it in matching
                else {
                    iter->Invalidate();
                    glob.mapCSLModels.erase(cslIter);
                }
            } else {
                LOG_MSG(logERR, ERR_OBJ_OBJ_NOT_FOUND, p->first.c_str());
                XPLMUnloadObject(inObject);
            }
        }
    
        // free up the memory for the copy of the ids
        delete p;
    }
    catch (const std::exception& e) { LOG_MSG(logFATAL, ERR_EXCEPTION, e.what()); }
    catch (...) { LOG_MSG(logFATAL, ERR_EXCEPTION, "<unknown>"); }
}