void TestPanelConcat::TestFocusUsage()
{
	// enables focus and widget events
	QApplication::setActiveWindow(&mPanel);

	// set initial focus
	mPanel.mInputA->setFocus();
	QVERIFY2(mPanel.mInputA->hasFocus(), "Input A doesn't have focus");

	// write STR1
	QTest::keyClicks(QApplication::focusWidget(), STR1);

	// move focus to next widget
	QTest::keyClick(&mPanel, Qt::Key_Tab);
	QVERIFY2(mPanel.mInputB->hasFocus(), "Input B doesn't have focus");

	// write STR2
	QTest::keyClicks(QApplication::focusWidget(), STR2);

	// move focus to next widget
	QTest::keyClick(&mPanel, Qt::Key_Tab);
	QVERIFY2(mPanel.mButtonConcat->hasFocus(), "Button CONCAT doesn't have focus");

	// press button CONCAT using space
	QTest::keyClick(QApplication::focusWidget(), Qt::Key_Space);
	QCOMPARE(mPanel.mLabelRes->text(), STR_RES);

	// move focus to next widget
	QTest::keyClick(&mPanel, Qt::Key_Tab);
	QVERIFY2(mPanel.mButtonCancel->hasFocus(), "Button CANCEL doesn't have focus");

	// press button CANCEL using space
	QTest::keyClick(QApplication::focusWidget(), Qt::Key_Space);
	QVERIFY2(mPanel.mInputA->text().isEmpty(), "Cancel didn't work on input A");
	QVERIFY2(mPanel.mInputB->text().isEmpty(), "Cancel didn't work on input B");
	QVERIFY2(mPanel.mLabelRes->text().isEmpty(), "Cancel didn't work on res label");
}