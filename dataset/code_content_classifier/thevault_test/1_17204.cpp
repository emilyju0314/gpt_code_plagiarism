TEST_F(NSSCertDatabaseChromeOSTest, ListModules) {
  std::vector<crypto::ScopedPK11Slot> modules_1;
  std::vector<crypto::ScopedPK11Slot> modules_2;

  db_1_->ListModules(&modules_1, false /* need_rw */);
  db_2_->ListModules(&modules_2, false /* need_rw */);

  bool found_1 = false;
  for (std::vector<crypto::ScopedPK11Slot>::iterator it = modules_1.begin();
       it != modules_1.end(); ++it) {
    EXPECT_NE(db_2_->GetPublicSlot().get(), (*it).get());
    if ((*it).get() == db_1_->GetPublicSlot().get())
      found_1 = true;
  }
  EXPECT_TRUE(found_1);

  bool found_2 = false;
  for (std::vector<crypto::ScopedPK11Slot>::iterator it = modules_2.begin();
       it != modules_2.end(); ++it) {
    EXPECT_NE(db_1_->GetPublicSlot().get(), (*it).get());
    if ((*it).get() == db_2_->GetPublicSlot().get())
      found_2 = true;
  }
  EXPECT_TRUE(found_2);
}