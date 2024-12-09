static const TTaskFactory GetTaskFactory(const std::string& taskFactoryKey)
{
   const auto& factoryMap = GetTaskFactoryMap();
   auto found = factoryMap.find(taskFactoryKey);
   if (found != factoryMap.end())
   {
      return found->second;
   }
   return nullptr;
}