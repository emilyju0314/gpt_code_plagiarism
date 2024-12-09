int MIFFile::AddFieldNative(const char *pszName, TABFieldType eMapInfoType,
                            int nWidth /*=0*/, int nPrecision /*=0*/,
                            GBool bIndexed /*=FALSE*/, GBool bUnique/*=FALSE*/)
{
    OGRFieldDefn *poFieldDefn;
    char *pszCleanName = NULL;
    int nStatus = 0;

    /*-----------------------------------------------------------------
     * Check that call happens at the right time in dataset's life.
     *----------------------------------------------------------------*/
    if ( m_eAccessMode == TABWrite && m_bHeaderWrote )
    {
        CPLError(CE_Failure, CPLE_AssertionFailed,
                 "AddFieldNative() must be called after opening a new "
                 "dataset, but before writing the first feature to it.");
        return -1;
    }

    /*-----------------------------------------------------------------
     * Validate field width... must be <= 254
     *----------------------------------------------------------------*/
    if (nWidth > 254)
    {
        CPLError(CE_Warning, CPLE_IllegalArg,
                 "Invalid size (%d) for field '%s'.  "
                 "Size must be 254 or less.", nWidth, pszName);
        nWidth = 254;
    }

    /*-----------------------------------------------------------------
     * Map fields with width=0 (variable length in OGR) to a valid default
     *----------------------------------------------------------------*/
    if (eMapInfoType == TABFDecimal && nWidth == 0)
        nWidth=20;
    else if (nWidth == 0)
        nWidth=254; /* char fields */

    /*-----------------------------------------------------------------
     * Create new OGRFeatureDefn if not done yet...
     *----------------------------------------------------------------*/
    if (m_poDefn == NULL)
    {
        char *pszFeatureClassName = TABGetBasename(m_pszFname);
        m_poDefn = new OGRFeatureDefn(pszFeatureClassName);
        CPLFree(pszFeatureClassName);
        // Ref count defaults to 0... set it to 1
        m_poDefn->Reference();
    }

    /*-----------------------------------------------------------------
     * Make sure field name is valid... check for special chars, etc.
     * (pszCleanName will have to be freed.)
     *----------------------------------------------------------------*/
    pszCleanName = TABCleanFieldName(pszName);

    /*-----------------------------------------------------------------
     * Map MapInfo native types to OGR types
     *----------------------------------------------------------------*/
    poFieldDefn = NULL;

    switch(eMapInfoType)
    {
      case TABFChar:
        /*-------------------------------------------------
         * CHAR type
         *------------------------------------------------*/
        poFieldDefn = new OGRFieldDefn(pszCleanName, OFTString);
        poFieldDefn->SetWidth(nWidth);
        break;
      case TABFInteger:
        /*-------------------------------------------------
         * INTEGER type
         *------------------------------------------------*/
        poFieldDefn = new OGRFieldDefn(pszCleanName, OFTInteger);
        break;
      case TABFSmallInt:
        /*-------------------------------------------------
         * SMALLINT type
         *------------------------------------------------*/
        poFieldDefn = new OGRFieldDefn(pszCleanName, OFTInteger);
        break;
      case TABFDecimal:
        /*-------------------------------------------------
         * DECIMAL type
         *------------------------------------------------*/
        poFieldDefn = new OGRFieldDefn(pszCleanName, OFTReal);
        poFieldDefn->SetWidth(nWidth);
        poFieldDefn->SetPrecision(nPrecision);
        break;
      case TABFFloat:
        /*-------------------------------------------------
         * FLOAT type
         *------------------------------------------------*/
        poFieldDefn = new OGRFieldDefn(pszCleanName, OFTReal);
        break;
      case TABFDate:
        /*-------------------------------------------------
         * DATE type (V450, returned as a string: "DD/MM/YYYY" or "YYYYMMDD")
         *------------------------------------------------*/
        poFieldDefn = new OGRFieldDefn(pszCleanName, OFTString);
        poFieldDefn->SetWidth(10);
        m_nVersion = MAX(m_nVersion, 450);
        break;
      case TABFTime:
        /*-------------------------------------------------
         * TIME type (v900, returned as a string: "HH:MM:SS" or "HHMMSSmmm")
         *------------------------------------------------*/
        poFieldDefn = new OGRFieldDefn(pszCleanName, OFTString);
        poFieldDefn->SetWidth(9);
        m_nVersion = MAX(m_nVersion, 900);
        break;
      case TABFDateTime:
        /*-------------------------------------------------
         * DATETIME type (v900, returned as a string: "DD/MM/YYYY HH:MM:SS",
         * "YYYY/MM/DD HH:MM:SS" or "YYYYMMDDHHMMSSmmm")
         *------------------------------------------------*/
        poFieldDefn = new OGRFieldDefn(pszCleanName, OFTString);
        poFieldDefn->SetWidth(19);
        break;
        m_nVersion = MAX(m_nVersion, 900);
      case TABFLogical:
        /*-------------------------------------------------
         * LOGICAL type (value "T" or "F")
         *------------------------------------------------*/
        poFieldDefn = new OGRFieldDefn(pszCleanName, OFTString);
        poFieldDefn->SetWidth(1);
        break;
      default:
        CPLError(CE_Failure, CPLE_NotSupported,
                 "Unsupported type for field %s", pszName);
        return -1;
    }

    /*-----------------------------------------------------
     * Add the FieldDefn to the FeatureDefn 
     *----------------------------------------------------*/
    m_poDefn->AddFieldDefn(poFieldDefn);
    delete poFieldDefn;

    /*-----------------------------------------------------------------
     * Keep track of native field type
     *----------------------------------------------------------------*/
    m_paeFieldType = (TABFieldType *)CPLRealloc(m_paeFieldType,
                                                m_poDefn->GetFieldCount()*
                                                sizeof(TABFieldType));
    m_paeFieldType[m_poDefn->GetFieldCount()-1] = eMapInfoType;

    /*-----------------------------------------------------------------
     * Extend array of Indexed/Unique flags
     *----------------------------------------------------------------*/
    m_pabFieldIndexed = (GBool *)CPLRealloc(m_pabFieldIndexed,
                                            m_poDefn->GetFieldCount()*
                                            sizeof(GBool));
    m_pabFieldUnique  = (GBool *)CPLRealloc(m_pabFieldUnique,
                                            m_poDefn->GetFieldCount()*
                                            sizeof(GBool));
    m_pabFieldIndexed[m_poDefn->GetFieldCount()-1] = bIndexed;
    m_pabFieldUnique[m_poDefn->GetFieldCount()-1] = bUnique;

    CPLFree(pszCleanName);
    return nStatus;
}