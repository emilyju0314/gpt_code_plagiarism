OGRErr OGRSpatialReference::SetStatePlane( int nZone, int bNAD83,
                                           const char *pszOverrideUnitName,
                                           double dfOverrideUnit )

{
    int         nAdjustedId;
    int         nPCSCode;
    char        szID[32];

/* -------------------------------------------------------------------- */
/*      Get the index id from stateplane.csv.                           */
/* -------------------------------------------------------------------- */
    if( bNAD83 )
        nAdjustedId = nZone;
    else
        nAdjustedId = nZone + 10000;

/* -------------------------------------------------------------------- */
/*      Turn this into a PCS code.  We assume there will only be one    */
/*      PCS corresponding to each Proj_ code since the proj code        */
/*      already effectively indicates NAD27 or NAD83.                   */
/* -------------------------------------------------------------------- */
    sprintf( szID, "%d", nAdjustedId );
    nPCSCode =
        atoi( CSVGetField( CSVFilename( "stateplane.csv" ),
                           "ID", szID, CC_Integer,
                           "EPSG_PCS_CODE" ) );
    if( nPCSCode < 1 )
    {
        char    szName[128];
        static int bFailureReported = FALSE;

        if( !bFailureReported )
        {
            bFailureReported = TRUE;
            CPLError( CE_Warning, CPLE_OpenFailed, 
                      "Unable to find state plane zone in stateplane.csv,\n"
                      "likely because the GDAL data files cannot be found.  Using\n"
                      "incomplete definition of state plane zone.\n" );
        }

        Clear();
        if( bNAD83 )
        {
            sprintf( szName, "State Plane Zone %d / NAD83", nZone );
            SetLocalCS( szName );
            SetLinearUnits( SRS_UL_METER, 1.0 );
        }
        else
        {
            sprintf( szName, "State Plane Zone %d / NAD27", nZone );
            SetLocalCS( szName );
            SetLinearUnits( SRS_UL_US_FOOT, atof(SRS_UL_US_FOOT_CONV) );
        }

        return OGRERR_FAILURE;
    }

/* -------------------------------------------------------------------- */
/*      Define based on a full EPSG definition of the zone.             */
/* -------------------------------------------------------------------- */
    OGRErr eErr = importFromEPSG( nPCSCode );

    if( eErr != OGRERR_NONE )
        return eErr;

/* -------------------------------------------------------------------- */
/*      Apply units override if required.                               */
/*                                                                      */
/*      We will need to adjust the linear projection parameter to       */
/*      match the provided units, and clear the authority code.         */
/* -------------------------------------------------------------------- */
    if( dfOverrideUnit != 0.0 
        && fabs(dfOverrideUnit - GetLinearUnits()) > 0.0000000001 )
    {
        double dfFalseEasting = GetNormProjParm( SRS_PP_FALSE_EASTING );
        double dfFalseNorthing= GetNormProjParm( SRS_PP_FALSE_NORTHING);
        OGR_SRSNode *poPROJCS;

        SetLinearUnits( pszOverrideUnitName, dfOverrideUnit );
        
        SetNormProjParm( SRS_PP_FALSE_EASTING, dfFalseEasting );
        SetNormProjParm( SRS_PP_FALSE_NORTHING, dfFalseNorthing );

        poPROJCS = GetAttrNode( "PROJCS" );
        if( poPROJCS != NULL && poPROJCS->FindChild( "AUTHORITY" ) != -1 )
        {
            poPROJCS->DestroyChild( poPROJCS->FindChild( "AUTHORITY" ) );
        }
    }

    return OGRERR_NONE;
}