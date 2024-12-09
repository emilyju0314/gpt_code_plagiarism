IN_PROC_BROWSER_TEST_F(BrowserActionsContainerTest,
                       MoveBrowserActions) {
  // Load three extensions with browser actions.
  const extensions::Extension* extension_a =
      LoadExtension(test_data_dir_.AppendASCII("api_test")
                                  .AppendASCII("browser_action")
                                  .AppendASCII("basics"));
  ASSERT_TRUE(extension_a);
  const extensions::Extension* extension_b =
      LoadExtension(test_data_dir_.AppendASCII("api_test")
                                  .AppendASCII("browser_action")
                                  .AppendASCII("add_popup"));
  ASSERT_TRUE(extension_b);
  const extensions::Extension* extension_c =
      LoadExtension(test_data_dir_.AppendASCII("api_test")
                                  .AppendASCII("browser_action")
                                  .AppendASCII("remove_popup"));
  ASSERT_TRUE(extension_c);

  EXPECT_EQ(3, browser_actions_bar()->VisibleBrowserActions());
  EXPECT_EQ(3, browser_actions_bar()->NumberOfBrowserActions());

  extensions::ExtensionToolbarModel* model =
      extensions::ExtensionToolbarModel::Get(profile());
  ASSERT_TRUE(model);

  // Order is now A B C.
  EXPECT_EQ(extension_a->id(), browser_actions_bar()->GetExtensionId(0));
  EXPECT_EQ(extension_b->id(), browser_actions_bar()->GetExtensionId(1));
  EXPECT_EQ(extension_c->id(), browser_actions_bar()->GetExtensionId(2));

  // Move C to first position. Order is C A B.
  model->MoveExtensionIcon(extension_c, 0);
  EXPECT_EQ(extension_c->id(), browser_actions_bar()->GetExtensionId(0));
  EXPECT_EQ(extension_a->id(), browser_actions_bar()->GetExtensionId(1));
  EXPECT_EQ(extension_b->id(), browser_actions_bar()->GetExtensionId(2));

  // Move B to third position. Order is still C A B.
  model->MoveExtensionIcon(extension_b, 2);
  EXPECT_EQ(extension_c->id(), browser_actions_bar()->GetExtensionId(0));
  EXPECT_EQ(extension_a->id(), browser_actions_bar()->GetExtensionId(1));
  EXPECT_EQ(extension_b->id(), browser_actions_bar()->GetExtensionId(2));

  // Move B to middle position. Order is C B A.
  model->MoveExtensionIcon(extension_b, 1);
  EXPECT_EQ(extension_c->id(), browser_actions_bar()->GetExtensionId(0));
  EXPECT_EQ(extension_b->id(), browser_actions_bar()->GetExtensionId(1));
  EXPECT_EQ(extension_a->id(), browser_actions_bar()->GetExtensionId(2));
}