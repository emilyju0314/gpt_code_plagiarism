void framebuffer_fill(bool value) {
    // Go through each byte in the buffer and set or unset it appropriately.
    for (int i=0; i<24; ++i) {
        if (value) {
            framebuffer[i] = 0xFF;
        }
        else {
            framebuffer[i] = 0x00;
        }
    }
}