void toLowerCase (char *kwd)
{
    int i;
    for ( i=0 ; i < strlen(kwd) ; i++ )
        if ( (kwd[i] >= 'A') && (kwd[i] <= 'Z') )
            kwd[i] += 'a' - 'A';
}