int isvalid(char l)
{
    if ( (l >= 'a') && (l <= 'z') )
        return(0);
    if ( (l >= 'A') && (l <= 'Z') )
        return(0);
    if ( (l >= '0') && (l <= '9') )
        return(0);
    return(1);
}