TEST_F(ArchiveTestFixture, TestArchivePackImmediateReading)
    {
        // the strategy is to create a archive file similar to how the level system does
        // one which contains subfolders
        // and a file inside that subfolder
        // to be successful, it must be possible to write that pack, close it, then open it via Archive
        // and be able to IMMEDIATELY
        // * read the file in the subfolder
        // * enumerate the folders (including that subfolder) even though they are 'virtual', not real folders on physical media
        // * all of the above even though the mount point for the archive is @products@ wheras the physical pack lives in @usercache@
        // finally, we're going to repeat the above test but with files mounted with subfolders
        // so for example, the pack will contain levelinfo.xml at the root of it
        // but it will be mounted at a subfolder (levels/mylevel).
        // this must cause FindNext and Open to work for levels/mylevel/levelinfo.xml.

        constexpr const char* testArchivePath_withSubfolders = "@usercache@/immediate.pak";
        constexpr const char* testArchivePath_withMountPoint = "@usercache@/levels/test/flatarchive.pak";

        AZ::IO::FileIOBase* fileIo = AZ::IO::FileIOBase::GetInstance();
        ASSERT_NE(nullptr, fileIo);

        AZ::IO::IArchive* archive = AZ::Interface<AZ::IO::IArchive>::Get();
        ASSERT_NE(nullptr, archive);

        auto console = AZ::Interface<AZ::IConsole>::Get();
        ASSERT_NE(nullptr, console);

        constexpr AZStd::string_view dataString = "HELLO WORLD"; // other unit tests make sure writing and reading is working, so don't test that here


        // delete test files in case they already exist
        archive->ClosePack(testArchivePath_withSubfolders);
        archive->ClosePack(testArchivePath_withMountPoint);
        fileIo->Remove(testArchivePath_withSubfolders);
        fileIo->Remove(testArchivePath_withMountPoint);
        fileIo->CreatePath("@usercache@/levels/test");


        AZStd::intrusive_ptr<AZ::IO::INestedArchive> pArchive = archive->OpenArchive(testArchivePath_withSubfolders, {}, AZ::IO::INestedArchive::FLAGS_CREATE_NEW);
        EXPECT_NE(nullptr, pArchive);
        EXPECT_EQ(0, pArchive->UpdateFile("levels\\mylevel\\levelinfo.xml", dataString.data(), dataString.size(), AZ::IO::INestedArchive::METHOD_COMPRESS, AZ::IO::INestedArchive::LEVEL_FASTEST));
        pArchive.reset();
        EXPECT_TRUE(IsPackValid(testArchivePath_withSubfolders));

        EXPECT_TRUE(archive->OpenPack("@products@", testArchivePath_withSubfolders));
        // ---- BARRAGE OF TESTS
        EXPECT_TRUE(archive->IsFileExist("levels\\mylevel\\levelinfo.xml"));
        EXPECT_TRUE(archive->IsFileExist("levels//mylevel//levelinfo.xml"));

        bool found_mylevel_folder = false;
        AZ::IO::ArchiveFileIterator handle = archive->FindFirst("levels\\*");

        EXPECT_TRUE(static_cast<bool>(handle));
        if (handle)
        {
            do
            {
                if ((handle.m_fileDesc.nAttrib & AZ::IO::FileDesc::Attribute::Subdirectory) == AZ::IO::FileDesc::Attribute::Subdirectory)
                {
                    if (azstricmp(handle.m_filename.data(), "mylevel") == 0)
                    {
                        found_mylevel_folder = true;
                    }
                }
                else
                {
                    EXPECT_STRCASENE("levelinfo.xml", handle.m_filename.data()); // you may not find files inside the archive in this folder.
                }
            } while (handle = archive->FindNext(handle));

            archive->FindClose(handle);
        }

        EXPECT_TRUE(found_mylevel_folder);

        bool found_mylevel_file = false;

        handle = archive->FindFirst("levels\\mylevel\\*");

        EXPECT_TRUE(static_cast<bool>(handle));
        if (handle)
        {
            do
            {
                if ((handle.m_fileDesc.nAttrib & AZ::IO::FileDesc::Attribute::Subdirectory) != AZ::IO::FileDesc::Attribute::Subdirectory)
                {
                    if (azstricmp(handle.m_filename.data(), "levelinfo.xml") == 0)
                    {
                        found_mylevel_file = true;
                    }
                }
                else
                {
                    EXPECT_STRCASENE("mylevel", handle.m_filename.data()); // you may not find the level subfolder here since we're in the subfolder already
                    EXPECT_STRCASENE("levels\\mylevel", handle.m_filename.data());
                    EXPECT_STRCASENE("levels//mylevel", handle.m_filename.data());
                }
            } while (handle = archive->FindNext(handle));

            archive->FindClose(handle);
        }

        EXPECT_TRUE(found_mylevel_file);

        // now test clean-up
        archive->ClosePack(testArchivePath_withSubfolders);
        fileIo->Remove(testArchivePath_withSubfolders);

        EXPECT_FALSE(archive->IsFileExist("levels\\mylevel\\levelinfo.xml"));
        EXPECT_FALSE(archive->IsFileExist("levels//mylevel//levelinfo.xml"));

        // Once the archive has been deleted it should no longer be searched
        CVarIntValueScope previousLocationPriority{ *console, "sys_pakPriority" };
        console->PerformCommand("sys_PakPriority", { AZ::CVarFixedString::format("%d", aznumeric_cast<int>(AZ::IO::FileSearchPriority::PakOnly)) });

        handle = archive->FindFirst("levels\\*");
        EXPECT_FALSE(static_cast<bool>(handle));
    }