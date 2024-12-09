bool ms2::MsInterface::getScan(utils::msInterface::Scan& scan, std::string fname, size_t scanNum)
{
    auto ms2FileIt = _ms2Map.find(fname);
    if(ms2FileIt == _ms2Map.end()){
        if(!read(fname)) return false;
        ms2FileIt = _ms2Map.find(fname);
    }
    if(!ms2FileIt->second->getScan(scanNum, scan)){
        std::cerr << NEW_LINE << "Error reading scan!" << NEW_LINE;
        return false;
    }
    return true;
}