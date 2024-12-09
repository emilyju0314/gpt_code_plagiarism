int
dropRootPrivilege() {
#ifndef windows_platform
    int prev_errno, my_errno;
    uid_t new_real_uid;

    if ( !isServiceUserSet() ) {
        /* not configured ... just return */
        return 0;
    }

    prev_errno = errno;

    new_real_uid = geteuid();
    if ( new_real_uid == 0 ) {
        /* will become the iRODS service user */
        new_real_uid = ServiceUid;
    }
    else {
        /* need to set effective uid to root
           for the call to setuid() */
        changeToRootUser();
    }

    if ( setuid( new_real_uid ) == -1 ) {
        my_errno = errno;
        errno = prev_errno;
        rodsLogError( LOG_ERROR, SYS_USER_NO_PERMISSION - my_errno,
                      "dropRootPrivilege: can't setuid() to uid %d",
                      new_real_uid );
        return SYS_USER_NO_PERMISSION - my_errno;
    }

    errno = prev_errno;
#endif

    return 0;
}