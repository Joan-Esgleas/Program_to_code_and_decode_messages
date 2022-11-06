/** @file Conjunto_Alfabetos.hh
    @brief Especificación de la clase Conjunto_Alfabetos
*/

#ifndef _CONJUNTO_ALFABETOS_HH_
#define _CONJUNTO_ALFABETOS_HH_

//####################################################
// Includes en diagrama
#include "Alfabeto.hh"

//####################################################
#ifndef NO_DIAGRAM
// Fuera de diagrama
#include <map>
#endif
//####################################################

/** @class Conjunto_Alfabetos
    @brief Representa el conjunto de características y operaciones que se podrá realizar sobre un conjunto de Alfabetos. 
    
    Ofrece la operación de lectura y de listar en la consola los alfabetos miembros en el conjunto.
    También ofrece las operaciones de añadir alfabetos y borrar alfabetos del conjunto.
    Dado a que es posible que otra classe quiera acceder a algun alfabeto concreto del conjunto, 
    he creado una operación de consulta que retorna un alfabeto del conjunto identificado con un identificador proporcionado. 
    
    Como también voy a necesitar saber si existe o no cierto alfabeto en el conjunt he creado una operacion de consulta que 
    retorna un booleano como true si el alfabeto existe y como falso si no existe

    Como voy a tener que acceder a los alfabetos del conjunto voy a implementar el conjunto como un map de strings 
    como identificadores y alfabetos.

*/
class Conjunto_Alfabetos {
    public:
    //Constructoras

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un conjunto de alfabetos.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de alfabetos vacio.
        \coste Constante
    */  
    Conjunto_Alfabetos();

    /** @brief Operacion de lectura de un conjunto de alfabetos
    
        Se lee un número inicial de alfabetos A ≥ 0 y una secuencia de A identificadores y alfabetos.
        \pre <em>cierto</em>
        \post El conjunto adquiere los alfabetos leeidos.
        \coste Es lineal respecto al coste de la cantidad de alfabetos a leer
    */    
    void Leer_conjunto_de_alfabetos();

    /** @brief Operacion que lee y añade un alfabeto al mapa de conjuntos de alfabetos
        Se lee y añade un nuevo alfabeto con un identificador. Luego se
        imprime el número de alfabetos en el sistema después de añadirlo.

        \pre No existe un alfabeto con el mismo identificador
        \post Añade el alfabeto leeido al conjunto.
    */
    void Anadir_alfabeto(string identificador_del_alfabeto);

    /** @brief Operacion que borra un alfabeto del conjunto.
        Se lee y elimina del sistema un alfabeto con un identificador. 
        Luego se imprime el número de alfabetos A después de borrarlo. 
        Si más tarde se añade otro alfabeto con el mismo identificador es como si el anterior no hubiera existido.

        \pre Existe un alfabeto con ese identificador y no hay ningun mensaje con ese alfabeto
        \post Borra un alfabeto del conjunto
    */
    void Borrar_alfabeto (string identificador_del_alfabeto);

    /** @brief Operacion que lista los alfabetos
        Se listan los alfabetos del sistema en orden creciente de identificador. 
        
        \pre <em>cierto</em>
        \post Imprime el conjunto de alfabetos.
    */
    void Listar_alfabetos() const;

    /** @brief Operacion que retorna un alfabeto identificado con un identificador
      
        \pre Ha de existir un alfabeto con ese identificador
        \post Retorna el alfabeto asociado a un identificador si el alfabeto no existe retorna un alfabeto con el identificador nulo.
    */
    Alfabeto Consultar_alfabeto (string Identificador) const;

    /** @brief Booleano que retorna true si existe al menos 1 alfabeto con este identificador y falso en cualqueir otro caso
     
        \pre <em>cierto</em>
        \post Retorna true si existe almenos 1 alfabeto con ese identificador y falso en cualquier otro caso.
    */
    bool Existe_alfabeto(string identificador_de_alfabeto);

    /** @brief Operacion que suma 1 a la cantidad de mensajes con ese alfabeto.
        
        \pre Existe un alfabeto con el identificador ida
        \post Suma 1 a la cantidad de mensajes con ese alfabeto.
    */
    void Anadir_mensaje_al_conjunto(string ida);

    /** @brief Operacion que resta 1 a la cantidad de mensajes con ese alfabeto.
        
        \pre Existe un alfabeto con el identificador ida
        \post Resta 1 a la cantidad de mensajes con ese alfabeto.
    */
    void Borrar_mensaje_al_conjunto(string ida);

    private:
        /** @brief Conjunto de alfabetos implementado como un mapa con una clave de identificadores 
        como string y elementos que son alfabeto */
        map<string,Alfabeto> ConjuntoDeAlfabetos;
};
#endif