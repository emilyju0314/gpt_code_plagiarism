TEST_F(AppActivityTest, TestUnloadFollowedByClose) {
  EXPECT_EQ(0, AppRegistry::Get()->NumberOfApplications());

  TestAppActivity* app_activity = CreateAppActivity(kDummyApp1);
  EXPECT_EQ(1, AppRegistry::Get()->NumberOfApplications());
  AppActivityRegistry* app_activity_registry =
      app_activity->app_activity_registry();
  EXPECT_EQ(1, app_activity_registry->NumberOfActivities());
  EXPECT_EQ(Activity::ACTIVITY_VISIBLE, app_activity->GetCurrentState());

  // Calling Unload now should not do anything since at least one activity in
  // the registry is still visible.
  app_activity_registry->Unload();
  EXPECT_EQ(0, test_app_content_control_delegate()->unload_called());

  // After setting our activity to unloaded however the application should get
  // unloaded as requested.
  app_activity->SetCurrentState(Activity::ACTIVITY_UNLOADED);
  app_activity_registry->Unload();
  EXPECT_EQ(1, test_app_content_control_delegate()->unload_called());

  // Check that our created application is gone, and instead a proxy got
  // created.
  ASSERT_EQ(1, AppRegistry::Get()->NumberOfApplications());
  ASSERT_EQ(app_activity_registry,
            AppRegistry::Get()->GetAppActivityRegistry(kDummyApp1, NULL));
  EXPECT_EQ(0, app_activity_registry->NumberOfActivities());
  Activity* activity_proxy =
      app_activity_registry->unloaded_activity_proxy_for_test();
  ASSERT_TRUE(activity_proxy);
  EXPECT_NE(app_activity, activity_proxy);
  EXPECT_EQ(Activity::ACTIVITY_UNLOADED, activity_proxy->GetCurrentState());

  // Close the proxy object and make sure that nothing bad happens.
  CloseActivity(activity_proxy);

  EXPECT_EQ(0, AppRegistry::Get()->NumberOfApplications());
  EXPECT_EQ(1, test_app_content_control_delegate()->unload_called());
  EXPECT_EQ(0, test_app_content_control_delegate()->restart_called());
}