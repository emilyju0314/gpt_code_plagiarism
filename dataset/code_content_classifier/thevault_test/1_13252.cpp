TEST_F(SafeBrowsingBlockingPageTest, MalwareReportsTransitionDisabled) {
  // The old pref is enabled.
  Profile* profile = Profile::FromBrowserContext(
      web_contents()->GetBrowserContext());
  profile->GetPrefs()->SetBoolean(prefs::kSafeBrowsingReportingEnabled, true);

  // Start a load.
  controller().LoadURL(GURL(kBadURL), content::Referrer(),
                             content::PAGE_TRANSITION_TYPED, std::string());

  // Simulate the load causing a safe browsing interstitial to be shown.
  ShowInterstitial(false, kBadURL);
  SafeBrowsingBlockingPage* sb_interstitial =
      GetSafeBrowsingBlockingPage();
  ASSERT_TRUE(sb_interstitial);

  base::RunLoop().RunUntilIdle();

  // At this point, nothing should have changed yet.
  EXPECT_FALSE(profile->GetPrefs()->GetBoolean(
      prefs::kSafeBrowsingExtendedReportingEnabled));

  // Simulate the user uncheck the report agreement checkbox.
  sb_interstitial->SetReportingPreference(false);

  ProceedThroughInterstitial(sb_interstitial);

  // The new pref is turned off.
  EXPECT_FALSE(profile->GetPrefs()->GetBoolean(
      prefs::kSafeBrowsingExtendedReportingEnabled));
  EXPECT_FALSE(profile->GetPrefs()->GetBoolean(
      prefs::kSafeBrowsingReportingEnabled));
  EXPECT_FALSE(profile->GetPrefs()->GetBoolean(
      prefs::kSafeBrowsingDownloadFeedbackEnabled));
}