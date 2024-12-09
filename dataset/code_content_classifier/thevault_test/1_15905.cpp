void LumaEncoder::setChannels(LumaFrame *frame)
{
    setVpxChannel(&m_rawFrame, frame->getChannel(0), 0);
	setVpxChannel(&m_rawFrame, frame->getChannel(1), 1);
	setVpxChannel(&m_rawFrame, frame->getChannel(2), 2);
}