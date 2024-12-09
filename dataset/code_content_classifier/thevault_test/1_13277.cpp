void Transcode::postMainLoop() throw()
{
    // stop the scheduler
    m_scheduler.stop();

    // base actions that should be done on exit
    launcher::Module::postMainLoop();
}