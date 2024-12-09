void ArgsTest::testTristate()
{
    ts::Args args(u"description", u"syntax", ts::Args::NO_EXIT_ON_ERROR | ts::Args::GATHER_PARAMETERS);
    args.option(u"opt1", 0, ts::Args::TRISTATE);
    args.option(u"opt2", 0, ts::Args::TRISTATE);
    args.option(u"opt3", 0, ts::Args::TRISTATE);
    args.option(u"opt4", 0, ts::Args::TRISTATE, 0, 1, -255, 256, true);
    args.option(u"opt5", 0, ts::Args::TRISTATE, 0, 1, -255, 256, true);
    args.option(u"opt6", 0, ts::Args::TRISTATE, 0, 1, -255, 256, true);
    args.option(u"opt7", 0, ts::Args::TRISTATE, 0, 1, -255, 256, true);
    args.option(u"opt8", 0, ts::Args::TRISTATE, 0, 1, -255, 256, true);

    TSUNIT_ASSERT(args.analyze(u"test", {u"--opt1", u"true", u"--opt2", u"no", u"--opt3", u"unknown", u"--opt4", u"--opt5=off", u"--opt6=yes", u"--opt7=maybe"}));

    TSUNIT_ASSERT(args.present(u"opt1"));
    TSUNIT_ASSERT(args.present(u"opt2"));
    TSUNIT_ASSERT(args.present(u"opt3"));
    TSUNIT_ASSERT(args.present(u"opt4"));
    TSUNIT_ASSERT(args.present(u"opt5"));
    TSUNIT_ASSERT(args.present(u"opt6"));
    TSUNIT_ASSERT(args.present(u"opt7"));
    TSUNIT_ASSERT(!args.present(u"opt8"));

    TSUNIT_EQUAL(ts::TRUE,  args.tristateValue(u"opt1"));
    TSUNIT_EQUAL(ts::FALSE, args.tristateValue(u"opt2"));
    TSUNIT_EQUAL(ts::MAYBE, args.tristateValue(u"opt3"));
    TSUNIT_EQUAL(ts::TRUE,  args.tristateValue(u"opt4"));
    TSUNIT_EQUAL(ts::FALSE, args.tristateValue(u"opt5"));
    TSUNIT_EQUAL(ts::TRUE,  args.tristateValue(u"opt6"));
    TSUNIT_EQUAL(ts::MAYBE, args.tristateValue(u"opt7"));
    TSUNIT_EQUAL(ts::MAYBE, args.tristateValue(u"opt8"));
}