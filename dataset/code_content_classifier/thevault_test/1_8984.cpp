bool validate_attempt(const GameOptions& game_options, const Code& attempt){
        bool att= false;
        // comparaison du nombre de caracteres de l essai et celui du secret_code

        if (attempt.value.length() == game_options.number_of_characters_per_code ){
            att = true;
            std::cout << "proper number of allowed character" << std::endl;
        }
        else{
            att= false;
            std::cout << " no proper number of allowed character" << std::endl;
        
        }
        return att;
        //-----------------------------------------------------------------------------------------
        

        // on verifie que les caracteres du attempt soient compris entre les min et max allowed character
        //  pour chaque valeur i de attempt on compare avec les min et max allowed character
        bool att2= true;

        unsigned int i = 0;
        while (att2 ==true &&  i < game_options.number_of_characters_per_code){
             att2= (attempt.value[i] > game_options.minimum_allowed_character && attempt.value[i]< game_options.maximum_allowed_character );
             i++; 
            
         }
        return att2;
        
    }