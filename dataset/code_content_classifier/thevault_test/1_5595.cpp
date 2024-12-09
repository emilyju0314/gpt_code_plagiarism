PictImage* NewPictImage( VidStream* vid_stream, int w, int h )
{
    PictImage* pi;

    /* Allocate memory space for pi structure. */

    pi = (PictImage *) malloc(sizeof(PictImage));

    /* Create a YV12 image (Y + V + U) */
    pi->image = (unsigned char *) malloc(w*h*12/8);
    pi->luminance = (unsigned char *)pi->image;
    pi->Cr = pi->luminance + (w*h);
    pi->Cb = pi->luminance + (w*h) + (w*h)/4;
  
    /* Alloc space for filter info */
    pi->mb_qscale = (unsigned short int *) malloc(vid_stream->mb_width * vid_stream->mb_height * sizeof(unsigned int));

    /* Reset locked flag. */
  
    pi->locked = 0;

    /* Return pointer to pi structure. */

    return pi;
}