TEST_F(RCJobTest, CopyCompiledAssets_MissingInputFile_Fails_DoesNotAssert_DoesNotAlterCache)
    {
        BuilderParams builderParams;
        ProcessJobResponse response;
        response.m_resultCode = ProcessJobResult_Success;
        // set only the output path, but not the input path:
        builderParams.m_processJobRequest.m_tempDirPath = m_data->m_absolutePathToTempInputFolder.c_str(); // input working scratch space folder
        builderParams.m_finalOutputDir = QString::fromUtf8(m_data->m_absolutePathToTempOutputFolder.c_str());  // output folder in the 'cache'
        response.m_resultCode = ProcessJobResult_Success;
        response.m_outputProducts.push_back({ "FiLe1.TxT" }); // make sure that there is at least one product so that it doesn't early out.
        UnitTestUtils::CreateDummyFile(QDir(m_data->m_absolutePathToTempInputFolder.c_str()).absoluteFilePath("FiLe1.TxT"), "output of file 1");
        response.m_outputProducts.push_back({ "FiLe2.txt" });
        // note well that we create the first file but we don't acutally create the second one, so it is missing.

        EXPECT_FALSE(RCJob::CopyCompiledAssets(builderParams, response));
        EXPECT_EQ(m_errorAbsorber->m_numAssertsAbsorbed, 0);
        EXPECT_EQ(m_errorAbsorber->m_numErrorsAbsorbed, 1);

        // no notifies should be hit since the operation should not have been attempted at all.
        ASSERT_EQ(m_data->m_notifyTracker.m_capturedStartPaths.size(), 0);
        ASSERT_EQ(m_data->m_notifyTracker.m_capturedStopPaths.size(), 0);
        QString expectedFinalOutputPath = QDir(QString::fromUtf8(m_data->m_absolutePathToTempOutputFolder.c_str())).absoluteFilePath("file1.txt");
        EXPECT_FALSE(QFile::exists(expectedFinalOutputPath));
    }