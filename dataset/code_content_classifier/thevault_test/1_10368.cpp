TEST_F(PerspectiveGeometryTest, LessThan5CommonTerms) {
  EXPECT_DOUBLE_EQ(reranker.CalcNewSimilarity(*docA, *docB, 0.32), 0.32);
  docA->AddTerm(1, 1.0, 30.0, 30.0);
  EXPECT_DOUBLE_EQ(reranker.CalcNewSimilarity(*docA, *docB, 0.32), 0.32);
  docB->AddTerm(2, 1.0, 25.0, 23.1);
  EXPECT_DOUBLE_EQ(reranker.CalcNewSimilarity(*docA, *docB, 0.32), 0.32);
  docB->AddTerm(3, 1.0, 34.7, 28.0);
  EXPECT_DOUBLE_EQ(reranker.CalcNewSimilarity(*docA, *docB, 0.32), 0.32);
  docB->AddTerm(4, 1.0, 10.6, 40.1);
  EXPECT_DOUBLE_EQ(reranker.CalcNewSimilarity(*docA, *docB, 0.32), 0.32);
  docB->AddTerm(5, 1.0, 60.1, 23.8);
  EXPECT_DOUBLE_EQ(reranker.CalcNewSimilarity(*docA, *docB, 0.32), 0.32);
  
}