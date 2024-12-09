transpileBrowser* transpileBrowser::TranspileComboCommands() {
  helper::String::ReplaceAll(
      code_,
      "_copyBrowserUrl",
      "_focusBrowserUrl\n_hitCopy");

  return this;
}