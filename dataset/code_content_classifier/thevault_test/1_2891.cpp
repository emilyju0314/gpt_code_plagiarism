TADDR LookupMapBase::GetValueFromCompressedMap(DWORD rid)
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