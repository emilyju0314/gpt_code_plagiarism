QAction* GetNodeSelectInEditorAction(const AZ::EntityId& sceneId, QObject* parent)
    {
        // Retrieve the selected nodes in our scene
        GraphModel::NodePtrList nodeList;
        GraphModelIntegration::GraphControllerRequestBus::EventResult(nodeList, sceneId, &GraphModelIntegration::GraphControllerRequests::GetSelectedNodes);

        // Iterate through the selected nodes to find their corresponding vegetation entities
        AzToolsFramework::EntityIdList vegetationEntityIdsToSelect;
        for (const auto& node : nodeList)
        {
            if (!node)
            {
                continue;
            }

            auto baseNodePtr = static_cast<LandscapeCanvas::BaseNode*>(node.get());
            vegetationEntityIdsToSelect.push_back(baseNodePtr->GetVegetationEntityId());
        }

        QAction* action = new QAction({ vegetationEntityIdsToSelect.size() > 1 ? QObject::tr("Select Entities in Editor") : QObject::tr("Select Entity in Editor") }, parent);

        QString tooltip = QObject::tr("Select the corresponding Entity/Entities in the Editor for the selected node(s) in the graph");
        action->setToolTip(tooltip);
        action->setStatusTip(tooltip);

        QObject::connect(action,
            &QAction::triggered,
            [vegetationEntityIdsToSelect](bool)
        {
            // Set the new selection
            AzToolsFramework::ToolsApplicationRequestBus::Broadcast(&AzToolsFramework::ToolsApplicationRequestBus::Events::SetSelectedEntities, vegetationEntityIdsToSelect);
        });

        return action;
    }