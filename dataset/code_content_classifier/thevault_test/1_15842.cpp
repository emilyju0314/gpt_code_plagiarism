NSSuper::NSSuper(short sStatus)
{
    try
    {
        _statut              = sStatus;

        _sNumVersion         = std::string("0.00.0002");

        _pDico               = (NSDico *) 0;
        _pFilGuide           = (NSFilGuide *) 0;
        _pFilDecode          = (NSFilGuide *) 0;

        _iTraceConsole       = trNone;
        _iTrace              = trWarning ;

        _ontologyManager     = (ontologyBaseManager*) 0;

        // _pLocalStrings       = new NSLocalChapterArray(NULL);

        loadLocalisationString("");

        _pClassifExpert      = (classifExpert *) 0;

        // _aContextArray       = new NSContextArray;

        // _bVerboseErrorMessages = true;

        _bToDoLocked         = false;

        // m_hStdOut	= (HANDLE) 0;
    }
    catch (...)
    {
        error("Exception NSSuper ctor.", standardError);
    }
}