AzToolsFramework::SourceControlResponseCallback GetConfigurationSaveCallback(
            AZStd::string configurationPayload, AZStd::function<void(bool)> postSaveCallback)
        {
            return [payloadBuffer = AZStd::move(configurationPayload), postSaveCB = AZStd::move(postSaveCallback)]
            (bool, const AzToolsFramework::SourceControlFileInfo& info)
            {
                // Save PhysX configuration.
                if (info.IsLockedByOther())
                {
                    AZ_Warning("PhysXEditor", false, R"(The file "%s" already exclusively opened by another user)", info.m_filePath.c_str());
                    return;
                }
                else if (info.IsReadOnly() && AZ::IO::SystemFile::Exists(info.m_filePath.c_str()))
                {
                    AZ_Warning("PhysXEditor", false, R"(The file "%s" is read-only)", info.m_filePath.c_str());
                    return;
                }

                bool saved = false;
                constexpr auto configurationMode
                    = AZ::IO::SystemFile::SF_OPEN_CREATE
                    | AZ::IO::SystemFile::SF_OPEN_CREATE_PATH
                    | AZ::IO::SystemFile::SF_OPEN_WRITE_ONLY;
                if (AZ::IO::SystemFile outputFile; outputFile.Open(info.m_filePath.c_str(), configurationMode))
                {
                    saved = outputFile.Write(payloadBuffer.data(), payloadBuffer.size()) == payloadBuffer.size();
                }

                AZ_Warning("PhysXEditor", saved, "Failed to save PhysX configuration");
                if (postSaveCB)
                {
                    postSaveCB(saved);
                }
            };
        }