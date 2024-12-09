void Streamer::postMainLoop() throw()
{
    if (m_httpfactory)
    {
        m_httpfactory->stop();
    }
    launcher::Module::postMainLoop();
}