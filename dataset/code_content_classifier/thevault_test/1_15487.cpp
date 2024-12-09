int EPSGGetWGS84Transform( int nGeogCS, double *padfTransform )

{
    int         nMethodCode, iDXField, iField;
    char        szCode[32];
    const char *pszFilename = CSVFilename("gcs.csv");

/* -------------------------------------------------------------------- */
/*      Fetch the line from the GCS table.                              */
/* -------------------------------------------------------------------- */
    char **papszLine;

    sprintf( szCode, "%d", nGeogCS );
    papszLine = CSVScanFileByName( pszFilename,
                                   "COORD_REF_SYS_CODE", 
                                   szCode, CC_Integer );
    if( papszLine == NULL )
        return FALSE;

/* -------------------------------------------------------------------- */
/*      Verify that the method code is one of our accepted ones.        */
/* -------------------------------------------------------------------- */
    nMethodCode = 
        atoi(CSLGetField( papszLine,
                          CSVGetFileFieldId(pszFilename,
                                            "COORD_OP_METHOD_CODE")));
    if( nMethodCode != 9603 && nMethodCode != 9607 && nMethodCode != 9606 )
        return FALSE;

/* -------------------------------------------------------------------- */
/*      Fetch the transformation parameters.                            */
/* -------------------------------------------------------------------- */
    iDXField = CSVGetFileFieldId(pszFilename, "DX");

    for( iField = 0; iField < 7; iField++ )
        padfTransform[iField] = atof(papszLine[iDXField+iField]);

/* -------------------------------------------------------------------- */
/*      9607 - coordinate frame rotation has reverse signs on the       */
/*      rotational coefficients.  Fix up now since we internal          */
/*      operate according to method 9606 (position vector 7-parameter). */
/* -------------------------------------------------------------------- */
    if( nMethodCode == 9607 )
    {
        padfTransform[3] *= -1;
        padfTransform[4] *= -1;
        padfTransform[5] *= -1;
    }
        
    return TRUE;
}