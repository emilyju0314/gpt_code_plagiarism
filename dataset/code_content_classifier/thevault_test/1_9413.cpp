TEST(PiezasTest, column_out_of_bound)
{
  Piezas bb = Piezas();
  Piece out_of_bound = bb.dropPiece(5);
  ASSERT_EQ(out_of_bound, Invalid);
}