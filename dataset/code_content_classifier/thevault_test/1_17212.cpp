TEST_F(WMITest, TestLaunchProcess) {
  int pid = 0;
  bool result = WmiLaunchProcess(L"cmd.exe /c echo excelent!", &pid);
  EXPECT_TRUE(result);
  EXPECT_GT(pid, 0);
}