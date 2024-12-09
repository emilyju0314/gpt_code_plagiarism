int TABFile::SetFeature(TABFeature *poFeature, int nFeatureId /*=-1*/)
{
    if (m_eAccessMode != TABWrite)
    {
        CPLError(CE_Failure, CPLE_NotSupported,
                 "SetFeature() can be used only with Write access.");
        return -1;
    }

    if (nFeatureId != -1)
    {
        CPLError(CE_Failure, CPLE_NotSupported,
                 "SetFeature(): random access not implemented yet.");
        return -1;
    }

    /*-----------------------------------------------------------------
     * Make sure file is opened and establish new feature id.
     *----------------------------------------------------------------*/
    if (m_poMAPFile == NULL)
    {
        CPLError(CE_Failure, CPLE_IllegalArg,
                 "SetFeature() failed: file is not opened!");
        return -1;
    }

    if (m_nLastFeatureId < 1)
    {
        /*-------------------------------------------------------------
         * OK, this is the first feature in the dataset... make sure the
         * .DAT schema has been initialized.
         *------------------------------------------------------------*/
        if (m_poDefn == NULL)
            SetFeatureDefn(poFeature->GetDefnRef(), NULL);

        /*-------------------------------------------------------------
         * Special hack to write out at least one field if none are in 
         * OGRFeatureDefn.
         *------------------------------------------------------------*/
        if( m_poDATFile->GetNumFields() == 0 )
        {
            CPLError(CE_Warning, CPLE_IllegalArg,
                     "MapInfo tables must contain at least 1 column, adding dummy FID column.");
            m_poDATFile->AddField("FID", TABFInteger, 10, 0 );
        }

        nFeatureId = m_nLastFeatureId = 1;
    }
    else
    {
        nFeatureId = ++ m_nLastFeatureId;
    }


    /*-----------------------------------------------------------------
     * Write fields to the .DAT file and update .IND if necessary
     *----------------------------------------------------------------*/
    if (m_poDATFile == NULL ||
        m_poDATFile->GetRecordBlock(nFeatureId) == NULL ||
        poFeature->WriteRecordToDATFile(m_poDATFile, m_poINDFile,
                                        m_panIndexNo) != 0 )
    {
        CPLError(CE_Failure, CPLE_FileIO,
                 "Failed writing attributes for feature id %d in %s",
                 nFeatureId, m_pszFname);
        return -1;
    }

    /*-----------------------------------------------------------------
     * Write geometry to the .MAP file
     * The call to PrepareNewObj() takes care of the .ID file.
     *----------------------------------------------------------------*/
    TABMAPObjHdr *poObjHdr = 
        TABMAPObjHdr::NewObj(poFeature->ValidateMapInfoType(m_poMAPFile),
                             nFeatureId);
    
    /*-----------------------------------------------------------------
     * ValidateMapInfoType() may have returned TAB_GEOM_NONE if feature
     * contained an invalid geometry for its class. Need to catch that
     * case and return the error.
     *----------------------------------------------------------------*/
    if (poObjHdr->m_nType == TAB_GEOM_NONE &&
        poFeature->GetFeatureClass() != TABFCNoGeomFeature )
    {
        CPLError(CE_Failure, CPLE_FileIO,
                 "Invalid geometry for feature id %d in %s",
                 nFeatureId, m_pszFname);
        return -1;
    }

    /*-----------------------------------------------------------------
     * The ValidateMapInfoType() call above has forced calculation of the
     * feature's IntMBR. Store that value in the ObjHdr for use by
     * PrepareNewObj() to search the best node to insert the feature.
     *----------------------------------------------------------------*/
    if ( poObjHdr && poObjHdr->m_nType != TAB_GEOM_NONE)
    {
        poFeature->GetIntMBR(poObjHdr->m_nMinX, poObjHdr->m_nMinY,
                             poObjHdr->m_nMaxX, poObjHdr->m_nMaxY);
    }

    if ( poObjHdr == NULL || m_poMAPFile == NULL ||
         m_poMAPFile->PrepareNewObj(poObjHdr) != 0 ||
         poFeature->WriteGeometryToMAPFile(m_poMAPFile, poObjHdr) != 0 ||
         m_poMAPFile->CommitNewObj(poObjHdr) != 0 )
    {
        CPLError(CE_Failure, CPLE_FileIO,
                 "Failed writing geometry for feature id %d in %s",
                 nFeatureId, m_pszFname);
        if (poObjHdr)
            delete poObjHdr;
        return -1;
    }

    delete poObjHdr;

    return nFeatureId;
}