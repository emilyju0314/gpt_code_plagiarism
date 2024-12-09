void list()
{
    for(const char *s(schemes); *s != '\0'; ++s)
    {
        if(*s == ',')
        {
            printf("\n");
        }
        else
        {
            printf("%c", *s);
        }
    }
    printf("\n");
    exit(1);
}