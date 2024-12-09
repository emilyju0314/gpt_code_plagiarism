TEST_F(HomeCardTest, AppSelection) {
  EXPECT_EQ(HomeCard::VISIBLE_MINIMIZED, HomeCard::Get()->GetState());

  WindowManager::GetInstance()->ToggleOverview();
  EXPECT_EQ(HomeCard::VISIBLE_BOTTOM, HomeCard::Get()->GetState());

  athena::ActivityManager::Get()->AddActivity(
      athena::ActivityFactory::Get()->CreateWebActivity(
          NULL, GURL("http://www.google.com/")));
  EXPECT_EQ(HomeCard::VISIBLE_MINIMIZED, HomeCard::Get()->GetState());
}