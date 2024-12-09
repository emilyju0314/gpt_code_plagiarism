TEST_F(AnimGraphActionCommandsFixture, DISABLED_AnimGraphActionCommandTests_UndoRemoveStateWithAction)
    {
        CommandSystem::CommandManager commandManager;
        AZStd::string result;
        MCore::CommandGroup commandGroup;

        // 1. Add state action.
        CommandSystem::AddStateAction(m_stateA, azrtti_typeid<AnimGraphParameterAction>());
        const AZStd::string serializedAfterAddAction = SerializeAnimGraph();
        EXPECT_EQ(1, m_stateA->GetTriggerActionSetup().GetNumActions())
            << "There should be exactly one state action.";

        // 2. Remove the whole state including the action.
        CommandSystem::DeleteNodes(&commandGroup, m_motionNodeAnimGraph.get(), { m_stateA });
        EXPECT_TRUE(commandManager.ExecuteCommandGroup(commandGroup, result));
        commandGroup.RemoveAllCommands();
        EXPECT_EQ(nullptr, m_motionNodeAnimGraph->RecursiveFindNodeByName("A")) << "State A should be gone.";

        // 3. Undo remove state.
        EXPECT_TRUE(commandManager.Undo(result));
        EXPECT_EQ(serializedAfterAddAction, SerializeAnimGraph());
    }