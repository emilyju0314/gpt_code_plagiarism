void stripPrefixes (char *string )
{
    static char *prefixes[] = { "kilo", "micro", "milli", "intra", "ultra",
                                "mega", "nano", "pico", "pseudo", 0 };
    int i;
    for ( i=0 ; prefixes[i] != 0 ; i++ ) 
    {
        if ( strncmp(prefixes[i],string,strlen(prefixes[i])) == 0 ) 
        {
            int j;
            for ( j=0 ; j<strlen(string)-strlen(prefixes[i]) ; j++ )
                string[j] = string[j+strlen(prefixes[i])];
            string[j] = '\0';
            return;
        }
    }
}