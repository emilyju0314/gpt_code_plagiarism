bool IgnoreCGFDependencies(const char* szPath)
    {
        if (AZ::StringFunc::Path::IsExtension(szPath, "cgfm"))
        {
            // Ignore all the .cgfm files
            return true;
        }

        AZStd::smatch matches;
        const AZStd::regex lodRegex("@products@\\\\(.*)_lod[0-9]+(\\.cgfm?)");
        if (!AZStd::regex_match(szPath, matches, lodRegex) || matches.size() != 3)
        {
            // The current file is not a valid LOD file
            return false;
        }

        AZStd::string nonLodFileName = matches.str(1) + matches.str(2);
        AZ::Data::AssetId nonLodFileId;
        AZ::Data::AssetCatalogRequestBus::BroadcastResult(
            nonLodFileId, &AZ::Data::AssetCatalogRequestBus::Events::GetAssetIdByPath,
            nonLodFileName.c_str(), AZ::Data::s_invalidAssetType, false);
        if (!nonLodFileId.IsValid())
        {
            // The current LOD file is not generated from a valid CGF file
            return false;
        }

        AZ::Outcome<AZStd::vector<AZ::Data::ProductDependency>, AZStd::string> result = AZ::Failure<AZStd::string>("No response");
        AZ::Data::AssetCatalogRequestBus::BroadcastResult(result, &AZ::Data::AssetCatalogRequestBus::Events::GetDirectProductDependencies, nonLodFileId);
        if (!result.IsSuccess())
        {
            return false;
        }

        AZStd::vector<AZ::Data::ProductDependency> dependencies = result.TakeValue();
        for (const AZ::Data::ProductDependency& dependency : dependencies)
        {
            AZ::Data::AssetInfo assetInfo;
            AZ::Data::AssetCatalogRequestBus::BroadcastResult(assetInfo, &AZ::Data::AssetCatalogRequestBus::Events::GetAssetInfoById, dependency.m_assetId);
            if (assetInfo.m_assetType == AZ::Data::s_invalidAssetType)
            {
                // This dependency has unresolved path. Cannot compare it with the current LOD file.
                continue;
            }
            AZStd::string dependencyRelativePath = assetInfo.m_relativePath;
            AZStd::replace(dependencyRelativePath.begin(), dependencyRelativePath.end(), AZ_WRONG_FILESYSTEM_SEPARATOR, AZ_CORRECT_FILESYSTEM_SEPARATOR);
            if (strstr(szPath, dependencyRelativePath.c_str()))
            {
                // The current LOD file is a product dependency of the source CGF file
                return false;
            }
        }

        return true;
    }