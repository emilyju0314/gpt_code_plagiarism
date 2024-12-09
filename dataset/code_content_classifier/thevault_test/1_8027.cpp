int mu2e::DbTool::findPidVid(std::string purpose, std::string version, int& pid, int& vid) {
  pid = -1;
  vid = -1;

  if( purpose.empty() && !version.empty() )  {
    std::cout << "Error - version must be used with a purpose" << std::endl;
    return 1;  
  }

  // both are empty
  if( purpose.empty() )  return 0;

  for(auto const& pp : _valcache.valPurposes().rows()) {
    if(pp.name()==purpose) pid = pp.pid(); 
  }

  if(pid<0) {
    std::cout << "Error - could not find purpose "<< purpose << std::endl;
    return 1;
  }

  // purpose found, version empty
  if(version.empty()) return 0;

  DbVersion dbver(purpose,version);
  if(dbver.major()<0 || dbver.minor()<0) {
    std::cout << "Error - version not incomplete, major minor numbers required: "<< version << std::endl;
    return 1;
  }

  for(auto const& vv : _valcache.valVersions().rows()) {
    if(vv.pid()==pid && vv.major()==dbver.major() && vv.minor()==dbver.minor()) {
      vid = vv.vid();
    }
  }

  if(vid<0) {
    std::cout << "Error - could not find version "<< version << std::endl;
    return 1;
  }

  return 0;
}