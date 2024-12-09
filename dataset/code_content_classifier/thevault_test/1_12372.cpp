TEST_F(CryMovie_CharacterTrackAnimator_Test, CryMovieUnitTest_CharacterTrackAnimator_ComputeAnimKeyNormalizedTime_NoLoop)
    {
        const float NORMALIZED_CLIP_START = .0f;
        const float NORMALIZED_CLIP_END = 1.0f;
        ICharacterKey key;
        m_dummyTrack.GetKey(EntityNodeTest::KEY_IDX, &key);
        key.m_bLoop = false;

        // check that the key is in what we expect for the test
        ASSERT_EQ(EntityNodeTest::KEY_TIME, key.time) << "Test Key frame should start at 1 second; something's wrong with the test setup.";
        ASSERT_EQ(EntityNodeTest::KEY_DURATION, key.m_duration) << "Test Key frame should last for 1 second; something's wrong with the test setup.";

        float test_sampleTime;
        f32 normalizedTime;

        // sample before clip starts
        test_sampleTime = KEY_TIME - 0.5f;
        normalizedTime = ComputeAnimKeyNormalizedTime(key, test_sampleTime);
        EXPECT_FLOAT_EQ(NORMALIZED_CLIP_START, normalizedTime);

        // sample after clip ends
        test_sampleTime = KEY_TIME + KEY_DURATION + 0.5f;
        normalizedTime = ComputeAnimKeyNormalizedTime(key, test_sampleTime);
        EXPECT_FLOAT_EQ(NORMALIZED_CLIP_END, normalizedTime);

        // sample at clip start/end - should return normalized time of .0f and 1.0f
        test_sampleTime = KEY_TIME;
        normalizedTime = ComputeAnimKeyNormalizedTime(key, test_sampleTime);
        EXPECT_FLOAT_EQ(NORMALIZED_CLIP_START, normalizedTime);

        test_sampleTime = KEY_TIME + KEY_DURATION;
        normalizedTime = ComputeAnimKeyNormalizedTime(key, test_sampleTime);
        EXPECT_FLOAT_EQ(NORMALIZED_CLIP_END, normalizedTime);

        // sample in different locations in the clip, before and after the clip to test looping
        const int NUM_TEST_SAMPLES = 10;
        for (int i = 0; i <= NUM_ANIMATION_USER_DATA_SLOTS; i++)
        {
            const float clipFraction = static_cast<float>(i) / static_cast<float>(NUM_TEST_SAMPLES);

            test_sampleTime = KEY_TIME + (clipFraction * KEY_DURATION);
            normalizedTime = ComputeAnimKeyNormalizedTime(key, test_sampleTime);

            EXPECT_FLOAT_EQ(clipFraction, normalizedTime);
        }
    }