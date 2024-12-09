TEST_F(ChromeBlacklistTrialTest, BlacklistDisabledRun) {
  // Set the beacons to enabled values.
  blacklist_registry_key_->WriteValue(blacklist::kBeaconState,
                                      blacklist::BLACKLIST_ENABLED);
  blacklist_registry_key_->WriteValue(blacklist::kBeaconVersion, L"Data");

  // Create the field trial with the blacklist disabled group.
  base::FieldTrialList field_trial_list(
    new metrics::SHA1EntropyProvider("test"));

  scoped_refptr<base::FieldTrial> trial(
    base::FieldTrialList::CreateFieldTrial(
      kBrowserBlacklistTrialName, kBrowserBlacklistTrialDisabledGroupName));

  // This setup code should now delete any existing blacklist beacons.
  InitializeChromeElf();

  // Ensure invalid values are returned to indicate that the beacon
  // values are indeed gone.
  ASSERT_EQ(blacklist::BLACKLIST_STATE_MAX, GetBlacklistState());
  ASSERT_EQ(base::string16(), GetBlacklistVersion());
}