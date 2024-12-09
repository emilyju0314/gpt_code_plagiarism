int foo(int t) {

    // Inicializacion de variables
    int n = 0 ;
    int i = 0 ;

    // Mientras el contador i sea menor que el numero dado...
    while (i < t) {
        // A la variable n se le suma el contador i
        n += i ;
        // Y se incrementa i en 1
        i++ ;
    }

    // Al salir del loop, significa que el contador
    // sobrepaso el valor de la variable dada o es igual.

    // Devolvemos la suma de los contadores necesarios para
    // alcanzar el valor de la variable dada.
    return n ;
}