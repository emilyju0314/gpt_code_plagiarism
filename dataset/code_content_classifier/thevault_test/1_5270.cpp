void ts::DSMCCStreamDescriptorsTable::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    display.duck().out() << UString::Format(u"%*sTable id extension: 0x%X (%d)", {indent, u"", section.tableIdExtension(), section.tableIdExtension()}) << std::endl;
    AbstractDescriptorsTable::DisplaySection(display, section, indent);
}