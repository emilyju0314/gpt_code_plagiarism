VidStream* NewVidStream( unsigned int buffer_len )
{
    int i, j;
    VidStream* vs;
    static const unsigned char default_intra_matrix[64] =
    {
        8, 16, 19, 22, 26, 27, 29, 34,
        16, 16, 22, 24, 27, 29, 34, 37,
        19, 22, 26, 27, 29, 34, 34, 38,
        22, 22, 26, 27, 29, 34, 37, 40,
        22, 26, 27, 29, 32, 35, 40, 48,
        26, 27, 29, 32, 35, 40, 48, 58,
        26, 27, 29, 34, 38, 46, 56, 69,
        27, 29, 35, 38, 46, 56, 69, 83
    };

    /* Check for legal buffer length. */

    if( buffer_len < 4 )
        return NULL;

    /* Make buffer length multiple of 4. */

    buffer_len = (buffer_len + 3) >> 2;

    /* Allocate memory for vs structure. */

    vs = (VidStream *) malloc(sizeof(VidStream));
    memset( vs, 0, (sizeof *vs) );

    /* Initialize pointers to extension and user data. */

    vs->group.ext_data = vs->group.user_data =
    vs->picture.extra_info = vs->picture.user_data =
    vs->picture.ext_data = vs->slice.extra_info =
    vs->ext_data = vs->user_data = NULL;

    /* Copy default intra matrix. */

    for( i = 0; i < 8; i++ )
    {
        for( j = 0; j < 8; j++ )
        {
            vs->intra_quant_matrix[i][j] = default_intra_matrix[i * 8 + j];
        }
    }

    /* Initialize non intra quantization matrix. */

    for( i = 0; i < 8; i++ )
    {
        for( j = 0; j < 8; j++ )
        {
            vs->non_intra_quant_matrix[i][j] = 16;
        }
    }
    
    /* Initialize noise base matrix */
    for( i = 0; i < 8; i++ )
        for( j = 0; j < 8; j++ )
            vs->noise_base_matrix[i][j] = (short) vs->non_intra_quant_matrix[i][j];

    j_rev_dct((short *) vs->noise_base_matrix);

    for( i = 0; i < 8; i++ )
        for( j = 0; j < 8; j++ )
	  vs->noise_base_matrix[i][j] *= vs->noise_base_matrix[i][j];

    /* Initialize pointers to image spaces. */

    vs->current = vs->past = vs->future = NULL;
    for( i = 0; i < RING_BUF_SIZE; i++ )
    {
        vs->ring[i] = NULL;
    }

    /* Create buffer. */

    vs->buf_start = (unsigned int *) malloc(buffer_len * 4);

    /*
    * Set max_buf_length to one less than actual length to deal with messy
    * data without proper seq. end codes.
    */

    vs->max_buf_length = buffer_len - 1;

    /* Initialize fields that used to be global */
    vs->ditherFlags = NULL;
    vs->rate_deal = -1;

    /* Reset everything for start of display */
    ResetVidStream(vs);

    /* Return structure. */

    return vs;
}