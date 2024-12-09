TEST_F(AppActivityTest, TestMultipleActivityUnloadLock) {
  EXPECT_EQ(0, AppRegistry::Get()->NumberOfApplications());

  TestAppActivity* app_activity1 = CreateAppActivity(kDummyApp1);
  TestAppActivity* app_activity2 = CreateAppActivity(kDummyApp1);
  TestAppActivity* app_activity3 = CreateAppActivity(kDummyApp1);

  // Check that we have 3 activities of the same application.
  EXPECT_EQ(1, AppRegistry::Get()->NumberOfApplications());
  AppActivityRegistry* app_activity_registry =
      app_activity1->app_activity_registry();
  EXPECT_EQ(app_activity_registry, app_activity2->app_activity_registry());
  EXPECT_EQ(app_activity_registry, app_activity3->app_activity_registry());
  EXPECT_EQ(3, app_activity_registry->NumberOfActivities());
  EXPECT_EQ(Activity::ACTIVITY_VISIBLE, app_activity1->GetCurrentState());
  EXPECT_EQ(Activity::ACTIVITY_VISIBLE, app_activity2->GetCurrentState());
  EXPECT_EQ(Activity::ACTIVITY_VISIBLE, app_activity3->GetCurrentState());

  // After setting all activities to UNLOADED the application should unload.
  app_activity1->SetCurrentState(Activity::ACTIVITY_UNLOADED);
  app_activity1->app_activity_registry()->Unload();
  EXPECT_EQ(0, test_app_content_control_delegate()->unload_called());
  app_activity2->SetCurrentState(Activity::ACTIVITY_UNLOADED);
  app_activity2->app_activity_registry()->Unload();
  EXPECT_EQ(0, test_app_content_control_delegate()->unload_called());
  app_activity3->SetCurrentState(Activity::ACTIVITY_UNLOADED);
  app_activity3->app_activity_registry()->Unload();
  EXPECT_EQ(1, test_app_content_control_delegate()->unload_called());

  // Now there should only be the proxy activity left.
  ASSERT_EQ(1, AppRegistry::Get()->NumberOfApplications());
  ASSERT_EQ(app_activity_registry,
            AppRegistry::Get()->GetAppActivityRegistry(kDummyApp1, NULL));
  EXPECT_EQ(0, app_activity_registry->NumberOfActivities());
  Activity* activity_proxy =
      app_activity_registry->unloaded_activity_proxy_for_test();
  ASSERT_TRUE(activity_proxy);
  EXPECT_NE(app_activity1, activity_proxy);
  EXPECT_NE(app_activity2, activity_proxy);
  EXPECT_NE(app_activity3, activity_proxy);
  EXPECT_EQ(Activity::ACTIVITY_UNLOADED, activity_proxy->GetCurrentState());

  // Close the proxy object and make sure that nothing bad happens.
  CloseActivity(activity_proxy);

  EXPECT_EQ(0, AppRegistry::Get()->NumberOfApplications());
  EXPECT_EQ(1, test_app_content_control_delegate()->unload_called());
  EXPECT_EQ(0, test_app_content_control_delegate()->restart_called());
}