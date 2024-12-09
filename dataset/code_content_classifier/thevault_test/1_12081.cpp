void RecoverFilesWindow::Accepted()
    {
        using namespace AZ::IO;
        FileIOBase* fileIo = FileIOBase::GetInstance();

        AZStd::string backupFilename;
        AZStd::string originalFilename;

        const int numRows = m_tableWidget->rowCount();
        for (int i = 0; i < numRows; ++i)
        {
            QWidget*            widget      = m_tableWidget->cellWidget(i, 0);
            QCheckBox*          checkbox    = static_cast<QCheckBox*>(widget);
            QTableWidgetItem*   item        = m_tableWidget->item(i, 2);
            const int32         filesIndex  = item->data(Qt::UserRole).toInt();

            // Get the recover and the backup filenames
            const AZStd::string& recoverFilename = m_files[filesIndex];
            
            backupFilename = recoverFilename;
            AzFramework::StringFunc::Path::StripExtension(backupFilename);

            // Add the file if the checkbox is checked.
            if (checkbox->isChecked())
            {
                // If the backup file doesn't exist anymore, we continue to the next file.
                if (!fileIo->Exists(backupFilename.c_str()))
                {
                    continue;
                }

                // Read the original filename from the .recover json file and check if it is valid.
                originalFilename = GetOriginalFilenameFromRecoverFile(backupFilename.c_str());
                if (originalFilename.empty())
                {
                    continue;
                }

                // Remove the original file.
                // This is needed because if the file still sexists, it's not possible to copy the backup file over.
                if (fileIo->Exists(originalFilename.c_str()))
                {
                    if (fileIo->Remove(originalFilename.c_str()) == ResultCode::Error)
                    {
                        const AZStd::string errorMessage = AZStd::string::format("Cannot delete file '<b>%s</b>'.", originalFilename.c_str());
                        CommandSystem::GetCommandManager()->AddError(errorMessage);
                        AZ_Error("EMotionFX", false, errorMessage.c_str());
                    }
                }

                // Copy the backup file over to the original file path.
                if (fileIo->Copy(backupFilename.c_str(), originalFilename.c_str()) == ResultCode::Error)
                {
                    const AZStd::string errorMessage = AZStd::string::format("Cannot copy file from '<b>%s</b>' to '<b>%s</b>'.", backupFilename.c_str(), originalFilename.c_str());
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

                // Remove the recover file.
                if (fileIo->Remove(recoverFilename.c_str()) == ResultCode::Error)
                {
                    const AZStd::string errorMessage = AZStd::string::format("Cannot delete file '<b>%s</b>'.", recoverFilename.c_str());
                    CommandSystem::GetCommandManager()->AddError(errorMessage);
                    AZ_Error("EMotionFX", false, errorMessage.c_str());
                }
            }
            else
            {
                // Remove the recover file.
                if (fileIo->Remove(recoverFilename.c_str()) == ResultCode::Error)
                {
                    const AZStd::string errorMessage = AZStd::string::format("Cannot delete file '<b>%s</b>'.", recoverFilename.c_str());
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
    }