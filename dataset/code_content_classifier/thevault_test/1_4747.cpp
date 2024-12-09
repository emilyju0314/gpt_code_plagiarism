TEST(AesSivBoringSslTest, testEncryptDecryptKeySizes) {
  std::string keymaterial(test::HexDecodeOrDie(
      "198371900187498172316311acf81d238ff7619873a61983d619c87b63a1987f"
      "987131819803719b847126381cd763871638aa71638176328761287361231321"
      "812731321de508761437195ff231765aa4913219873ac6918639816312130011"
      "abc900bba11400187984719827431246bbab1231eb4145215ff7141436616beb"
      "9817298148712fed3aab61000ff123313e"));
  for (int keysize = 0; keysize <= keymaterial.size(); ++keysize){
    std::string key = std::string(keymaterial, 0, keysize);
    auto cipher = AesSivBoringSsl::New(key);
    if (keysize == 64) {
      EXPECT_TRUE(cipher.ok());
    } else {
      EXPECT_FALSE(cipher.ok()) << "Accepted invalid key size:" << keysize;
    }
  }
}