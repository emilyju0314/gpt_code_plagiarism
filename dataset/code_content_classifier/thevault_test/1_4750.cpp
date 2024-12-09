void WycheproofTest(const rapidjson::Document &root) {
  for (const rapidjson::Value& test_group : root["testGroups"].GetArray()) {
    const size_t key_size = test_group["keySize"].GetInt();
    if (!AesSivBoringSsl::IsValidKeySizeInBytes(key_size / 8)) {
      // Currently the key size is restricted to two 256-bit AES keys.
      continue;
    }
    for (const rapidjson::Value& test : test_group["tests"].GetArray()) {
      std::string comment = test["comment"].GetString();
      std::string key = WycheproofUtil::GetBytes(test["key"]);
      std::string msg = WycheproofUtil::GetBytes(test["msg"]);
      std::string ct = WycheproofUtil::GetBytes(test["ct"]);
      std::string aad = WycheproofUtil::GetBytes(test["aad"]);
      int id = test["tcId"].GetInt();
      std::string result = test["result"].GetString();
      auto cipher = std::move(AesSivBoringSsl::New(key).ValueOrDie());

      // Test encryption.
      // Encryption should always succeed since msg and aad are valid inputs.
      std::string encrypted =
          cipher->EncryptDeterministically(msg, aad).ValueOrDie();
      std::string encrypted_hex = test::HexEncode(encrypted);
      std::string ct_hex = test::HexEncode(ct);
      if (result == "valid" || result == "acceptable") {
        EXPECT_EQ(ct_hex, encrypted_hex)
            << "incorrect encryption: " << id << " " << comment;
      } else {
        EXPECT_NE(ct_hex, encrypted_hex)
            << "invalid encryption: " << id << " " << comment;
      }

      // Test decryption
      auto decrypted = cipher->DecryptDeterministically(ct, aad);
      if (decrypted.ok()) {
        if (result == "invalid") {
          ADD_FAILURE() << "decrypted invalid ciphertext:" << id;
        } else {
          EXPECT_EQ(test::HexEncode(msg),
                    test::HexEncode(decrypted.ValueOrDie()))
              << "incorrect decryption: " << id << " " << comment;
        }
      } else {
        EXPECT_NE(result, "valid")
            << "failed to decrypt: " << id << " " << comment;
      }
    }
  }
}