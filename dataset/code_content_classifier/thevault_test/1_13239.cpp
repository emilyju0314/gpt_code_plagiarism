TEST_F(BrowserPluginTest, InitialResize) {
  LoadHTML(GetHTMLForBrowserPluginObject().c_str());
  // Verify that the information in Attach is correct.
  BrowserPluginHostMsg_Attach_Params params;
  MockBrowserPlugin* browser_plugin = GetCurrentPluginWithAttachParams(&params);

  EXPECT_EQ(640, params.resize_guest_params.view_size.width());
  EXPECT_EQ(480, params.resize_guest_params.view_size.height());
  ASSERT_TRUE(browser_plugin);
}