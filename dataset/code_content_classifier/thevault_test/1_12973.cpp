void TestCalculator::testDiff_data()
{
	QTest::addColumn<int>("a");
	QTest::addColumn<int>("b");
	QTest::addColumn<int>("result");

	//Then you add rows of values.Each row contains a name and a list of values:
	QTest::newRow("all 0") << 0 << 0 << 0;
	QTest::newRow("same number") << 10 << 10 << 0;
	QTest::newRow("opposite number") << 10 << -10 << 20;
	QTest::newRow("positive res") << 10 << 5 << 5;
	QTest::newRow("negative res") << 5 << 10 << -5;
}