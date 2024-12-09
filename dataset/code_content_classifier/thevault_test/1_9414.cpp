TEST(PiezasTest, resetCheck)
{
  Piezas bb = Piezas();
  bb.dropPiece(0);
  bb.dropPiece(0);
  bb.dropPiece(0);
  bb.dropPiece(0);

  bb.dropPiece(1);
  bb.dropPiece(1);
  bb.dropPiece(1);
  bb.dropPiece(1);

  bb.dropPiece(2);
  bb.dropPiece(2);
  bb.dropPiece(2);
  bb.dropPiece(2);

  bb.dropPiece(3);
  bb.dropPiece(3);
  bb.dropPiece(3);
  bb.dropPiece(3);

  bb.reset();

  ASSERT_EQ(bb.pieceAt(0,0),Blank);
  ASSERT_EQ(bb.pieceAt(0,1),Blank);
  ASSERT_EQ(bb.pieceAt(0,2),Blank);

}