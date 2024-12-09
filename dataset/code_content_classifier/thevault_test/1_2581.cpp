CChangeSetBuilder::CChangeSetBuilder (
	FILE *inOutFile,
	CDataSourceTextFile &inSource,
	CDataSourceTextFile &inDest) :

	mOutFile (inOutFile), mSource (inSource), mDest (inDest)
{
	THROW_IF_NOT(mOutFile  &&  &mSource  &&  &mDest, XBadParameter);
}