TEST_F(SafeBrowsingBlockingPageTest, NavigatingBackAndForth) {
  // Enable malware reports.
  Profile* profile = Profile::FromBrowserContext(
      web_contents()->GetBrowserContext());
  profile->GetPrefs()->SetBoolean(
      prefs::kSafeBrowsingExtendedReportingEnabled, true);

  // Navigate somewhere.
  Navigate(kGoodURL, 1);

  // Now navigate to a bad page triggerring an interstitial.
  controller().LoadURL(GURL(kBadURL), content::Referrer(),
                       content::PAGE_TRANSITION_TYPED, std::string());
  ShowInterstitial(false, kBadURL);
  SafeBrowsingBlockingPage* sb_interstitial =
      GetSafeBrowsingBlockingPage();
  ASSERT_TRUE(sb_interstitial);

  // Proceed, then navigate back.
  ProceedThroughInterstitial(sb_interstitial);
  Navigate(kBadURL, 2);  // Commit the navigation.
  GoBack(true);

  // We are back on the good page.
  sb_interstitial = GetSafeBrowsingBlockingPage();
  ASSERT_FALSE(sb_interstitial);
  ASSERT_EQ(2, controller().GetEntryCount());
  EXPECT_EQ(kGoodURL, controller().GetActiveEntry()->GetURL().spec());

  // Navigate forward to the malware URL.
  web_contents()->GetController().GoForward();
  ShowInterstitial(false, kBadURL);
  sb_interstitial = GetSafeBrowsingBlockingPage();
  ASSERT_TRUE(sb_interstitial);

  // Let's proceed and make sure everything is OK (bug 17627).
  ProceedThroughInterstitial(sb_interstitial);
  Navigate(kBadURL, 2);  // Commit the navigation.
  sb_interstitial = GetSafeBrowsingBlockingPage();
  ASSERT_FALSE(sb_interstitial);
  ASSERT_EQ(2, controller().GetEntryCount());
  EXPECT_EQ(kBadURL, controller().GetActiveEntry()->GetURL().spec());

  // Two reports should have been sent.
  EXPECT_EQ(2u, ui_manager_->GetDetails()->size());
  ui_manager_->GetDetails()->clear();
}