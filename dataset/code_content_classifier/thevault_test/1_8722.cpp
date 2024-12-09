NPError NPP_Destroy(NPP instance, NPSavedData** save)
{
   if(!instance)
      return NPERR_INVALID_INSTANCE_ERROR;
   
   Plugin* plugin = static_cast<Plugin*>(instance->pdata);
   delete plugin;
   instance->pdata = NULL;
   return NPERR_NO_ERROR;
}