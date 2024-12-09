Piezas::Piezas()
{
  board = std::vector<std::vector<Piece>>(BOARD_ROWS, std::vector<Piece>(BOARD_COLS,Blank));
  turn = X;
}