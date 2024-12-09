void SliceEditorEntityOwnershipService::OnAssetReloaded(AZ::Data::Asset<AZ::Data::AssetData> asset)
    {
        AZ_PROFILE_FUNCTION(AzToolsFramework);

        EntityIdList selectedEntities;
        ToolsApplicationRequests::Bus::BroadcastResult(selectedEntities, &ToolsApplicationRequests::GetSelectedEntities);

        SliceEntityOwnershipService::OnAssetReloaded(asset);

        // Ensure selection set is preserved after applying the new level slice.
        ToolsApplicationRequests::Bus::Broadcast(&ToolsApplicationRequests::SetSelectedEntities, selectedEntities);
    }