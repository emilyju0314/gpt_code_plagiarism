Data::Instance<RPI::ShaderResourceGroup> UtilityClass::CreateShaderResourceGroup(
                Data::Instance<RPI::Shader> shader,
                const char* shaderResourceGroupId,
                [[maybe_unused]] const char* moduleName)
            {
                Data::Instance<RPI::ShaderResourceGroup> srg = RPI::ShaderResourceGroup::Create(shader->GetAsset(), AZ::Name{ shaderResourceGroupId });
                if (!srg)
                {
                    AZ_Error(moduleName, false, "Failed to create shader resource group");
                    return nullptr;
                }
                return srg;
            }