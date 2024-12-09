static void SetBoundActions(
            const AZStd::vector<ActionOverride>& actions, AZStd::vector<BoundOverrideActions>& boundActions)
        {
            for (const auto& action : actions)
            {
                // check if we already have an action with this uri
                auto actionIt = AZStd::find_if(boundActions.begin(), boundActions.end(),
                    [action](const BoundOverrideActions& boundActionOverride)
                    {
                        return action.m_uri == boundActionOverride.m_actionOverride.m_uri;
                    });

                // if we do not already have an action with this uri, store it
                if (actionIt == boundActions.end())
                {
                    boundActions.push_back({ action.m_uri, action });
                }
                else
                {
                    // if we do already have an action with this uri, check if the new and existing
                    // action both have valid entity ids, and if so, if they match - if the entity
                    // and component ids are valid and match, keep this action and the previous one
                    // (so add/push_back), otherwise we want to override it.
                    if (action.m_entityIdComponentPair.GetEntityId().IsValid() &&
                        actionIt->m_actionOverride.m_entityIdComponentPair.GetEntityId().IsValid() &&
                        action.m_entityIdComponentPair != actionIt->m_actionOverride.m_entityIdComponentPair)
                    {
                        boundActions.push_back({ action.m_uri, action });
                    }
                    else
                    {
                        // overwrite existing action if uri already exists
                        actionIt->m_actionOverride = action;
                    }
                }
            }
        }