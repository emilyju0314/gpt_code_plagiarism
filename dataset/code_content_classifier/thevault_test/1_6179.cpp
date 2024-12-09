void real_fail_null( const void *eval, const char *eval_str, const char *func, const char *file, int line )
{
	if ( eval == NULL )
	{

		string exc;
		ostringstream sb;

		sb << file << ":" << line << ": In function \"" << func << "\": " << eval_str << " is NULL" << ends;
		exc = sb.str();
		throw exc;
	}
}