void CreateProjectCtrl::NotifyCurrentScreen()
    {
        ScreenWidget* currentScreen = reinterpret_cast<ScreenWidget*>(m_stack->currentWidget());
        if (currentScreen)
        {
            currentScreen->NotifyCurrentScreen();
        }

        // Gather the enabled gems from the default project template when starting the create new project workflow.
        ReinitGemCatalogForSelectedTemplate();

        // make sure the gem repo has the latest details
        m_gemRepoScreen->Reinit();
    }