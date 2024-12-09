ts::SDT::Service::Service(const AbstractTable* table) :
    EntryWithDescriptors(table),
    EITs_present(false),
    EITpf_present(false),
    running_status(0),
    CA_controlled(false)
{
}