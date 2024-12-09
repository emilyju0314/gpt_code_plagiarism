void AsmXMLWriter::printLLVMName(StringRef Name, PrefixType Prefix) {
  assert(!Name.empty() && "Cannot get empty name!");
  Out << "<Name>";

  std::string name;
  switch (Prefix) {
  default: llvm_unreachable("Bad prefix!");
  case NoPrefix:     break;
  case GlobalPrefix: name += "@"; break;
  case LabelPrefix:  break;
  case LocalPrefix:  name += "%"; break;
  }
  name += Name.str();

  RawWriter::write(name, Out);
  Out << "</Name>\n";
}