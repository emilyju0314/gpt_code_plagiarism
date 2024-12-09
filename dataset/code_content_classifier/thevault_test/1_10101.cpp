TEST_F(HardwareBeforeStreamingTest,
       GetRecordingDeviceNameRetrievesDeviceNames) {
  char device_name[128] = {0};
  char guid_name[128] = {0};

#ifdef _WIN32
  EXPECT_EQ(0, voe_hardware_->GetRecordingDeviceName(
      -1, device_name, guid_name));
  EXPECT_GT(strlen(device_name), 0u) << kNoDevicesErrorMessage;
  device_name[0] = '\0';

  EXPECT_EQ(0, voe_hardware_->GetPlayoutDeviceName(
      -1, device_name, guid_name));
  EXPECT_GT(strlen(device_name), 0u) << kNoDevicesErrorMessage;

#else
  EXPECT_EQ(0, voe_hardware_->GetRecordingDeviceName(
      0, device_name, guid_name));
  EXPECT_GT(strlen(device_name), 0u) << kNoDevicesErrorMessage;
  device_name[0] = '\0';

  EXPECT_EQ(0, voe_hardware_->GetPlayoutDeviceName(
      0, device_name, guid_name));
  EXPECT_GT(strlen(device_name), 0u) << kNoDevicesErrorMessage;
#endif  // !WIN32
}