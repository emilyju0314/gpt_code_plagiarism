int CEncoder::Encode(const short * pdata, int data_size)
{
    CAutoLock l(&m_lock);

    if (!pgf || !m_outFrameBuf || !pdata || data_size < 0 || (data_size & (sizeof(short) - 1)))
        return -1;

    // some data left in the buffer, shift to start
    if (m_outReadOffset > 0)
    {
        if (m_outOffset > m_outReadOffset)
            memmove(m_outFrameBuf, m_outFrameBuf + m_outReadOffset, m_outOffset - m_outReadOffset);

        m_outOffset -= m_outReadOffset;
    }

    m_outReadOffset = 0;



    m_bFinished = FALSE;

    int bytes_processed = 0;
    int const nch = lame_get_num_channels(pgf);

    while (1)
    {
        int nsamples = (data_size - bytes_processed) / (sizeof(short) * nch);

        if (nsamples <= 0)
            break;

        if (nsamples > 1152)
            nsamples = 1152;

        if (m_outOffset >= OUT_BUFFER_MAX)
            break;

        int out_bytes = 0;

        if (nch == 2)
            out_bytes = lame_encode_buffer_interleaved(
                                            pgf,
                                            (short *)(pdata + (bytes_processed / sizeof(short))),
                                            nsamples,
                                            m_outFrameBuf + m_outOffset,
                                            OUT_BUFFER_SIZE - m_outOffset);
        else
            out_bytes = lame_encode_buffer(
                                            pgf,
                                            pdata + (bytes_processed / sizeof(short)),
                                            pdata + (bytes_processed / sizeof(short)),
                                            nsamples,
                                            m_outFrameBuf + m_outOffset,
                                            OUT_BUFFER_SIZE - m_outOffset);

        if (out_bytes < 0)
            return -1;

        m_outOffset     += out_bytes;
        bytes_processed += nsamples * nch * sizeof(short);
    }

    return bytes_processed;
}