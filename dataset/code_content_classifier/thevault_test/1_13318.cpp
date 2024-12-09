void XMLTest::testWrongKlk()
{
    printOut("\nXML wrong (klk) test ... ");

    XML xml;
    xml.parseFromFile(m_fname);
    std::string wrong = "";
    wrong = xml.getValue("/child::wrong/child::id");
}