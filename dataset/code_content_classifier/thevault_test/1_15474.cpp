int MIFFile::SetFeature(TABFeature *poFeature, int nFeatureId /*=-1*/)
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
    if (m_poMIDFile == NULL)
    {
        CPLError(CE_Failure, CPLE_IllegalArg,
                 "SetFeature() failed: file is not opened!");
        return -1;
    }

    if (m_bHeaderWrote == FALSE)
    {
        /*-------------------------------------------------------------
         * OK, this is the first feature in the dataset... make sure the
         * .MID schema has been initialized.
         *------------------------------------------------------------*/
        if (m_poDefn == NULL)
            SetFeatureDefn(poFeature->GetDefnRef(), NULL);

         WriteMIFHeader();     
         nFeatureId = 1;
    }
    else
    {
        nFeatureId = ++ m_nWriteFeatureId;
    }


    /*-----------------------------------------------------------------
     * Write geometry to the .Mif file
     *----------------------------------------------------------------*/
    if (m_poMIFFile == NULL ||
        poFeature->WriteGeometryToMIFFile(m_poMIFFile) != 0)
    {
        CPLError(CE_Failure, CPLE_FileIO,
                 "Failed writing geometry for feature id %d in %s",
                 nFeatureId, m_pszFname);
        return -1;
    }

    if (m_poMIDFile == NULL ||
        poFeature->WriteRecordToMIDFile(m_poMIDFile) != 0 )
    {
        CPLError(CE_Failure, CPLE_FileIO,
                 "Failed writing attributes for feature id %d in %s",
                 nFeatureId, m_pszFname);
        return -1;
    }

   
    return nFeatureId; 
}