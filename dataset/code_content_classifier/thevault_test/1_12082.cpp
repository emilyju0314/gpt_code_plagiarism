void RecoverFilesWindow::Rejected()
    {
        using namespace AZ::IO;
        FileIOBase* fileIo = FileIOBase::GetInstance();

        const size_t numFiles = m_files.size();
        AZStd::string backupFilename;
        for (size_t i = 0; i < numFiles; ++i)
        {
            backupFilename = m_files[i];
            AzFramework::StringFunc::Path::StripExtension(backupFilename);

            // Remove the recover file.
            if (fileIo->Remove(m_files[i].c_str()) == ResultCode::Error)
            {
                const AZStd::string errorMessage = AZStd::string::format("Cannot delete file '<b>%s</b>'.", m_files[i].c_str());
                CommandSystem::GetCommandManager()->AddError(errorMessage);
                AZ_Error("EMotionFX", false, errorMessage.c_str());
            }

            // Remove the backup file.
            if (fileIo->Remove(backupFilename.c_str()) == ResultCode::Error)
            {
                const AZStd::string errorMessage = AZStd::string::format("Cannot delete file '<b>%s</b>'.", backupFilename.c_str());
                CommandSystem::GetCommandManager()->AddError(errorMessage);
                AZ_Error("EMotionFX", false, errorMessage.c_str());
            }
        }
    }