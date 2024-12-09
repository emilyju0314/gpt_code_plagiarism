void create_buffer(GLuint* buffer)
{
    glGenBuffersARB(1, buffer);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, *buffer);
    glBufferData(GL_PIXEL_PACK_BUFFER, MAXX*MAXY*4, NULL, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
}