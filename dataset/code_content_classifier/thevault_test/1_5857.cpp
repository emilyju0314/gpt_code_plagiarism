List *
gpdb::GetOpFamiliesForScOp
	(
	Oid opno
	)
{
	GP_WRAP_START;
	{
		/* catalog tables: pg_amop */

		// We return the operator families this operator
		// belongs to.
		return get_operator_opfamilies(opno);
	}
	GP_WRAP_END;
	
	return NIL;
}