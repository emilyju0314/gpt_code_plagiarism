CChangeSetProcessor::CChangeSetProcessor(
	FILE *inFile1,		// reference file
	FILE *inFile2,		// file to write to
	FILE *inSetFile		// instruction changeset file
) :
	mFile1(inFile1), mFile2(inFile2), mSetFile(inSetFile)
{
}