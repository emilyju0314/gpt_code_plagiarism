ts::UString ts::TablesFactory::descriptorTables(const UString& desc_node_name) const
{
    auto it = desc_node_name.findSimilar(_descriptorTablesIds);
    UString result;

    while (it != _descriptorTablesIds.end() && desc_node_name.similar(it->first)) {
        if (!result.empty()) {
            result.append(u", ");
        }
        result.append(names::TID(it->second, CASID_NULL, names::NAME | names::HEXA));
        ++it;
    }

    return result;
}