void ArgsTest::testRanges()
{
    ts::Args args(u"description", u"syntax", ts::Args::NO_EXIT_ON_ERROR);
    args.option(u"opt1", 0, ts::Args::UINT8, 0, ts::Args::UNLIMITED_COUNT);
    args.option(u"opt2", 0, ts::Args::UINT8, 0, 3, 0, 100);
    args.option(u"opt3", 0, ts::Args::INTEGER, 0, ts::Args::UNLIMITED_COUNT, 0, ts::Args::UNLIMITED_VALUE, true);

    ts::ReportBuffer<> log;
    args.redirectReport(&log);

    TSUNIT_ASSERT(args.analyze(u"test", {u"--opt1", u"0", u"--opt1", u"1,0-0x00C", u"--opt1", u"4,7"}));
    TSUNIT_ASSERT(args.present(u"opt1"));
    TSUNIT_ASSERT(!args.present(u"opt2"));
    TSUNIT_ASSERT(!args.present(u"opt3"));
    TSUNIT_EQUAL(5, args.count(u"opt1"));
    TSUNIT_EQUAL(0,  args.intValue<int>(u"opt1", -1, 0));
    TSUNIT_EQUAL(10, args.intValue<int>(u"opt1", -1, 1));
    TSUNIT_EQUAL(11, args.intValue<int>(u"opt1", -1, 2));
    TSUNIT_EQUAL(12, args.intValue<int>(u"opt1", -1, 3));
    TSUNIT_EQUAL(47, args.intValue<int>(u"opt1", -1, 4));
    TSUNIT_EQUAL(-1, args.intValue<int>(u"opt1", -1, 5));

    TSUNIT_ASSERT(!args.analyze(u"test", {u"--opt2", u"1", u"--opt2", u"10-12"}));
    TSUNIT_EQUAL(u"Error: too many option --opt2, 3 maximum", log.getMessages());

    TSUNIT_ASSERT(args.analyze(u"test", {u"--opt2", u"1", u"--opt2", u"10-11"}));
    TSUNIT_EQUAL(3, args.count(u"opt2"));
    TSUNIT_EQUAL(1,  args.intValue<int>(u"opt2", -1, 0));
    TSUNIT_EQUAL(10, args.intValue<int>(u"opt2", -1, 1));
    TSUNIT_EQUAL(11, args.intValue<int>(u"opt2", -1, 2));
    TSUNIT_EQUAL(-1, args.intValue<int>(u"opt2", -1, 3));

    TSUNIT_ASSERT(args.analyze(u"test", {u"--opt3=100,000", u"--opt3", u"--opt3=9000-9,003"}));
    TSUNIT_EQUAL(6, args.count(u"opt3"));
    TSUNIT_EQUAL(100000, args.intValue<int>(u"opt3", -1, 0));
    TSUNIT_EQUAL(-1,   args.intValue<int>(u"opt3", -1, 1));
    TSUNIT_EQUAL(9000, args.intValue<int>(u"opt3", -1, 2));
    TSUNIT_EQUAL(9001, args.intValue<int>(u"opt3", -1, 3));
    TSUNIT_EQUAL(9002, args.intValue<int>(u"opt3", -1, 4));
    TSUNIT_EQUAL(9003, args.intValue<int>(u"opt3", -1, 5));
    TSUNIT_EQUAL(-1,   args.intValue<int>(u"opt3", -1, 6));
}