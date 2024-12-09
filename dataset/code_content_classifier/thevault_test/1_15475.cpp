int MIFFile::SetFeatureDefn(OGRFeatureDefn *poFeatureDefn,
                         TABFieldType *paeMapInfoNativeFieldTypes /* =NULL */)
{
    int numFields;
    int nStatus = 0;

    /*-----------------------------------------------------------------
     * Check that call happens at the right time in dataset's life.
     *----------------------------------------------------------------*/
    if ( m_eAccessMode == TABWrite && m_bHeaderWrote )
    {
        CPLError(CE_Failure, CPLE_AssertionFailed,
                 "SetFeatureDefn() must be called after opening a new "
                 "dataset, but before writing the first feature to it.");
        return -1;
    }

    /*-----------------------------------------------------------------
     * Delete current feature defn if there is already one.
     * AddFieldNative() will take care of creating a new one for us.
     *----------------------------------------------------------------*/
    if (m_poDefn && m_poDefn->Dereference() == 0)
        delete m_poDefn;
    m_poDefn = NULL;

    /*-----------------------------------------------------------------
     * Copy field information
     *----------------------------------------------------------------*/
    numFields = poFeatureDefn->GetFieldCount();

    for(int iField=0; iField<numFields; iField++)
    {
        TABFieldType eMapInfoType;
        OGRFieldDefn *poFieldDefn = poFeatureDefn->GetFieldDefn(iField);

        if (paeMapInfoNativeFieldTypes)
        {
            eMapInfoType = paeMapInfoNativeFieldTypes[iField];
        }
        else
        {
            /*---------------------------------------------------------
             * Map OGRFieldTypes to MapInfo native types
             *--------------------------------------------------------*/
            switch(poFieldDefn->GetType())
            {
              case OFTInteger:
                eMapInfoType = TABFInteger;
                break;
              case OFTReal:
                eMapInfoType = TABFFloat;
                break;
              case OFTString:
              default:
                eMapInfoType = TABFChar;
            }
        }

        nStatus = AddFieldNative(poFieldDefn->GetNameRef(), eMapInfoType,
                                 poFieldDefn->GetWidth(),
                                 poFieldDefn->GetPrecision(), FALSE, FALSE);
    }

    return nStatus;
}