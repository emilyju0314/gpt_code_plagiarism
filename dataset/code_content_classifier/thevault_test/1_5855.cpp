int32 
gpdb::CdbHashConstList
	(
	List *constants,
	int num_segments,
	Oid *hashfuncs
	)
{
	GP_WRAP_START;
	{
		return cdbhash_const_list(constants, num_segments, hashfuncs);
	}
	GP_WRAP_END;
	return 0;
}