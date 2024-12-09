string AsString(const int64 &Value,const char *format)
{
    char temp[256];
    string ret;
    switch (format[1])
    {
        case 'd':
            sprintf(temp,"%lld",Value);
            ret=temp;
            break;
        case 'b':
            sprintf(temp,"%llb",Value);
            ret=temp;
            break;
        case 'X':
            sprintf(temp,"%llX",Value);
            ret=temp;
            break;
        case 'x':
            sprintf(temp,"%llx",Value);
            ret=temp;
            break;
    }
    return ret;
}