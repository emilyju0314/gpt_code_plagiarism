const bool FoundStaticFolder::GetExist() const
{
   std::lock_guard lock(m_foundMutex);
   return m_found;
}