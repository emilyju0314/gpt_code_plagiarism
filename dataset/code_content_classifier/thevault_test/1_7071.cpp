void DirMonitor::HandleDeleteSelf(int wd)
{
  cout << "IN_DELETE_SELF triggered for wd " << wd << endl;
  string path = GetDirPath(wd);
  if (path.empty()) return;
  RemovePair(path, wd);
  wds_[wd].clear();
  RemoveFromParentList(path, wd);
}