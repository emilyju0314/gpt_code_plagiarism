void fl_open_callback(void (*cb)(const char *)) {
  open_cb = cb;
  if (cb) {
    AEInstallEventHandler(kCoreEventClass, kAEOpenDocuments,
                          NewAEEventHandlerUPP((AEEventHandlerProcPtr)
			      OpenAppleEventHandler), 0, false);
  } else {
    AERemoveEventHandler(kCoreEventClass, kAEOpenDocuments,
                          NewAEEventHandlerUPP((AEEventHandlerProcPtr)
			      OpenAppleEventHandler), false);
  }
}