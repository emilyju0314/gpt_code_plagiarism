string tkDecrypt (string s) {

    // Definicion de variables
    string decrypted ;           // contiene el string decriptado
    string vowels    = "aeiou" ;
    string vowelsCap = "AEIOU" ;
    int vowelLocation ;          // contiene la posicion en el string donde se encuentra una vocal

    // Este loop va letra por letra en el string dado
    for (int i = 0; i < s.length(); i++) {

        // Si encuentra que la letra que corresponde al previo
        // numero ASCII es una vocal mayuscula...
        if ( vowelsCap.find(s[i] - 1) != -1 ) {

            // Guarda la posicion donde se encuentra esta vocal dentro
            // de nuestro string de vocales mayusculas
            vowelLocation = vowelsCap.find(s[i] - 1) ;

            // Y basado en esta localizacion, intercambia la vocal
            // en mayuscula por la vocal en minuscula
            decrypted += vowels[vowelLocation] ;
        }

        // Si la letra es 'A', la anterior vuelve al final del alfabeto
        else if (s[i] == 'A') decrypted += 'z' ;

        // Normalmente, se busca la letra que corresponde al codigo ASCII anterior
        else decrypted += s[i] - 1 ;
    }

    // Devolver el string decriptado
    return decrypted ;
}