static bool GetAttributeArgumentByIndex(const Data::Asset<ShaderAsset>& shaderAsset, const AZ::Name& attributeName, const RHI::ShaderStageAttributeArguments& args, const size_t argIndex, uint16_t* value, AZStd::string& errorMsg)
        {
            if (value)
            {
                const auto numArguments = args.size();
                if (numArguments > argIndex)
                {
                    if (args[argIndex].type() == azrtti_typeid<int>())
                    {
                        *value = aznumeric_caster(AZStd::any_cast<int>(args[argIndex]));
                    }
                    else
                    {
                        errorMsg = AZStd::string::format("Was expecting argument '%zu' in attribute '%s' to be of type 'int' from shader asset '%s'", argIndex, attributeName.GetCStr(), shaderAsset.GetHint().c_str());
                        return false;
                    }
                }
                else
                {
                     errorMsg = AZStd::string::format("Was expecting at least '%zu' arguments in attribute '%s' from shader asset '%s'", argIndex + 1, attributeName.GetCStr(), shaderAsset.GetHint().c_str());
                     return false;
                }
            }
            return true;
        }