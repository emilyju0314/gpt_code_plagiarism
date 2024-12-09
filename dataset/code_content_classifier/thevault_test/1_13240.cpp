TEST_F(BrowserPluginTest, RemovePluginBeforeNavigation) {
  std::string html = base::StringPrintf(kHTMLForSourcelessPluginObject,
                                        kBrowserPluginMimeType);
  LoadHTML(html.c_str());
  EXPECT_FALSE(browser_plugin_manager()->sink().GetUniqueMessageMatching(
      BrowserPluginHostMsg_PluginDestroyed::ID));
  ExecuteJavaScript("x = document.getElementById('browserplugin'); "
                    "x.parentNode.removeChild(x);");
  ProcessPendingMessages();
  EXPECT_FALSE(browser_plugin_manager()->sink().GetUniqueMessageMatching(
      BrowserPluginHostMsg_PluginDestroyed::ID));
}