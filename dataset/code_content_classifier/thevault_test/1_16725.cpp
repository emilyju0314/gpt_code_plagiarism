double GetLineAngle ( DSCC_POINT Start, DSCC_POINT End )
{
    if ( End.x != Start.x )
    {
        double atg = atan ( ((double)(Start.y-End.y)) / ((double)(End.x-Start.x)) ) ;
        if ( End.x > Start.x )
            return atg ;
        else
        {
            if ( End.y < Start.y )
                return atg+PI ;
            else
                return atg-PI ;
        }
    }
    else
    {
        if ( End.y < Start.y )
            return PI/2 ;
        else if ( End.y > Start.y )
            return -PI/2 ;
        else
            return 0 ;
    }
}