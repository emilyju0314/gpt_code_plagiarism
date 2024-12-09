void *
gpdb::OptimizerAlloc
		(
			size_t size
		)
{
	GP_WRAP_START;
	{
		return Ext_OptimizerAlloc(size);
	}
	GP_WRAP_END;

	return NULL;
}