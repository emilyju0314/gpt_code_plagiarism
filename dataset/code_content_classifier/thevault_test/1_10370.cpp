TEST_F(PerspectiveGeometryTest, OneOutlierIdentityTransform) {
  docB->AddTerm(1, 1.0, 30.0, 30.0);
  docB->AddTerm(2, 1.0, 25.0, 23.1);
  docB->AddTerm(3, 1.0, 34.7, 28.0);
  docB->AddTerm(4, 1.0, 10.6, 40.1);
  docB->AddTerm(5, 1.0, 60.1, 23.8);

  docA->AddTerm(6, 1.0, 20.1, 13.8);
  docB->AddTerm(6, 1.0, 66.1, 3.8);
  EXPECT_DOUBLE_EQ(reranker.CalcNewSimilarity(*docA, *docB, 0.32), 0.32);
}