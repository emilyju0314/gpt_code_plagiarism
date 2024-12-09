bool ms2::MsInterface::getScan(utils::msInterface::Scan& scan, std::string fname, size_t scanNum) const
{
    //load spectrum
    auto ms2FileIt = _ms2Map.find(fname);
    if(ms2FileIt == _ms2Map.end()){
        std::cerr << NEW_LINE << "Key error in Ms2Map!" << NEW_LINE;
        return false;
    }
    if(!ms2FileIt->second->getScan(scanNum, scan)){
        std::cerr << NEW_LINE << "Error reading scan!" << NEW_LINE;
        return false;
    }
    return true;
}