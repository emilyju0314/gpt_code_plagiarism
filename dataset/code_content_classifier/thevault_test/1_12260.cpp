TEST_F(AnimGraphModelFixture, CanReloadAReferenceNodesReferencedGraph)
    {
        using testing::Eq;

        {
            AZStd::string result;
            EXPECT_TRUE(CommandSystem::GetCommandManager()->ExecuteCommand("CreateAnimGraph -animGraphId 0", result)) << result.c_str();
        }

        auto* animGraph = EMotionFX::GetAnimGraphManager().FindAnimGraphByID(0);

        CommandSystem::CreateAnimGraphNode(nullptr, animGraph, azrtti_typeid<EMotionFX::AnimGraphReferenceNode>(), "Reference", animGraph->GetRootStateMachine(), 0, 0);
        auto* referenceNode = static_cast<AnimGraphReferenceNode*>(animGraph->RecursiveFindNodeByName("Reference0"));

        const AZ::Data::AssetId assetId("{B359FEA1-7628-4981-91E2-63F58413EEF5}");

        AnimGraph* referenceAnimGraph = nullptr;
        {
            AZ::Data::Asset<Integration::AnimGraphAsset> referenceAnimGraphAsset =
                AnimGraphAssetFactory::Create(assetId, AnimGraphFactory::Create<OneBlendTreeParameterNodeAnimGraph>());
            referenceAnimGraph = referenceAnimGraphAsset->GetAnimGraph();
            referenceAnimGraph->SetFileName("ReferencedAnimGraph.animgraph");
            referenceAnimGraph->InitAfterLoading();
            referenceAnimGraph->SetIsOwnedByRuntime(true);
            referenceAnimGraphAsset->SetStatus(AZ::Data::AssetData::AssetStatus::Queued);
            referenceNode->SetAnimGraphAsset(referenceAnimGraphAsset);
            CallOnAnimGraphAssetChanged(referenceNode);
            referenceAnimGraphAsset->SetStatus(AZ::Data::AssetData::AssetStatus::Ready);

            // In normal operation, asset loading results in this sequence of events:
            //
            // AnimGraphAssetHandler::OnInitAsset
            //     sets owned by runtime = true
            // AnimGraphModel::OnAssetReady
            //     not added to top-level because is owned by runtime = true
            // AnimGraphReferenceNode::OnAssetReady
            //     sets owned by runtime = false
            //     emits OnReferenceAnimGraphChanged
            //         AnimGraphModel::OnReferenceAnimGraphChanged
            //             adds nodes of the graph to the right places in the model

            // Let the AnimGraphModel know that the anim graph asset has been loaded
            AZ::Data::AssetBus::Broadcast(&AZ::Data::AssetBus::Events::OnAssetReady, referenceAnimGraphAsset);
        }


        auto* parameterNode = static_cast<BlendTreeParameterNode*>(referenceAnimGraph->GetRootStateMachine()->GetChildNode(0)->GetChildNode(0));
        EXPECT_TRUE(parameterNode);

        QModelIndexList modelIndexesForParameterNode = GetModel()->FindModelIndexes(parameterNode);
        EXPECT_THAT(modelIndexesForParameterNode.size(), Eq(1));
        QPersistentModelIndex index = modelIndexesForParameterNode[0];
        EXPECT_TRUE(index.isValid());

        {
            auto* handler = static_cast<Integration::AnimGraphAssetHandler*>(AZ::Data::AssetManager::Instance().GetHandler(azrtti_typeid<Integration::AnimGraphAsset>()));
            AZ::Data::Asset<Integration::AnimGraphAsset> newAsset{handler->CreateAsset(assetId, AZ::AzTypeInfo<Integration::AnimGraphAsset>::Uuid()), AZ::Data::AssetLoadBehavior::Default};
            newAsset->SetData(AnimGraphFactory::Create<OneBlendTreeParameterNodeAnimGraph>().release());
            newAsset->GetAnimGraph()->SetFileName("ReferencedAnimGraph.animgraph");
            newAsset->GetAnimGraph()->InitAfterLoading();
            newAsset->GetAnimGraph()->SetIsOwnedByRuntime(true);
            newAsset->SetStatus(AZ::Data::AssetData::AssetStatus::Ready);

            // In normal operation, asset reloading results in this sequence of events:
            //
            // AnimGraphAssetHandler::OnInitAsset
            //     sets owned by runtime = true
            // AnimGraphModel::OnAssetReloaded
            //     not added to top-level because is owned by runtime = true
            // AnimGraphReferenceNode::OnAssetReloaded
            //     sets owned by runtime = false
            //     emits OnReferenceAnimGraphAboutToBeChanged
            //         AnimGraphModel::OnReferenceAnimGraphAboutToBeChanged
            //             removes child nodes of the existing reference node
            //     releases reference to old asset, potentially deleting the old anim graph
            //     emits OnReferenceAnimGraphChanged
            //         AnimGraphModel::OnReferenceAnimGraphChanged
            //             adds nodes of the graph to the right places in the model
            AZ::Data::AssetBus::Broadcast(&AZ::Data::AssetBus::Events::OnAssetReloaded, newAsset);
        }
        EXPECT_FALSE(index.isValid());

        QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
    }