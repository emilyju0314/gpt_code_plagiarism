bool Datum::ToBehaviorContext(AZ::BehaviorValueParameter& destination) const
    {
        AZ::BehaviorContext* behaviorContext = nullptr;
        AZ::ComponentApplicationBus::BroadcastResult(behaviorContext, &AZ::ComponentApplicationRequests::GetBehaviorContext);
        AZ_Assert(behaviorContext, "Script Canvas can't do anything without a behavior context!");
        AZ::BehaviorClass* destinationBehaviorClass = AZ::BehaviorContextHelper::GetClass(behaviorContext, destination.m_typeId);
        const auto targetType = Data::FromAZType(destination.m_typeId);

        const bool success =
            ((IS_A(targetType) || IsConvertibleTo(targetType)) || (IS_A(Data::Type::String()) && AZ::BehaviorContextHelper::IsStringParameter(destination)))
            && DatumHelpers::ToBehaviorContext(m_type, GetValueAddress(), destination, destinationBehaviorClass);

        AZ_Error("Script Canvas", success, "Cannot push Datum with type %s into BehaviorValueParameter expecting type %s", GetName(m_type).c_str(), GetName(targetType).c_str());

        return success;
    }