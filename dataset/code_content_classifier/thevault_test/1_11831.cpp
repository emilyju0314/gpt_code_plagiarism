TEST_P(GetSimulatedRootJointFixture, TestSimulatedObject_GetSimulatedRootJoint)
    {
        PrefabLeftArmSkeleton leftArmSkeleton;

        Actor actor;
        EXPECT_CALL(actor, GetSkeleton())
            .WillRepeatedly(testing::Return(&leftArmSkeleton.m_skeleton));

        SimulatedObjectSetup setup(&actor);
        SimulatedObject* object = setup.AddSimulatedObject();

        const int jointIndex1 = testing::get<0>(GetParam());
        const int jointIndex2 = testing::get<1>(GetParam());

        object->AddSimulatedJointAndChildren(jointIndex1);
        if (jointIndex2 >= 0)
        {
            object->AddSimulatedJointAndChildren(jointIndex2);
        }

        const SimulatedJoint* simulatedJoint1 = object->FindSimulatedJointBySkeletonJointIndex(jointIndex1);
        EXPECT_TRUE(simulatedJoint1);

        if (jointIndex2 >= 0 && jointIndex2 != jointIndex1)
        {
            const SimulatedJoint* simulatedJoint2 = object->FindSimulatedJointBySkeletonJointIndex(jointIndex2);
            EXPECT_TRUE(simulatedJoint2);

            const Skeleton& skeleton = leftArmSkeleton.m_skeleton;
            const int hasCommonParent = NodeHasCommonParent(skeleton.GetNode(jointIndex1), skeleton.GetNode(jointIndex2));

            if (hasCommonParent == 0)
            {
                // simulatedJoint1 and simulatedJoint2 are not in each other's
                // parent list
                EXPECT_EQ(object->GetSimulatedRootJoint(object->GetSimulatedRootJointIndex(simulatedJoint1)), simulatedJoint1);
                EXPECT_EQ(object->GetSimulatedRootJoint(object->GetSimulatedRootJointIndex(simulatedJoint2)), simulatedJoint2);
                EXPECT_EQ(object->GetNumSimulatedRootJoints(), 2);
            }
            else if (hasCommonParent < 0)
            {
                // simulatedJoint1 is a parent of simulatedJoint2
                EXPECT_EQ(object->GetSimulatedRootJoint(object->GetSimulatedRootJointIndex(simulatedJoint1)), simulatedJoint1);
                EXPECT_EQ(object->GetNumSimulatedRootJoints(), 1);
            }
            else
            {
                // simulatedJoint2 is a parent of simulatedJoint1
                EXPECT_EQ(object->GetSimulatedRootJoint(object->GetSimulatedRootJointIndex(simulatedJoint2)), simulatedJoint2);
                EXPECT_EQ(object->GetNumSimulatedRootJoints(), 1);
            }
        }
        else
        {
            EXPECT_EQ(object->GetSimulatedRootJoint(object->GetSimulatedRootJointIndex(simulatedJoint1)), simulatedJoint1);
            EXPECT_EQ(object->GetNumSimulatedRootJoints(), 1);
        }
    }