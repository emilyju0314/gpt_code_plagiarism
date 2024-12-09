const char* GetGraphicsDriverTxt ()
{
    if (glob.UsingModernGraphicsDriver())
#if APL
        return "Metal";
#else
        return "Vulkan";
#endif
    else
        return "OpenGL";
}