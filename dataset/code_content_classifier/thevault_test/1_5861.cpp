bool
gpdb::IsAbortRequested
	(
	void
	)
{
	// No GP_WRAP_START/END needed here. We just check these global flags,
	// it cannot throw an ereport().
	return (QueryCancelPending || ProcDiePending);
}