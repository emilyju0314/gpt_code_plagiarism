inline bool AnyFromLua(lua_State* lua, int stackIndex, BehaviorValueParameter& value, BehaviorClass* valueClass, ScriptContext::StackVariableAllocator* stackTempAllocator)
        {
            if (stackTempAllocator)
            {
                // Note, this is safe to do in this case, even if we are reading an any pointer type
                // The BehaviorValueParameter remains in scope for the duration of AZ::LuaScriptCaller::Call, so
                // StoreResult, even though it's using temporarily allocated memory, should remain in scope for the lifetime of the CustomReaderWriter invocation
                value.m_value = stackTempAllocator->allocate(sizeof(AZStd::any), AZStd::alignment_of<AZStd::any>::value);

                // if a reference type, the StoreResult call will point to returned, temporary memory, so a value copy is necessary
                // this value was created by the stackTempAllocator, so it is acceptable to modify the BVP.
                value.m_traits = 0;

                if (valueClass->m_defaultConstructor)
                {
                    valueClass->m_defaultConstructor(value.m_value, valueClass->m_userData);
                }
            }

            AZ_Assert(value.m_value, "Invalid call to FromLua! Either a stack allocator must be passed, or value.m_value must be a valid storage location.");
            return value.StoreResult(AZStd::move(ScriptValue<AZStd::any>::StackRead(lua, stackIndex)));
        }