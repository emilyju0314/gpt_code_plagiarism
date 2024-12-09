void
MobiCache::checkRoute(Path & p,
                      int & subroute_bad_count,
                      int & link_bad_count,
                      double & link_bad_time,
                      int & link_bad_tested,
                      int & link_good_tested,
		      double & link_good_time)
{
  int c;
  int flag = 0;

  if(p.length() == 0)
    return;
  assert(p.length() >= 2);

  for (c = 0; c < p.length() - 1; c++)
    {
      assert(LS_UNLOGGED == p[c].log_stat || LS_LOGGED == p[c].log_stat );
      if (God::instance()->hops(p[c].getNSAddr_t(), p[c+1].getNSAddr_t()) != 1)
	{ // the link's dead
          if(p[c].log_stat == LS_UNLOGGED)
	    {
	      trace("SRC %.9f _%s_ check-cache [%d %d] %s->%s dead %d %.9f",
		    Scheduler::instance().clock(), net_id.dump(),
		    p.length(), c, p[c].dump(), p[c+1].dump(),
                    p[c].link_type, p[c].t);
	      p[c].log_stat = LS_LOGGED;
	    }
          if(flag == 0)
            {
              subroute_bad_count += p.length() - c - 1;
              flag = 1;
            }
          link_bad_count += 1;
          link_bad_time += Scheduler::instance().clock() - p[c].t;
          link_bad_tested += (p[c].link_type == LT_TESTED) ? 1 : 0;
	}
      else
        {
	  
	  link_good_time += Scheduler::instance().clock() - p[c].t;
	  
          if(p[c].log_stat == LS_LOGGED)
            {
              trace("SRC %.9f _%s_ resurrected-link [%d %d] %s->%s dead %d %.9f",
                    Scheduler::instance().clock(), net_id.dump(),
                    p.length(), c, p[c].dump(), p[c+1].dump(),
                    p[c].link_type, p[c].t);
              p[c].log_stat = LS_UNLOGGED;
            }
          link_good_tested += (p[c].link_type == LT_TESTED) ? 1 : 0;
        }
    }
}