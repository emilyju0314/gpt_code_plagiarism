TEST(Document, DocumentToString)
{
  Document document("1.0");
  document.root_node = Node("test", "content");
  string asString = (string)document;
  EXPECT_EQ(asString, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<test>content</test>");

  document.root_node.push_back(Node("pushBack"));
  string asString2 = (string)document;
  EXPECT_EQ(asString2, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<test>content<pushBack/></test>");
}