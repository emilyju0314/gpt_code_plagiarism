TEST_F(SafeBrowsingBlockingPageTest, MalwareReportsTransitionEnabled) {
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

  ProceedThroughInterstitial(sb_interstitial);

  // Since the user has proceeded without changing the checkbox, the new pref
  // has been updated.
  EXPECT_TRUE(profile->GetPrefs()->GetBoolean(
      prefs::kSafeBrowsingExtendedReportingEnabled));
}