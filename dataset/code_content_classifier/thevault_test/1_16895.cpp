__attribute__ ((constructor))
void loaderInit()
{
    pspKernelSetKernelPC();
    pspSdkInstallNoDeviceCheckPatch();
	pspSdkInstallNoPlainModuleCheckPatch();
	pspSdkInstallKernelLoadModulePatch();
    pspDebugInstallKprintfHandler(NULL);

	pspDebugInstallErrorHandler(ExceptionHandler);

#if defined(_PSP_GDB)
	pspDebugGdbStubInit();
#endif
}