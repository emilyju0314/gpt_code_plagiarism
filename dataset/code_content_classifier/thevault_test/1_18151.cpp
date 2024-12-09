int
changeToRootUser() {
    int prev_errno, my_errno;

    if ( !isServiceUserSet() ) {
        /* not configured ... just return */
        return 0;
    }

#ifndef windows_platform
    /* preserve the errno from before. We'll often be   */
    /* called after a "permission denied" type error,   */
    /* so we need to preserve this previous error state */
    prev_errno = errno;
    if ( seteuid( 0 ) == -1 ) {
        my_errno = errno;
        errno = prev_errno;
        rodsLogError( LOG_ERROR, SYS_USER_NO_PERMISSION - my_errno,
                      "changeToRootUser: can't change to root user id" );
        return SYS_USER_NO_PERMISSION - my_errno;
    }
#endif

    return 0;
}