void HttpMInvalCache::process_inv(int, InvalidationRec *ivlist, int cache)
{
	InvalidationRec *p = ivlist, *q, *r;
	//int upd = 0;
	while (p != NULL) {
		ClientPage* pg = (ClientPage *)pool_->get_page(p->pg());

		// XXX Establish server states. Server states only gets 
		// established when we have a page (no matter if we have its
		// content), and we have got an invalidation for the page. 
		// Then we know we've got an invalidation contract for the 
		// page.
		if (pg != NULL) {
			check_sstate(pg->server()->id(), cache);
			// Count this invalidation no matter whether we're
			// going to drop it. But if we doesn't get it 
			// from our virtual parent, don't count it
			SState *sst = lookup_sstate(pg->server()->id());
			if (sst == NULL) {
				// How come we doesn't know the server???
				fprintf(stderr, 
					"%s %d: couldn't find the server.\n", 
					__FILE__, __LINE__);
				abort();
			}
			if ((sst->cache()->cache()->id() == cache) && 
			    (pg->mtime() > p->mtime())) {
				// Don't count repeated invalidations.
				pg->count_inval(Ca_, push_low_bound_);
				log("E NTF p %s v %d\n",p->pg(),pg->counter());
			}
		}

		// Hook for filters of derived classes
		if (recv_inv_filter(pg, p) == HTTP_INVALCACHE_FILTERED) {
			// If we do not have the page, or we have (or know 
			// about) a newer page, ignore this invalidation 
			// record and keep going.
			//
			// If we have this version of the page, and it's 
			// already invalid, ignore this extra invalidation
			q = p;
			p = p->next();
			q->detach();
			delete q;
		} else {
			// Otherwise we invalidate our page and setup a 
			// invalidation sending record for the page
			pg->invalidate(p->mtime());
			// Delete existing record for that page if any
			q = get_invrec(p->pg());
			if ((q != NULL) && (q->mtime() < p->mtime())) {
				q->detach();
				delete q;
				q = NULL;
				num_inv_--;
			}
			r = p; 
			p = p->next();
			r->detach();
			// Insert it if necessary
			if (q == NULL) {
				r->insert(&invlist_);
				num_inv_++;
				// XXX
				Tcl::instance().evalf("%s mark-invalid",name_);
				log("E GINV p %s m %.17g\n", r->pg(), r->mtime());
			} else
				delete r;
		}
	}
}