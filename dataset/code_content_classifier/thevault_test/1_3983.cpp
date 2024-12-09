static void help(){
    printf("This is a chessboard pattern detector.\n"
           "Usage: chessfind <img>\n"
           "    -x <board_width>        # the number of inner corners on the horizontal dimension\n"
           "    -y <board_width>        # the number of inner corners on the vertical dimension\n"
           "    -s <square_size>        # the square edge length in preferred units\n"
           "    -save                   # enable saving of the pattern\n"
           "    -show                   # enable display of the pattern\n"
           "\n" );
}