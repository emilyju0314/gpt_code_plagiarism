TEST(PiezasTest, O_first_turn)
{
  Piezas bb = Piezas();
  //Need to drop a piece first to switch turns
  bb.dropPiece(0);
  Piece O_ret = bb.dropPiece(0);
  ASSERT_EQ(O_ret, O);
}