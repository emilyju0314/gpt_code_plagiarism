Expr *
gpdb::EvaluateExpr
	(
	Expr *expr,
	Oid result_type,
	int32 typmod
	)
{
	GP_WRAP_START;
	{
		// GPDB_91_MERGE_FIXME: collation
		return evaluate_expr(expr, result_type, typmod, InvalidOid);
	}
	GP_WRAP_END;
	return NULL;
}