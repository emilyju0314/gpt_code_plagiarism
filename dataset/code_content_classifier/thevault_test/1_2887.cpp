BOOL Module::IsVisibleToDebugger()
{
    WRAPPER_NO_CONTRACT; 
    SUPPORTS_DAC;

    if (IsResource())
    {
        return FALSE;
    }

    return TRUE;
}