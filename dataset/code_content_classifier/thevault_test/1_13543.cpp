void TestStreamer::testFailures()
{
    test::printOut("\nDVB Streamer failure test ... ");

    test::printOut("\n\tPreparation ... ");
    // add two channels
    testFirst();
    // test failures base
    testFailuresBase();
    // do base test now
    testChannels();
}