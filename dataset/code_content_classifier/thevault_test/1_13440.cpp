struct stream_s* Stream::getStreamStruct(const u_int pnr)
{
    // find the stream at adapter structure by the program number
    GList *sl = g_list_first(m_adapter.streams);
    while(sl)
    {
        struct stream_s *stream = static_cast<struct stream_s*>(sl->data);
        if (stream)
        {
            if (stream->input)
            {
                // only one input here
                GList *il = g_list_first(stream->input);
                struct input_s *input =
                    static_cast<struct input_s*>(il->data);
                if (input->pnr.pnr == pnr)
                {
                    // found it
                    return stream;
                }
            }
        }
        sl=g_list_next(sl);
    }
    return NULL;
}