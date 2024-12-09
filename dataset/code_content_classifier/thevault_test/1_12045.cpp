AZ::EntityId CreateEntityFromSelection(const QModelIndexList& selection, QAbstractItemModel* model)
    {
        AZ::Vector3 position = AZ::Vector3::CreateZero();
        CViewport *view = GetIEditor()->GetViewManager()->GetGameViewport();
        int width, height;
        view->GetDimensions(&width, &height);
        position = LYVec3ToAZVec3(view->ViewToWorld(QPoint(width / 2, height / 2)));

        AZ::EntityId newEntityId;
        EBUS_EVENT_RESULT(newEntityId, AzToolsFramework::EditorRequests::Bus, CreateNewEntityAtPosition, position, AZ::EntityId());
        if (newEntityId.IsValid())
        {
            // Add all the selected components.
            AZ::ComponentTypeList componentsToAdd;
            for (auto index : selection)
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

            AzToolsFramework::EntityCompositionRequestBus::Broadcast(&AzToolsFramework::EntityCompositionRequests::AddComponentsToEntities, AzToolsFramework::EntityIdList{ newEntityId }, componentsToAdd);

            return newEntityId;
        }

        return AZ::EntityId();
    }