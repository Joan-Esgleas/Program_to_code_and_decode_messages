/** @file Alfabeto.hh
    @brief Especificación de la clase Alfabeto
*/

#ifndef _ALFABETO_HH_
#define _ALFABETO_HH_

//####################################################
//Includes en diagrama

//####################################################
#ifndef NO_DIAGRAM
// Fuera de diagrama
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#endif
//####################################################
using namespace std;

/** @class Alfabeto
    @brief Representa el conjunto de características y operaciones de un Alfabeto. 

    Ofrece la operación de lectura y escritura de un alfabeto y las operaciones de
    codificar y descodificar characteres mediante substitución polialfabetica con los propios alfabetos.
    El alfabeto en si mismo se leera y guardará como un string.
    También para optimizar temporalmente las operaciones de codificación y descodificación creamos un booleano
    que idica si el alfabeto eseta ordenado en sentido alfa numerico para poder aplicar la busqueda binaria en 
    las operaciónes de codificación y descodificación optimizando el coste temporal.

*/
class Alfabeto {
    public:
    //Constructoras

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un Alfabeto.
        \pre <em>cierto</em>
        \post El resultado es un alfabeto vacio
        \coste Constante
    */  
    Alfabeto();

    //Operaciones

    /** @brief Operación de lectura
        
        Lee un alfabeto, despues comprueba si el alfabeto está ordenado o no

        \pre <em>cierto</em>
        \post alfabeto = alfabeto leido; indica si el alfabeto leido esta ordenado o no
        \coste Logaritmico respecto al tamaño del alfabeto
    */
    void Leer_Alfabeto();

    /** @brief Operación que imprime el alfabeto en la consola

        \pre <em>cierto</em>
        \post Imprime el alfabeto
        \coste constante 
    */
    void Imprimir_Alfabeto() const;

    /** @brief Operación de Codificación de una letra de la matriz de permutación
     
        Codifica una letra m, con una clave c segun la matriz generada por el afabeto \n
        Ej: Un alfabeto de todas las letras de la a a la z en minuscula, generaria esta matriz: \n

        a b c d e f g h i j k l m n o p q r s t u v w x y z \n
        b c d e f g h i j k l m n o p q r s t u v w x y z a \n
        c d e f g h i j k l m n o p q r s t u v w x y z a b \n
        d e f g h i j k l m n o p q r s t u v w x y z a b c \n
        e f g h i j k l m n o p q r s t u v w x y z a b c d \n
        f g h i j k l m n o p q r s t u v w x y z a b c d e \n
        g h i j k l m n o p q r s t u v w x y z a b c d e f \n
        h i j k l m n o p q r s t u v w x y z a b c d e f g \n
        i j k l m n o p q r s t u v w x y z a b c d e f g h \n
        j k l m n o p q r s t u v w x y z a b c d e f g h i \n
        k l m n o p q r s t u v w x y z a b c d e f g h i j \n
        l m n o p q r s t u v w x y z a b c d e f g h i j k \n
        m n o p q r s t u v w x y z a b c d e f g h i j k l \n
        n o p q r s t u v w x y z a b c d e f g h i j k l m \n
        o p q r s t u v w x y z a b c d e f g h i j k l m n \n
        p q r s t u v w x y z a b c d e f g h i j k l m n o \n
        q r s t u v w x y z a b c d e f g h i j k l m n o p \n
        r s t u v w x y z a b c d e f g h i j k l m n o p q \n
        s t u v w x y z a b c d e f g h i j k l m n o p q r \n
        t u v w x y z a b c d e f g h i j k l m n o p q r s \n
        u v w x y z a b c d e f g h i j k l m n o p q r s t \n
        v w x y z a b c d e f g h i j k l m n o p q r s t u \n
        w x y z a b c d e f g h i j k l m n o p q r s t u v \n
        x y z a b c d e f g h i j k l m n o p q r s t u v w \n
        y z a b c d e f g h i j k l m n o p q r s t u v w x \n
        z a b c d e f g h i j k l m n o p q r s t u v w x y \n

        Si m = d c c = c el resultado sera f

        \pre m, c existen en el alfabeto, el alfabeto no es vacio
        \post Retorna la letra asignada a la matriz de coordenadas m,c 
        \coste Depende, si el alfabeto está ordenado la busqueda es logaritmica respecto al tamaño del alfabeto, si no lo esta el coste es lineal
    */
    char Codificar_letra_en_la_matriz_de_permutacion (const char& m, const char& c);

    /** @brief Operación de decodificación de una letra de la matriz de permutación
        La entrada es un letra codificada mediante a la matriz de permutación x, con la letra clave c,
        una vez encontrada la letra x en la fila que empieza por c, se registra la posición y 
        luego retorna la letra en la posición registrada en la primera fila

        \pre x, c existen en el alfabeto, el alfabeto no es vacio
        \post Retorna la letra decodificada de x con la clave c 
        \coste Depende, si el alfabeto está ordenado la busqueda es logaritmica respecto al tamaño del alfabeto, si no lo esta el coste es lineal
    */
    char Decodificar_letra_en_la_matriz_de_permutacion (const char& x, const char& c);

    /** @brief Retorna la cantidad de mensajes en un alfabeto

        \pre <em>cierto</em>
        \post Retorna la cantidad de mensajes en un alfabeto
    */
    int Cantidad_De_Mensajes() const;

    /** @brief Añade 1 a la cantidad de mensajes que tiene ese alfabeto

        \pre <em>cierto</em>
        \post Añade 1 a la cantidad de mensajes que tiene ese alfabeto
    */
    void Anadir_Mensaje();

    /** @brief Resta 1 a la cantidad de mensajes que tiene ese alfabeto

        \pre <em>cierto</em>
        \post Resta 1 a la cantidad de mensajes que tiene ese alfabeto
    */
    void Suprimir_Mensaje();

    private:

    /** @brief alfabeto almacenado como string */
    string alfabeto;
    /** @brief alfabeto la cantidad de mensajes con este alfabeto*/
    int CantidadDeMensajes;
    /** @brief Idicador si el alfabeto esta ordenado o no true si lo está, false si no lo está*/
    bool Alfabeto_Ordenado;
    /** @brief Booleano que indica si el alfabeto es un subconjunto ordenado del alfabeto ascii*/
    bool Es_especial_el_alfabeto;

    /** @brief Operacion privada que comprueba si el alfabeto esta ordenado.

        \pre El alafabeto no esta vacio
        \post retorna true si esta ordenado false en otro caso
        \coste Logaritmico respecto la longitud del alfabeto is_sorted()
    */
    bool Mirar_si_el_alfabeto_esta_ordenado();

    /** @brief Operacion privada que comprueba si el alfabeto es un subconjunto ordenado del alfabeto ascii

        \pre El alafabeto no esta vacio
        \post retorna true si el alfabeto es un subconjunto del alfabeto ascii
        \coste Logaritmico respecto la longitud del alfabeto
    */
    bool Mirar_si_el_alfabeto_es_especial();
    
    /** @brief Operación de codificación de una letra de la matriz de permutación si el alfabeto esta ordenado

        \pre m y c existen en el alfabeto
        \post retorna el caracter codificado en la matriz
        \coste Logaritmico respecto a la longitud del alfabeto
    */
    char Codifica_letra_en_la_matriz_de_permutacion_ordenado (const char& m, const char& c);
    
    /** @brief Operación de Codificación de una letra de la matriz de permutación si el alfabeto no esta ordenado

        \pre m y c existen en el alfabeto
        \post retorna el caracter codificado en la matriz
        \coste lineal respecto a la longitud del alfabeto
    */
    char Codificar_letra_en_la_matriz_de_permutacion_no_ordenado (const char& m, const char& c);
    
    /** @brief Operación de decodificación de una letra de la matriz de permutación si el alfabeto esta ordenado

        \pre x y c existen en el alfabeto
        \post retorna el caracter dodificado en la matriz
        \coste Logaritmico respecto a la longitud del alfabeto
    */
    char Decodificar_letra_en_la_matriz_de_permutacion_ordenado (const char& x, const char& c);
    
    /** @brief Operación de decodificación de una letra de la matriz de permutación si el alfabeto no esta ordenado

        \pre x y c existen en el alfabeto
        \post retorna el caracter decodificado en la matriz
        \coste lineal respecto a la longitud del alfabeto
    */
    char Decodificar_letra_en_la_matriz_de_permutacion_no_ordenado (const char& x, const char& c);
};
#endif