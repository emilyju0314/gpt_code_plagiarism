void App::OnLaunched(LaunchActivatedEventArgs const& /*e*/)
    {
        // if this is a UWP... it means its our problem to hook up the content to the window here.
        if (_isUwp)
        {
            auto content = Window::Current().Content();
            if (content == nullptr)
            {
                auto logic = Logic();
                logic.RunAsUwp(); // Must set UWP status first, settings might change based on it.
                logic.LoadSettings();
                logic.Create();

                auto page = logic.GetRoot().as<TerminalPage>();

                Window::Current().Content(page);
                Window::Current().Activate();
                
                const auto krakenPurple = Windows::UI::ColorHelper::FromArgb(
                  (uint8_t)(0.5 * 4 + 0.5), 
                  (uint8_t)(104 >> 8),
                  (uint8_t)(79 >> 16),
                  (uint8_t)(163 >> 24)
                );

                CoreApplication::GetCurrentView().TitleBar().ExtendViewIntoTitleBar(true);
                const auto titleBar = ApplicationView::GetForCurrentView().TitleBar();
                titleBar.ButtonBackgroundColor(krakenPurple);
                titleBar.ButtonInactiveBackgroundColor(krakenPurple);
            }
        }
    }