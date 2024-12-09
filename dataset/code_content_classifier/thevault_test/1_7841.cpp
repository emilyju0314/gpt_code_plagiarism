void Impl::XLSheet::SetName(const std::string& name) {

    // ===== Update defined names
    m_parentWorkbook.UpdateSheetName(m_sheetName.value(), name);

    // ===== Change sheet name in main .xml files
    m_sheetName.set_value(name.c_str());
    m_nodeInWorkbook.attribute("name").set_value(name.c_str());
    m_nodeInApp.text().set(name.c_str());

}