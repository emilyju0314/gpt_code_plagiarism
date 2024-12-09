void inner_init() {
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
    OPENSSL_init_ssl(0, NULL);
#endif
    WORKFLOW_library_init(&PYWF_GLOBAL_SETTINGS_DEFAULT);
}