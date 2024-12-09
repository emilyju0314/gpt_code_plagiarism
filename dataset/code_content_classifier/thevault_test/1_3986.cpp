int display_info_request_handler(const char *path, const char *types, lo_arg ** argv,
                                 int argc, void *data, void *user_data)
{
    printf("*RECEIVED display_info_request* [@%0.3f]\n",curtime());
    
    return 1;
}