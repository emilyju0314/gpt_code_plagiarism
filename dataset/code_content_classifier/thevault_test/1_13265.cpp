TEST_F(AppActivityTest, TwoAppsWithOneActivityEach) {
  EXPECT_EQ(0, AppRegistry::Get()->NumberOfApplications());
  {
    TestAppActivity* app_activity1 = CreateAppActivity(kDummyApp1);
    EXPECT_EQ(1, AppRegistry::Get()->NumberOfApplications());
    EXPECT_EQ(1, app_activity1->app_activity_registry()->NumberOfActivities());
    TestAppActivity* app_activity2 = CreateAppActivity(kDummyApp2);
    EXPECT_EQ(2, AppRegistry::Get()->NumberOfApplications());
    EXPECT_EQ(1, app_activity2->app_activity_registry()->NumberOfActivities());
    EXPECT_EQ(1, app_activity1->app_activity_registry()->NumberOfActivities());
    CloseActivity(app_activity1);
    CloseActivity(app_activity2);
  }
  EXPECT_EQ(0, AppRegistry::Get()->NumberOfApplications());
  EXPECT_EQ(0, test_app_content_control_delegate()->unload_called());
  EXPECT_EQ(0, test_app_content_control_delegate()->restart_called());
}