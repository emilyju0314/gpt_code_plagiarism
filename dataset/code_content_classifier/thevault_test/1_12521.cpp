TEST_P(SyncingSystemFixture, SyncingSystemPlaySpeedTests)
    {
        const SyncParam param = GetParam();
        param.m_eventFactoryA(m_syncTrackA);
        param.m_eventFactoryB(m_syncTrackB);
        GetEMotionFX().Update(0.0f);

        MCore::AttributeFloat* weightParam = m_animGraphInstance->GetParameterValueChecked<MCore::AttributeFloat>(0);
        weightParam->SetValue(param.m_weightParam);

        // Test reverse motion
        m_motionNodeA->SetReverse(param.m_reverseMotion);
        m_motionNodeB->SetReverse(param.m_reverseMotion);
        uint32 playTimeIndex = 0;
        const float tolerance = 0.00001f;
        Simulate(2.0f/*simulationTime*/, 10.0f/*expectedFps*/, 0.0f/*fpsVariance*/,
            /*preCallback*/[]([[maybe_unused]] AnimGraphInstance* animGraphInstance) {},
            /*postCallback*/[]([[maybe_unused]] AnimGraphInstance* animGraphInstance) {},
            /*preUpdateCallback*/[](AnimGraphInstance*, float, float, int) {},
            /*postUpdateCallback*/[this, &playTimeIndex, &tolerance, &param](AnimGraphInstance* animGraphInstance, [[maybe_unused]] float time, [[maybe_unused]] float timeDelta, [[maybe_unused]] int frame)
            {
                const float motionPlaySpeedA = m_motionNodeA->ExtractCustomPlaySpeed(animGraphInstance);
                const float durationA = m_motionNodeA->GetDuration(animGraphInstance);
                const float statePlaySpeedA = m_motionNodeA->GetPlaySpeed(animGraphInstance);
                const float motionPlaySpeedB = m_motionNodeB->ExtractCustomPlaySpeed(animGraphInstance);
                const float durationB = m_motionNodeB->GetDuration(animGraphInstance);
                const float statePlaySpeedB = m_motionNodeB->GetPlaySpeed(animGraphInstance);

                if (m_blend2Node->GetSyncMode() == AnimGraphObject::SYNCMODE_DISABLED)
                {
                    // We don't blend playspeeds when sync is disabled, the motion nodes should keep their playspeeds.
                    EXPECT_EQ(motionPlaySpeedA, statePlaySpeedA) << "Motion playspeeds should match the set playspeed in the motion node throughout blending.";
                    EXPECT_EQ(motionPlaySpeedB, statePlaySpeedB) << "Motion playspeeds should match the set playspeed in the motion node throughout blending.";
                }
                else if(m_blend2Node->GetSyncMode() == AnimGraphObject::SYNCMODE_CLIPBASED)
                {
                    float factorA;
                    float factorB;
                    float interpolatedSpeedA;
                    AZStd::tie(interpolatedSpeedA, factorA, factorB) = AnimGraphNode::SyncPlaySpeeds(
                        motionPlaySpeedA, durationA, motionPlaySpeedB, durationB, param.m_weightParam);
                    EXPECT_FLOAT_EQ(statePlaySpeedA, interpolatedSpeedA * factorA) << "Motion playspeeds should match the set playspeed in the motion node throughout blending.";
                }
                else if(m_blend2Node->GetSyncMode() == AnimGraphObject::SYNCMODE_TRACKBASED)
                {
                    const float motionPlayTimeA = m_motionNodeA->GetCurrentPlayTime(animGraphInstance);
                    const float motionPlayTimeB = m_motionNodeB->GetCurrentPlayTime(animGraphInstance);

                    EXPECT_NEAR(motionPlayTimeA, param.m_expectedPlayTimeA[playTimeIndex], tolerance) << "Motion node A playtime should match the expected playtime.";
                    EXPECT_NEAR(motionPlayTimeB, param.m_expectedPlayTimeB[playTimeIndex], tolerance) << "Motion node B playtime should match the expected playtime.";
                    playTimeIndex++;
                }
            }
        );
    }