int
changeToServiceUser() {
    int prev_errno, my_errno;

    if ( !isServiceUserSet() ) {
        /* not configured ... just return */
        return 0;
    }

#ifndef windows_platform
    prev_errno = errno;

    if ( setegid( ServiceGid ) == -1 ) {
        /* if only setegid fails, log error but continue */
        rodsLog( LOG_ERROR, "changeToServiceUser: setegid() failed, errno = %d", errno );
        errno = prev_errno;
    }

    if ( seteuid( ServiceUid ) == -1 ) {
        my_errno = errno;
        errno = prev_errno;
        rodsLogError( LOG_ERROR, SYS_USER_NO_PERMISSION - my_errno,
                      "changeToServiceUser: can't change to service user id" );
        return SYS_USER_NO_PERMISSION - my_errno;
    }
#endif

    return 0;
}