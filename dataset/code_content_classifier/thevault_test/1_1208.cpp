size_t base64_encode_alloc (const char *in, size_t inlen, char **out)
{
    size_t outlen = 1 + BASE64_LENGTH (inlen);

    /* Check for overflow in outlen computation.
    *
    * If there is no overflow, outlen >= inlen.
    *
    * If the operation (inlen + 2) overflows then it yields at most +1, so
    * outlen is 0.
    *
    * If the multiplication overflows, we lose at least half of the
    * correct value, so the result is < ((inlen + 2) / 3) * 2, which is
    * less than (inlen + 2) * 0.66667, which is less than inlen as soon as
    * (inlen > 4).
    */
    if (inlen > outlen)
    {
        *out = NULL;
        return 0;
    }

    *out = (char *)malloc (outlen);
    if (!*out)
        return outlen;

    base64_encode (in, inlen, *out, outlen);

    return outlen - 1;
}