TEST_F(ImageDocumentTest, testCopy) {
  doc.AddTerm(5, 0.5, 6, 3);
  doc.AddTerm(3, 1.0);
  doc.AddTerm(9, 2.5, 4, 7);
  doc.AddTerm(5, 1.0, 9, 1);
  doc.SetLabel("ALabel");
  doc.SetMetaData("Meta Data");
  boost::shared_ptr<ImageDocument> copy(doc.copy());

  EXPECT_EQ(copy->label(), doc.label());
  EXPECT_EQ(copy->metaData(), doc.metaData());

  doc.Normalize();
  
  EXPECT_TRUE(doc.IsNormalized());
  EXPECT_FALSE(copy->IsNormalized());
  EXPECT_FLOAT_EQ(copy->GetVal(5), 1.5);
  EXPECT_FLOAT_EQ(doc.GetVal(5), 0.3);
  EXPECT_FLOAT_EQ(copy->GetVal(3), 1.0);
  EXPECT_FLOAT_EQ(doc.GetVal(3), 0.2);
  float c1[][2] = { {6, 3}, {9, 1} };
  ExpectEqCoords(doc.GetCoords(5), c1);
  ExpectEqCoords(copy->GetCoords(5), c1);

  // Now add another coordinate
  doc.AddTerm(5, 3.0, 7, 8);
  float c2[][2] = { {6, 3}, {9, 1}, {7, 8} };
  ExpectEqCoords(doc.GetCoords(5), c2);
  ExpectEqCoords(copy->GetCoords(5), c1);

  // Now change the label and meta data
  doc.SetLabel("BLabel");
  doc.SetMetaData("NewMeta");
  EXPECT_EQ(copy->label(), "ALabel");
  EXPECT_EQ(copy->metaData(), "Meta Data");
  EXPECT_NE(copy->label(), doc.label());
  EXPECT_NE(copy->metaData(), doc.metaData());
}