void CloseCurrentLevel()
    {
        CCryEditDoc* currentLevel = GetIEditor()->GetDocument();
        if (currentLevel && currentLevel->IsDocumentReady())
        {
            // This closes the current document (level)
            currentLevel->OnNewDocument();

            // Then we need to tell the game engine there is no level to render anymore
            if (GetIEditor()->GetGameEngine())
            {
                GetIEditor()->GetGameEngine()->SetLevelPath("");
                GetIEditor()->GetGameEngine()->SetLevelLoaded(false);

                CViewManager* pViewManager = GetIEditor()->GetViewManager();
                CViewport* pGameViewport = pViewManager ? pViewManager->GetGameViewport() : nullptr;
                if (pGameViewport)
                {
                    pGameViewport->SetViewTM(Matrix34::CreateIdentity());
                }
            }
        }
    }