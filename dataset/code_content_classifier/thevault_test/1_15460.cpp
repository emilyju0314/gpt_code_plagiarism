K2HUniqTimespec* K2HUniqTimespec::Get(void)
{
	static K2HUniqTimespec	uniqts;					// singleton
	return &uniqts;
}