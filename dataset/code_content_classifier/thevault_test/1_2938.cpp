void Reset_Handler(void) {
    uint32_t *pSrc, *pDest;

    // Initialize the initialized data section
    pSrc = &__etext;
    pDest = &__data_start__;

    if ((&__data_start__ != &__data_end__) && (pSrc != pDest)) {
        for (; pDest < &__data_end__; pDest++, pSrc++) {
            *pDest = *pSrc;
        }
    }

    // Clear the zero section
    if (&__bss_start__ != &__bss_end__) {
        for (pDest = &__bss_start__; pDest < &__bss_end__; pDest++) {
            *pDest = 0ul;
        }
    }

    SystemInit();

    /* Initialize the C library */
    __libc_init_array();

    ClearCore::SysMgr.Initialize();

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
    // ISO C++ forbids hijacking main(), but we can't avoid it
    // in this application.
    main();
#pragma GCC diagnostic pop

    while (1) {
        continue;
    }
}