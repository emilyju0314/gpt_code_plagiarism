Flit*
GenericBuffer::peek (unsigned ch)
{
    assert(ch < buffers.size());
    assert(buffers[ch].size() <= buffer_size);

    Flit* f = 0;
    if(buffers[ch].size() > 0)
        f = buffers[ch].front();
    return f;
}