void PrepareCollisionMeshesNodesString(EMotionFX::Actor* actor, size_t lod, AZStd::string* outNodeNames)
    {
        // reset the resulting string
        outNodeNames->clear();
        outNodeNames->reserve(16384);

        // check if the actor is invalid
        if (actor == nullptr)
        {
            return;
        }

        // check if the lod is invalid
        if (lod > (actor->GetNumLODLevels() - 1))
        {
            return;
        }

        // get the number of nodes and iterate through them
        const size_t numNodes = actor->GetNumNodes();
        for (size_t i = 0; i < numNodes; ++i)
        {
            EMotionFX::Mesh* mesh = actor->GetMesh(lod, i);
            if (mesh && mesh->GetIsCollisionMesh())
            {
                *outNodeNames += AZStd::string::format("%s;", actor->GetSkeleton()->GetNode(i)->GetName());
            }
        }

        // make sure there is no semicolon at the end
        AzFramework::StringFunc::Strip(*outNodeNames, MCore::CharacterConstants::semiColon, true /* case sensitive */, false /* beginning */, true /* ending */);
    }