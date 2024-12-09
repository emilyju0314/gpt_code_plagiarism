unsigned
RRSimpleArbiter::pick_winner ()
{
    for ( uint i=last_winner+1; i<requested.size() ; i++ )
        if ( requested[i] )
        {
            last_winner = i;
            return last_winner;
        }

    for ( uint i=0; i<=last_winner ; i++ )
        if ( requested[i] )
        {
            last_winner = i;
            return last_winner;
        }

    return no_channels;
}