int pattern_state_request_handler(const char *path, const char* types, lo_arg **argv, int argc, void *data, void *user_data)
{
    //lo_server_thread_add_method(st, "/pattern_state", "iiiifff", pattern_state_request_handler, NULL);
    //lo_server_thread_add_method(st, "/pattern_state", "iifffff", pattern_state_request_handler, NULL);
    //lo_server_thread_add_method(st, "/pattern_state", "ifff",    pattern_state_request_handler, NULL);
    
    int type = fmin(fmax((int)(argv[0]->i),0),2);

    //graycode
    if( type == 0 && strcmp("iiiifff",types) == 0 )
    {
        bool inv = ((argv[1]->i)==0)?false:true;
        int axis =  argv[2]->i;
        int bit  =  argv[3]->i;
        float r  =  argv[4]->f;
        float g  =  argv[5]->f;
        float b  =  argv[6]->f;
        state.cur_invert = inv;
        // if bit == -1 do not change
        if(bit!=-1)
            state.cur_bitindex = bit;
        // if axis == -1 do not change
        if(axis>=0)
            state.cur_axis = axis;
        state.cur_r = r;
        state.cur_g = g;
        state.cur_b = b;
        
        state.dirty_n = 1;
        state.cur_rendermode = type;
        return 0;
    } 

    //sinusoid
    if( type == 1 && strcmp("iiifffff",types) == 0 )
    {
        bool  inv   =(argv[1]->i)==0?false:true;
        int   axis  = argv[2]->i;
        float freq  = argv[3]->f;
        float phase = argv[4]->f;
        float r    =  argv[5]->f;
        float g    =  argv[6]->f;
        float b    =  argv[7]->f;
        state.cur_freq = freq;
        state.cur_phase = phase;
        state.cur_invert = inv;
        state.cur_r = r;
        state.cur_g = g;
        state.cur_b = b;
        state.dirty_n = 1;
        state.cur_rendermode = type;
        return 0;
    }
    
    //monochrome flat
    if( type == 2 && strcmp("iifff",types) == 0 )
    {
        bool  inv = (argv[1]->i)==0?false:true;
        float r   =  argv[2]->f;
        float g   =  argv[3]->f;
        float b   =  argv[4]->f;
        state.cur_invert = inv;
        state.cur_r = r;
        state.cur_g = g;
        state.cur_b = b;
        state.cur_rendermode = type;
        state.dirty_n = 1;
        return 0;
    }
    
   return 1; 
}