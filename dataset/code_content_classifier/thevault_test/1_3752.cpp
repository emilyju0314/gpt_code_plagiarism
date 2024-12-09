double CSystem::GetFreeDiskSpace(const char *path)
{
	struct statfs64 buf;
	int ret = statfs64( path, &buf );
	if ( ret < 0 )
		return 0.0;
	return (double) ( buf.f_bsize * buf.f_bfree );
}