/** @file Mensaje.cc
    @brief Código de la clase Mensaje
*/

#include "../Cabeceras/Mensaje.hh"

Mensaje::Mensaje() {
};

void Mensaje::Leer_Mensaje() {
    cin.ignore();
    getline(cin,mensaje);
}

void Mensaje::Leer_Mensaje(string identificador_de_alfabeto) {
    id_alfabeto = identificador_de_alfabeto;
    Leer_Mensaje();
}

void Mensaje::Imprimir_Mensaje() const {
    cout << id_alfabeto << endl;
    cout << '"' << mensaje << '"' << endl;
}

void Mensaje::Codificar_substitucion(const Conjunto_Alfabetos& conj_alfabetos) {
    // Copia temporal del alfabeto para evitar busquedas inecesarias al conjunto de alfabetos y asi ahorrar tiempo
    const Alfabeto a = conj_alfabetos.Consultar_alfabeto(id_alfabeto);
    a.Imprimir_Alfabeto();

}

void Mensaje::Descodificar_substitucion(const Conjunto_Alfabetos& conj_alfabetos) {
    // Copia temporal del alfabeto para evitar busquedas inecesarias al conjunto de alfabetos y asi ahorrar tiempo
    Alfabeto a = conj_alfabetos.Consultar_alfabeto(id_alfabeto);
    a.Imprimir_Alfabeto();
}

void Mensaje::Codificar_permutacion(int Tam_bloque) {
    cout << "Se codifica por permutacion el mensaje con el tamaño de bloque " << Tam_bloque << endl;;
}

void Mensaje::Descodificar_permutacion(int Tam_bloque) {
    cout << "Se descodifica por permutacion el mensaje con el tamaño de bloque " << Tam_bloque << endl;;
}

void Mensaje::Leer_Clave() {
    cin >> Clave;
}

string Mensaje::Identificador_de_alfabeto() {
    return id_alfabeto;
}