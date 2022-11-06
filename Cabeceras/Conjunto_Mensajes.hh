/** @file Conjunto_Mensajes.hh
    @brief Especificación de la clase Conjunto_Mensajes
*/

#ifndef _CONJUNTO_MENSAJES_HH_
#define _CONJUNTO_MENSAJES_HH_

//####################################################
// Includes en diagrama
#include "Mensaje.hh"
#include "Conjunto_Alfabetos.hh"

//####################################################
#ifndef NO_DIAGRAM
// Fuera de diagrama
#include <map>
#include <vector>
#endif
//####################################################

/** @class Conjunto_Mensajes
    @brief Representa el conjunto de características y operaciones que se podrá realizar sobre un conjunto de mensajes. 
   
    Ofrece la operación de lectura y de listar en la consola los mensajes miembros en el conjunto. También ofrece 
    las operaciones de añadir mensajes y borrar mensajes del conjunto.
    
    Existen dos operaciones para codificar menjaes que se encuentran guardados en el conjunto, una por substitucion y otra por permutacion

    Como voy a tener que acceder a los mensajes del conjunto voy a implementar el conjunto como un map de strings como 
    identificadores y mensajes.

    Por último hay dos operaciones que retornan un booleano como true si existe un mensaje con un identificador de mensaje o identificador de alfabeto determinado

*/
class Conjunto_Mensajes {
    public:
    //Constructoras

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un Conjunto de mensajes.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de mensajes vacio
        \coste Constante
    */  
    Conjunto_Mensajes();
    
    /** @brief Se leerá un número inicial de mensajes M ≥ 0 y una secuencia de
            M mensajes. Cada mensaje vendrá precedido por un string, que servirá como identifi-
            cador del mismo y del identificador del alfabeto al que pertenece. Se garantiza que los
            identificadores de los mensajes no están repetidos y que los alfabetos están entre los
            anteriormente leídos.
     
        \pre <em>cierto</em>
        \post Retorna el map de los mensajes leidos.
    */
    void Leer_conjunto_de_mensajes(Conjunto_Alfabetos& conj_alfabetos);

    /** @brief Esta operacion añade un mensaje al conjunto
     *      Se lee y añade un nuevo mensaje con identificador idm y el identificador de alfabeto ida
     
        \pre No existe ningun mensaje con el mismo identificador de mensaje en el conjunto i existe un alfabeto con ese identificador.
        \post Añade el mensaje leido al conjunto de mensajes y se imprime el número de mensaje M después de añadirlo. 
    */
    void Anadir_mensaje(string identificador_de_mensaje, string identificador_de_alfabeto, Conjunto_Alfabetos& conj_alfabetos);

    /** @brief Operacion que borra un mensaje del conjunto.
     *      Se lee y elimina del sistema un mensaje con un identificador.Se imprime el número de mensaje M después de borrarlo. 
            Si más tarde se añade otro mensaje con el mismo identificador es como si el anterior no hubiera existido.

        \pre Existe un mensaje con ese identificador en el conjunto
        \post Borra un mensaje del conjunto y imprime el numero M de mensajes que quedan despues de borrarlo
    */
    void Borrar_mensaje(string identificador_de_mensaje, Conjunto_Alfabetos& conj_alfabetos);

    /** @brief Operacion que lista los mensajes
     *      Se listan los mensajes del sistema en orden creciente de identificador. 
        \pre <em>cierto</em>
        \post Imprime el conjunto de mensajes.
    */
    void Listar_mensajes() const;

    /** @brief Operacion que codifica por substitucion un mensaje guardado en el conjunto
      
        \pre Existe un mensaje con el identificador identificador de mensaje
        \post Imprime el mensaje codificado por substitucion
    */
    void Codificar_substitucion_guardado(string identificador_del_mensaje, const Conjunto_Alfabetos& conj_alfabetos);
    
    /** @brief Operacion que codifica por permutacion un mensaje guardado en el conjunto
      
        \pre Existe un mensaje con el identificador identificador de mensaje
        \post Imprime el mensaje permutacion por substitucion
    */
    void Codificar_permutacion_guardado(int tamaño_de_bloque, string identificador_del_mensaje);

    /** @brief Operacion que retorna true si existe almenos un mensaje con ese idetificador de alfabeto y falso en cualquier otro caso
      
        \pre <em>cierto</em>
        \post Operacion que retorna true si existe almenos un mensaje con ese idetificador de alfabeto y falso en cualquier otro caso
    */
    bool Existe_mensajes_con_alfabeto(string identificador_de_alfabeto, const Conjunto_Alfabetos& conj_Alfabetos);

    /** @brief Operacion que retorna true si existe almenos un mensaje con ese idetificador y falso en cualquier otro caso
      
        \pre <em>cierto</em>
        \post Operacion que retorna true si existe almenos un mensaje con ese idetificador y falso en cualquier otro caso
    */
    bool Existe_mensajes(string identificador_de_mensaje);

    private:
    /** @brief Conjunto de mensajes implementado como un mapa con una clave de identificadores 
        como string y elementos que son mensajes */
    map<string,Mensaje> ConjuntoDeMensajes;
};
#endif