Code ask_attempt(std::ostream& output_stream, std::istream& input_stream, const GameOptions& game_options, const Board& board) {
         
         Code attempt;

         output_stream << "What's your choice #01 (" << game_options.number_of_characters_per_code
                       << " characters allowed between '" << game_options.minimum_allowed_character << "' & '"
                       << game_options.maximum_allowed_character << "') ?" << std::endl;
         input_stream >> attempt.value;

         while (!validate_attempt(game_options, attempt))
         {
             output_stream << "no allowed characters or no valid length, enter an other choice\n"
                           << "What's your choice #01 (" << game_options.number_of_characters_per_code
                           << " characters allowed between '" << game_options.minimum_allowed_character << "' & '"
                           << game_options.maximum_allowed_character << "') ?" << std::endl;
             input_stream >> attempt.value;
         }

         return attempt;
    }