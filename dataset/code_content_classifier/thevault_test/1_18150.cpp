int
initServiceUser() {
#ifndef windows_platform
    char *serviceUser;
    struct passwd *pwent;

    serviceUser = getenv( "irodsServiceUser" );
    if ( serviceUser == NULL || getuid() != 0 ) {
        /* either the option is not set, or not running     */
        /* with the necessary root permission. Just return. */
        return 0;
    }

    /* clear errno before getpwnam to distinguish an error from user */
    /* not existing. pwent == NULL && errno == 0 means no entry      */
    errno = 0;
    pwent = getpwnam( serviceUser );
    if ( pwent ) {
        ServiceUid = pwent->pw_uid;
        ServiceGid = pwent->pw_gid;
        return changeToServiceUser();
    }

    if ( errno ) {
        rodsLogError( LOG_ERROR, SYS_USER_RETRIEVE_ERR,
                      "setServiceUser: error in getpwnam %s, errno = %d",
                      serviceUser, errno );
        return SYS_USER_RETRIEVE_ERR - errno;
    }
    else {
        rodsLogError( LOG_ERROR, SYS_USER_RETRIEVE_ERR,
                      "setServiceUser: user %s doesn't exist", serviceUser );
        return SYS_USER_RETRIEVE_ERR;
    }
#else
    return 0;
#endif
}