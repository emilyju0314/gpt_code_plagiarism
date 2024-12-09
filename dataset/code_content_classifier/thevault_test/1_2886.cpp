BOOL Module::IsInSameVersionBubble(Module *target)
{
    STANDARD_VM_CONTRACT;

    if (this == target)
    {
        return TRUE;
    }

    if (!HasNativeOrReadyToRunImage())
    {
        return FALSE;
    }

    // Check if the current module's image has native manifest metadata, otherwise the current->GetNativeAssemblyImport() asserts.
    COUNT_T cMeta=0;
    const void* pMeta = GetFile()->GetOpenedILimage()->GetNativeManifestMetadata(&cMeta);
    if (pMeta == NULL)
    {
        return FALSE;
    }

    IMDInternalImport* pMdImport = GetNativeAssemblyImport();

    LPCUTF8 targetName = target->GetAssembly()->GetSimpleName();

    HENUMInternal assemblyEnum;
    HRESULT hr = pMdImport->EnumAllInit(mdtAssemblyRef, &assemblyEnum);
    mdAssemblyRef assemblyRef;
    while (pMdImport->EnumNext(&assemblyEnum, &assemblyRef))
    {
        LPCSTR assemblyName;
        hr = pMdImport->GetAssemblyRefProps(assemblyRef, NULL, NULL, &assemblyName, NULL, NULL, NULL, NULL);
        if (strcmp(assemblyName, targetName) == 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}