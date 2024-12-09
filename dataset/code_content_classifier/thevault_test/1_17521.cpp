std::list<XPLMObjectRef> CSLModel::GetAllObjRefs ()
{
    // This loads the object, so we should make sure to have a VERT_OFFSET, too
    if (bVertOfsReadFromFile) {
        // span a job to read it from the object files
        bVertOfsReadFromFile = false;
        futVertOfs = std::async(std::launch::async,
                                &CSLModel::FetchVertOfsFromObjFile, this);
    }
    
    bool bFullyLoaded = true;
    std::list<XPLMObjectRef> l;
    for (CSLObj& obj: listObj)                  // loop over all object
    {
        if (obj.IsInvalid())                    // if any object is considered valid
            return std::list<XPLMObjectRef>();  // return an empty list
        
        l.push_back(obj.GetAndLoadObj());       // load and save the handle
        if (l.back() == NULL)                   // not (yet) loaded?
            bFullyLoaded = false;               // return an empty list in the end
    }
    
    // Also check if our vertical offset is available now
    if (futVertOfs.valid()) {                   // we are waiting for a result
        if (futVertOfs.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
            bFullyLoaded = false;               // not yet available
        else
            vertOfs = futVertOfs.get();         // avaiable, get it
    }
    
    // return the complete list of handles if all was successful
    return bFullyLoaded ? l : std::list<XPLMObjectRef>();
}