bool containsVowel ( char *word )
{
    register int i;
    for ( i=0 ; i < strlen(word) ; i++ )
        if ( i > 0 ) 
        {
            if ( vowel(word[i],word[i-1]) == true )
                return(true);
        }
        else 
        {
            if ( vowel(word[0],'a') == true )
                return(true);
        }
    return(false);
}