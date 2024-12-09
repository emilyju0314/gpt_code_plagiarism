int TABFile::ParseTABFileFirstPass(GBool bTestOpenNoError)
{
    int         iLine, numLines, numFields = 0;
    char        **papszTok=NULL;
    GBool       bInsideTableDef = FALSE, bFoundTableFields=FALSE;

    if (m_eAccessMode != TABRead)
    {
        CPLError(CE_Failure, CPLE_NotSupported,
                 "ParseTABFile() can be used only with Read access.");
        return -1;
    }

    numLines = CSLCount(m_papszTABFile);

    for(iLine=0; iLine<numLines; iLine++)
    {
        /*-------------------------------------------------------------
         * Tokenize the next .TAB line, and check first keyword
         *------------------------------------------------------------*/
        CSLDestroy(papszTok);
        papszTok = CSLTokenizeStringComplex(m_papszTABFile[iLine], " \t(),;",
                                            TRUE, FALSE);
        if (CSLCount(papszTok) < 2)
            continue;   // All interesting lines have at least 2 tokens

        if (EQUAL(papszTok[0], "!version"))
        {
            m_nVersion = atoi(papszTok[1]);
            if (m_nVersion == 100)
            {
                /* Version 100 files contain only the fields definition,
                 * so we set default values for the other params.
                 */
                bInsideTableDef = TRUE;
                CPLFree(m_pszCharset);
                m_pszCharset = CPLStrdup("Neutral");
                m_eTableType = TABTableNative;
            }

        }
        else if (EQUAL(papszTok[0], "!edit_version"))
        {
            /* Sometimes, V450 files have version 300 + edit_version 450
             * for us version and edit_version are the same 
             */
            m_nVersion = atoi(papszTok[1]);
        }
        else if (EQUAL(papszTok[0], "!charset"))
        {
            CPLFree(m_pszCharset);
            m_pszCharset = CPLStrdup(papszTok[1]);
        }
        else if (EQUAL(papszTok[0], "Definition") &&
                 EQUAL(papszTok[1], "Table") )
        {
            bInsideTableDef = TRUE;
        }
        else if (bInsideTableDef && !bFoundTableFields &&
                 (EQUAL(papszTok[0], "Type") || EQUAL(papszTok[0],"FORMAT:")) )
        {
            if (EQUAL(papszTok[1], "NATIVE") || EQUAL(papszTok[1], "LINKED"))
                m_eTableType = TABTableNative;
            else if (EQUAL(papszTok[1], "DBF"))
                m_eTableType = TABTableDBF;
            else
            {
                // Type=ACCESS, or other unsupported type... cannot open!
                if (!bTestOpenNoError)
                    CPLError(CE_Failure, CPLE_NotSupported,
                             "Unsupported table type '%s' in file %s.  "
                      "This type of .TAB file cannot be read by this library.",
                             papszTok[1], m_pszFname);
                CSLDestroy(papszTok);
                return -1;
            }
        }
        else if (bInsideTableDef && !bFoundTableFields &&
                 (EQUAL(papszTok[0],"Fields") || EQUAL(papszTok[0],"FIELDS:")))
        {
            /*---------------------------------------------------------
             * We found the list of table fields
             * Just remember number of fields... the field types will be
             * parsed inside ParseTABFileFields() later...
             *--------------------------------------------------------*/
            bFoundTableFields = TRUE;
            numFields = atoi(papszTok[1]);

            if (numFields < 1 || numFields>2048 || iLine+numFields >= numLines)
            {
                if (!bTestOpenNoError)
                    CPLError(CE_Failure, CPLE_FileIO,
                         "Invalid number of fields (%s) at line %d in file %s",
                             papszTok[1], iLine+1, m_pszFname);

                CSLDestroy(papszTok);
                return -1;
            }

            bInsideTableDef = FALSE;
        }/* end of fields section*/
        else
        {
            // Simply Ignore unrecognized lines
        }
    }

    CSLDestroy(papszTok);

    if (m_pszCharset == NULL)
        m_pszCharset = CPLStrdup("Neutral");

    if (numFields == 0)
    {
        if (!bTestOpenNoError)
            CPLError(CE_Failure, CPLE_NotSupported,
                     "%s contains no table field definition.  "
                     "This type of .TAB file cannot be read by this library.",
                     m_pszFname);
        return -1;
    }

    return 0;
}