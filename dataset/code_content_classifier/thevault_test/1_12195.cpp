void PrepareExcludedNodesString(EMotionFX::Actor* actor, AZStd::string* outNodeNames)
    {
        // reset the resulting string
        outNodeNames->clear();
        outNodeNames->reserve(16384);

        // check if the actor is valid
        if (actor == nullptr)
        {
            return;
        }

        // get the number of nodes and iterate through them
        const size_t numNodes = actor->GetNumNodes();
        for (size_t i = 0; i < numNodes; ++i)
        {
            EMotionFX::Node* node = actor->GetSkeleton()->GetNode(i);

            if (node->GetIncludeInBoundsCalc() == false)
            {
                *outNodeNames += node->GetName();
                *outNodeNames += ";";
            }
        }

        // make sure there is no semicolon at the end
        AzFramework::StringFunc::Strip(*outNodeNames, MCore::CharacterConstants::semiColon, true /* case sensitive */, false /* beginning */, true /* ending */);
    }