void ClientFlightLoopEnds () noexcept
{
    // Release the data access lock
    try { glockDataMain.unlock(); }
    catch(...) { /* ignore all errors */ }
}