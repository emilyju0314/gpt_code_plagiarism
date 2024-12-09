void ArgsTest::testRedirection()
{
    TestArgs args(&CERR);

    TSUNIT_ASSERT(ts::UString::Save(ts::UStringVector({u"param2", u"--opt1", u"--opt2", u"@@foo"}), _tempFile1));
    TSUNIT_ASSERT(ts::UString::Save(ts::UStringVector({u"--opt4", u"3", u"@" + _tempFile1}), _tempFile2));

    TSUNIT_ASSERT(args.analyze(u"test", {u"param1", u"@" + _tempFile2, u"--opt4", u"5"}));
    TSUNIT_ASSERT(args.present(u""));
    TSUNIT_ASSERT(args.present(u"opt1"));
    TSUNIT_ASSERT(args.present(u"opt2"));
    TSUNIT_ASSERT(!args.present(u"opt3"));
    TSUNIT_ASSERT(args.present(u"opt4"));

    TSUNIT_EQUAL(2, args.count(u""));
    TSUNIT_EQUAL(1, args.count(u"opt1"));
    TSUNIT_EQUAL(1, args.count(u"opt2"));
    TSUNIT_EQUAL(2, args.count(u"opt4"));
    TSUNIT_EQUAL(u"param1", args.value(u"", u"", 0));
    TSUNIT_EQUAL(u"param2", args.value(u"", u"", 1));
    TSUNIT_EQUAL(u"@foo", args.value(u"opt2"));
    TSUNIT_EQUAL(3, args.intValue<int>(u"opt4", 0, 0));
    TSUNIT_EQUAL(5, args.intValue<int>(u"opt4", 0, 1));
}