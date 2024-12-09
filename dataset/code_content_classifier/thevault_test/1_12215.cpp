void CAnimComponentNode::AddPropertyToParamInfoMap(const CAnimParamType& paramType)
{
    BehaviorPropertyInfo propertyInfo;                  // the default value type is AnimValueType::Float
    {
        // property is handled by Component animation (Behavior Context getter/setters). Regardless of the param Type, it must have a non-empty name
        // (the VirtualProperty name)
        AZ_Assert(paramType.GetName() && strlen(paramType.GetName()), "All AnimParamTypes animated on Components must have a name for its VirtualProperty");

        // Initialize property name string, which sets to AnimParamType::ByString by default
        propertyInfo = paramType.GetName();

        if (paramType.GetType() != AnimParamType::ByString)
        {
            // This sets the eAnimParamType enumeration but leaves the string name untouched
            propertyInfo.m_animNodeParamInfo.paramType = paramType.GetType();
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////
        //! Detect the value type from reflection in the Behavior Context
        //
        // Query the property type Id from the Sequence Component and set it if a supported type is found
        AZ::Uuid propertyTypeId = AZ::Uuid::CreateNull();
        Maestro::SequenceComponentRequests::AnimatablePropertyAddress propertyAddress(m_componentId, propertyInfo.m_displayName.c_str());

        Maestro::SequenceComponentRequestBus::EventResult(propertyTypeId, m_pSequence->GetSequenceEntityId(), &Maestro::SequenceComponentRequestBus::Events::GetAnimatedAddressTypeId,
            GetParentAzEntityId(), propertyAddress);

        if (propertyTypeId == AZ::Vector3::TYPEINFO_Uuid())
        {
            propertyInfo.m_animNodeParamInfo.valueType = AnimValueType::Vector;
        }
        else if (propertyTypeId == AZ::Color::TYPEINFO_Uuid())
        {
            propertyInfo.m_animNodeParamInfo.valueType = AnimValueType::RGB;
        }
        else if (propertyTypeId == AZ::Quaternion::TYPEINFO_Uuid())
        {
            propertyInfo.m_animNodeParamInfo.valueType = AnimValueType::Quat;
        }
        else if (propertyTypeId == AZ::AzTypeInfo<bool>::Uuid())
        {
            propertyInfo.m_animNodeParamInfo.valueType = AnimValueType::Bool;
        }
        // Special case, if an AssetId property named "Motion" is found, create an AssetBlend.
        // The Simple Motion Component exposes a virtual property named "motion" of type AssetId.
        // We it is detected here create an AssetBlend type in Track View. The Asset Blend has special
        // UI and will be used to drive mulitple properties on this component, not just the motion AssetId.
        else if (propertyTypeId == AZ::Data::AssetId::TYPEINFO_Uuid() && 0 == azstricmp(paramType.GetName(), "motion"))
        {
            propertyInfo.m_animNodeParamInfo.valueType = AnimValueType::AssetBlend;
        }
        // the fall-through default type is propertyInfo.m_animNodeParamInfo.valueType = AnimValueType::Float
    }

    m_paramTypeToBehaviorPropertyInfoMap[paramType] = propertyInfo;
}