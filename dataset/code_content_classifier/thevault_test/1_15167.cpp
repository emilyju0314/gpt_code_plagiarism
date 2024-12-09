const FileSystem::TFileData FileSystem::SyncReadFile(const std::filesystem::path& absolutePath)
{
   std::ifstream inFile(absolutePath, std::ios::in | std::ios::binary | std::ios::ate);
   
   if ((!inFile) || (!inFile.good()))
   {
      throw std::exception("SyncReadFile");
   }

   std::streampos len = inFile.tellg();
   if (!inFile)
   {
      throw std::exception("SyncReadFile");
   }

   auto pBlob = std::make_shared< std::vector< uint8_t > >();
   pBlob->resize(size_t(len));

   inFile.seekg(0, std::ios::beg);
   if (!inFile)
   {
      throw std::exception("SyncReadFile");
   }

   inFile.read(reinterpret_cast<char*>(pBlob->data()), len);
   if (!inFile)
   {
      throw std::exception("SyncReadFile");
   }

   inFile.close();

   return pBlob;
}