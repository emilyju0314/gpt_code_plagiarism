NPError NPP_SetWindow (NPP instance, NPWindow* pNPWindow)
{
  if(instance == NULL)
    return NPERR_INVALID_INSTANCE_ERROR;

  if(pNPWindow == NULL)
    return NPERR_GENERIC_ERROR;

  Plugin * pPlugin = (Plugin *)instance->pdata;

  if(pPlugin == NULL)
    return NPERR_GENERIC_ERROR;

  if(!pPlugin->is_initialized()) {
    // window just created
    if(!pPlugin->Init(pNPWindow)) {
      delete pPlugin;
      pPlugin = NULL;
      instance->pdata = NULL;
      return NPERR_MODULE_LOAD_FAILED_ERROR;
    }
  }

  return NPERR_NO_ERROR;
}