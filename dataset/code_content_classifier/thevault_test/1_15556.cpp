bool hasSuffix ( char *word, char *suffix, char *stem )
{
    char tmp[BIG_KEYWORDSIZE];
    if ( strlen(word) <= strlen(suffix) )
        return(false);
    if ( (strlen(suffix) > 1) &&
         ( word[strlen(word)-2] != suffix[strlen(suffix)-2] ) )
        return(false);
    strcpy ( stem, "" );
    strncat ( stem, word, strlen(word) - strlen(suffix) );
    strcpy ( tmp, stem );
    strcat ( tmp, suffix );
    if ( strcmp (  tmp, word ) == 0 )
        return(true);
    else
        return(false);
}