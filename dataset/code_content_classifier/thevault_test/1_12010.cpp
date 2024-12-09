void AnimGraphPlugin::OnClickedRecorderNodeHistoryItem(EMotionFX::Recorder::ActorInstanceData* actorInstanceData, EMotionFX::Recorder::NodeHistoryItem* historyItem)
    {
        MCORE_UNUSED(actorInstanceData);

        // try to locate the node based on its unique ID
        EMotionFX::AnimGraph* animGraph = EMotionFX::GetAnimGraphManager().FindAnimGraphByID(historyItem->m_animGraphId);
        if (animGraph == nullptr)
        {
            QMessageBox::warning(m_dock, "Cannot Find Anim Graph", "The anim graph used by this node cannot be located anymore, did you delete it?", QMessageBox::Ok);
            return;
        }

        EMotionFX::AnimGraphNode* foundNode = animGraph->RecursiveFindNodeById(historyItem->m_nodeId);
        if (foundNode == nullptr)
        {
            QMessageBox::warning(m_dock, "Cannot Find Node", "The anim graph node cannot be found. Did you perhaps delete the node or change animgraph?", QMessageBox::Ok);
            return;
        }

        EMotionFX::AnimGraphNode* nodeToShow = foundNode->GetParentNode();
        if (nodeToShow)
        {
            const QModelIndex foundNodeIndex = m_animGraphModel->FindModelIndex(nodeToShow, historyItem->m_animGraphInstance);
            if (foundNodeIndex.isValid())
            {
                m_animGraphModel->Focus(foundNodeIndex);
            }
        }
    }