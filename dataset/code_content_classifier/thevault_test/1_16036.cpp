bool LoaderSubsystemC418::IsLoaded()
{
//returns the vail of the photogate
#ifndef NOHW
    return m_photogate.Get();
#else
    return 0;
#endif
}