TTime TTime::BeginDST( unsigned year )
{
    if( year > 1986 )
        {
        TDate endMarch(31, 3, year);
        return BuildLocal( endMarch.Previous(SUNDAY)+7, 2 );
        }

    // Ah, remember those energy conscious years...???
    if( year==1974 )
        return BuildLocal( TDate(6,1,1974), 2 );
    if( year==1975 )
        return BuildLocal( TDate(23,2,1975), 2 );

    TDate endApril( 30, 4, year );
    return BuildLocal( endApril.Previous(SUNDAY), 2 );
}