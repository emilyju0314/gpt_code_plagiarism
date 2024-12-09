void Actor::ScaleToUnitType(MCore::Distance::EUnitType targetUnitType)
    {
        if (m_unitType == targetUnitType)
        {
            return;
        }

        // calculate the scale factor and scale
        const float scaleFactor = static_cast<float>(MCore::Distance::GetConversionFactor(m_unitType, targetUnitType));
        Scale(scaleFactor);

        // update the unit type
        m_unitType = targetUnitType;
    }