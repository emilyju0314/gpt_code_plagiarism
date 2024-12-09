bool HairComponentController::CreateHairObject()
            {
                // Do not create a hairRenderObject when actor instance hasn't been created.
                EMotionFX::ActorInstance* actorInstance = nullptr;
                EMotionFX::Integration::ActorComponentRequestBus::EventResult(
                    actorInstance, m_entityId, &EMotionFX::Integration::ActorComponentRequestBus::Events::GetActorInstance);

                if (!actorInstance)
                {
                    return false;
                }

                if (!m_featureProcessor)
                {
                    AZ_Error("Hair Gem", false, "Required feature processor does not exist yet");
                    return false;
                }

                if (!m_configuration.m_hairAsset.GetId().IsValid() || !m_configuration.m_hairAsset.IsReady())
                {
                    AZ_Warning("Hair Gem", false, "Hair Asset was not ready - second attempt will be made when ready");
                    return false;
                }

                AMD::TressFXAsset* hairAsset = m_configuration.m_hairAsset.Get()->m_tressFXAsset.get();
                if (!hairAsset)
                {
                    AZ_Error("Hair Gem", false, "Hair asset could not be loaded");
                    return false;
                }

                if (!GenerateLocalToGlobalBoneIndex(actorInstance, hairAsset))
                {
                    return false;
                }
                
                // First remove the existing hair object - this can happen if the configuration
                // or the hair asset selected changes.
                RemoveHairObject();

                // create a new instance - will remove the old one.
                m_renderObject.reset(new HairRenderObject());
                AZStd::string hairName;
                AzFramework::StringFunc::Path::GetFileName(m_configuration.m_hairAsset.GetHint().c_str(), hairName);
                if (!m_renderObject->Init( m_featureProcessor, hairName.c_str(), hairAsset,
                    &m_configuration.m_simulationSettings, &m_configuration.m_renderingSettings))
                {
                    AZ_Warning("Hair Gem", false, "Hair object was not initialize succesfully");
                    m_renderObject.reset();    // no instancing yet - remove manually
                    return false;
                }

                // Resize the bone matrices array. The size should equal to the number of bones in the tressFXAsset.
                m_cachedHairBoneMatrices.resize(m_hairBoneIndexLookup.size());
                m_cachedCollisionBoneMatrices.resize(m_collisionBoneIndexLookup.size());

                // Feature processor registration that will hold an instance.
                // Remark: DO NOT remove the TressFX asset - it's data might be required for
                // more instance hair objects. 
                m_featureProcessor->AddHairRenderObject(m_renderObject);
                return true;
            }