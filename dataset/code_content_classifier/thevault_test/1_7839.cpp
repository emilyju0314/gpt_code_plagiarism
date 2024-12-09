Impl::XLWorkbook::XLWorkbook(XLDocument& parent, const std::string& filePath)

        : XLAbstractXMLFile(parent, filePath),
          m_sheetId(0),
          m_relationships(parent, "xl/_rels/workbook.xml.rels"),
          m_sharedStrings(parent),
          m_document(&parent) {

    ParseXMLData();
}