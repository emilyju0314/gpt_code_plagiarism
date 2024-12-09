string tkEncrypt(string s) {

    // Definicion de variables
    string encrypted ;           // contiene el string encriptado
    string vowels    = "aeiou" ;
    string vowelsCap = "AEIOU" ;
    int vowelLocation ;          // contiene la posicion en el string donde se encuentra una vocal

    // Este loop va letra por letra en el string dado
    for (int i = 0; i < s.length(); i++) {

        // Si encuentra que la letra que corresponde al proximo
        // numero ASCII es una vocal...
        if ( vowels.find(s[i] + 1) != -1 ) {

            // Guarda la posicion donde se encuentra esta vocal dentro
            // de nuestro string de vocales
            vowelLocation = vowels.find(s[i] + 1) ;

            // Y basado en esta localizacion, intercambia la vocal
            // en minuscula por la vocal en mayuscula
            encrypted += vowelsCap[vowelLocation] ;
        }

        // Si la letra es 'z', la proxima vuelve al principo del alfabeto
        else if (s[i] == 'z') encrypted += 'A' ;

        // Normalmente, se busca la letra que corresponde al codigo ASCII proximo
        else encrypted += s[i] + 1 ;
    }

    // Devolver el string encriptado
    return encrypted ;
}