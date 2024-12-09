void processImage()
{
    // read data into source pbo. note: use BGRA format for optimal performance
    glBindBuffer(GL_PIXEL_PACK_BUFFER_ARB, pbo_source);
    glReadPixels(0, 0, image_width, image_height, GL_BGRA, GL_UNSIGNED_BYTE, NULL); 

    // run the Cuda kernel
    process(pbo_source, pbo_dest, image_width, image_height, blur_radius);

    // download texture from destination PBO
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, pbo_dest);
    glBindTexture(GL_TEXTURE_2D, tex_screen);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 
                    image_width, image_height, 
                    GL_BGRA, GL_UNSIGNED_BYTE, NULL);

    glBindBuffer(GL_PIXEL_PACK_BUFFER_ARB, 0);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    CUT_CHECK_ERROR_GL();
}