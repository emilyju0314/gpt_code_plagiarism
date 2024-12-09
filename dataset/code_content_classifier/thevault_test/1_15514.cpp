TABFeature *TABFile::GetFeatureRef(int nFeatureId)
{
    CPLErrorReset();

    if (m_eAccessMode != TABRead)
    {
        CPLError(CE_Failure, CPLE_NotSupported,
                 "GetFeatureRef() can be used only with Read access.");
        return NULL;
    }

    /*-----------------------------------------------------------------
     * Make sure file is opened and Validate feature id by positioning
     * the read pointers for the .MAP and .DAT files to this feature id.
     *----------------------------------------------------------------*/
    if (m_poMAPFile == NULL)
    {
        CPLError(CE_Failure, CPLE_IllegalArg,
                 "GetFeatureRef() failed: file is not opened!");
        return NULL;
    }


    if (nFeatureId <= 0 || nFeatureId > m_nLastFeatureId ||
        m_poMAPFile->MoveToObjId(nFeatureId) != 0 ||
        m_poDATFile->GetRecordBlock(nFeatureId) == NULL )
    {
        //     CPLError(CE_Failure, CPLE_IllegalArg,
        //    "GetFeatureRef() failed: invalid feature id %d", 
        //    nFeatureId);
        return NULL;
    }
    
    /*-----------------------------------------------------------------
     * Flush current feature object
     * __TODO__ try to reuse if it is already of the right type
     *----------------------------------------------------------------*/
    if (m_poCurFeature)
    {
        delete m_poCurFeature;
        m_poCurFeature = NULL;
    }

    /*-----------------------------------------------------------------
     * Create new feature object of the right type
     * Unsupported object types are returned as raw TABFeature (i.e. NONE
     * geometry)
     *----------------------------------------------------------------*/
    m_poCurFeature = TABFeature::CreateFromMapInfoType(m_poMAPFile->GetCurObjType(), 
                                                       m_poDefn);

    /*-----------------------------------------------------------------
     * Read fields from the .DAT file
     * GetRecordBlock() has already been called above...
     *----------------------------------------------------------------*/
    if (m_poCurFeature->ReadRecordFromDATFile(m_poDATFile) != 0)
    {
        delete m_poCurFeature;
        m_poCurFeature = NULL;
        return NULL;
    }

    /*-----------------------------------------------------------------
     * Read geometry from the .MAP file
     * MoveToObjId() has already been called above...
     *----------------------------------------------------------------*/
    TABMAPObjHdr *poObjHdr = 
        TABMAPObjHdr::NewObj(m_poMAPFile->GetCurObjType(), 
                             m_poMAPFile->GetCurObjId());
    // Note that poObjHdr==NULL is a valid case if geometry type is NONE

    if ((poObjHdr && poObjHdr->ReadObj(m_poMAPFile->GetCurObjBlock()) != 0) ||
        m_poCurFeature->ReadGeometryFromMAPFile(m_poMAPFile, poObjHdr) != 0)
    {
        delete m_poCurFeature;
        m_poCurFeature = NULL;
        if (poObjHdr) 
            delete poObjHdr;
        return NULL;
    }
    if (poObjHdr)       // May be NULL if feature geometry type is NONE
        delete poObjHdr; 

    m_nCurFeatureId = nFeatureId;
    m_poCurFeature->SetFID(m_nCurFeatureId);

    m_poCurFeature->SetRecordDeleted(m_poDATFile->IsCurrentRecordDeleted());

    return m_poCurFeature;
}