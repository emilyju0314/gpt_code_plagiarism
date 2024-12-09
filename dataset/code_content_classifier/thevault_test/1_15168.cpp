const bool FoundDynamicFile::GetExist() const
{
   for (const auto& iter: m_arrayProvider)
   {
      auto pPointer = iter.lock();
      if (nullptr != pPointer)
      {
         if (true == pPointer->QueryDynamicFile(m_path))
         {
            return true;
         }
      }
   }
   return false;
}