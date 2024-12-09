bool base64_decode_alloc (const char *in, size_t inlen, char **out, size_t *outlen)
{
  /* This may allocate a few bytes too much, depending on input,
     but it's not worth the extra CPU time to compute the exact amount.
     The exact amount is 3 * inlen / 4, minus 1 if the input ends
     with "=" and minus another 1 if the input ends with "==".
     Dividing before multiplying avoids the possibility of overflow.  */
    size_t needlen = 3 * (inlen / 4) + 2;

    *out = (char *)malloc (needlen);
    if (!*out)
        return true;

    if (!base64_decode (in, inlen, *out, &needlen))
    {
        free (*out);
        *out = NULL;
        return false;
    }

    if (outlen)
        *outlen = needlen;

    return true;
}