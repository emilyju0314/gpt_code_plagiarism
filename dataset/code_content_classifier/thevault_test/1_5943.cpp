UMachine::UMachine(const std::string& name)
  : urbi::UObject(name)
  , machine(0)
{
  // Register the Urbi constructor.  This is the only mandatory
  // part of the C++ constructor.
  UBindFunction(UMachine, init);
}