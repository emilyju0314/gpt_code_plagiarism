void virtual_station::relocate_grid_center()
{
	
	if ( this->npts_record_sum <= this->station_num_threshold)
	{
		double skip;
		skip = 0;
	}
	else 
	{
		double new_lat;
		double new_lon;
		int count;
		int tag;
		new_lat = 0;
		for(count = 0; count < this->npts_record_sum ; count++)
		{
			// to avoid the 0-180 transition
			// when lon > 150 || < -150, we use 0-360 range and change it back to -180 ~180 range
			tag = this->record_tag[count];
			new_lat += this->my_big_record->my_record[tag].sta_lat;
		}
		new_lat = new_lat / this->npts_record_sum;


		// we use one record to decide whick lon range to use
		tag = 0;
		double lon_tmp;
		lon_tmp = this->my_big_record->my_record[tag].sta_lon;
		new_lon = 0;


		if(   this->sta_lon < -150 || this->sta_lon > 150  )
		{
			for(count = 0; count < this->npts_record_sum ; count++)
			{
				// to avoid the 0-180 transition
				// when lon > 150 || < -150, we use 0-360 range and change it back to -180 ~180 range
				tag = this->record_tag[count];
				new_lon += lon2360(this->my_big_record->my_record[tag].sta_lon);
				cout << " count "<< count << " coverted sta lon "<< lon2360(this->my_big_record->my_record[tag].sta_lon) << endl;
			}
			new_lon = new_lon / this->npts_record_sum;
			if( new_lon > 180 )
				new_lon = new_lon - 360;
		}
		else
		{
			for(count = 0; count < this->npts_record_sum ; count++)
			{
				// to avoid the 0-180 transition
				// when lon > 150 || < -150, we use 0-360 range and change it back to -180 ~180 range
				tag = this->record_tag[count];
				new_lon += this->my_big_record->my_record[tag].sta_lon;
			}
			new_lon = new_lon / this->npts_record_sum;

		}

		cout << " before relocation "<< this->sta_lat << " " << this->sta_lon << endl;


		//this->grid_lat = new_lat;
		//this->grid_lon = new_lon;
		this->sta_lat = new_lat;
		this->sta_lon = new_lon;
		cout << " after relocation "<< this->sta_lat << " " << this->sta_lon << endl;

	}

}