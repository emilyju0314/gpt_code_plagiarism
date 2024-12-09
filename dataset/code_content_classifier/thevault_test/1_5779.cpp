void ms2::MsInterface::getUniqueFileList(std::vector<std::string> &fnames,
                                         std::vector<Dtafilter::Scan>::const_iterator begin,
                                         std::vector<Dtafilter::Scan>::const_iterator end) const
{
    fnames.clear();
    for(auto scan = begin; scan != end; scan++){
        if(std::find(fnames.begin(), fnames.end(), scan->getPrecursor().getFile()) == fnames.end()){
            fnames.push_back(scan->getPrecursor().getFile());
        }
    }
}