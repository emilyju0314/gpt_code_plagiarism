void display_board(std::ostream& output_stream, const GameOptions& game_options, const Board& board){
        if (is_win(game_options, board) || is_end_of_game(game_options, board))
         {
             output_stream << "\n--------------------------------\n"
                           << "| secret   ";
             for (auto sc : board.secret_code.value)
             {
                 output_stream << sc;
                 output_stream << " ";
             }
         }
         else
         {

             output_stream << "--------------------------------\n"
                           << "| secret   ";
             for (unsigned i = 0; i < game_options.number_of_characters_per_code; i++)
             {
                 output_stream << "* ";
             }
         }
         output_stream << "|              |\n--------------------------------\n"
                       << "| attempts ";

         for (unsigned j = 0; j < game_options.number_of_characters_per_code; j++)
         {
             output_stream << "  ";
         }
         output_stream << "| bulls | cows |\n "
                       << "--------------------------------\n";

         for (unsigned k = game_options.max_number_of_attempts; k > 0; k--)
         {
             std::string point{};
             for (unsigned l = 0; l < game_options.number_of_characters_per_code; l++)
             {
                 point += ". ";
             }
             if (board.attempts_and_feedbacks.size() < k)
             {
                 if (k < 10)
                     output_stream << "| #0";
                 else
                     output_stream << "| #";
                 output_stream << k << "      " << point << "|       |      |\n";
             }
             else
             {
                 if (k < 10)
                     output_stream << "| #0";
                 else
                     output_stream << "| #";
                 output_stream << k << "      ";
                 for (auto byone : board.attempts_and_feedbacks.at(k - 1).attempt.value)
                 {
                     output_stream << byone;
                     output_stream << " ";
                 }
                 output_stream << "|   " << board.attempts_and_feedbacks.at(k - 1).feedback.bulls << "   |  "
                               << board.attempts_and_feedbacks.at(k - 1).feedback.cows << "   |\n";
             }
         }
         output_stream << "--------------------------------\n";
    }