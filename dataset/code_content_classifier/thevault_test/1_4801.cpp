int numLocations(GLenum type)
{
    switch (type)
    {
    case GL_FLOAT_MAT2:
    case GL_FLOAT_MAT2x3:
    case GL_FLOAT_MAT2x4:
        return 2;
    case GL_FLOAT_MAT3x2:
    case GL_FLOAT_MAT3:
    case GL_FLOAT_MAT3x4:
        return 3;
    case GL_FLOAT_MAT4x2:
    case GL_FLOAT_MAT4x3:
    case GL_FLOAT_MAT4:
        return 4;
    default:
        return 1;
    }
}