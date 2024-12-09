int SubsDataGroupManager::findCBWithmTmsi( uint32_t key )
	{
		std::lock_guard<std::mutex> lock(mTmsi_cb_id_map_mutex);
        
		auto itr = mTmsi_cb_id_map.find( key );
		if( itr != mTmsi_cb_id_map.end())
		{
			return itr->second;
		}
		return -1;
	}