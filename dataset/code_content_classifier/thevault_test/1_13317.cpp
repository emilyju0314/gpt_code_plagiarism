void XMLTest::testWrongItself()
{
    printOut("\nXML wrong (itself) test ... ");

    XML xml;
    xml.parseFromFile(m_fname_wrong);
}