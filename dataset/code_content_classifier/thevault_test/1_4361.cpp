int Mal::start_mal(bool quiet) {

    int timer=1, done = 0;
    char jcmd1[]="{\"action\":\"set_network_connection_mode\",\"args\":{\"mode\":0,\"ondemand_timeout\":2,\"manual_mode\":1}}";
    char jcmd2[]="{\"action\":\"set_wwan_allow_data_roaming\",\"args\":{\"enable\":1}}";

    if( !quiet ) printf( "\n");
    while( !done ) {
        if( send_mal_command(jcmd1, NULL, 0, false) < 0 ) {
            if( !quiet ) {
                printf( "Starting MAL interface. (%d)\r",timer++);
                fflush(stdout);
                }
            sleep(1);
            continue;
            }
        done = (send_mal_command(jcmd2, NULL, 0, false) == 0);
        }
    if( !quiet ) printf( "                                \r");
    return done;
}