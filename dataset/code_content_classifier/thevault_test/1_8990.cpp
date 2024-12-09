GameOptionsMenuChoice ask_game_options_menu_choice(std::istream& input_stream)
     {
        unsigned int c = ask_int_or_default(input_stream, -1);
         switch (c)
         {
         case 0:
             return GameOptionsMenuChoice::BackToMain;
         case 1:
             return GameOptionsMenuChoice::ModifyMaximumNumberOfAttempts;
         case 2:
             return GameOptionsMenuChoice::ModifyNumberOfCharactersPerCode;
         case 3:
             return GameOptionsMenuChoice::ModifyMinimumAllowedCharacter;
         case 4:
             return GameOptionsMenuChoice::ModifyMaximumAllowedCharacter;
         case 5:
             return GameOptionsMenuChoice::SaveOptions;
         case 6:
             return GameOptionsMenuChoice::LoadOptions;
         }
         return GameOptionsMenuChoice::Error;
     }