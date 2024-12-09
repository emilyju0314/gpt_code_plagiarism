int SubsDataGroupManager::deletemTmsikey( uint32_t key )
	{
		std::lock_guard<std::mutex> lock(mTmsi_cb_id_map_mutex);
 
		return mTmsi_cb_id_map.erase( key );
	}