void Impl::XLWorkbook::UpdateSheetName(const std::string& oldName, const std::string& newName) {

    for (auto& sheet : m_sheets) {
        if (sheet.sheetType == XLSheetType::WorkSheet)
            Worksheet(sheet.sheetNode.attribute("name").value())->UpdateSheetName(oldName, newName);
    }

    // ===== Set up temporary variables
    std::string oldNameTemp = oldName;
    std::string newNameTemp = newName;
    std::string formula;

    // ===== If the sheet name contains spaces, it should be enclosed in single quotes (')
    if (oldName.find(' ') != std::string::npos)
        oldNameTemp = "\'" + oldName + "\'";
    if (newName.find(' ') != std::string::npos)
        newNameTemp = "\'" + newName + "\'";

    // ===== Ensure only sheet names are replaced (references to sheets always ends with a '!')
    oldNameTemp += '!';
    newNameTemp += '!';

    // ===== Iterate through all defined names
    for (auto& definedName : m_definedNames) {
        formula = definedName.definedNameNode.text().get();

        // ===== Skip if formula contains a '[' and ']' (means that the defined refers to external workbook)
        if (formula.find('[') == string::npos && formula.find(']') == string::npos) {

            // ===== For all instances of the old sheet name in the formula, replace with the new name.
            while (formula.find(oldNameTemp) != string::npos) {
                formula.replace(formula.find(oldNameTemp), oldNameTemp.length(), newNameTemp);
            }
            definedName.definedNameNode.text().set(formula.c_str());
        }
    }
}