void 
rsm::commit_change(unsigned vid) 
{
  ScopedLock ml(&rsm_mutex);
  commit_change_wo(vid);
}