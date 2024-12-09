bool
aomdv_rt_entry::new_disjoint_path(nsaddr_t nexthop, nsaddr_t lasthop)
{
  AOMDV_Path *path = rt_path_list.lh_first;

  for(; path; path = path->path_link.le_next) {
    if ( (path->nexthop == nexthop) || (path->lasthop == lasthop) )
      return false;
  }
  return true;

}