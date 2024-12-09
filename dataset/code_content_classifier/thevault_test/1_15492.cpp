OGRErr OGRSpatialReference::importFromEPSG( int nCode )

{
    OGRErr  eErr;

    bNormInfoSet = FALSE;

/* -------------------------------------------------------------------- */
/*      Clear any existing definition.                                  */
/* -------------------------------------------------------------------- */
    if( GetRoot() != NULL )
    {
        delete poRoot;
        poRoot = NULL;
    }

/* -------------------------------------------------------------------- */
/*      Verify that we can find the required filename(s).               */
/* -------------------------------------------------------------------- */
    if( CSVScanFileByName( CSVFilename( "gcs.csv" ),
                           "COORD_REF_SYS_CODE", 
                           "4269", CC_Integer ) == NULL )
    {
        CPLError( CE_Failure, CPLE_OpenFailed, 
                  "Unable to open EPSG support file %s.\n"
                  "Try setting the GDAL_DATA environment variable to point to the\n"
                  "directory containing EPSG csv files.", 
                  CSVFilename( "gcs.csv" ) );
        return OGRERR_FAILURE;
    }

/* -------------------------------------------------------------------- */
/*      Is this a GeogCS code?   this is inadequate as a criteria       */
/* -------------------------------------------------------------------- */
    if( EPSGGetGCSInfo( nCode, NULL, NULL, NULL, NULL, NULL, NULL ) )
        eErr = SetEPSGGeogCS( this, nCode );
    else
        eErr = SetEPSGProjCS( this, nCode );

/* -------------------------------------------------------------------- */
/*      If we get it as an unsupported code, try looking it up in       */
/*      the epsg.wkt coordinate system dictionary.                      */
/* -------------------------------------------------------------------- */
    if( eErr == OGRERR_UNSUPPORTED_SRS )
    {
        char szCode[32];
        sprintf( szCode, "%d", nCode );
        eErr = importFromDict( "epsg.wkt", szCode );
    }

/* -------------------------------------------------------------------- */
/*      If we get it as an unsupported code, try looking it up in       */
/*      the PROJ.4 support file(s).                                     */
/* -------------------------------------------------------------------- */
    static int bLoopingToProj4 = FALSE;

    if( eErr == OGRERR_UNSUPPORTED_SRS && !bLoopingToProj4 )
    {
        char szWrkDefn[100];

        sprintf( szWrkDefn, "+init=epsg:%d", nCode );
        bLoopingToProj4 = TRUE;
        CPLPushErrorHandler( CPLQuietErrorHandler );
        eErr = SetFromUserInput( szWrkDefn );
        CPLPopErrorHandler();
        bLoopingToProj4 = FALSE;

        if( eErr != OGRERR_NONE )
            eErr = OGRERR_UNSUPPORTED_SRS;
        else
        {
            if( IsProjected() )
                SetAuthority( "PROJCS", "EPSG", nCode );
            else if( IsGeographic() )
                SetAuthority( "GEOGCS", "EPSG", nCode );
        }
    }

    if( eErr == OGRERR_UNSUPPORTED_SRS )
    {
        CPLError( CE_Failure, CPLE_NotSupported,
                  "EPSG PCS/GCS code %d not found in EPSG support files.  Is this a valid\nEPSG coordinate system?", 
                  nCode );
    }

/* -------------------------------------------------------------------- */
/*      Make sure any peculiarities in the ordering are fixed up.       */
/* -------------------------------------------------------------------- */
    if( eErr == OGRERR_NONE )
        eErr = FixupOrdering();

    return eErr;
}