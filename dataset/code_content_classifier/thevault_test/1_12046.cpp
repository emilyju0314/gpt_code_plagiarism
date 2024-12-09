void AddComponentsToSelectedEntities(const QModelIndexList& selectedComponents, QAbstractItemModel* model)
    {
        AzToolsFramework::EntityIdList selectedEntities;
        AzToolsFramework::ToolsApplicationRequestBus::BroadcastResult(selectedEntities, &AzToolsFramework::ToolsApplicationRequests::GetSelectedEntities);
        if (selectedEntities.empty())
        {
            return;
        }

        // Add all the selected components.
        AZ::ComponentTypeList componentsToAdd;
        for (auto index : selectedComponents)
        {
            // We only need to consider the first column, it's important that the data() function that 
            // returns ComponentDataModel::ClassDataRole also does so for the first column.
            if (index.column() != 0)
            {
                continue;
            }

            QVariant classDataVariant = model->data(index, ComponentDataModel::ClassDataRole);
            if (classDataVariant.isValid())
            {
                const AZ::SerializeContext::ClassData* classData = reinterpret_cast<const AZ::SerializeContext::ClassData*>(classDataVariant.value<void*>());
                componentsToAdd.push_back(classData->m_typeId);
            }
        }

        AzToolsFramework::EntityCompositionRequestBus::Broadcast(&AzToolsFramework::EntityCompositionRequests::AddComponentsToEntities, selectedEntities, componentsToAdd);
    }