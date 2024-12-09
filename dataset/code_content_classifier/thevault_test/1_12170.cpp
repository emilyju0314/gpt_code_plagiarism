void AssetImporterManager::reject()
{
    m_pathMap.clear();
    m_destinationRootDirectory = "";
    Q_EMIT StopAssetImporter();
}