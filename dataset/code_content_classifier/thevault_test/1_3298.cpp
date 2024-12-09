size_t CHexEditDoc::FindDffdEltAt(FILE_ADDRESS addr)
{
	int ii, end = df_address_.size();

	for (ii = 0; ii < end; ++ii)
	{
		if (df_type_[ii] > DF_DATA)
		{
			FILE_ADDRESS aa = df_address_[ii];
			if (addr >= aa && addr < aa + df_size_[ii])
				return ii;
		}
	}
	return end;  // not found
}