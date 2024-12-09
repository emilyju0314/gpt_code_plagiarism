TEST_F(AppActivityTest, TestUnloadProxyLocation) {
  // Set up some activities for some applications.
  TestAppActivity* app_activity1a = CreateAppActivity(kDummyApp1);
  TestAppActivity* app_activity2a = CreateAppActivity(kDummyApp2);
  TestAppActivity* app_activity2b = CreateAppActivity(kDummyApp2);
  TestAppActivity* app_activity1b = CreateAppActivity(kDummyApp1);
  EXPECT_EQ(3, GetActivityPosition(app_activity1b));
  EXPECT_EQ(2, GetActivityPosition(app_activity2b));
  EXPECT_EQ(1, GetActivityPosition(app_activity2a));
  EXPECT_EQ(0, GetActivityPosition(app_activity1a));

  // Unload an app and make sure that the proxy is in the newest activity slot.
  AppActivityRegistry* app_activity_registry =
      app_activity2a->app_activity_registry();
  app_activity2a->SetCurrentState(Activity::ACTIVITY_UNLOADED);
  app_activity2b->SetCurrentState(Activity::ACTIVITY_UNLOADED);
  app_activity2a->app_activity_registry()->Unload();
  EXPECT_EQ(0, app_activity_registry->NumberOfActivities());
  Activity* activity_proxy =
      app_activity_registry->unloaded_activity_proxy_for_test();
  RunAllPendingInMessageLoop();

  EXPECT_EQ(2, GetActivityPosition(app_activity1b));
  EXPECT_EQ(1, GetActivityPosition(activity_proxy));
  EXPECT_EQ(0, GetActivityPosition(app_activity1a));

  CloseActivity(activity_proxy);
  CloseActivity(app_activity1b);
  CloseActivity(app_activity1a);
}