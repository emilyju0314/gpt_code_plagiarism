static int
EPSGGetProjTRFInfo( int nPCS, int * pnProjMethod,
                    int *panParmIds, double * padfProjParms )

{
    int         nProjMethod, i;
    double      adfProjParms[7];
    char        szTRFCode[16];
    char       *pszFilename = CPLStrdup(CSVFilename( "pcs.csv" ));

/* -------------------------------------------------------------------- */
/*      Get the proj method.  If this fails to return a meaningful      */
/*      number, then the whole function fails.                          */
/* -------------------------------------------------------------------- */
    sprintf( szTRFCode, "%d", nPCS );
    nProjMethod =
        atoi( CSVGetField( pszFilename,
                           "COORD_REF_SYS_CODE", szTRFCode, CC_Integer,
                           "COORD_OP_METHOD_CODE" ) );
    if( nProjMethod == 0 )
    {
        CPLFree( pszFilename );
        return FALSE;
    }

/* -------------------------------------------------------------------- */
/*      Get the parameters for this projection.                         */
/* -------------------------------------------------------------------- */

    for( i = 0; i < 7; i++ )
    {
        char    szParamUOMID[32], szParamValueID[32], szParamCodeID[32];
        char    *pszValue;
        int     nUOM;
        
        sprintf( szParamCodeID, "PARAMETER_CODE_%d", i+1 );
        sprintf( szParamUOMID, "PARAMETER_UOM_%d", i+1 );
        sprintf( szParamValueID, "PARAMETER_VALUE_%d", i+1 );

        if( panParmIds != NULL )
            panParmIds[i] = 
                atoi(CSVGetField( pszFilename, "COORD_REF_SYS_CODE", szTRFCode,
                                  CC_Integer, szParamCodeID ));

        nUOM = atoi(CSVGetField( pszFilename, "COORD_REF_SYS_CODE", szTRFCode,
                                 CC_Integer, szParamUOMID ));
        pszValue = CPLStrdup(
            CSVGetField( pszFilename, "COORD_REF_SYS_CODE", szTRFCode,
                         CC_Integer, szParamValueID ));

        // there is a bug in the EPSG 6.2.2 database for PCS 2935 and 2936
        // such that they have foot units for the scale factor.  Avoid this.
        if( (panParmIds[i] == NatOriginScaleFactor 
             || panParmIds[i] == InitialLineScaleFactor
             || panParmIds[i] == PseudoStdParallelScaleFactor) 
            && nUOM < 9200 )
            nUOM = 9201;

        if( nUOM >= 9100 && nUOM < 9200 )
            adfProjParms[i] = EPSGAngleStringToDD( pszValue, nUOM );
        else if( nUOM > 9000 && nUOM < 9100 )
        {
            double dfInMeters;

            if( !EPSGGetUOMLengthInfo( nUOM, NULL, &dfInMeters ) )
                dfInMeters = 1.0;
            adfProjParms[i] = atof(pszValue) * dfInMeters;
        }
        else if( EQUAL(pszValue,"") ) /* null field */
        {
            adfProjParms[i] = 0.0;
        }
        else /* really we should consider looking up other scaling factors */
        {
            if( nUOM != 9201 )
                CPLDebug( "OGR", "Non-unity scale factor units!" );
            adfProjParms[i] = atof(pszValue);
        }

        CPLFree( pszValue );
    }

/* -------------------------------------------------------------------- */
/*      Transfer requested data into passed variables.                  */
/* -------------------------------------------------------------------- */
    if( pnProjMethod != NULL )
        *pnProjMethod = nProjMethod;

    if( padfProjParms != NULL )
    {
        for( i = 0; i < 7; i++ )
            padfProjParms[i] = adfProjParms[i];
    }

    CPLFree( pszFilename );

    return TRUE;
}