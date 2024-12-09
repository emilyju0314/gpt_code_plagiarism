AZStd::unordered_set<AZ::Component*> GetRelatedIncompatibleComponents(const AZStd::vector<AZ::Component*>& components)
    {
        AZStd::unordered_set<AZ::Component*> allIncompatibleComponents;
        for (auto component : components)
        {
            const AZStd::unordered_set<AZ::Component*> incompatibleComponents = GetRelatedIncompatibleComponents(component);
            allIncompatibleComponents.insert(incompatibleComponents.begin(), incompatibleComponents.end());
        }
        return allIncompatibleComponents;
    }