AZStd::vector<JointGroup> CreateJoints(int numJoints,
            AzPhysics::Scene* scene,
            GenerateSpawnPositionFuncPtr* parentPositionGenerator = nullptr,
            GenerateSpawnPositionFuncPtr* childPositionGenerator = nullptr,
            GenerateTwistLimitsFuncPtr* twistLimitsGenerator = nullptr)
        {
            AZStd::vector<JointGroup> joints;

            auto shapeConfiguration = AZStd::make_shared<Physics::SphereShapeConfiguration>(JointConstants::CreateJointDefaults::ColliderRadius);
            AzPhysics::ShapeColliderPair shapeColliderConfig(AZStd::make_shared<Physics::ColliderConfiguration>(), shapeConfiguration);
            for (int i = 0; i < numJoints; i++)
            {
                JointGroup newJoint;

                AzPhysics::RigidBodyConfiguration rigidBodyConfig;
                if (parentPositionGenerator)
                {
                    rigidBodyConfig.m_position = (*parentPositionGenerator)(i);
                }
                else
                {
                    rigidBodyConfig.m_position = AZ::Vector3(JointConstants::CreateJointDefaults::DefaultXPosition * i, 0.0f, 0.0f);
                }
                rigidBodyConfig.m_colliderAndShapeData = shapeColliderConfig;
                AzPhysics::SimulatedBodyHandle rigidBodyHandle = scene->AddSimulatedBody(&rigidBodyConfig);
                newJoint.m_parent = azdynamic_cast<AzPhysics::RigidBody*>(scene->GetSimulatedBodyFromHandle(rigidBodyHandle));

                //fix the child
                AzPhysics::StaticRigidBodyConfiguration staticRigidBodyConfig;
                if (childPositionGenerator)
                {
                    staticRigidBodyConfig.m_position = (*childPositionGenerator)(i);
                }
                else
                {
                    staticRigidBodyConfig.m_position = AZ::Vector3(
                        JointConstants::CreateJointDefaults::DefaultXPosition * i,
                        JointConstants::CreateJointDefaults::DefaultYPosition,
                        0.0f);
                }
                staticRigidBodyConfig.m_colliderAndShapeData = shapeColliderConfig;

                AzPhysics::SimulatedBodyHandle staticRigidBodyHandle = scene->AddSimulatedBody(&staticRigidBodyConfig);
                newJoint.m_child = scene->GetSimulatedBodyFromHandle(staticRigidBodyHandle);

                PhysX::D6JointLimitConfiguration config;

                TwistLimits limits(JointConstants::CreateJointDefaults::UpperLimit, JointConstants::CreateJointDefaults::LowerLimit);
                if (twistLimitsGenerator)
                {
                    limits = (*twistLimitsGenerator)(i);
                }
                config.m_twistLimitUpper = limits.m_upperLimit;
                config.m_twistLimitLower = limits.m_lowerLimit;
                config.m_swingLimitY = 1.0f;
                config.m_swingLimitZ = 1.0f;
                newJoint.m_jointHandle = scene->AddJoint(&config, newJoint.m_parent->m_bodyHandle, newJoint.m_child->m_bodyHandle);
                joints.emplace_back(AZStd::move(newJoint));
            }

            return AZStd::move(joints);
        }