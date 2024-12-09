TEST_F(ChromeBlacklistTrialTest, DefaultRun) {
  // Set some dummy values as beacons.
  blacklist_registry_key_->WriteValue(blacklist::kBeaconState,
                                      blacklist::BLACKLIST_DISABLED);
  blacklist_registry_key_->WriteValue(blacklist::kBeaconVersion, L"Data");

  // This setup code should result in the default group, which should have
  // the blacklist set up.
  InitializeChromeElf();

  // Ensure the beacon values are now correct, indicating the
  // blacklist beacon was setup.
  ASSERT_EQ(blacklist::BLACKLIST_ENABLED, GetBlacklistState());
  chrome::VersionInfo version_info;
  base::string16 version(base::UTF8ToUTF16(version_info.Version()));
  ASSERT_EQ(version, GetBlacklistVersion());
}