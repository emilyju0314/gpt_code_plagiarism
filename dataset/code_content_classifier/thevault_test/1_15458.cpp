bool K2HShmUpdater::UpdateArea(K2HShm* pk2hshm)
{
	if(!pk2hshm){
		ERR_K2HPRN("Parameter is wrong.");
		return false;
	}

	while(!fullock::flck_trylock_noshared_mutex(&K2HShmUpdater::lockval));		// no call sched_yield()

	bool	change	= false;
	bool	result	= pk2hshm->CheckAreaUpdate(change);

	fullock::flck_unlock_noshared_mutex(&K2HShmUpdater::lockval);

	return result;
}