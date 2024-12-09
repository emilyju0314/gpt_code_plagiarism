Board create_board(const GameOptions& game_options){
        Board board;

        // on va declarer une classe string sc pour la concatenation de tout ce que la fonction generate_random_character renvoie.
        std::string sc = "";
        for (unsigned int i = 0; i < game_options.number_of_characters_per_code; i++) {

             // concatenation.
             sc = sc + generate_random_character(game_options.minimum_allowed_character, game_options.maximum_allowed_character);
        }

        // attribution du resultat de la concatenation au membre secret_code.
        board.secret_code.value= sc;

        return board;

        
    }