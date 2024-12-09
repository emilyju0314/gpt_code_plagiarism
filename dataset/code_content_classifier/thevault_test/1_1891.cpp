void
CFrameBufferObject::attachTexture( GLenum texTarget, GLuint texId, 
                                   GLenum attachment, int mipLevel, int zSlice )
{
    bindRenderPath();
    switch (texTarget) {
        case GL_TEXTURE_1D:
            glFramebufferTexture1DEXT( GL_FRAMEBUFFER_EXT, attachment,
                                       GL_TEXTURE_1D, texId, mipLevel );
            break;
        case GL_TEXTURE_3D:
            glFramebufferTexture3DEXT( GL_FRAMEBUFFER_EXT, attachment,
                                       GL_TEXTURE_3D, texId, mipLevel, zSlice );
           break;
        default:
            // Default is GL_TEXTURE_2D, GL_TEXTURE_RECTANGLE_ARB, or cube faces
            glFramebufferTexture2DEXT( GL_FRAMEBUFFER_EXT, attachment,
                                       texTarget, texId, mipLevel );
            break;
    }
    unbindRenderPath();
}