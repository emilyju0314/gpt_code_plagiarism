IN_PROC_BROWSER_TEST_F(BrowserActionsContainerOverflowTest,
                       TestBasicActionOverflow) {
  // Load three extensions with browser actions.
  // TODO(devlin): Make a method to load these, and generate them rather than
  // using files.
  base::FilePath test_data_path =
      test_data_dir_.AppendASCII("api_test").AppendASCII("browser_action");
  const extensions::Extension* extension_a =
      LoadExtension(test_data_path.AppendASCII("basics"));
  const extensions::Extension* extension_b =
      LoadExtension(test_data_path.AppendASCII("add_popup"));
  const extensions::Extension* extension_c =
      LoadExtension(test_data_path.AppendASCII("remove_popup"));

  // Since the overflow bar isn't attached to a view, we have to kick it in
  // order to retrigger layout each time we change the number of icons in the
  // bar.
  overflow_bar()->Layout();

  // Sanity checks:
  // All extensions loaded.
  ASSERT_TRUE(extension_a);
  ASSERT_TRUE(extension_b);
  ASSERT_TRUE(extension_c);

  // All actions are showing, and are in the installation order.
  EXPECT_EQ(-1, model()->GetVisibleIconCount());
  ASSERT_EQ(3u, main_bar()->num_browser_actions());
  EXPECT_EQ(extension_a, main_bar()->GetBrowserActionViewAt(0)->extension());
  EXPECT_EQ(extension_b, main_bar()->GetBrowserActionViewAt(1)->extension());
  EXPECT_EQ(extension_c, main_bar()->GetBrowserActionViewAt(2)->extension());
  EXPECT_TRUE(VerifyVisibleCount(3u));

  // Reduce the visible count to 2. Order should be unchanged (A B C), but
  // only A and B should be visible on the main bar.
  model()->SetVisibleIconCountForTest(2u);
  overflow_bar()->Layout();  // Kick.
  EXPECT_EQ(extension_a, main_bar()->GetBrowserActionViewAt(0)->extension());
  EXPECT_EQ(extension_b, main_bar()->GetBrowserActionViewAt(1)->extension());
  EXPECT_EQ(extension_c, main_bar()->GetBrowserActionViewAt(2)->extension());
  EXPECT_TRUE(VerifyVisibleCount(2u));

  // Move extension C to the first position. Order should now be C A B, with
  // C and A visible in the main bar.
  model()->MoveExtensionIcon(extension_c, 0);
  overflow_bar()->Layout();  // Kick.
  EXPECT_EQ(extension_c, main_bar()->GetBrowserActionViewAt(0)->extension());
  EXPECT_EQ(extension_a, main_bar()->GetBrowserActionViewAt(1)->extension());
  EXPECT_EQ(extension_b, main_bar()->GetBrowserActionViewAt(2)->extension());
  EXPECT_TRUE(VerifyVisibleCount(2u));

  // Hide action A. This results in it being sent to overflow, and reducing the
  // visible size to 1, so the order should be C A B, with only C visible in the
  // main bar.
  extensions::ExtensionActionAPI::SetBrowserActionVisibility(
      extensions::ExtensionPrefs::Get(profile()),
      extension_a->id(),
      false);
  overflow_bar()->Layout();  // Kick.
  EXPECT_EQ(extension_c, main_bar()->GetBrowserActionViewAt(0)->extension());
  EXPECT_EQ(extension_a, main_bar()->GetBrowserActionViewAt(1)->extension());
  EXPECT_EQ(extension_b, main_bar()->GetBrowserActionViewAt(2)->extension());
  EXPECT_TRUE(VerifyVisibleCount(1u));
}