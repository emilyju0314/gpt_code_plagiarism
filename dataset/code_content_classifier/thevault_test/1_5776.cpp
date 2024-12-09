bool ms2::MsInterface::read(InputScanList::const_iterator begin, InputScanList::const_iterator end)
{
    //first get unique names of ms2 files to read
    std::vector<std::string> fileNamesList;
    ms2::MsInterface::getUniqueFileList(fileNamesList, begin, end);

    //read ms2 files
    bool allSucess = true;
    size_t len = fileNamesList.size();
    for(size_t i = 0; i < len; i++) {
        std::string _fname = fileNamesList[i];
        bool fileRead = _ms2Map.find(_fname) == _ms2Map.end();
        if(fileRead) {
            if(!read(_fname)) allSucess = false;
        }
    }

    if(!allSucess){
        std::cerr << "Error reading ms2 files!" << NEW_LINE;
        return false;
    }

    return true;
}