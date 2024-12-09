bool ms2::MsInterface::read(std::string fname)
{
    // Check if file already exists and exit if it does.
    if(_ms2Map.find(fname) != _ms2Map.end()) return true;

    auto _file = std::shared_ptr<utils::msInterface::MsInterface>();
    utils::msInterface::MsInterface::FileType fileType = utils::msInterface::MsInterface::getFileType(fname);
    if(fileType == utils::msInterface::MsInterface::FileType::MS2)
        _file = std::make_shared<utils::msInterface::Ms2File>();
    else if(fileType == utils::msInterface::MsInterface::FileType::MZXML)
        _file = std::make_shared<utils::msInterface::MzXMLFile>();
    else if(fileType == utils::msInterface::MsInterface::FileType::MZML)
        _file = std::make_shared<utils::msInterface::MzMLFile>();
    else {
        std::cerr << "Unknown file type for file " << fname << NEW_LINE;
        return false;
    }
    if(!_file->read(fname)) {
        std::cerr << "\n\tFailed to read: " << fname << NEW_LINE;
        std::cerr << "\t\tNo file found at: " << utils::absPath(fname) << NEW_LINE;
        return false;
    }

    // lock mutex
    std::lock_guard<std::mutex> lock (mutex);
    _ms2Map[fname] = _file;
    return true;
}