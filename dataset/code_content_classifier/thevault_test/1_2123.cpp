void BioGearsEngineTest::DiffusionClearanceExcretionTests(const std::string& rptDirectory)
{

  m_Logger->ResetLogFile(rptDirectory + "/DiffusionClearanceExcretionTests.log");
  // Set up our test report

  SETestReport testReport = SETestReport(m_Logger);

  SETestSuite& tsDistMass = testReport.CreateTestSuite();
  tsDistMass.SetName("DistributeMass");
  DistributeMass(tsDistMass);

  SETestSuite& ts1 = testReport.CreateTestSuite();
  ts1.SetName("PerfusionLimitedDiffusionTest");
  PerfusionLimitedDiffusionTest(ts1);

  //SETestSuite& ts5 = testReport.CreateTestSuite();
  //ts5.SetName("ActiveTransportTest");
  //ActiveTransportTest(ts5, rptDirectory);

  SETestSuite& ts6 = testReport.CreateTestSuite();
  ts6.SetName("InstantDiffusionTest");
  InstantDiffusionTest(ts6);

  //SETestSuite& ts7 = testReport.CreateTestSuite();
  //ts6.SetName("GenericClearanceTest");
  //GenericClearanceTest(ts7);

  //SETestSuite& ts8 = testReport.CreateTestSuite();
  //ts7.SetName("GenericExcretionTest");
  //GenericExcretionTest(ts8);

  //testReport.WriteFile(rptDirectory + "/GasCompartmentTest.xml");
}