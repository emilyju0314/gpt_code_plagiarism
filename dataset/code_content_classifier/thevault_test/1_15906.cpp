void LumaEncoder::setVpxChannel(vpx_image_t *dest, const float *src, int plane)
{
    unsigned char *buf = dest->planes[plane];
    const int stride = dest->stride[plane];
    
    // Width and height depends on chroma sub sampling for the color channels
    const int w = (plane > 0 && dest->x_chroma_shift > 0) ?
                  (dest->d_w + 1) >> dest->x_chroma_shift : dest->d_w;
    const int h = (plane > 0 && dest->y_chroma_shift > 0) ? 
                  (dest->d_h + 1) >> dest->y_chroma_shift : dest->d_h;
    
    const int m = ((dest->fmt & VPX_IMG_FMT_HIGHBITDEPTH) ? 2 : 1);
    const int profile = m_params.profile;
    
    //fprintf(stderr, "--plane %d: %dx%d. stride = %d, bit depth = %dx8, profile = %d\n", plane, w, h, stride, m, profile);
    
    float avg = 0.0f;
    
    size_t ind1, ind2;
    float res;
    for (int y=0; y<h; y++)
    {
        for (int x=0; x<w; x++)
        {
            // Color sub sampling, as simple average
            if (plane && (profile == 2 || profile == 0))
            {
                    ind1 = 2*x+4*y*w;
                    ind2 = ind1 + 2*w; //2*x+(2*y+1)*2*w;
                    res = 0.25f*(src[ind1] + src[ind1+1] + src[ind2] + src[ind2+1]);
            }
            else
            {
                res = src[x+y*w];
                avg += res;
            }
            
            // Quantize the pixel
       		res = m_quant.quantize(res, plane);
            
            // For high bit depths, split pixel into separate bytes (big endian)
            if (profile > 1)
            {
                unsigned char bl = res/256;
                unsigned char bh = res - bl*256;
                buf[m*x+y*stride+1] = bl; //* ((unsigned char *)&val); //low byte
                buf[m*x+y*stride] = bh; //* ((unsigned char *)((&val)+1)); //high byte
            }
            else
                buf[m*x+y*stride] = res;
        }
    }
    
    // Warn if average luminace is < 1, which could imply uncalibrated input
    avg /= (w*h);
    if (!plane && avg <= 1.0f)
        fprintf(stderr, "\n\tWarning! Mean luminance is %f cd/m2. Is input calibrated to physical units? \n", avg);
}