void ArgsTest::testGatherParameters()
{
    ts::ReportBuffer<> log;
    ts::Args args(u"description", u"syntax", ts::Args::NO_EXIT_ON_ERROR | ts::Args::GATHER_PARAMETERS);
    args.redirectReport(&log);

    args.option(u"");
    args.option(u"opt1");
    args.option(u"opt2", 'o', ts::Args::UNSIGNED);

    TSUNIT_ASSERT(args.analyze(u"test", {u"--opt1", u"--opt2", u"11", u"12", u"--opt2", u"13"}));
    TSUNIT_ASSERT(args.valid());
    TSUNIT_ASSERT(args.count(u"opt1") == 1);
    TSUNIT_ASSERT(args.count(u"opt2") == 1);
    TSUNIT_ASSERT(args.count(u"") == 3);
    TSUNIT_ASSERT(args.intValue<int>(u"opt2") == 11);
    TSUNIT_EQUAL(u"12", args.value(u"", u"", 0));
    TSUNIT_EQUAL(u"--opt2", args.value(u"", u"", 1));
    TSUNIT_EQUAL(u"13", args.value(u"", u"", 2));

    TSUNIT_ASSERT(args.valid());
    args.invalidate();
    TSUNIT_ASSERT(!args.valid());
}