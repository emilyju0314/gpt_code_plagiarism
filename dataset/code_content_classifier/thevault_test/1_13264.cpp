TEST_F(AppActivityTest, OneAppActivity) {
  EXPECT_EQ(0, AppRegistry::Get()->NumberOfApplications());
  {
    TestAppActivity* app_activity = CreateAppActivity(kDummyApp1);
    EXPECT_EQ(1, AppRegistry::Get()->NumberOfApplications());
    EXPECT_EQ(1, app_activity->app_activity_registry()->NumberOfActivities());
    EXPECT_EQ(AppRegistry::Get()->GetAppActivityRegistry(kDummyApp1, NULL),
              app_activity->app_activity_registry());
    CloseActivity(app_activity);
  }
  EXPECT_EQ(0, AppRegistry::Get()->NumberOfApplications());
  EXPECT_EQ(0, test_app_content_control_delegate()->unload_called());
  EXPECT_EQ(0, test_app_content_control_delegate()->restart_called());
}