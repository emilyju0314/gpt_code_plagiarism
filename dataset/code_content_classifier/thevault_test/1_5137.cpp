void ArgsTest::testDecimals()
{
    TestArgs args(&CERR);

    TSUNIT_ASSERT(args.analyze(u"test", {u"param", u"--opt10", u"34", u"--opt10", u"0.1", u"--opt10", u"2.3456789-3"}));
    TSUNIT_EQUAL(658,   args.count(u"opt10"));
    TSUNIT_EQUAL(34000, args.intValue<int>(u"opt10", 0, 0));
    TSUNIT_EQUAL(100,   args.intValue<int>(u"opt10", 0, 1));
    TSUNIT_EQUAL(2345,  args.intValue<int>(u"opt10", 0, 2));
    TSUNIT_EQUAL(2346,  args.intValue<int>(u"opt10", 0, 3));
    TSUNIT_EQUAL(3000,  args.intValue<int>(u"opt10", 0, 657));
}