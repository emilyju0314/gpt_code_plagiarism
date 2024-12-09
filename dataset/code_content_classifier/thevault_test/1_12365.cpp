TEST_F(ClickDetectorFixture, ClickIsNotRegisteredAfterIgnoringMouseMovesBeforeMouseUpWithLargeDelta)
    {
        using ::testing::Eq;

        const ClickDetector::ClickOutcome downOutcome = m_clickDetector.DetectClick(ClickDetector::ClickEvent::Down, ScreenVector(0, 0));
        const ClickDetector::ClickOutcome upOutcome = m_clickDetector.DetectClick(ClickDetector::ClickEvent::Up, ScreenVector(50, 50));

        EXPECT_THAT(downOutcome, Eq(ClickDetector::ClickOutcome::Nil));
        EXPECT_THAT(upOutcome, Eq(ClickDetector::ClickOutcome::Release));
    }