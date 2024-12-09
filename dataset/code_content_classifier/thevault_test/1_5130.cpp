void ArgsTest::testThousandsSeparator()
{
    ts::ReportBuffer<> log;
    TestArgs args(&log);

    TSUNIT_ASSERT(args.analyze(u"test", {u"a", u"-5", u"2000", u"--opt5=3,000", u"-50x4,000", u"-5", u"80 000", u"-5", u"2,000 000"}));
    TSUNIT_EQUAL(5, args.count(u"opt5"));
    TSUNIT_EQUAL(2000, args.intValue<int>(u"opt5", 0, 0));
    TSUNIT_EQUAL(3000, args.intValue<int>(u"opt5", 0, 1));
    TSUNIT_EQUAL(0x4000, args.intValue<int>(u"opt5", 0, 2));
    TSUNIT_EQUAL(80000, args.intValue<int>(u"opt5", 0, 3));
    TSUNIT_EQUAL(2000000, args.intValue<int>(u"opt5", 0, 4));
}