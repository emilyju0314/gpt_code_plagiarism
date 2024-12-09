int generic_handler(const char *path, const char *types, lo_arg ** argv,
                    int argc, void *data, void *user_data)
{
    if( DBUG )
    {
        int i;
        
        printf("path: <%s>\n", path);
        for (i = 0; i < argc; i++) {
            printf("arg %d '%c' ", i, types[i]);
            lo_arg_pp((lo_type)types[i], argv[i]);
            printf("\n");
        }
        printf("\n");
        fflush(stdout);
    }
    
    return 1;
}