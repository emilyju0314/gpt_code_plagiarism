void ArgsTest::testOptionalValue()
{
    ts::ReportBuffer<> log;
    TestArgs args(&log);

    TSUNIT_ASSERT(args.analyze(u"test", {u"a", u"--opt8", u"2"}));
    TSUNIT_ASSERT(args.count(u"") == 2);
    TSUNIT_ASSERT(args.present(u"opt8"));
    TSUNIT_ASSERT(args.intValue<uint32_t>(u"opt8") == 0);

    TSUNIT_ASSERT(args.analyze(u"test", {u"a", u"--opt8=2"}));
    TSUNIT_ASSERT(args.count(u"") == 1);
    TSUNIT_ASSERT(args.present(u"opt8"));
    TSUNIT_ASSERT(args.intValue<uint32_t>(u"opt8") == 2);
}