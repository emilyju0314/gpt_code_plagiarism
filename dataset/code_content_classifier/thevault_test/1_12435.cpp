void SortTransformParentsBeforeChildren(AZStd::vector<AZ::Entity*>& entities)
    {
        AZ_PROFILE_FUNCTION(AzToolsFramework);

        // IDs of those present in 'entities'. Does not include parent ID if parent not found in 'entities'
        AZStd::unordered_set<AZ::EntityId> existingEntityIds;

        // map children by their parent ID (even if parent not found in 'entities')
        AZStd::unordered_map<AZ::EntityId, AZStd::vector<AZ::Entity*>> parentIdToChildrenPtrs;

        // store any entities with bad setups here, we'll put them last in the final sort
        AZStd::vector<AZ::Entity*> badEntities;

        // gather data about the entities...
        for (AZ::Entity* entity : entities)
        {
            if (!entity)
            {
                badEntities.push_back(entity);
                continue;
            }

            AZ::EntityId entityId = entity->GetId();

            if (!entityId.IsValid())
            {
                AZ_Warning("Entity", false, "Hierarchy sort found entity '%s' with invalid ID", entity->GetName().c_str());

                badEntities.push_back(entity);
                continue;
            }

            bool entityIdIsUnique = existingEntityIds.insert(entityId).second;
            if (!entityIdIsUnique)
            {
                AZ_Warning("Entity", false, "Hierarchy sort found multiple entities using same ID as entity '%s' %s",
                    entity->GetName().c_str(),
                    entityId.ToString().c_str());

                badEntities.push_back(entity);
                continue;
            }

            // search for any component that implements the TransformInterface.
            // don't use EBus because we support sorting entities that haven't been initialized or activated.
            // entities with no transform component will be treated like entities with no parent.
            AZ::EntityId parentId;
            if (AZ::TransformInterface* transformInterface = AZ::EntityUtils::FindFirstDerivedComponent<AZ::TransformInterface>(entity))
            {
                parentId = transformInterface->GetParentId();

                // if entity is parented to itself, sort it as if it had no parent
                if (parentId == entityId)
                {
                    AZ_Warning("Entity", false, "Hierarchy sort found entity parented to itself '%s' %s",
                        entity->GetName().c_str(),
                        entityId.ToString().c_str());

                    parentId.SetInvalid();
                }
            }

            parentIdToChildrenPtrs[parentId].push_back(entity);
        }

        // clear 'entities', we'll refill it in sorted order...
        const size_t originalEntityCount = entities.size();
        entities.clear();

        // use 'candidateIds' to track the parent IDs we're going to process next.
        // the first candidates should be the parents of the roots.
        AZStd::vector<AZ::EntityId> candidateIds;
        candidateIds.reserve(originalEntityCount + 1);
        for (auto& parentChildrenPair : parentIdToChildrenPtrs)
        {
            const AZ::EntityId& parentId = parentChildrenPair.first;

            // we found a root if parent ID doesn't correspond to any entity in the list
            if (existingEntityIds.find(parentId) == existingEntityIds.end())
            {
                candidateIds.push_back(parentId);
            }
        }

        // process candidates until everything is sorted:
        // - add candidate's children to the final sorted order
        // - add candidate's children to list of candidates, so we can process *their* children in a future loop
        // - erase parent/children entry from parentToChildrenIds
        // - continue until nothing is left in parentToChildrenIds
        for (size_t candidateIndex = 0; !parentIdToChildrenPtrs.empty(); ++candidateIndex)
        {
            // if there are no more candidates, but there are still unsorted children, then we have an infinite loop.
            // pick an arbitrary parent from the loop to be the next candidate.
            if (candidateIndex == candidateIds.size())
            {
                const AZ::EntityId& parentFromLoopId = parentIdToChildrenPtrs.begin()->first;

#ifdef AZ_ENABLE_TRACING
                // Find name to use in warning message
                AZStd::string parentFromLoopName;
                for (auto& parentIdChildrenPtrPair : parentIdToChildrenPtrs)
                {
                    for (AZ::Entity* entity : parentIdChildrenPtrPair.second)
                    {
                        if (entity->GetId() == parentFromLoopId)
                        {
                            parentFromLoopName = entity->GetName();
                            break;
                        }
                        if (!parentFromLoopName.empty())
                        {
                            break;
                        }
                    }
                }

                AZ_Warning("Entity", false, "Hierarchy sort found parenting loop involving entity '%s' %s",
                    parentFromLoopName.c_str(),
                    parentFromLoopId.ToString().c_str());
#endif // AZ_ENABLE_TRACING

                candidateIds.push_back(parentFromLoopId);
            }

            const AZ::EntityId& parentId = candidateIds[candidateIndex];

            auto foundChildren = parentIdToChildrenPtrs.find(parentId);
            if (foundChildren != parentIdToChildrenPtrs.end())
            {
                for (AZ::Entity* child : foundChildren->second)
                {
                    entities.push_back(child);
                    candidateIds.push_back(child->GetId());
                }

                parentIdToChildrenPtrs.erase(foundChildren);
            }
        }

        // put bad entities at the end of the sorted list
        entities.insert(entities.end(), badEntities.begin(), badEntities.end());

        AZ_Assert(entities.size() == originalEntityCount, "Wrong number of entities after sort! This algorithm is busted.");
    }