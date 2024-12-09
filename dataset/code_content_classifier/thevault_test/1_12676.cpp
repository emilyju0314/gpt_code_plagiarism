NPError NPP_Destroy (NPP instance, NPSavedData** save)
{
  if(instance == NULL)
    return NPERR_INVALID_INSTANCE_ERROR;

  NPError rv = NPERR_NO_ERROR;

  Plugin * pPlugin = (Plugin *)instance->pdata;
  if(pPlugin != NULL) {
    pPlugin->Destroy();
    delete pPlugin;
    instance->pdata = NULL;
  }
  return rv;
}