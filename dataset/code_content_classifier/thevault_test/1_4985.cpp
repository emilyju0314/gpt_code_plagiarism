PP_Resource CreateDeviceContext(PP_Instance instance,
                                const struct PP_Size* size) {
  PP_Resource device_context;
  device_context = g_graphics_2d_interface->Create(instance, size, PP_FALSE);
  if (!device_context)
    return 0;
  return device_context;
}