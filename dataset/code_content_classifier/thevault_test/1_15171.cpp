void FoundDynamicFile::AsyncDeleteAll(const TPassableCallback& callback)
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
            pProvider->AsyncDeleteDynamicFile(path, callback);
         });
      }
   }

   return;
}