void ts::tsswitch::InputExecutor::getOutputArea(ts::TSPacket*& first, TSPacketMetadata*& data, size_t& count)
{
    GuardCondition lock(_mutex, _todo);
    first = &_buffer[_outFirst];
    data = &_metadata[_outFirst];
    count = std::min(_outCount, _buffer.size() - _outFirst);
    _outputInUse = count > 0;
    lock.signal();
}