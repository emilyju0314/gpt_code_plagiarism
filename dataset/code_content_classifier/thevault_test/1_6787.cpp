StateInfo * PgmAgent::find_TSI(ns_addr_t &tsi)
{

  // Use the TSI from the SPM packet and locate the proper state block.
  list<StateInfo>::iterator iter = state_list_.begin();
  while(iter != state_list_.end()) {
    if ( (*iter).tsi().isEqual (tsi) ) {
      return &(*iter);
    }
    iter++;
  }

  return NULL;
}