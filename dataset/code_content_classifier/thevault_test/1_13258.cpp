IN_PROC_BROWSER_TEST_F(BrowserActionsContainerTest, HighlightMode) {
  // Load three extensions with browser actions.
  ASSERT_TRUE(LoadExtension(test_data_dir_.AppendASCII("api_test")
                                          .AppendASCII("browser_action")
                                          .AppendASCII("basics")));
  std::string id_a = browser_actions_bar()->GetExtensionId(0);
  ASSERT_TRUE(LoadExtension(test_data_dir_.AppendASCII("api_test")
                                          .AppendASCII("browser_action")
                                          .AppendASCII("add_popup")));
  std::string id_b = browser_actions_bar()->GetExtensionId(1);
  ASSERT_TRUE(LoadExtension(test_data_dir_.AppendASCII("api_test")
                                          .AppendASCII("browser_action")
                                          .AppendASCII("remove_popup")));

  EXPECT_EQ(3, browser_actions_bar()->VisibleBrowserActions());
  EXPECT_EQ(3, browser_actions_bar()->NumberOfBrowserActions());

  BrowserActionsContainer* container = browser()
                                           ->window()
                                           ->GetBrowserWindowTesting()
                                           ->GetToolbarView()
                                           ->browser_actions();

  // Currently, dragging should be enabled.
  BrowserActionView* action_view = container->GetBrowserActionViewAt(0);
  ASSERT_TRUE(action_view);
  gfx::Point point(action_view->x(), action_view->y());
  EXPECT_TRUE(container->CanStartDragForView(action_view, point, point));

  extensions::ExtensionToolbarModel* model =
      extensions::ExtensionToolbarModel::Get(profile());

  extensions::ExtensionIdList extension_ids;
  extension_ids.push_back(id_a);
  extension_ids.push_back(id_b);
  model->HighlightExtensions(extension_ids);

  // Only two browser actions should be visible.
  EXPECT_EQ(2, browser_actions_bar()->VisibleBrowserActions());
  EXPECT_EQ(2, browser_actions_bar()->NumberOfBrowserActions());

  // We shouldn't be able to drag in highlight mode.
  action_view = container->GetBrowserActionViewAt(0);
  EXPECT_FALSE(container->CanStartDragForView(action_view, point, point));

  // We should go back to normal after leaving highlight mode.
  model->StopHighlighting();
  EXPECT_EQ(3, browser_actions_bar()->VisibleBrowserActions());
  EXPECT_EQ(3, browser_actions_bar()->NumberOfBrowserActions());
  action_view = container->GetBrowserActionViewAt(0);
  EXPECT_TRUE(container->CanStartDragForView(action_view, point, point));
}