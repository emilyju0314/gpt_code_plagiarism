int iFuseFdReopen(iFuseFd_t *iFuseFd) {
    int status = 0;
    openedDataObjInp_t dataObjCloseInp;
    dataObjInp_t dataObjOpenInp;
    iFuseConn_t *iFuseConn = NULL;
    int fd;
    
    assert(iFuseFd != NULL);
    assert(iFuseFd->conn != NULL);
    assert(iFuseFd->fd > 0);

    pthread_rwlock_wrlock(&iFuseFd->lock);

    iFuseConn = iFuseFd->conn;
    iFuseConnLock(iFuseConn);

    bzero(&dataObjCloseInp, sizeof (openedDataObjInp_t));
    dataObjCloseInp.l1descInx = iFuseFd->fd;

    status = iFuseRodsClientDataObjClose(iFuseConn->conn, &dataObjCloseInp);
    iFuseConnUpdateLastActTime(iFuseConn, false);
    if (status < 0) {
        if (iFuseRodsClientReadMsgError(status)) {
            // reconnect and retry 
            if(iFuseConnReconnect(iFuseConn) < 0) {
                iFuseLibLogError(LOG_ERROR, status, "iFuseFdReopen: iFuseConnReconnect of %s (%d) error",
                    iFuseFd->iRodsPath, iFuseFd->fd);
            } else {
                status = iFuseRodsClientDataObjClose(iFuseConn->conn, &dataObjCloseInp);
                if (status < 0) {
                    iFuseLibLogError(LOG_ERROR, status, "iFuseFdReopen: close of %s (%d) error",
                        iFuseFd->iRodsPath, iFuseFd->fd);
                }
            }
        } else {
            iFuseLibLogError(LOG_ERROR, status, "iFuseFdReopen: close of %s (%d) error",
                iFuseFd->iRodsPath, iFuseFd->fd);
        }
    }
    
    if(status < 0) {
        iFuseConnUnlock(iFuseConn);
        pthread_rwlock_unlock(&iFuseFd->lock);
        return status;
    }
    
    iFuseFd->lastFilePointer = -1;

    bzero(&dataObjOpenInp, sizeof ( dataObjInp_t));
    dataObjOpenInp.openFlags = iFuseFd->openFlag;
    rstrcpy(dataObjOpenInp.objPath, iFuseFd->iRodsPath, MAX_NAME_LEN);

    assert(iFuseConn->conn != NULL);
    
    fd = iFuseRodsClientDataObjOpen(iFuseConn->conn, &dataObjOpenInp);
    iFuseConnUpdateLastActTime(iFuseConn, false);
    if (fd <= 0) {
        if (iFuseRodsClientReadMsgError(fd)) {
            // reconnect and retry 
            if(iFuseConnReconnect(iFuseConn) < 0) {
                iFuseLibLogError(LOG_ERROR, fd, "iFuseFdReopen: iFuseConnReconnect of %s error, status = %d",
                    iFuseFd->iRodsPath, fd);
                iFuseConnUnlock(iFuseConn);
                pthread_rwlock_unlock(&iFuseFd->lock);
                return -ENOENT;
            } else {
                fd = iFuseRodsClientDataObjOpen(iFuseConn->conn, &dataObjOpenInp);
                if (fd <= 0) {
                    iFuseLibLogError(LOG_ERROR, fd, "iFuseFdReopen: iFuseRodsClientDataObjOpen of %s error, status = %d",
                        iFuseFd->iRodsPath, fd);
                    iFuseConnUnlock(iFuseConn);
                    pthread_rwlock_unlock(&iFuseFd->lock);
                    return -ENOENT;
                }
            }
        } else {
            iFuseLibLogError(LOG_ERROR, fd, "iFuseFdReopen: iFuseRodsClientDataObjOpen of %s error, status = %d",
                iFuseFd->iRodsPath, fd);
            iFuseConnUnlock(iFuseConn);
            pthread_rwlock_unlock(&iFuseFd->lock);
            return -ENOENT;
        }
    }
    
    iFuseFd->fd = fd;
    
    iFuseConnUnlock(iFuseConn);
    
    pthread_rwlock_unlock(&iFuseFd->lock);
    return status;
}