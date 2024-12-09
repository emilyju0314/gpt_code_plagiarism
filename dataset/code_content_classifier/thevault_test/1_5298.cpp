void ts::DataBroadcastIdDescriptor::DisplaySelectorBytes(TablesDisplay& display, const uint8_t* data, size_t size, int indent, uint16_t dbid)
{
    // Interpretation depends in the data broadcast id.
    switch (dbid) {
        case 0x0005:
            DisplaySelectorMPE(display, data, size, indent, dbid);
            break;
        case 0x000A:
            DisplaySelectorSSU(display, data, size, indent, dbid);
            break;
        case 0x000B:
            DisplaySelectorINT(display, data, size, indent, dbid);
            break;
        default:
            DisplaySelectorGeneric(display, data, size, indent, dbid);
            break;
    }
    display.displayExtraData(data, size, indent);
}