void
handle_mgr::delete_handle_wo(std::string m)
{
  if (hmap.find(m) == hmap.end()) {
    tprintf("handle_mgr::delete_handle_wo: cl %s isn't in cl list\n", m.c_str());
  } else {
    tprintf("handle_mgr::delete_handle_wo: cl %s refcnt %d\n", m.c_str(),
	   hmap[m]->refcnt);
    struct hinfo *h = hmap[m];
    if (h->refcnt == 0) {
      if (h->cl) {
        h->cl->cancel();
        delete h->cl;
      }
      pthread_mutex_destroy(&h->cl_mutex);
      hmap.erase(m);
      delete h;
    } else {
      h->del = true;
    }
  }
}