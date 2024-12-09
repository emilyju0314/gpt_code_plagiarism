void clean (char *kwd)
{
    int i,j,last=strlen(kwd);
    for ( i=0 ; i < last ; i++ ) 
    {
        if ( isvalid(kwd[i]) != 0 ) 
        {
            for ( j = i ; j < last-1 ; j++ )
                kwd[j] = kwd[j+1];
            kwd[last-1] = '\0';
            last--;
            i--;
        }
    }
}