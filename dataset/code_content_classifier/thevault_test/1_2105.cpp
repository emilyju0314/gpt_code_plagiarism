float *LoadImage32(const char *path, int reqsize, float *mean, unsigned int* bufSize)
{
    if (bufSize != NULL) 
    {
        *bufSize = 0;
    }
    int width, height, cp, i;
    unsigned char *img, *imgresized;
    float *imgfp32;

    img = stbi_load(path, &width, &height, &cp, 3);
    if(!img)
    {
        printf("The picture %s could not be loaded\n", path);
        return 0;
    }
    imgresized = (unsigned char*) malloc(3*reqsize*reqsize);
    if(!imgresized)
    {
        free(img);
        perror("malloc");
        return 0;
    }
    stbir_resize_uint8(img, width, height, 0, imgresized, reqsize, reqsize, 0, 3);
    free(img);
    unsigned int allocateSize = sizeof(*imgfp32) * reqsize * reqsize * 3;
    if (bufSize != NULL)
    {
        *bufSize = allocateSize;
    }
    imgfp32 = (float*) malloc(allocateSize);
    if(!imgfp32)
    {
        if (bufSize != NULL)
        {
            *bufSize = 0;
        }
        free(imgresized);
        perror("malloc");
        return 0;
    }
    for(i = 0; i < reqsize * reqsize * 3; i++)
    {
	    imgfp32[i] = imgresized[i];
    }
    free(imgresized);
    for(i = 0; i < reqsize*reqsize; i++)
    {
        // imgfp32 comes in RGB order but network expects to be in
        // BRG order so convert to BGR here while subtracting the mean.
        float blue, green, red;
        blue = imgfp32[3*i+2];
        green = imgfp32[3*i+1];
        red = imgfp32[3*i+0];

        imgfp32[3*i+0] = blue-mean[0];
        imgfp32[3*i+1] = green-mean[1]; 
        imgfp32[3*i+2] = red-mean[2];

        // uncomment to see what values are getting passed to mvncLoadTensor() before conversion to half float
        //printf("Blue: %f, Grean: %f,  Red: %f \n", imgfp32[3*i+0], imgfp32[3*i+1], imgfp32[3*i+2]);
    }
    return imgfp32;
}