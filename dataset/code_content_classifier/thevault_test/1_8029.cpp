int mu2e::DbTool::extendEiovMap(int gid, eiovMap& emap, 
				int& minrun, int& maxrun) {

  for(auto const& glr :  _valcache.valGroupLists().rows()) {
    if(glr.gid()==gid ) {
      auto const& ir =  _valcache.valIovs().row(glr.iid());
      auto const& cr = _valcache.valCalibrations().row(ir.cid());
      if(int(ir.iov().startRun()) < minrun) minrun = ir.iov().startRun();
      if(int(ir.iov().endRun()) > maxrun) maxrun = ir.iov().endRun();
      emap[cr.tid()].emplace_back(ir.iid(),ir.cid(),ir.iov());
    }
  } // group lists

  return 0;
}