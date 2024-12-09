TEST_F(AppActivityTest, TestUnloadWithReload) {
  EXPECT_EQ(0, AppRegistry::Get()->NumberOfApplications());

  TestAppActivity* app_activity = CreateAppActivity(kDummyApp1);
  AppActivityRegistry* app_activity_registry =
      app_activity->app_activity_registry();

  // Unload the activity.
  app_activity->SetCurrentState(Activity::ACTIVITY_UNLOADED);
  app_activity_registry->Unload();
  EXPECT_EQ(1, test_app_content_control_delegate()->unload_called());

  // Try to activate the activity again. This will force the application to
  // reload.
  Activity* activity_proxy =
      app_activity_registry->unloaded_activity_proxy_for_test();
  activity_proxy->SetCurrentState(Activity::ACTIVITY_VISIBLE);
  EXPECT_EQ(1, test_app_content_control_delegate()->restart_called());

  // However - the restart in this test framework does not really restart and
  // all objects should be gone now.
  EXPECT_EQ(0, AppRegistry::Get()->NumberOfApplications());
}