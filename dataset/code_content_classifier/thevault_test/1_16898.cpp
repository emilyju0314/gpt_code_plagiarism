void MFIniLine::DumpRecursive(int depth)
{
	MFCALLSTACK;

	char prefix[256];
	int c;
	for(c=0; c<depth*2; c++)
	{
		prefix[c] = ' ';
	}
	prefix[c]=0;

	MFIniLine *pLine = this;

	char buffer[256];
	while(pLine)
	{
		MFString_Copy(buffer,prefix);
		for(int i=0; i<pLine->GetStringCount(); i++)
		{
			MFString_Cat(buffer, MFStr("'%s'",pLine->GetString(i)));
			MFString_Cat(buffer, "  ");
		}
		MFDebug_Message(buffer);
		if(pLine->Sub())
		{
			MFDebug_Message(MFStr("%s{",prefix));
			pLine->Sub()->DumpRecursive(depth+1);
			MFDebug_Message(MFStr("%s}",prefix));
		}
		pLine = pLine->Next();
	}
}