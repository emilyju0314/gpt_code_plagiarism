TEST(LangModelTest, AddACharacter) {
  constexpr char kTestString[] = "Simple ASCII string to encode !@#$%&";
  constexpr char kTestStringRupees[] = "ASCII string with Rupee symbol ₹";
  // Setup the arguments.
  std::string script_dir = LANGDATA_DIR;
  std::string eng_dir = file::JoinPath(script_dir, "eng");
  std::string unicharset_path = TestDataNameToPath("eng_beam.unicharset");
  UNICHARSET unicharset;
  EXPECT_TRUE(unicharset.load_from_file(unicharset_path.c_str()));
  std::string version_str = "TestVersion";
  file::MakeTmpdir();
  std::string output_dir = FLAGS_test_tmpdir;
  LOG(INFO) << "Output dir=" << output_dir << "\n";
  std::string lang1 = "eng";
  bool pass_through_recoder = false;
  // If these reads fail, we get a warning message and an empty list of words.
  std::vector<std::string> words = split(ReadFile(file::JoinPath(eng_dir, "eng.wordlist")), '\n');
  EXPECT_GT(words.size(), 0);
  std::vector<std::string> puncs = split(ReadFile(file::JoinPath(eng_dir, "eng.punc")), '\n');
  EXPECT_GT(puncs.size(), 0);
  std::vector<std::string> numbers = split(ReadFile(file::JoinPath(eng_dir, "eng.numbers")), '\n');
  EXPECT_GT(numbers.size(), 0);
  bool lang_is_rtl = false;
  // Generate the traineddata file.
  EXPECT_EQ(0, CombineLangModel(unicharset, script_dir, version_str, output_dir, lang1,
                                pass_through_recoder, words, puncs, numbers, lang_is_rtl, nullptr,
                                nullptr));
  // Init a trainer with it, and encode kTestString.
  std::string traineddata1 = file::JoinPath(output_dir, lang1, lang1) + ".traineddata";
  LSTMTrainer trainer1;
  trainer1.InitCharSet(traineddata1);
  std::vector<int> labels1;
  EXPECT_TRUE(trainer1.EncodeString(kTestString, &labels1));
  std::string test1_decoded = trainer1.DecodeLabels(labels1);
  std::string test1_str(&test1_decoded[0], test1_decoded.length());
  LOG(INFO) << "Labels1=" << test1_str << "\n";

  // Add a new character to the unicharset and try again.
  int size_before = unicharset.size();
  unicharset.unichar_insert("₹");
  SetupBasicProperties(/*report_errors*/ true, /*decompose (NFD)*/ false, &unicharset);
  EXPECT_EQ(size_before + 1, unicharset.size());
  // Generate the traineddata file.
  std::string lang2 = "extended";
  EXPECT_EQ(EXIT_SUCCESS, CombineLangModel(unicharset, script_dir, version_str, output_dir, lang2,
                                           pass_through_recoder, words, puncs, numbers, lang_is_rtl,
                                           nullptr, nullptr));
  // Init a trainer with it, and encode kTestString.
  std::string traineddata2 = file::JoinPath(output_dir, lang2, lang2) + ".traineddata";
  LSTMTrainer trainer2;
  trainer2.InitCharSet(traineddata2);
  std::vector<int> labels2;
  EXPECT_TRUE(trainer2.EncodeString(kTestString, &labels2));
  std::string test2_decoded = trainer2.DecodeLabels(labels2);
  std::string test2_str(&test2_decoded[0], test2_decoded.length());
  LOG(INFO) << "Labels2=" << test2_str << "\n";
  // encode kTestStringRupees.
  std::vector<int> labels3;
  EXPECT_TRUE(trainer2.EncodeString(kTestStringRupees, &labels3));
  std::string test3_decoded = trainer2.DecodeLabels(labels3);
  std::string test3_str(&test3_decoded[0], test3_decoded.length());
  LOG(INFO) << "labels3=" << test3_str << "\n";
  // Copy labels1 to a std::vector, renumbering the null char to match trainer2.
  // Since Tensor Flow's CTC implementation insists on having the null be the
  // last label, and we want to be compatible, null has to be renumbered when
  // we add a class.
  int null1 = trainer1.null_char();
  int null2 = trainer2.null_char();
  EXPECT_EQ(null1 + 1, null2);
  std::vector<int> labels1_v(labels1.size());
  for (unsigned i = 0; i < labels1.size(); ++i) {
    if (labels1[i] == null1) {
      labels1_v[i] = null2;
    } else {
      labels1_v[i] = labels1[i];
    }
  }
  EXPECT_THAT(labels1_v, testing::ElementsAreArray(&labels2[0], labels2.size()));
  // To make sure we we are not cheating somehow, we can now encode the Rupee
  // symbol, which we could not do before.
  EXPECT_FALSE(trainer1.EncodeString(kTestStringRupees, &labels1));
  EXPECT_TRUE(trainer2.EncodeString(kTestStringRupees, &labels2));
}