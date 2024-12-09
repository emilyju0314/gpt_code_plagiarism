void ExecutionStateInterpretedPureOnGraphStart::Execute()
    {
        // execute the script in a single call
        auto lua = LoadLuaScript();
        // Lua: graph_VM
        AZ::Internal::azlua_getfield(lua, -1, Grammar::k_OnGraphStartFunctionName);
        // Lua: graph_VM, graph_VM['k_OnGraphStartFunctionName']
        AZ::Internal::LuaClassToStack(lua, this, azrtti_typeid<ExecutionStateInterpretedPureOnGraphStart>(), AZ::ObjectToLua::ByReference, AZ::AcquisitionOnPush::None);
        // Lua: graph_VM, graph_VM['k_OnGraphStartFunctionName'], userdata<ExecutionState>
        Execution::ActivationInputArray storage;
        Execution::ActivationData data(m_component->GetRuntimeDataOverrides(), storage);
        Execution::ActivationInputRange range = Execution::Context::CreateActivateInputRange(data, m_component->GetEntityId());
        Execution::PushActivationArgs(lua, range.inputs, range.totalCount);
        // Lua: graph_VM, graph_VM['k_OnGraphStartFunctionName'], userdata<ExecutionState>, args...
        const int result = Execution::InterpretedSafeCall(lua, aznumeric_caster(1 + range.totalCount), 0);
        // Lua: graph_VM, ?
        if (result == LUA_OK)
        {
            // Lua: graph_VM
            lua_pop(lua, 1);
        }
        else
        {
            // Lua: graph_VM, error
            lua_pop(lua, 2);
        }
    }