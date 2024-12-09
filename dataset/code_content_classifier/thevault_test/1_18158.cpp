int
phyPathRegNoChkPerm( rsComm_t *rsComm, dataObjInp_t *phyPathRegInp ) {
    int status;

    addKeyVal( &phyPathRegInp->condInput, NO_CHK_FILE_PERM_KW, "" );

    status = irsPhyPathReg( rsComm, phyPathRegInp );
    return status;
}