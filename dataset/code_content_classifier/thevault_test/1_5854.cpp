void
gpdb::GpdbEreportImpl
	(
	int xerrcode,
	int severitylevel,
	const char *xerrmsg,
	const char *xerrhint,
	const char *filename,
	int lineno,
	const char *funcname
	)
{
	GP_WRAP_START;
	{
		// We cannot use the ereport() macro here, because we want to pass on
		// the caller's filename and line number. This is essentially an
		// expanded version of ereport(). It will be caught by the
		// GP_WRAP_END, and propagated up as a C++ exception, to be
		// re-thrown as a Postgres error once we leave the C++ land.
		if (errstart(severitylevel, filename, lineno, funcname, TEXTDOMAIN))
			errfinish (errcode(xerrcode),
					   errmsg("%s", xerrmsg),
					   xerrhint ? errhint("%s", xerrhint) : 0);
	}
	GP_WRAP_END;
}