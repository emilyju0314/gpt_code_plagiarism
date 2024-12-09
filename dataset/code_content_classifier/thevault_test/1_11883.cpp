PYBIND11_EMBEDDED_MODULE(azlmbrtest, m)
{
    EditorPythonBindings::EditorPythonBindingsNotificationBus::Broadcast(&EditorPythonBindings::EditorPythonBindingsNotificationBus::Events::OnImportModule, m.ptr());
    TestTypes::RegisterAzEntityId(m);
}