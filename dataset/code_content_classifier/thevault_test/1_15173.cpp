const bool FoundStaticFile::GetExist() const
{
   std::lock_guard lock(m_bestMutex);
   return m_bestFound;
}