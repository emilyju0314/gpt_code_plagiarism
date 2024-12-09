void FoundStaticFile::AsyncLoadBest(const TLoadCallback& loadCallback)
{
   std::shared_ptr< IFileSystemProvider> pBestProvider = nullptr;
   std::filesystem::path bestPath;
   bool found = false;
   {
      std::lock_guard lock(m_bestMutex);
      pBestProvider = m_pBestProvider.lock();
      bestPath = m_bestPath;
      found = m_bestFound;
   }
   LoadStaticFile(m_pFileSystem.lock(), loadCallback, found, bestPath, pBestProvider.get());
}