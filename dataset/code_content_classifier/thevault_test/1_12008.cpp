void AnimGraphPlugin::InitForAnimGraph(EMotionFX::AnimGraph* setup)
    {
        AZ_UNUSED(setup);
        m_attributesWindow->Unlock();
        m_attributesWindow->Init(QModelIndex(), true); // Force update
        m_parameterWindow->Reinit();
        m_nodeGroupWindow->Init();
        m_viewWidget->UpdateAnimGraphOptions();
#if AZ_TRAIT_EMOTIONFX_HAS_GAME_CONTROLLER
        m_gameControllerWindow->ReInit();
#endif
    }