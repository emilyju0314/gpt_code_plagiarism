bool IonFinder::Params::getFlist(bool force)
{
    if(_inDirs.empty()){
        _inDirs.push_back(_wd);
        _wd = utils::parentDir(_wd);
    }
    for(auto& _inDir : _inDirs)
    {
        std::string fname = (_inDirSpecified ? (_wd + _inDir) : _inDir) + ("/" + _dtaFilterBase);
        if(utils::fileExists(fname)){
            _filterFiles[utils::baseName(_inDir)] = fname;
        }
        else{
            if(force) std::cerr << "WARN: ";
            else std::cerr << "ERROR: ";
            std::cerr << "No filter file found in: " << _inDir << NEW_LINE;
            if(force) return false;
        }
    }
    return !_filterFiles.empty();
}