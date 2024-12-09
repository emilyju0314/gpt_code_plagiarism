int mu2e::DbTool::commitCalibrationTable(DbTable::cptr_t const& ptr, 
					 bool admin) {
  DbTableCollection coll;
  coll.emplace_back(DbLiveTable(mu2e::DbIoV(),ptr));
  return commitCalibrationList(coll,false,false,admin);
}