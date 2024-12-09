void TestMpegts::testFLV()
{
    klk::test::printOut( "\nTranscode test "
                         "(mpegts source, FLV destination) ... ");
    test(media::FLV);
}