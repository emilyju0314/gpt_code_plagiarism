AZStd::vector<Physics::Character*> CreateCharacterControllers(
            int numCharacterControllers,
            CharacterConstants::CharacterSettings::ColliderType colliderType,
            AzPhysics::SceneHandle& sceneHandle,
            GenerateSpawnPositionFuncPtr* genSpawnPosFuncPtr = nullptr)
        {
            //define some common configs
            PhysX::CharacterControllerConfiguration characterConfig;
            characterConfig.m_maximumSlopeAngle = CharacterConstants::CharacterSettings::MaximumSlopeAngle;
            characterConfig.m_stepHeight = CharacterConstants::CharacterSettings::StepHeight;

            switch (colliderType)
            {
            case CharacterConstants::CharacterSettings::ColliderType::Box:
                {
                    characterConfig.m_shapeConfig = AZStd::make_shared<Physics::BoxShapeConfiguration>(
                        AZ::Vector3(CharacterConstants::CharacterSettings::CharacterBoxWidth,
                            CharacterConstants::CharacterSettings::CharacterBoxDepth,
                            CharacterConstants::CharacterSettings::CharacterBoxHeight)
                    );

                }
                break;
            case CharacterConstants::CharacterSettings::ColliderType::Capsule:
            default:
                {
                    characterConfig.m_shapeConfig = AZStd::make_shared<Physics::CapsuleShapeConfiguration>(
                        CharacterConstants::CharacterSettings::CharacterCylinderHeight,
                        CharacterConstants::CharacterSettings::CharacterCylinderRadius);
                }
                break;
            }

            auto* sceneInterface = AZ::Interface<AzPhysics::SceneInterface>::Get();

            AZStd::vector<Physics::Character*> controllers;
            controllers.reserve(numCharacterControllers);
            for (int i = 0; i < numCharacterControllers; i++)
            {
                const AZ::Vector3 spawnPosition = genSpawnPosFuncPtr != nullptr ? (*genSpawnPosFuncPtr)(i) : AZ::Vector3::CreateZero();
                characterConfig.m_position = spawnPosition;
                AzPhysics::SimulatedBodyHandle newHandle = sceneInterface->AddSimulatedBody(sceneHandle, &characterConfig);
                if (newHandle != AzPhysics::InvalidSimulatedBodyHandle)
                {
                    if (auto* characterPtr = azdynamic_cast<Physics::Character*>(
                            sceneInterface->GetSimulatedBodyFromHandle(sceneHandle, newHandle)
                        ))
                    {
                        controllers.emplace_back(characterPtr);
                    }
                }
            }

            return controllers;
        }