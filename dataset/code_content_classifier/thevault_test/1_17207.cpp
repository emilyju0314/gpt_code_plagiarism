TEST_F(NSSCertDatabaseChromeOSTest, NoCrashIfShutdownBeforeDoneOnWorkerPool) {
  ScopedCERTCertificateList certlist;
  db_1_->ListCerts(base::BindOnce(&SwapCertLists, base::Unretained(&certlist)));
  EXPECT_EQ(0U, certlist.size());

  db_1_.reset();

  RunUntilIdle();

  EXPECT_LT(0U, certlist.size());
}