void CEditorFileMonitor::OnFileMonitorChange(const SFileChangeInfo& rChange)
{
    CCryEditApp* app = CCryEditApp::instance();
    if (app == nullptr || app->IsExiting())
    {
        return;
    }

    // skip folders!
    if (QFileInfo(rChange.filename).isDir())
    {
        return;
    }

    // Process updated file.
    // Make file relative to PrimaryCD folder.
    QString filename = rChange.filename;

    // Make path relative to the the project directory
    AZ::IO::Path projectPath{ AZ::Utils::GetProjectPath() };
    AZ::IO::FixedMaxPath projectRelativeFilePath = AZ::IO::PathView(filename.toUtf8().constData()).LexicallyProximate(
        projectPath);

    if (!projectRelativeFilePath.empty())
    {
        AZ::IO::PathView ext = projectRelativeFilePath.Extension();

        // Check for File Monitor callback
        std::vector<SFileChangeCallback>::iterator iter;
        for (iter = m_vecFileChangeCallbacks.begin(); iter != m_vecFileChangeCallbacks.end(); ++iter)
        {
            SFileChangeCallback& sCallback = *iter;

            // We compare against length of callback string, so we get directory matches as well as full filenames
            if (sCallback.pListener)
            {
                if (sCallback.extension == "*" || AZ::IO::PathView(sCallback.extension.toUtf8().constData()) == ext)
                {
                    if (AZ::IO::PathView(sCallback.item.toUtf8().constData()) == projectRelativeFilePath)
                    {
                        sCallback.pListener->OnFileChange(qPrintable(projectRelativeFilePath.c_str()), IFileChangeListener::EChangeType(rChange.changeType));
                    }
                }
            }
        }

        // Set this flag to make sure that the viewport will update at least once,
        // so that the changes will be shown, even if the app does not have focus.
        CCryEditApp::instance()->ForceNextIdleProcessing();
    }
}