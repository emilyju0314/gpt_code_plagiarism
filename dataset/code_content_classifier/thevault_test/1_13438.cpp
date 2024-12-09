void Stream::freeStream(struct stream_s* stream)
{
    if (!stream)
        return; // nothing to do

    // free tmp data from output
    GList *ol = g_list_first(stream->output);
    while (ol)
    {
        struct output_s *output =
            static_cast<struct output_s*>(ol->data);
        KLKFREE(output->remoteaddr);
        KLKFREE(output->localaddr);
        KLKFREE(output);
        ol=g_list_next(ol);
    }
    g_list_free(stream->output);

    // free input
    GList *il = g_list_first(stream->input);
    while (il)
    {
        struct input_s *input =
            static_cast<struct input_s*>(il->data);
        KLKFREE(input);
        il=g_list_next(il);
    }
    g_list_free(stream->input);

    // free stream itself
    KLKFREE(stream);
}