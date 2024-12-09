void
OSRuntimeUnloadCPPForSegmentInKmod(
    kernel_segment_command_t * segment,
    kmod_info_t              * kmodInfo)
{

    kernel_section_t * section = NULL;  // do not free
    OSKext           * theKext = NULL;  // must release

    if (gKernelCPPInitialized && kmodInfo) {
        theKext = OSKext::lookupKextWithIdentifier(kmodInfo->name);
    }

    for (section = firstsect(segment);
         section != 0;
         section = nextsect(segment, section)) {

        if (sectionIsDestructor(section)) {
            structor_t * destructors = (structor_t *)section->addr;

            if (destructors) {
                int num_destructors = section->size / sizeof(structor_t);
                int hit_null_destructor = 0;

                for (int i = 0; i < num_destructors; i++) {
                    if (destructors[i]) {
                        (*destructors[i])();
                    } else if (!hit_null_destructor) {
                        hit_null_destructor = 1;
                        OSRuntimeLog(theKext, kOSRuntimeLogSpec,
                            "Null destructor in kext %s segment %s!",
                            kmodInfo ? kmodInfo->name : "(unknown)",
                            section->segname);
                    }
                }
            } /* if (destructors) */
        } /* if (strncmp...) */
    } /* for (section...) */

    OSSafeReleaseNULL(theKext);
    return;
}