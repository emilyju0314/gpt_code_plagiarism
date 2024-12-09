int pattern_change_request_handler(const char *path, const char *types, lo_arg ** argv,
                                   int argc, void *data, void *user_data)
{
    //printf("*RECEIVED pattern_change_request* [@%0.3f]\n",curtime());
    //int axis     = argv[0]->i;
    //int index    = argv[1]->i;
    //int inverted = argv[2]->i;
    
    /* example showing pulling the argument values out of the argv array */
    int axis     = argv[0]->i;
    int bit      = argv[1]->i;
    bool inv     = (argv[2]->i)==0?false:true;
    float r      = argv[3]->f;
    float g      = argv[4]->f;
    float b      = argv[5]->f;
    state.cur_r = r;
    state.cur_g = g;
    state.cur_b = b;

    printf("[@%0.3f] *RECV pattern_change* ",curtime());
    printf("[axis:%d][idx:%d][inv:%c] [r,g,b=%0.2f,%0.2f,%0.2f]\n",
                axis, bit, inv?'T':'F', r,g,b);
    printf("%s <- i:%d i:%d i:%d\n\n", path, argv[0]->i, argv[1]->i, argv[2]->i);
    fflush(stdout);
    
    state.dirty_n = 1;
    
    // if bit == -1 do not change
    if(bit!=-1)
        state.cur_bitindex = bit;
    
    // if axis == -1 do not change
    if(axis!=-1)
        state.cur_axis = axis;
    
    state.cur_invert = inv;
    
    return 0;
}