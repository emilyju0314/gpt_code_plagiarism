INT32 LookupMapBase::GetNextCompressedEntry(BitStreamReader *pTableStream, INT32 iLastValue)
{
    CONTRACTL
    {
        INSTANCE_CHECK;
        NOTHROW;
        GC_NOTRIGGER;
        MODE_ANY;
        SUPPORTS_DAC;
        PRECONDITION(MapIsCompressed());
    }