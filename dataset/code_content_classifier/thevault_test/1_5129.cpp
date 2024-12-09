void ArgsTest::testValidCommandContainer()
{
    ts::ReportBuffer<> log;
    TestArgs args(&log);

    ts::UStringVector arguments;
    arguments.push_back(u"--opt3");
    arguments.push_back(u"6");
    arguments.push_back(u"a");
    arguments.push_back(u"--opt1");
    arguments.push_back(u"b");
    arguments.push_back(u"--opt9");
    arguments.push_back(u"val2");
    arguments.push_back(u"--opt3");
    arguments.push_back(u"0");

    TSUNIT_ASSERT(args.analyze(u"test", arguments));

    TSUNIT_EQUAL(u"test", args.appName());
    TSUNIT_ASSERT(args.count(u"") == 2);
    TSUNIT_EQUAL(u"a", args.value(u"", u"", 0));
    TSUNIT_EQUAL(u"b", args.value(u"", u"", 1));
    TSUNIT_ASSERT(args.count(u"opt1") == 1);
    TSUNIT_ASSERT(args.present(u"opt1"));
    TSUNIT_ASSERT(args.count(u"opt2") == 0);
    TSUNIT_ASSERT(!args.present(u"opt2"));
    TSUNIT_ASSERT(args.count(u"opt3") == 2);
    TSUNIT_ASSERT(args.present(u"opt3"));
    TSUNIT_ASSERT(args.intValue<int>(u"opt3", -1, 0) == 6);
    TSUNIT_ASSERT(args.intValue<int>(u"opt3", -1, 1) == 0);
    TSUNIT_ASSERT(args.intValue<int>(u"opt3", -1, 2) == -1);
    TSUNIT_ASSERT(args.count(u"opt4") == 0);
    TSUNIT_ASSERT(args.count(u"opt5") == 0);
    TSUNIT_ASSERT(args.count(u"opt6") == 0);
    TSUNIT_ASSERT(args.count(u"opt7") == 0);
    TSUNIT_ASSERT(args.count(u"opt8") == 0);
    TSUNIT_ASSERT(args.count(u"opt9") == 1);
    TSUNIT_ASSERT(args.present(u"opt9"));
    TSUNIT_ASSERT(args.intValue<int>(u"opt9") == 12);

    ts::UString s;
    args.getValue(s, u"", u"x", 0);
    TSUNIT_EQUAL(u"a", s);
    args.getValue(s, u"", u"x", 1);
    TSUNIT_EQUAL(u"b", s);
    args.getValue(s, u"", u"x", 2);
    TSUNIT_EQUAL(u"x", s);

    ts::UStringVector vs;
    args.getValues(vs, u"");
    ts::UStringVector ref;
    ref.push_back(u"a");
    ref.push_back(u"b");
    TSUNIT_ASSERT(vs == ref);

    int i;
    args.getIntValue(i, u"opt3", -1, 0);
    TSUNIT_ASSERT(i == 6);
    args.getIntValue(i, u"opt3", -1, 1);
    TSUNIT_ASSERT(i == 0);
    args.getIntValue(i, u"opt3", -1, 2);
    TSUNIT_ASSERT(i == -1);

    std::vector<int> vi;
    args.getIntValues(vi, u"opt3");
    std::vector<int> iref;
    iref.push_back(6);
    iref.push_back(0);
    TSUNIT_ASSERT(vi == iref);
}