void generate_h0()
{
    for (unsigned int y = 0; y<fftInputH; y++) {
        for (unsigned int x = 0; x<fftInputW; x++) {
            float kx = CUDART_PI_F * x / (float) patchSize;
            float ky = 2.0f * CUDART_PI_F * y / (float) patchSize;

            // note - these random numbers should be from a Gaussian distribution really
            float Er = 2.0f * rand() / (float) RAND_MAX - 1.0f;
            float Ei = 2.0f * rand() / (float) RAND_MAX - 1.0f;

            float P = sqrt(phillips(kx, ky, windDir, windSpeed, A));  

            float h0_re = 1.0f / sqrtf(2.0f) * Er * P;
            float h0_im = 1.0f / sqrtf(2.0f) * Ei * P;

            int i = y*fftInputW+x;
            h_h0[i].x = h0_re;
            h_h0[i].y = h0_im;
        }
    }
}