TEST(ProcCpuInfo, GetProcInfo) {
  ProcCpuInfo proc_info;
  EXPECT_TRUE(proc_info.LoadFromSystem());

  int out_cpus = 0;
  EXPECT_TRUE(proc_info.GetNumCpus(&out_cpus));
  LOG(LS_INFO) << "GetNumCpus: " << out_cpus;
  EXPECT_GT(out_cpus, 0);

  int out_cpus_phys = 0;
  EXPECT_TRUE(proc_info.GetNumPhysicalCpus(&out_cpus_phys));
  LOG(LS_INFO) << "GetNumPhysicalCpus: " << out_cpus_phys;
  EXPECT_GT(out_cpus_phys, 0);
  EXPECT_LE(out_cpus_phys, out_cpus);

  int out_family = 0;
  EXPECT_TRUE(proc_info.GetCpuFamily(&out_family));
  LOG(LS_INFO) << "cpu family: " << out_family;
  EXPECT_GE(out_family, 4);

#if defined(__arm__)
  std::string out_processor;
  EXPECT_TRUE(proc_info.GetSectionStringValue(0, "Processor", &out_processor));
  LOG(LS_INFO) << "Processor: " << out_processor;
  EXPECT_NE(std::string::npos, out_processor.find("ARM"));

  // Most other info, such as model, stepping, vendor, etc.
  // is missing on ARM systems.
#else
  int out_model = 0;
  EXPECT_TRUE(proc_info.GetSectionIntValue(0, "model", &out_model));
  LOG(LS_INFO) << "model: " << out_model;

  int out_stepping = 0;
  EXPECT_TRUE(proc_info.GetSectionIntValue(0, "stepping", &out_stepping));
  LOG(LS_INFO) << "stepping: " << out_stepping;

  int out_processor = 0;
  EXPECT_TRUE(proc_info.GetSectionIntValue(0, "processor", &out_processor));
  LOG(LS_INFO) << "processor: " << out_processor;
  EXPECT_EQ(0, out_processor);

  std::string out_str;
  EXPECT_TRUE(proc_info.GetSectionStringValue(0, "vendor_id", &out_str));
  LOG(LS_INFO) << "vendor_id: " << out_str;
  EXPECT_FALSE(out_str.empty());
#endif
}