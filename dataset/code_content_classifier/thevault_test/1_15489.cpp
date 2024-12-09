static int
EPSGGetGCSInfo( int nGCSCode, char ** ppszName,
                int * pnDatum, char **ppszDatumName,
                int * pnPM, int *pnEllipsoid, int *pnUOMAngle )

{
    char        szSearchKey[24];
    int         nDatum, nPM, nUOMAngle, nEllipsoid;
    const char  *pszFilename = CSVFilename("gcs.csv");


/* -------------------------------------------------------------------- */
/*      Search the database for the corresponding datum code.           */
/* -------------------------------------------------------------------- */
    sprintf( szSearchKey, "%d", nGCSCode );

    nDatum = atoi(CSVGetField( pszFilename, "COORD_REF_SYS_CODE", 
                               szSearchKey, CC_Integer,
                               "DATUM_CODE" ) );

    if( nDatum < 1 )
        return FALSE;

    if( pnDatum != NULL )
        *pnDatum = nDatum;
    
/* -------------------------------------------------------------------- */
/*      Get the PM.                                                     */
/* -------------------------------------------------------------------- */
    nPM = atoi(CSVGetField( pszFilename, "COORD_REF_SYS_CODE", 
                            szSearchKey, CC_Integer,
                            "PRIME_MERIDIAN_CODE" ) );

    if( nPM < 1 )
        return FALSE;

    if( pnPM != NULL )
        *pnPM = nPM;

/* -------------------------------------------------------------------- */
/*      Get the Ellipsoid.                                              */
/* -------------------------------------------------------------------- */
    nEllipsoid = atoi(CSVGetField( pszFilename, "COORD_REF_SYS_CODE", 
                                   szSearchKey, CC_Integer,
                                   "ELLIPSOID_CODE" ) );

    if( nEllipsoid < 1 )
        return FALSE;

    if( pnEllipsoid != NULL )
        *pnEllipsoid = nEllipsoid;

/* -------------------------------------------------------------------- */
/*      Get the angular units.                                          */
/* -------------------------------------------------------------------- */
    nUOMAngle = atoi(CSVGetField( pszFilename, "COORD_REF_SYS_CODE", 
                                  szSearchKey, CC_Integer,
                                  "UOM_CODE" ) );

    if( nUOMAngle < 1 )
        return FALSE;

    if( pnUOMAngle != NULL )
        *pnUOMAngle = nUOMAngle;

/* -------------------------------------------------------------------- */
/*      Get the name, if requested.                                     */
/* -------------------------------------------------------------------- */
    if( ppszName != NULL )
        *ppszName =
            CPLStrdup(CSVGetField( pszFilename, "COORD_REF_SYS_CODE", 
                                   szSearchKey, CC_Integer,
                                   "COORD_REF_SYS_NAME" ));
    
/* -------------------------------------------------------------------- */
/*      Get the datum name, if requested.                               */
/* -------------------------------------------------------------------- */
    if( ppszDatumName != NULL )
        *ppszDatumName =
            CPLStrdup(CSVGetField( pszFilename, "COORD_REF_SYS_CODE", 
                                   szSearchKey, CC_Integer,
                                   "DATUM_NAME" ));
    
    return( TRUE );
}