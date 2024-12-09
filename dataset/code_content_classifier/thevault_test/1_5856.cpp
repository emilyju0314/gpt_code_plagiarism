List *
gpdb::GetIndexOpFamilies
	(
	Oid index_oid
	)
{
	GP_WRAP_START;
	{
		/* catalog tables: pg_index */

		// We return the operator families of the index keys.
		return get_index_opfamilies(index_oid);
	}
	GP_WRAP_END;
	
	return NIL;
}