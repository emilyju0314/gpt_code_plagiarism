int SubsDataGroupManager::deleteimsikey( DigitRegister15 key )
	{
		std::lock_guard<std::mutex> lock(imsi_cb_id_map_mutex);
 
		return imsi_cb_id_map.erase( key );
	}