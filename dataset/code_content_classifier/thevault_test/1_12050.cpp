static bool HelpersVisible()
    {
        bool helpersVisible = false;
        EditorRequestBus::BroadcastResult(helpersVisible, &EditorRequests::DisplayHelpersVisible);
        return helpersVisible;
    }