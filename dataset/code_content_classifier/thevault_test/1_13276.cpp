void Transcode::preMainLoop()
{
    // Inits scheduler
    // starts processor thread
    m_scheduler.init();
    launcher::Module::preMainLoop();
}