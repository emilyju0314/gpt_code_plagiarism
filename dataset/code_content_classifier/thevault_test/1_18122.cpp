int specialQueryIx( int ix ) {
    if ( ix == 0 ) {
        return COL_QUOTA_USER_ID;
    }
    if ( ix == 1 ) {
        return COL_R_RESC_NAME;
    }
    if ( ix == 2 ) {
        return COL_QUOTA_LIMIT;
    }
    if ( ix == 3 ) {
        return COL_QUOTA_OVER;
    }
    if ( ix == 4 ) {
        return COL_QUOTA_RESC_ID;
    }
    return 0;
}