int pattern_status_request_handler(const char *path, const char *types, lo_arg ** argv,
                                   int argc, void *data, void *user_data)
{
    printf("*RECEIVED pattern_status_request* [@%0.3f]\n",curtime());
    int val    = argv[0]->i;
    
    return 1;
}