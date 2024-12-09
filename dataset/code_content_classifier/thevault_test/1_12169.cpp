TEST_F(EditorPythonBindingsTest, VerifyExpectedLibrariesPresent)
    {
        enum class LogTypes
        {
            Skip = 0,
            ScriptWorked
        };

        m_testSink.m_evaluateMessage = [](const char* window, const char* message) -> int
        {
            if (AzFramework::StringFunc::Equal(window, "python"))
            {
                if (AzFramework::StringFunc::Equal(message, "EditorPythonBindingsTest_VerifyExpectedLibrariesPresent"))
                {
                    return static_cast<int>(LogTypes::ScriptWorked);
                }
            }
            return static_cast<int>(LogTypes::Skip);
        };

        AZ::Entity e;
        e.CreateComponent<EditorPythonBindings::PythonSystemComponent>();
        e.Init();
        e.Activate();

        SimulateEditorBecomingInitialized();

        const char* script = 
            R"(
import sys
import sqlite3
import ssl
print ('EditorPythonBindingsTest_VerifyExpectedLibrariesPresent')
)";
        AzToolsFramework::EditorPythonRunnerRequestBus::Broadcast(&AzToolsFramework::EditorPythonRunnerRequestBus::Events::ExecuteByString, script, true);

        e.Deactivate();

        EXPECT_EQ(m_testSink.m_evaluationMap[(int)LogTypes::ScriptWorked], 1);
    }