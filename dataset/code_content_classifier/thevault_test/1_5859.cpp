bool
gpdb::InterpretOidsOption
	(
	List *options,
	bool allowOids
	)
{
	GP_WRAP_START;
	{
		return interpretOidsOption(options, allowOids);
	}
	GP_WRAP_END;
	return false;
}