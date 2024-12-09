NPError NPP_New(NPMIMEType pluginType, NPP instance, uint16_t mode, 
	int16_t argc, char* argn[], char* argv[], NPSavedData* saved)
{
   Plugin* plugin = new(std::nothrow) Plugin(instance, &NPNFuncs);
   if(!plugin)
      return NPERR_OUT_OF_MEMORY_ERROR;
   
   instance->pdata = plugin;
   return NPERR_NO_ERROR;
}