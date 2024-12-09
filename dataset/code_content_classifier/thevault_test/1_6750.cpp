void
LinkCache::checkLink_logall(const ID& from, const ID& to, int action)
{
	Link *l = findLink(from.addr, to.addr);

	assert(action == ACTION_EVICT);
	assert(l);

	if(God::instance()->hops(from.addr, to.addr) != 1) {
		trace("SRC %.9f _%s_ %s [%d %d] %s->%s dead %d %.9f",
		      CURRENT_TIME, net_id.dump(),
		      action_name[action], 0, 0,
		      from.dump(), to.dump(),
		      l->ln_linktype, l->ln_t);
	}
}