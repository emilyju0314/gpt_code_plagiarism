void gen_rgb(SDL_Surface* in, float red, float grn, float blu)
{
    if( SDL_MUSTLOCK( in ) ) {
        SDL_LockSurface( in );
    }
    
    // CV_8UC3
    // automatically fill the matrix (expects preallocated)
    int w = in->w;
    int h = in->h;
    unsigned char *img_data = (unsigned char*)(in->pixels);
    for(int r=0; r<h; r++) {
        for(int c=0; c<w; c++) {
            /*
            Uint32 pixelPosition = r * (pitch / sizeof(unsigned int)) + c;
         if(false){
            Uint32 color = SDL_MapRGB(&pixelFormat,\
                    static_cast<Uint8>(fmin(fmax(255*blu,0),255)),\
                    static_cast<Uint8>(fmin(fmax(255*blu,0),255)),\
                    static_cast<Uint8>(fmin(fmax(255*blu,0),255)));
            
            pixels[pixelPosition] = color;
        }
        */
            int idx = (r*w+c)*4;
            img_data[idx]   = static_cast<unsigned char>(fmin(fmax(255*blu,0),255));
            img_data[idx+1] = static_cast<unsigned char>(fmin(fmax(255*grn,0),255));
            img_data[idx+2] = static_cast<unsigned char>(fmin(fmax(255*red,0),255));
            img_data[idx+3] = 255;
        }
    }
    if( SDL_MUSTLOCK( in ) ) {
        //Lock the surface
        SDL_UnlockSurface( in );
    }
    //SDL_UnlockTexture( in );
}