void FoundDynamicFile::AsyncLoadBest(const TLoadCallback& loadCallback)
{
   std::shared_ptr< IFileSystemProvider > pProvider;
   for (const auto& iter: m_arrayProvider)
   {
      auto pPointer = iter.lock();
      if (nullptr != pPointer)
      {
         if (true == pPointer->QueryDynamicFile(m_path))
         {
            pProvider = pPointer;
         }
      }
   }
   auto pFileSystem = m_pFileSystem.lock();
   if ((nullptr != pProvider) && (nullptr != pFileSystem))
   {
      auto path(m_path);
      pFileSystem->AddAsyncTask([=](){
         pProvider->AsyncLoadDynamicFile(loadCallback, path);
      });
   } 
   else
   {
      if (nullptr != loadCallback)
      {
         loadCallback(false, nullptr);
      }
   }
}