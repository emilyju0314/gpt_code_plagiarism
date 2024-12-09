void CHexEditDoc::close_file()
{
	// Close file if it was opened successfully
	if (pfile1_ != NULL)
	{
		pfile1_->Close();
		delete pfile1_;
		pfile1_ = NULL;
	}

	if (pthread2_ != NULL && pfile2_ != NULL)
	{
		pfile2_->Close();
		delete pfile2_;
		pfile2_ = NULL;
	}
	if (pthread3_ != NULL && pfile3_ != NULL)
	{
		pfile3_->Close();
		delete pfile3_;
		pfile3_ = NULL;
	}
	if (pthread4_ != NULL && pfile4_ != NULL)
	{
		CloseCompFile();
	}
	if (pthread5_ != NULL && pfile5_ != NULL)
	{
		pfile5_->Close();
		delete pfile5_;
		pfile5_ = NULL;
	}
	if (pthread6_ != NULL && pfile6_ != NULL)
	{
		pfile6_->Close();
		delete pfile6_;
		pfile6_ = NULL;
	}
}