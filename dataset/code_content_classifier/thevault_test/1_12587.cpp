Flit*
GenericBuffer::pull (unsigned ch)
{
    assert(ch < buffers.size() );
    assert(buffers[ch].size() != 0);

    Flit* f = buffers[ch].front();
    buffers[ch].pop_front();
    return f;
}