bool vowel ( char ch, char prev )
{
    switch ( ch ) 
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u': return(true);
        break;
    case 'y': return( vowel(prev,'?') == true );
        break;
    default : return(false);
        break;
    }
}