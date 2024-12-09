void FormatErrorMessageWithHostConfig(winrt::AdaptiveRenderContext const& renderContext, winrt::TextBlock const& errorMessage)
    {
        auto hostConfig = renderContext.HostConfig();
        auto inputsConfig = hostConfig.Inputs();
        auto errorMessageConfig = inputsConfig.ErrorMessage();

        // Set size defined in host config
        winrt::TextSize textSize = errorMessageConfig.Size();
        uint32_t resultSize = GetFontSizeFromFontType(hostConfig, winrt::FontType::Default, textSize);
        errorMessage.FontSize(resultSize);

        // Set weight defined in host config
        winrt::TextWeight textWeight = errorMessageConfig.Weight();
        auto resultWeight = GetFontWeightFromStyle(hostConfig, winrt::FontType::Default, textWeight);
        errorMessage.FontWeight(resultWeight);
    }