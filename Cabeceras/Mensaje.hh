/** @file Mensaje.hh
    @brief Especificación de la clase Mensaje
*/

#ifndef _MENSAJE_HH_
#define _MENSAJE_HH_

//####################################################
//Includes en diagrama
#include "Alfabeto.hh"
#include "Conjunto_Alfabetos.hh"

//####################################################
#ifndef NO_DIAGRAM
// Fuera de diagrama
#include "../OmitirEnDoxygen/BinTree.hh"
#endif
//####################################################

/** @class Mensaje
    @brief Representa el conjunto de características y operaciones que se podrá realizar sobre un Mensaje.

    Ofrece las operaciones de leer y escribir mensajes. Existen dos funciones de leer mensajes 
    Tambien se ofrece las operaciones de codificación y descodificon del mensaje por substicución polialfabética por una clave y un conjunto de alfabetos pasado por parametro.
    Tambíen estan las operaciones de codificación y decodificación por permutación arbolescente con un tamanyo de bloque
    passado por parametro.
    Por último la clase también ofrece una operación de lectura de la clave

    La clase almacena 3 datos como string, el mensaje el identificador de alfabeto y por ultimo una clave
*/
class Mensaje {
    public:
    //Constructoras

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un Mensaje.
        \pre <em>cierto</em>
        \post El resultado es un Mensaje vacio
    */  
    Mensaje();
    
    /** @brief Operacion que lee un mensaje
        Lee un mensaje y lo pone en el mensaje
     
        \pre <em>cierto</em>
        \post Guarda el mensaje que se a leido.
    */
    void Leer_Mensaje();


    /** @brief Operacion que lee un mensaje
        Lee un mensaje y lo pone en el mensaje
     
        \pre Existe en un conjunto de alfabetos un alfabeto con el mismo identificador 
             que el pasado por parametro.
        \post Guarda el mensaje y el identificador de alfabeto que se a leido.
    */
    void Leer_Mensaje(string identificador_de_alfabeto);

    /** @brief Operacion que imprime el mensaje en la consola
        Imprime el mensaje y el identificador con el formato que esta por indicado
     
        \pre <em>cierto</em>
        \post Imprime el mensaje en la consola
    */ 
    void Imprimir_Mensaje() const;

    /** @brief Operacion que codifica por substitucion polialfabética.
        
        \pre Todos los caracteres de la clave y el mensaje existe en el alfabeto, 
             en el conjunto de alfabetos existe un alfabeto con el mismo identificador 
             del que dispone la classe mensaje.
        \post Imprime el mensaje codificado
    */  
    void Codificar_substitucion(const Conjunto_Alfabetos& conj_alfabetos);

    /** @brief Operacion que decodifica por substitucion polialfabética.
        
        \pre Todos los caracteres de la clave y el mensaje existe en el alfabeto, 
             en el conjunto de alfabetos existe un alfabeto con el mismo identificador 
             del que dispone la classe mensaje.
        \post Imprime el mensaje decodificado
    */
    void Descodificar_substitucion(const Conjunto_Alfabetos& conj_alfabetos);

    /** @brief Operacion que codifica por permutación arbolescente. 
            codifica el mensaje mediante el tamaño de bloque i imprime el mensaje codificado
        
        \pre Tam_bloque >= 0.
        \post Imprime el mensaje codificado
    */  
    void Codificar_permutacion(int Tam_bloque);

    /** @brief Operacion que decodifica por permutación arbolescente. 
            decodifica el mensaje mediante el tamaño de bloque i imprime el mensaje decodificado
        
        \pre Tam_bloque >= 0.
        \post Imprime el mensaje decodificado
    */  
    void Descodificar_permutacion(int Tam_bloque);

    /** @brief Operacion que lee una clave
        Lee una clave guarda en el string clave
     
        \pre <em>cierto</em>
        \post Guarda la clave en el string clave.
    */
    void Leer_Clave();

    /** @brief Consultora que retorna su identificador de alfabeto
     
        \pre <em>cierto</em>
        \post Retorna el identificador de alfabeto
    */
    string Identificador_de_alfabeto();

    private:
    /** @brief Identificador del alfabeto */
    string id_alfabeto;
    /** @brief Mensaje guardado como string */
    string mensaje;
    /**@brief Clave guardada como string*/
    string Clave;
};
#endif