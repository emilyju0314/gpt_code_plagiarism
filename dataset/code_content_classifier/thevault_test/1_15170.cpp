void FoundDynamicFile::AsyncSaveAll(const TFileData& data, const TPassableCallback& callback)
{
   auto pFileSystem = m_pFileSystem.lock();
   if (nullptr == pFileSystem)
   {
      return;
   }
   for (const auto& iter: m_arrayProvider)
   {
      auto pProvider = iter.lock();
      if (nullptr != pProvider)
      {
         auto path(m_path);
         pFileSystem->AddAsyncTask([=](){
            pProvider->AsyncSaveDynamicFile(path, data, callback);
         });
      }
   }

   return;
}