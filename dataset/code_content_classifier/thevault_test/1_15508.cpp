int TABFile::Open(const char *pszFname, const char *pszAccess,
                  GBool bTestOpenNoError /*=FALSE*/ )
{
    char *pszTmpFname = NULL;
    int nFnameLen = 0;

    CPLErrorReset();
   
    if (m_poMAPFile)
    {
        CPLError(CE_Failure, CPLE_AssertionFailed,
                 "Open() failed: object already contains an open file");

        return -1;
    }

    /*-----------------------------------------------------------------
     * Validate access mode
     *----------------------------------------------------------------*/
    if (EQUALN(pszAccess, "r", 1))
    {
        m_eAccessMode = TABRead;
        pszAccess = "rb";
    }
    else if (EQUALN(pszAccess, "w", 1))
    {
        m_eAccessMode = TABWrite;
        pszAccess = "wb";
    }
    else
    {
        if (!bTestOpenNoError)
            CPLError(CE_Failure, CPLE_FileIO,
                 "Open() failed: access mode \"%s\" not supported", pszAccess);
        else
            CPLErrorReset();

        return -1;
    }

    /*-----------------------------------------------------------------
     * Make sure filename has a .TAB extension... 
     *----------------------------------------------------------------*/
    m_pszFname = CPLStrdup(pszFname);
    nFnameLen = strlen(m_pszFname);

    if (nFnameLen > 4 && (strcmp(m_pszFname+nFnameLen-4, ".TAB")==0 ||
                     strcmp(m_pszFname+nFnameLen-4, ".MAP")==0 ||
                     strcmp(m_pszFname+nFnameLen-4, ".DAT")==0 ) )
        strcpy(m_pszFname+nFnameLen-4, ".TAB");
    else if (nFnameLen > 4 && (EQUAL(m_pszFname+nFnameLen-4, ".tab") ||
                               EQUAL(m_pszFname+nFnameLen-4, ".map") ||
                               EQUAL(m_pszFname+nFnameLen-4, ".dat") ) )
        strcpy(m_pszFname+nFnameLen-4, ".tab");
    else
    {
        if (!bTestOpenNoError)
            CPLError(CE_Failure, CPLE_FileIO,
                     "Open() failed for %s: invalid filename extension",
                     m_pszFname);
        else
            CPLErrorReset();

        CPLFree(m_pszFname);
        return -1;
    }

    pszTmpFname = CPLStrdup(m_pszFname);


#ifndef _WIN32
    /*-----------------------------------------------------------------
     * On Unix, make sure extension uses the right cases
     * We do it even for write access because if a file with the same
     * extension already exists we want to overwrite it.
     *----------------------------------------------------------------*/
    TABAdjustFilenameExtension(m_pszFname);
#endif

    /*-----------------------------------------------------------------
     * Handle .TAB file... depends on access mode.
     *----------------------------------------------------------------*/
    if (m_eAccessMode == TABRead)
    {
        /*-------------------------------------------------------------
         * Open .TAB file... since it's a small text file, we will just load
         * it as a stringlist in memory.
         *------------------------------------------------------------*/
        m_papszTABFile = TAB_CSLLoad(m_pszFname);
        if (m_papszTABFile == NULL)
        {
            if (!bTestOpenNoError)
            {
                CPLError(CE_Failure, CPLE_FileIO,
                         "Failed opening %s.", m_pszFname);
            }
            CPLFree(m_pszFname);
            m_pszFname = NULL;
            CSLDestroy(m_papszTABFile);
            m_papszTABFile = NULL;
            CPLFree( pszTmpFname );
            return -1;
        }

        /*-------------------------------------------------------------
         * Do a first pass on the TAB header to establish the type of 
         * dataset we have (NATIVE, DBF, etc.)... and also to know if
         * it is a supported type.
         *------------------------------------------------------------*/
        if ( ParseTABFileFirstPass(bTestOpenNoError) != 0 )
        {
            // No need to produce an error... it's already been done if 
            // necessary... just cleanup and exit.

            CPLFree(m_pszFname);
            m_pszFname = NULL;
            CSLDestroy(m_papszTABFile);
            m_papszTABFile = NULL;
            CPLFree( pszTmpFname );

            return -1;
        }
    }
    else
    {
        /*-------------------------------------------------------------
         * In Write access mode, the .TAB file will be written during the 
         * Close() call... we will just set some defaults here.
         *------------------------------------------------------------*/
        m_nVersion = 300;
        CPLFree(m_pszCharset);
        m_pszCharset = CPLStrdup("Neutral");
        m_eTableType = TABTableNative;

        /*-------------------------------------------------------------
         * Do initial setup of feature definition.
         *------------------------------------------------------------*/
        char *pszFeatureClassName = TABGetBasename(m_pszFname);
        m_poDefn = new OGRFeatureDefn(pszFeatureClassName);
        m_poDefn->Reference();
        CPLFree(pszFeatureClassName);
    }


    /*-----------------------------------------------------------------
     * Open .DAT file (or .DBF)
     *----------------------------------------------------------------*/
    if (nFnameLen > 4 && strcmp(pszTmpFname+nFnameLen-4, ".TAB")==0)
    {
        if (m_eTableType == TABTableDBF)
            strcpy(pszTmpFname+nFnameLen-4, ".DBF");
        else  // Default is NATIVE
            strcpy(pszTmpFname+nFnameLen-4, ".DAT");
    }
    else 
    {
        if (m_eTableType == TABTableDBF)
            strcpy(pszTmpFname+nFnameLen-4, ".dbf");
        else  // Default is NATIVE
            strcpy(pszTmpFname+nFnameLen-4, ".dat");
    }

#ifndef _WIN32
    TABAdjustFilenameExtension(pszTmpFname);
#endif

    m_poDATFile = new TABDATFile;
   
    if ( m_poDATFile->Open(pszTmpFname, pszAccess, m_eTableType) != 0)
    {
        // Open Failed... an error has already been reported, just return.
        CPLFree(pszTmpFname);
        Close();
        if (bTestOpenNoError)
            CPLErrorReset();

        return -1;
    }

    m_nLastFeatureId = m_poDATFile->GetNumRecords();


    /*-----------------------------------------------------------------
     * Parse .TAB file field defs and build FeatureDefn (only in read access)
     *----------------------------------------------------------------*/
    if (m_eAccessMode == TABRead && ParseTABFileFields() != 0)
    {
        // Failed... an error has already been reported, just return.
        CPLFree(pszTmpFname);
        Close();
        if (bTestOpenNoError)
            CPLErrorReset();

        return -1;
    }


    /*-----------------------------------------------------------------
     * Open .MAP (and .ID) file
     * Note that the .MAP and .ID files are optional.  Failure to open them
     * is not an error... it simply means that all features will be returned
     * with NONE geometry.
     *----------------------------------------------------------------*/
    if (nFnameLen > 4 && strcmp(pszTmpFname+nFnameLen-4, ".DAT")==0)
        strcpy(pszTmpFname+nFnameLen-4, ".MAP");
    else 
        strcpy(pszTmpFname+nFnameLen-4, ".map");

#ifndef _WIN32
    TABAdjustFilenameExtension(pszTmpFname);
#endif

    m_poMAPFile = new TABMAPFile;
    if (m_eAccessMode == TABRead)
    {
        /*-------------------------------------------------------------
         * Read access: .MAP/.ID are optional... try to open but return
         * no error if files do not exist.
         *------------------------------------------------------------*/
        if (m_poMAPFile->Open(pszTmpFname, pszAccess, TRUE) < 0)
        {
            // File exists, but Open Failed... 
            // we have to produce an error message
            if (!bTestOpenNoError)
                CPLError(CE_Failure, CPLE_FileIO, 
                         "Open() failed for %s", pszTmpFname);
            else
                CPLErrorReset();

            CPLFree(pszTmpFname);
            Close();
            return -1;
        }

        /*-------------------------------------------------------------
         * Set geometry type if the geometry objects are uniform.
         *------------------------------------------------------------*/
        int numPoints=0, numRegions=0, numTexts=0, numLines=0;

        GetFeatureCountByType( numPoints, numLines, numRegions, numTexts);

        numPoints += numTexts;
        if( numPoints > 0 && numLines == 0 && numRegions == 0 )
            m_poDefn->SetGeomType( wkbPoint );
        else if( numPoints == 0 && numLines > 0 && numRegions == 0 )
            m_poDefn->SetGeomType( wkbLineString );
        else
            /* we leave it unknown indicating a mixture */;
    }
    else if (m_poMAPFile->Open(pszTmpFname, pszAccess) != 0)
    {
        // Open Failed for write... 
        // an error has already been reported, just return.
        CPLFree(pszTmpFname);
        Close();
        if (bTestOpenNoError)
            CPLErrorReset();

        return -1;
    }


    CPLFree(pszTmpFname);
    pszTmpFname = NULL;

    /*-----------------------------------------------------------------
     * __TODO__ we could probably call GetSpatialRef() here to force
     * parsing the projection information... this would allow us to 
     * assignSpatialReference() on the geometries that we return.
     *----------------------------------------------------------------*/

    return 0;
}