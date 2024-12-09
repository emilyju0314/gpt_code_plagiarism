void AnimGraphPlugin::OnAfterLoadLayout()
    {
        // fit graph on screen
        if (m_graphWidget->GetActiveGraph())
        {
            m_graphWidget->GetActiveGraph()->FitGraphOnScreen(m_graphWidget->geometry().width(), m_graphWidget->geometry().height(), m_graphWidget->GetMousePos(), false);
        }

        // connect to the timeline recorder data
        TimeViewPlugin* timeViewPlugin = FindTimeViewPlugin();
        if (timeViewPlugin)
        {
            connect(timeViewPlugin, &TimeViewPlugin::DoubleClickedRecorderNodeHistoryItem, this, &AnimGraphPlugin::OnDoubleClickedRecorderNodeHistoryItem);
            connect(timeViewPlugin, &TimeViewPlugin::ClickedRecorderNodeHistoryItem, this, &AnimGraphPlugin::OnClickedRecorderNodeHistoryItem);
        }

        SetOptionFlag(WINDOWS_PARAMETERWINDOW, GetParameterDock()->isVisible());
        SetOptionFlag(WINDOWS_ATTRIBUTEWINDOW, GetAttributeDock()->isVisible());
        SetOptionFlag(WINDOWS_PALETTEWINDOW, GetNodePaletteDock()->isVisible());
#if AZ_TRAIT_EMOTIONFX_HAS_GAME_CONTROLLER
        SetOptionFlag(WINDOWS_GAMECONTROLLERWINDOW, GetGameControllerDock()->isVisible());
#endif
        SetOptionFlag(WINDOWS_NODEGROUPWINDOW, GetNodeGroupDock()->isVisible());
    }