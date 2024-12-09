Assembly * 
Module::GetAssemblyIfLoaded(
    mdAssemblyRef       kAssemblyRef, 
    LPCSTR              szWinRtNamespace,   // = NULL
    LPCSTR              szWinRtClassName,   // = NULL
    IMDInternalImport * pMDImportOverride,  // = NULL
    BOOL                fDoNotUtilizeExtraChecks, // = FALSE
    ICLRPrivBinder      *pBindingContextForLoadedAssembly // = NULL
)    
{
    CONTRACT(Assembly *)
    {
        INSTANCE_CHECK;
        NOTHROW;
        GC_NOTRIGGER;
        FORBID_FAULT;
        MODE_ANY;
        POSTCONDITION(CheckPointer(RETVAL, NULL_OK));
        SUPPORTS_DAC;
    }
    CONTRACT_END;

    Assembly * pAssembly = NULL;
    BOOL fCanUseRidMap = ((pMDImportOverride == NULL) &&
                          (szWinRtNamespace == NULL));

#ifdef _DEBUG
    fCanUseRidMap = fCanUseRidMap && (CLRConfig::GetConfigValue(CLRConfig::INTERNAL_GetAssemblyIfLoadedIgnoreRidMap) == 0);
#endif

    // If we're here due to a generic instantiation, then we should only be querying information from the ngen image we're finding the generic instantiation in.
#if !defined(DACCESS_COMPILE) && defined(FEATURE_PREJIT)
    _ASSERTE(!IsGenericInstantiationLookupCompareThread() || HasNativeImage());
#endif

    // Don't do a lookup if an override IMDInternalImport is provided, since the lookup is for the
    // standard IMDInternalImport and might result in an incorrect result.
    // WinRT references also do not update RID map, so don't try to look it up
    if (fCanUseRidMap)
    {
        pAssembly = LookupAssemblyRef(kAssemblyRef);
    }
    
#ifndef DACCESS_COMPILE
    // Check if actually loaded, unless a GC is in progress or the current thread is
    // walking the stack (either its own stack, or another thread's stack) as that works
    // only with loaded assemblies
    //
    // NOTE: The case where the current thread is walking a stack can be problematic for
    // other reasons, as the remaining code of this function uses "GetAppDomain()", when
    // in fact the right AppDomain to use is the one corresponding to the frame being
    // traversed on the walked thread. Dev10 TFS bug# 762348 tracks that issue.
    if ((pAssembly != NULL) && !IsGCThread() && !IsStackWalkerThread())
    {
        _ASSERTE(::GetAppDomain() != NULL);
        DomainAssembly * pDomainAssembly = pAssembly->GetDomainAssembly();
        if ((pDomainAssembly == NULL) || !pDomainAssembly->IsLoaded())
            pAssembly = NULL;
    }   
#endif //!DACCESS_COMPILE
    
    if (pAssembly == NULL)
    {
        do
        {
            AppDomain * pAppDomainExamine = AppDomain::GetCurrentDomain();
            
            DomainAssembly * pCurAssemblyInExamineDomain = GetAssembly()->GetDomainAssembly();
            if (pCurAssemblyInExamineDomain == NULL)
            {
                continue;
            }

#ifdef FEATURE_COMINTEROP
            if (szWinRtNamespace != NULL)
            {
                _ASSERTE(szWinRtClassName != NULL);
                
                CLRPrivBinderWinRT * pWinRtBinder = pAppDomainExamine->GetWinRtBinder();
                if (pWinRtBinder != nullptr)
                {
                    ENABLE_FORBID_GC_LOADER_USE_IN_THIS_SCOPE();
                    pAssembly = pWinRtBinder->FindAssemblyForTypeIfLoaded(
                        dac_cast<PTR_AppDomain>(pAppDomainExamine), 
                        szWinRtNamespace, 
                        szWinRtClassName);
                }
                
                // Never store WinMD AssemblyRefs into the rid map.
                if (pAssembly != NULL)
                {
                    break;
                }
                
                // Never attemt to search the assembly spec binding cache for this form of WinRT assembly reference.
                continue;
            }
#endif // FEATURE_COMINTEROP

#ifndef DACCESS_COMPILE
            {
                IMDInternalImport * pMDImport = (pMDImportOverride == NULL) ? (GetMDImport()) : (pMDImportOverride);
                
                //we have to be very careful here.
                //we are using InitializeSpecInternal so we need to make sure that under no condition 
                //the data we pass to it can outlive the assembly spec.
                AssemblySpec spec;
                if (FAILED(spec.InitializeSpecInternal(kAssemblyRef, 
                                                       pMDImport, 
                                                       pCurAssemblyInExamineDomain,
                                                       FALSE /*fAllowAllocation*/)))
                {
                    continue;
                }

                // If we have been passed the binding context for the loaded assembly that is being looked up in the 
                // cache, then set it up in the AssemblySpec for the cache lookup to use it below.
                if (pBindingContextForLoadedAssembly != NULL)
                {
                    _ASSERTE(spec.GetBindingContext() == NULL);
                    spec.SetBindingContext(pBindingContextForLoadedAssembly);
                }
                DomainAssembly * pDomainAssembly = nullptr;

                {
                    pDomainAssembly = pAppDomainExamine->FindCachedAssembly(&spec, FALSE /*fThrow*/);
                }

                if (pDomainAssembly && pDomainAssembly->IsLoaded())
                    pAssembly = pDomainAssembly->GetCurrentAssembly(); // <NOTE> Do not use GetAssembly - that may force the completion of a load

                // Only store in the rid map if working with the current AppDomain.
                if (fCanUseRidMap && pAssembly)
                    StoreAssemblyRef(kAssemblyRef, pAssembly);

                if (pAssembly != NULL)
                    break;
            }
#endif //!DACCESS_COMPILE
        } while (false);
    }

#if !defined(DACCESS_COMPILE) && defined(FEATURE_PREJIT)
    if (pAssembly == NULL && (IsStackWalkerThread() || IsGCThread() || IsGenericInstantiationLookupCompareThread()) && !fDoNotUtilizeExtraChecks)
    {
        // The GetAssemblyIfLoaded function must succeed in finding assemblies which have already been loaded in a series of interesting cases
        // (GC, Stackwalking, GenericInstantiationLookup). This logic is used to handle cases where the normal lookup done above
        // may fail, and more extensive (and slow) lookups are necessary. This logic is gated by a long series of checks to ensure it doesn't
        // run in cases which are not known to be problematic, or would not benefit from the logic here.
        //
        // This is logic which tries extra possibilities to find an assembly. It is believed this logic can only be hit in cases where an ngen
        // image depends on an assembly through some sort of binding version/public key token adjustment (due to binding policy, unification, or portability rules)
        // and the assembly depended on was loaded through a binder that utilizes the AssemblySpecBindingCache for binder caching. (The cache's in the other
        // binder's successfully answer the GetAssemblyIfLoaded question in the case of non-exact matches where the match was discovered during
        // ngen resolution.)
        // This restricts the scenario to a somewhat restricted case.

        BOOL eligibleForAdditionalChecks = TRUE;
        if (szWinRtNamespace != NULL)
            eligibleForAdditionalChecks = FALSE; // WinRT binds do not support this scan

        AssemblySpec specSearchAssemblyRef;

        // Get the assembly ref information that we are attempting to satisfy.
        if (eligibleForAdditionalChecks)
        {
            IMDInternalImport * pMDImport = (pMDImportOverride == NULL) ? (GetMDImport()) : (pMDImportOverride);

            if (FAILED(specSearchAssemblyRef.InitializeSpecInternal(kAssemblyRef, 
                                                    pMDImport, 
                                                    NULL,
                                                    FALSE /*fAllowAllocation*/)))
            {
                eligibleForAdditionalChecks = FALSE; // If an assemblySpec can't be constructed then we're not going to succeed
                                                     // This should not ever happen, due to the above checks, but this logic 
                                                     // is intended to be defensive against unexpected behavior.
            }
            else if (specSearchAssemblyRef.IsContentType_WindowsRuntime())
            {
                eligibleForAdditionalChecks = FALSE; // WinRT binds do not support this scan
            }
        }

        if (eligibleForAdditionalChecks)
        {
            BOOL abortAdditionalChecks = false;

            // When working with an ngenn'd assembly, as an optimization we can scan only that module for dependency info.
            bool onlyScanCurrentModule = HasNativeImage() && GetFile()->IsAssembly();
            mdAssemblyRef foundAssemblyRef = mdAssemblyRefNil;

            // In each AppDomain that might be interesting, scan for an ngen image that is loaded that has a dependency on the same 
            // assembly that is now being looked up. If that ngen image has the same dependency, then we can use the CORCOMPILE_DEPENDENCIES
            // table to find the exact AssemblyDef that defines the assembly, and attempt a load based on that information.
            // As this logic is expected to be used only in exceedingly rare situations, this code has not been tuned for performance
            // in any way.
            do
            {
                AppDomain * pAppDomainExamine = ::GetAppDomain(); // There is only 1 AppDomain on CoreCLR
            
                DomainAssembly * pCurAssemblyInExamineDomain = GetAssembly()->GetDomainAssembly();
                if (pCurAssemblyInExamineDomain == NULL)
                {
                    continue;
                }

                DomainFile *pDomainFileNativeImage;
                
                if (onlyScanCurrentModule)
                {
                    pDomainFileNativeImage = pCurAssemblyInExamineDomain;
                    // Do not reset foundAssemblyRef.
                    // This will allow us to avoid scanning for foundAssemblyRef in each domain we iterate through
                }
                else
                {
                    foundAssemblyRef = mdAssemblyRefNil;
                    pDomainFileNativeImage = pAppDomainExamine->GetDomainFilesWithNativeImagesList();
                }

                while (!abortAdditionalChecks && (pDomainFileNativeImage != NULL) && (pAssembly == NULL))
                {
                    Module *pNativeImageModule = pDomainFileNativeImage->GetCurrentModule();
                    _ASSERTE(pNativeImageModule->HasNativeImage());
                    IMDInternalImport *pImportFoundNativeImage = pNativeImageModule->GetNativeAssemblyImport(FALSE);
                    if (pImportFoundNativeImage != NULL)
                    {
                        if (IsNilToken(foundAssemblyRef))
                        {
                            // Enumerate assembly refs in nmd space, and compare against held ref.
                            HENUMInternalHolder hAssemblyRefEnum(pImportFoundNativeImage);
                            if (FAILED(hAssemblyRefEnum.EnumInitNoThrow(mdtAssemblyRef, mdAssemblyRefNil)))
                            {
                                continue;
                            }

                            mdAssemblyRef assemblyRef = mdAssemblyRefNil;

                            // Find if the native image has a matching assembly ref in its compile dependencies.
                            while (pImportFoundNativeImage->EnumNext(&hAssemblyRefEnum, &assemblyRef) && (pAssembly == NULL))
                            {
                                AssemblySpec specFoundAssemblyRef;
                                if (FAILED(specFoundAssemblyRef.InitializeSpecInternal(assemblyRef, 
                                                                        pImportFoundNativeImage, 
                                                                        NULL,
                                                                        FALSE /*fAllowAllocation*/)))
                                {
                                    continue; // If the spec cannot be loaded, it isn't the one we're looking for
                                }

                                // Check for AssemblyRef equality
                                if (specSearchAssemblyRef.CompareEx(&specFoundAssemblyRef))
                                {
                                    foundAssemblyRef = assemblyRef;
                                    break;
                                }
                            }
                        }

                        pAssembly = pNativeImageModule->GetAssemblyIfLoadedFromNativeAssemblyRefWithRefDefMismatch(foundAssemblyRef, &abortAdditionalChecks);

                        if (fCanUseRidMap && pAssembly)
                            StoreAssemblyRef(kAssemblyRef, pAssembly);
                    }

                    // If we're only scanning one module for accurate dependency information, break the loop here.
                    if (onlyScanCurrentModule)
                        break;

                    pDomainFileNativeImage = pDomainFileNativeImage->FindNextDomainFileWithNativeImage();
                }
            } while (false);
        }
    }
#endif // !defined(DACCESS_COMPILE) && defined(FEATURE_PREJIT)

    // When walking the stack or computing GC information this function should never fail.
    _ASSERTE((pAssembly != NULL) || !(IsStackWalkerThread() || IsGCThread()));

#ifdef DACCESS_COMPILE
    
    // Note: In rare cases when debugger walks the stack, we could actually have pAssembly=NULL here.
    // To fix that we should DACize the AppDomain-iteration code above (especially AssemblySpec).
    _ASSERTE(pAssembly != NULL);
    
#endif //DACCESS_COMPILE
    
    RETURN pAssembly;
}