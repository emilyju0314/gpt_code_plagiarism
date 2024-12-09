inline void AnyToLua(lua_State* lua, BehaviorValueParameter& param)
        {
            AZStd::any* value = param.GetAsUnsafe<AZStd::any>();
            if (value)
            {
                ScriptValue<AZStd::any>::StackPush(lua, *value);
            }
        }