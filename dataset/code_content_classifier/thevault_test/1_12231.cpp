void doublePropertySpinboxHandler::ConsumeAttributeCommon(PropertyDoubleSpinCtrl* GUI, AZ::u32 attrib, PropertyAttributeReader* attrValue, const char* debugName)
    {
        (void)debugName;
        double value;
        if (attrib == AZ::Edit::Attributes::Min)
        {
            if (attrValue->Read<double>(value))
            {
                GUI->setMinimum(value);
            }
            else
            {
                // emit a warning!
                AZ_WarningOnce("AzToolsFramework", false, "Failed to read 'Min' attribute from property '%s' into Spin Box", debugName);
            }
            return;
        }
        else if (attrib == AZ::Edit::Attributes::Max)
        {
            if (attrValue->Read<double>(value))
            {
                GUI->setMaximum(value);
            }
            else
            {
                AZ_WarningOnce("AzToolsFramework", false, "Failed to read 'Max' attribute from property '%s' into Spin Box", debugName);
            }
            return;
        }
        else if (attrib == AZ::Edit::Attributes::Step)
        {
            if (attrValue->Read<double>(value))
            {
                GUI->setStep(value);
            }
            else
            {
                // emit a warning!
                AZ_WarningOnce("AzToolsFramework", false, "Failed to read 'Step' attribute from property '%s' into Spin Box", debugName);
            }
            return;
        }
        else if (attrib == AZ_CRC("Multiplier", 0xa49aa95b))
        {
            if (attrValue->Read<double>(value))
            {
                GUI->setMultiplier(value);
            }
            else
            {
                // emit a warning!
                AZ_WarningOnce("AzToolsFramework", false, "Failed to read 'Multiplier' attribute from property '%s' into Spin Box", debugName);
            }
            return;
        }
        else if (attrib == AZ::Edit::Attributes::Suffix)
        {
            AZStd::string result;
            if (attrValue->Read<AZStd::string>(result))
            {
                GUI->setSuffix(result.c_str());
            }
            else
            {
                AZ_WarningOnce("AzToolsFramework", false, "Failed to read 'Suffix' attribute from property '%s' into Spin Box", debugName);
            }
            return;
        }
        else if (attrib == AZ_CRC("Prefix", 0x93b1868e))
        {
            AZStd::string result;
            if (attrValue->Read<AZStd::string>(result))
            {
                GUI->setPrefix(result.c_str());
            }
            else
            {
                AZ_WarningOnce("AzToolsFramework", false, "Failed to read 'Prefix' attribute from property '%s' into Spin Box", debugName);
            }
            return;
        }
        else if (attrib == AZ::Edit::Attributes::Decimals)
        {
            int intValue = 0;
            if (attrValue->Read<int>(intValue))
            {
                GUI->setDecimals(intValue);
            }
            else
            {
                // emit a warning!
                AZ_WarningOnce("AzToolsFramework", false, "Failed to read 'Decimals' attribute from property '%s' into Spin Box", debugName);
            }
            return;
        }
        else if (attrib == AZ::Edit::Attributes::DisplayDecimals)
        {
            int intValue = 0;
            if (attrValue->Read<int>(intValue))
            {
                GUI->setDisplayDecimals(intValue);
            }
            else
            {
                // emit a warning!
                AZ_WarningOnce("AzToolsFramework", false, "Failed to read 'DisplayDecimals' attribute from property '%s' into Spin Box", debugName);
            }
            return;
        }
    }