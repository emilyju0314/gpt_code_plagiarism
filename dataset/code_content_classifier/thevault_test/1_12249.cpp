void NodeWindowPlugin::UpdateVisibleNodeIndices()
    {
        // reset the visible nodes array
        m_visibleNodeIndices.clear();

        // get the currently selected actor instance
        const CommandSystem::SelectionList& selection       = CommandSystem::GetCommandManager()->GetCurrentSelection();
        EMotionFX::ActorInstance*           actorInstance   = selection.GetSingleActorInstance();
        if (actorInstance == nullptr)
        {
            // make sure the empty visible nodes array gets passed to the manager, an empty array means all nodes are shown
            GetManager()->SetVisibleJointIndices(m_visibleNodeIndices);
            return;
        }

        AZStd::string filterString = m_hierarchyWidget->GetSearchWidgetText();
        AZStd::to_lower(filterString.begin(), filterString.end());
        const bool showNodes        = m_hierarchyWidget->GetDisplayNodes();
        const bool showBones        = m_hierarchyWidget->GetDisplayBones();
        const bool showMeshes       = m_hierarchyWidget->GetDisplayMeshes();

        // get access to the actor and the number of nodes
        EMotionFX::Actor* actor = actorInstance->GetActor();
        const size_t numNodes = actor->GetNumNodes();

        // reserve memory for the visible node indices
        m_visibleNodeIndices.reserve(numNodes);

        // extract the bones from the actor
        AZStd::vector<size_t> boneList;
        actor->ExtractBoneList(actorInstance->GetLODLevel(), &boneList);

        // iterate through all nodes and check if the node is visible
        AZStd::string nodeName;
        for (size_t i = 0; i < numNodes; ++i)
        {
            EMotionFX::Node* node = actor->GetSkeleton()->GetNode(i);

            // get the node name and lower case it
            nodeName = node->GetNameString();
            AZStd::to_lower(nodeName.begin(), nodeName.end());

            const size_t        nodeIndex   = node->GetNodeIndex();
            EMotionFX::Mesh*    mesh        = actor->GetMesh(actorInstance->GetLODLevel(), nodeIndex);
            const bool          isMeshNode  = (mesh);
            const bool          isBone      = (AZStd::find(begin(boneList), end(boneList), nodeIndex) != end(boneList));
            const bool          isNode      = (isMeshNode == false && isBone == false);

            if (((showMeshes && isMeshNode) ||
                 (showBones && isBone) ||
                 (showNodes && isNode)) &&
                (filterString.empty() || nodeName.find(filterString) != AZStd::string::npos))
            {
                // this node is visible!
                m_visibleNodeIndices.emplace(nodeIndex);
            }
        }

        // pass it over to the manager
        GetManager()->SetVisibleJointIndices(m_visibleNodeIndices);
    }