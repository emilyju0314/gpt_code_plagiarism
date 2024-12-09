void loom::ensure_py_init() {
   static bool python_inited = false;
   if (python_inited) {
      return;
   }   
   logger->debug("Initializing Python interpreter");
   python_inited = true;
   PyImport_AppendInittab("loom_c", PyInit_loom_c);
   Py_Initialize();
   PyEval_InitThreads();

   data_wrapper_init();

   // Force the bootstrap sequence in MAIN thread
   PyObject *loom_wside = PyImport_ImportModule("loom.wside.core");
   Py_DecRef(loom_wside);

   main_thread = PyEval_SaveThread();
   logger->debug("Python interpreter initialized");
}