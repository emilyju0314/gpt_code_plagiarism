BOOL Module::MightContainMatchingProperty(mdProperty tkProperty, ULONG nameHash)
{
    CONTRACTL
    {
        NOTHROW;
        GC_NOTRIGGER;
        MODE_ANY;
    }