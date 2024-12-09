TEST_F(ClickDetectorFixture, DoubleClickIsRegisteredIfMouseDeltaHasMovedLessThanDeadzoneInClickInterval)
    {
        using ::testing::Eq;

        const ClickDetector::ClickOutcome firstDownOutcome =
            m_clickDetector.DetectClick(ClickDetector::ClickEvent::Down, ScreenVector(0, 0));
        const ClickDetector::ClickOutcome firstUpOutcome = m_clickDetector.DetectClick(ClickDetector::ClickEvent::Up, ScreenVector(0, 0));
        const ClickDetector::ClickOutcome secondDownOutcome =
            m_clickDetector.DetectClick(ClickDetector::ClickEvent::Down, ScreenVector(0, 0));
        const ClickDetector::ClickOutcome secondUpOutcome = m_clickDetector.DetectClick(ClickDetector::ClickEvent::Up, ScreenVector(0, 0));

        EXPECT_THAT(firstDownOutcome, Eq(ClickDetector::ClickOutcome::Nil));
        EXPECT_THAT(firstUpOutcome, Eq(ClickDetector::ClickOutcome::Click));
        EXPECT_THAT(secondDownOutcome, Eq(ClickDetector::ClickOutcome::Nil));
        EXPECT_THAT(secondUpOutcome, Eq(ClickDetector::ClickOutcome::Nil));
    }