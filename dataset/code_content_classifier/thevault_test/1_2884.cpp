PTR_Module Module::GetPreferredZapModuleForFieldDesc(FieldDesc * pFD)
{
    CONTRACTL
    {
        NOTHROW;
        GC_NOTRIGGER;
        MODE_ANY;
    }