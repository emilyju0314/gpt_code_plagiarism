int SubsDataGroupManager::addmTmsikey( uint32_t key, int cb_index )
	{
		std::lock_guard<std::mutex> lock(mTmsi_cb_id_map_mutex);

		int rc = 1;

		auto itr = mTmsi_cb_id_map.insert(std::pair<uint32_t, int>( key, cb_index ));
		if (itr.second == false)
		{
			rc = -1;
		}
		return rc;
	}