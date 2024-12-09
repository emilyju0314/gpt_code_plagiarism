TEST(PiezasTest, column_full)
{
  Piezas bb = Piezas();
  bb.dropPiece(0);
  bb.dropPiece(0);
  bb.dropPiece(0);
  bb.dropPiece(0);

  Piece too_full = bb.dropPiece(0);
  ASSERT_EQ(too_full, Blank);
}