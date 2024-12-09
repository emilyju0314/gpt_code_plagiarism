TTime TTime::EndDST( unsigned year )
{
    TDate endOctober( 31, 10, year );
    return BuildLocal( endOctober.Previous(SUNDAY), 1 );
}