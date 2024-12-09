bool CLevelFileDialog::ValidateLevelPath(const QString& levelPath) const
{
    if (levelPath.isEmpty() || Path::GetExt(levelPath) != "")
    {
        return false;
    }

    // Split path
    QStringList splittedPath = levelPath.split(QRegularExpression(QStringLiteral(R"([\\/])")), Qt::SkipEmptyParts);

    // This shouldn't happen, but be careful
    if (splittedPath.empty())
    {
        return false;
    }

    // Make sure that no folder before the last in the name contains a level
    if (splittedPath.size() > 1)
    {
        QString currentPath = (Path::GetEditingGameDataFolder() + "/" + kLevelsFolder).c_str();
        for (size_t i = 0; i < splittedPath.size() - 1; ++i)
        {
            currentPath += "/" + splittedPath[static_cast<int>(i)];

            if (CFileUtil::FileExists(currentPath) || CheckLevelFolder(currentPath))
            {
                return false;
            }
        }
    }

    return true;
}