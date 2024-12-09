void ArgsTest::testBitMask()
{
    ts::ReportBuffer<> log;
    TestArgs args(&log);

    TSUNIT_ASSERT(args.analyze(u"test", USV({u"a"})));
    TSUNIT_EQUAL(0x10, args.bitMaskValue<int>(u"mask", 0x10));

    TSUNIT_ASSERT(args.analyze(u"test", {u"--mask", u"bit1", u"a"}));
    TSUNIT_EQUAL(0x01, args.bitMaskValue<int>(u"mask", 0x10));

    TSUNIT_ASSERT(args.analyze(u"test", {u"--mask", u"bit2", u"--mask", u"bit3", u"a"}));
    TSUNIT_EQUAL(0x06, args.bitMaskValue<int>(u"mask", 0x10));
}