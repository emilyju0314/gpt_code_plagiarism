bool base64_decode (const char *in, size_t inlen, char *out, size_t *outlen)
{
    size_t outleft = *outlen;

    while (inlen >= 2)
    {
        if (!isbase64 (in[0]) || !isbase64 (in[1]))
            break;

        if (outleft)
        {
            *out++ = (char)((b64[to_uchar (in[0])] << 2) | (b64[to_uchar (in[1])] >> 4));
            outleft--;
        }

        if (inlen == 2)
            break;

        if (in[2] == '=')
        {
            if (inlen != 4)
                break;

            if (in[3] != '=')
                break;
        }
        else
        {
            if (!isbase64 (in[2]))
	           break;

            if (outleft)
            {
                *out++ = (char)(((b64[to_uchar (in[1])] << 4) & 0xf0) | (b64[to_uchar (in[2])] >> 2));
                outleft--;
            }

            if (inlen == 3)
                break;

            if (in[3] == '=')
            {
                if (inlen != 4)
                    break;
            }
            else
            {
                if (!isbase64 (in[3]))
                    break;

                if (outleft)
                {
                    *out++ = (char)(((b64[to_uchar (in[2])] << 6) & 0xc0) | b64[to_uchar (in[3])]);
                    outleft--;
                }
            }
        }

        in += 4;
        inlen -= 4;
    }

    *outlen -= outleft;

    if (inlen != 0)
        return false;

    return true;
}