const char* CSLModelsLoad (const std::string& _path,
                           int _maxDepth)
{
    // First we identify all package, so that (theoretically)
    // package dependencies to other packages can be resolved.
    // (This might rarely be used as OBJ8 only consists of one file,
    //  but the original xsb_aircraft.txt syntax requires it.)
    std::vector<std::string> paths;
    const char* res = CSLModelsFindPkgs(_path, paths, _maxDepth);
    
    // Now we can process each folder and read in the CSL models there
    for (const std::string& p: paths)
    {
        const char* r = CSLModelsProcessAcFile(p);
        if (r[0]) {                     // error?
            res = r;                    // keep it as function result (but continue with next path anyway)
            LOG_MSG(logWARN, "%s", res);// also report it to the log
        }
    }
    
    // How many models do we now have in total?
    LOG_MSG(logINFO, INFO_TOTAL_NUM_MODELS, (unsigned long)glob.mapCSLModels.size())
    
    // return the final result
    return res;
}