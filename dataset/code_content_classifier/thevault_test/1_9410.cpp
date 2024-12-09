TEST(PiezasTest, X_first_turn)
{
  Piezas bb = Piezas();
  Piece X_ret = bb.dropPiece(0);
  ASSERT_EQ(X_ret, X);
}