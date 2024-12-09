void ArgsTest::testValidCommandArgcArgv()
{
    ts::ReportBuffer<> log;
    TestArgs args(&log);

    char* argv[] = {
        const_cast<char*>("test"),
        const_cast<char*>("--opt3"),
        const_cast<char*>("6"),
        const_cast<char*>("a"),
        const_cast<char*>("--opt1"),
        const_cast<char*>("b"),
        const_cast<char*>("--opt9"),
        const_cast<char*>("val2"),
        const_cast<char*>("--opt3"),
        const_cast<char*>("0")};
    const int argc = 10;

    TSUNIT_ASSERT(args.analyze(argc, argv));

    TSUNIT_EQUAL(u"test", args.appName());
    TSUNIT_EQUAL(2, args.count(u""));
    TSUNIT_EQUAL(u"a", args.value(u"", u"", 0));
    TSUNIT_EQUAL(u"b", args.value(u"", u"", 1));
    TSUNIT_EQUAL(1, args.count(u"opt1"));
    TSUNIT_ASSERT(args.present(u"opt1"));
    TSUNIT_EQUAL(0, args.count(u"opt2"));
    TSUNIT_ASSERT(!args.present(u"opt2"));
    TSUNIT_EQUAL(2, args.count(u"opt3"));
    TSUNIT_ASSERT(args.present(u"opt3"));
    TSUNIT_EQUAL(6, args.intValue<int>(u"opt3", -1, 0));
    TSUNIT_EQUAL(0, args.intValue<int>(u"opt3", -1, 1));
    TSUNIT_EQUAL(-1, args.intValue<int>(u"opt3", -1, 2));
    TSUNIT_EQUAL(0, args.count(u"opt4"));
    TSUNIT_EQUAL(0, args.count(u"opt5"));
    TSUNIT_EQUAL(0, args.count(u"opt6"));
    TSUNIT_EQUAL(0, args.count(u"opt7"));
    TSUNIT_EQUAL(0, args.count(u"opt8"));
    TSUNIT_EQUAL(1, args.count(u"opt9"));
    TSUNIT_ASSERT(args.present(u"opt9"));
    TSUNIT_EQUAL(12, args.intValue<int>(u"opt9"));

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
    TSUNIT_EQUAL(6, i);
    args.getIntValue(i, u"opt3", -1, 1);
    TSUNIT_EQUAL(0, i);
    args.getIntValue(i, u"opt3", -1, 2);
    TSUNIT_EQUAL(-1, i);

    std::vector<int> vi;
    args.getIntValues(vi, u"opt3");
    std::vector<int> iref;
    iref.push_back(6);
    iref.push_back(0);
    TSUNIT_ASSERT(vi == iref);
}