int SubsDataGroupManager::findCBWithimsi( DigitRegister15 key )
	{
		std::lock_guard<std::mutex> lock(imsi_cb_id_map_mutex);
        
		auto itr = imsi_cb_id_map.find( key );
		if( itr != imsi_cb_id_map.end())
		{
			return itr->second;
		}
		return -1;
	}