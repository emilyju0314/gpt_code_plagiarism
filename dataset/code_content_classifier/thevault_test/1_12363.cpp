TEST_F(PlatformConfigurationUnitTests_OnePCHostFixture, GetScanFolderForFile_SubFolderFile_IsFound)
{
    using namespace AzToolsFramework::AssetSystem;
    using namespace AssetProcessor;

    m_config->AddScanFolder(ScanFolderInfo(m_tempPath.filePath("scanfolder1"), "ScanFolder1", "sf1", true, false, m_platforms), true); // a root folder that has watched subfolders, not recursive
    m_config->AddScanFolder(ScanFolderInfo(m_tempPath.filePath("scanfolder1/Editor"), "Editor ScanFolder", "sf2", false, true, m_platforms), true); // a child folder that exists within that scan folder.

    const ScanFolderInfo* info = m_config->GetScanFolderForFile(m_tempPath.filePath("scanfolder1/Editor/something.txt"));

    ASSERT_TRUE(info);
    EXPECT_STREQ(info->ScanPath().toUtf8().constData(), m_tempPath.filePath("scanfolder1/Editor").toUtf8().constData());
    EXPECT_STREQ(info->GetDisplayName().toUtf8().constData(), "Editor ScanFolder");
}