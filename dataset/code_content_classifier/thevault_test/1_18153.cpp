int
changeToUser( uid_t uid ) {
    int prev_errno, my_errno;

    if ( !isServiceUserSet() ) {
        /* not configured ... just return */
        return 0;
    }

#ifndef windows_platform
    prev_errno = errno;
    if ( geteuid() != 0 ) {
        changeToRootUser();
    }
    if ( seteuid( uid ) == -1 ) {
        my_errno = errno;
        errno = prev_errno;
        rodsLogError( LOG_ERROR, SYS_USER_NO_PERMISSION - my_errno,
                      "changeToUser: can't change to user id %d",
                      uid );
        return SYS_USER_NO_PERMISSION - my_errno;
    }
    errno = prev_errno;
#endif

    return 0;
}