void Streamer::preMainLoop()
{
    launcher::Module::preMainLoop();
    getHTTPFactory()->init();
}