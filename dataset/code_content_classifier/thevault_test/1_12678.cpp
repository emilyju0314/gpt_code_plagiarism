NPError	NPP_GetValue(NPP instance, NPPVariable variable, void *value)
{
  if(instance == NULL)
    return NPERR_INVALID_INSTANCE_ERROR;

  NPError rv = NPERR_NO_ERROR;

  if(instance == NULL)
    return NPERR_GENERIC_ERROR;

  Plugin * plugin = (Plugin *)instance->pdata;
  if(plugin == NULL)
    return NPERR_GENERIC_ERROR;

  switch (variable) {
  case NPPVpluginNameString:
    *((char **)value) = "NPVR";
    break;
  case NPPVpluginDescriptionString:
    *((char **)value) = "NPAPI plugin to expose fun VR devices.";
    break;
  case NPPVpluginScriptableNPObject:
    *(NPObject **)value = plugin->vr_object();
    break;
  default:
    rv = NPERR_GENERIC_ERROR;
  }

  return rv;
}