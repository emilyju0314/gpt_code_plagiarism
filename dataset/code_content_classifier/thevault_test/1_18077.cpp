int SubsDataGroupManager::addimsikey( DigitRegister15 key, int cb_index )
	{
		std::lock_guard<std::mutex> lock(imsi_cb_id_map_mutex);

		int rc = 1;

		auto itr = imsi_cb_id_map.insert(std::pair<DigitRegister15, int>( key, cb_index ));
		if (itr.second == false)
		{
			rc = -1;
		}
		return rc;
	}