bool CLevelFileDialog::CheckLevelFolder(const QString folder, QStringList* levelFiles)
{
    CFileEnum fileEnum;
    QFileInfo fileData;
    bool bIsLevelFolder = false;

    for (bool bFoundFile = fileEnum.StartEnumeration(folder, "*", &fileData);
         bFoundFile; bFoundFile = fileEnum.GetNextFile(&fileData))
    {
        const QString fileName = fileData.fileName();

        if (!fileData.isDir())
        {
            QString ext = "." + Path::GetExt(fileName);

            const char* defaultExtension = EditorUtils::LevelFile::GetDefaultFileExtension();

            if (ext == defaultExtension)
            {
                bIsLevelFolder = true;

                if (levelFiles)
                {
                    levelFiles->push_back(fileName);
                }
            }
        }
    }

    return bIsLevelFolder;
}