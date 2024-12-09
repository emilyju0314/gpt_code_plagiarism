Assembly * Module::GetAssemblyIfLoadedFromNativeAssemblyRefWithRefDefMismatch(mdAssemblyRef kAssemblyRef, BOOL *pfDiscoveredAssemblyRefMatchesTargetDefExactly)
{
    CONTRACT(Assembly *)
    {
        INSTANCE_CHECK;
        NOTHROW;
        GC_NOTRIGGER;
        FORBID_FAULT;
        MODE_ANY;
        POSTCONDITION(CheckPointer(RETVAL, NULL_OK));
    }
    CONTRACT_END;

    _ASSERTE(HasNativeImage());

    Assembly *pAssembly = NULL;
    IMDInternalImport *pImportFoundNativeImage = this->GetNativeAssemblyImport(FALSE);

    if (!pImportFoundNativeImage)
    {
        RETURN NULL;
    }

    if (kAssemblyRef != mdAssemblyRefNil)
    {
        // Scan CORCOMPILE_DEPENDENCIES tables
        PEImageLayout* pNativeLayout = this->GetNativeImage();
        COUNT_T dependencyCount;
        CORCOMPILE_DEPENDENCY *pDependencies = pNativeLayout->GetNativeDependencies(&dependencyCount);

        // Find the assemblyDef that defines the exact target
        mdAssemblyRef foundAssemblyDef = mdAssemblyRefNil;

        for (COUNT_T i = 0; i < dependencyCount; ++i)
        {
            CORCOMPILE_DEPENDENCY* pDependency = &(pDependencies[i]);
            if (pDependency->dwAssemblyRef == kAssemblyRef)
            {
                foundAssemblyDef = pDependency->dwAssemblyDef;
                break;
            }
        }

        // In this case we know there is no assembly redirection involved. Skip any additional work.
        if (kAssemblyRef == foundAssemblyDef)
        {
            *pfDiscoveredAssemblyRefMatchesTargetDefExactly = true;
            RETURN NULL;
        }

        if (foundAssemblyDef != mdAssemblyRefNil)
        {
            // Find out if THIS reference is satisfied
            // Specify fDoNotUtilizeExtraChecks to prevent recursion
            Assembly *pAssemblyCandidate = this->GetAssemblyIfLoaded(foundAssemblyDef, NULL, NULL, pImportFoundNativeImage, TRUE /*fDoNotUtilizeExtraChecks*/); 

            // This extended check is designed only to find assemblies loaded via an AssemblySpecBindingCache based binder. Verify that's what we found.
            if(pAssemblyCandidate != NULL)
            {
                if (!pAssemblyCandidate->GetManifestFile()->HasHostAssembly())
                {
                    pAssembly = pAssemblyCandidate;
                }
                else
                {
                    // This should only happen in the generic instantiation case when multiple threads are racing and
                    // the assembly found is one which we will determine is the wrong assembly.
                    //
                    // We can't assert that (as its possible under stress); however it shouldn't happen in the stack walk or GC case, so we assert in those cases.
                    _ASSERTE("Non-AssemblySpecBindingCache based assembly found with extended search" && !(IsStackWalkerThread() || IsGCThread()) && IsGenericInstantiationLookupCompareThread());
                }
            }
        }
    }

    RETURN pAssembly;
}