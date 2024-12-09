TEST_F(VerbsSymbolTest, SymInfo_Demangle) {
  MockConsole console(&session());

  // Should demangle if given mangled input.
  console.ProcessInputLine("sym-info _ZN3fxl10LogMessage6streamEv");
  auto event = console.GetOutputEvent();
  ASSERT_EQ(MockConsole::OutputEvent::Type::kOutput, event.type);
  ASSERT_EQ(
      "Demangled name: fxl::LogMessage::stream()\n\n"
      "No symbol \"_ZN3fxl10LogMessage6streamEv\" found in the current context.\n",
      event.output.AsString());

  // When input is not mangled it shouldn't show any demangled thing.
  console.ProcessInputLine("sym-info LogMessage6streamEv");
  event = console.GetOutputEvent();
  ASSERT_EQ(MockConsole::OutputEvent::Type::kOutput, event.type);
  ASSERT_EQ("No symbol \"LogMessage6streamEv\" found in the current context.\n",
            event.output.AsString());

  // Shouldn't demangle basic types. "i" would normally be converted to "int" by the demangler.
  console.ProcessInputLine("sym-info i");
  event = console.GetOutputEvent();
  ASSERT_EQ(MockConsole::OutputEvent::Type::kOutput, event.type);
  ASSERT_EQ("No symbol \"i\" found in the current context.\n",
            event.output.AsString());

}