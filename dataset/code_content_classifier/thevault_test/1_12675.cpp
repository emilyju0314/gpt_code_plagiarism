NPError NPP_New(NPMIMEType pluginType,
                NPP instance,
                uint16_t mode,
                int16_t argc,
                char* argn[],
                char* argv[],
                NPSavedData* saved)
{
  if(instance == NULL)
    return NPERR_INVALID_INSTANCE_ERROR;

#ifdef XP_MACOSX
  // Setting Core Graphics drawing is required for the plugin to load in
  // modern browsers, because the default QuickDraw mode is no longer
  // supported. We don't actually care whether setting this succeeds, because
  // we don't draw.
  NPNFuncs.setvalue(instance, NPPVpluginDrawingModel,
                    (void*)NPDrawingModelCoreGraphics);
  // http://crbug.com/139816 suggests that the Cocoa event model will soon be
  // required too.
  NPNFuncs.setvalue(instance, NPPVpluginEventModel, (void*) NPEventModelCocoa);
#endif

  NPError rv = NPERR_NO_ERROR;

  Plugin * pPlugin = new Plugin(instance);
  if(pPlugin == NULL)
    return NPERR_OUT_OF_MEMORY_ERROR;

  instance->pdata = (void *)pPlugin;
  return rv;
}