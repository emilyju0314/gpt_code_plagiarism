TEST_F(CryMovie_CharacterTrackAnimator_Test, CryMovieUnitTest_CharacterTrackAnimator_ComputeAnimKeyNormalizedTime_Loop)
    {
        const float NORMALIZED_CLIP_START = .0f;
        const float ERROR_TOLERANCE = 0.0001f;
        ICharacterKey key;
        m_dummyTrack.GetKey(EntityNodeTest::KEY_IDX, &key);
        key.m_bLoop = true;

        // check that the key is in what we expect for the test
        ASSERT_EQ(EntityNodeTest::KEY_TIME, key.time) << "Test Key frame should start at 1 second; something's wrong with the test setup.";
        ASSERT_EQ(EntityNodeTest::KEY_DURATION, key.m_duration) << "Test Key frame should last for 1 second; something's wrong with the test setup.";

        float test_sampleTime;
        f32 normalizedTime;

        // sample in different locations in the clip, before and after the clip to test looping
        const int NUM_TEST_SAMPLES = 10;
        for (int i = 0; i <= NUM_ANIMATION_USER_DATA_SLOTS; i++)
        {
            const float clipFraction = static_cast<float>(i) / static_cast<float>(NUM_TEST_SAMPLES);

            // sample before clip
            test_sampleTime = KEY_TIME - (clipFraction * KEY_DURATION);
            normalizedTime = ComputeAnimKeyNormalizedTime(key, test_sampleTime);
            EXPECT_FLOAT_EQ(NORMALIZED_CLIP_START, normalizedTime);

            // sample within clip
            test_sampleTime = KEY_TIME + (clipFraction * KEY_DURATION);
            normalizedTime = ComputeAnimKeyNormalizedTime(key, test_sampleTime);
            EXPECT_NEAR(clipFraction, normalizedTime, ERROR_TOLERANCE);

            if (i > 0)
            {
                // sample after clip
                test_sampleTime = KEY_TIME + KEY_DURATION + (clipFraction * KEY_DURATION);
                normalizedTime = ComputeAnimKeyNormalizedTime(key, test_sampleTime);
                EXPECT_NEAR(clipFraction, normalizedTime, ERROR_TOLERANCE);
            }
        }
    }