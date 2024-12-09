TEST(PiezasTest, X_win)
{
  Piezas bb = Piezas();

  bb.dropPiece(0); //X
  bb.dropPiece(1); //O
  bb.dropPiece(0); //X
  bb.dropPiece(2); //O
  bb.dropPiece(0); //X
  bb.dropPiece(3); //O
  bb.dropPiece(1); //X
  bb.dropPiece(1); //O
  bb.dropPiece(2); //X
  bb.dropPiece(2); //O
  bb.dropPiece(3); //X
  bb.dropPiece(3); //O

  Piece state = bb.gameState();
  ASSERT_EQ(state,X);


}