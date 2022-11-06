/** @file Conjunto_Alfabetos.cc
    @brief Código de la clase Conjunto_Alfabetos
*/

#include "../Cabeceras/Conjunto_Alfabetos.hh"

Conjunto_Alfabetos::Conjunto_Alfabetos() {
}

void Conjunto_Alfabetos::Leer_conjunto_de_alfabetos() {
    int numConj;
    cin >> numConj;
    for (int i = 0; i < numConj; i++) {
        string ida;
        cin >> ida;
        Alfabeto al;
        al.Leer_Alfabeto();
        ConjuntoDeAlfabetos[ida] = al;
    }
}

void Conjunto_Alfabetos::Anadir_alfabeto(string identificador_del_alfabeto) {
    Alfabeto a;
    a.Leer_Alfabeto();
    ConjuntoDeAlfabetos[identificador_del_alfabeto] = a;
    cout << ConjuntoDeAlfabetos.size() << endl;
}

void Conjunto_Alfabetos::Borrar_alfabeto (string identificador_del_alfabeto) {
    ConjuntoDeAlfabetos.erase(identificador_del_alfabeto);
    cout << ConjuntoDeAlfabetos.size() << endl;
}

void Conjunto_Alfabetos::Listar_alfabetos() const {
    map<string, Alfabeto>::const_iterator it = ConjuntoDeAlfabetos.begin();
    int n = 1;
    while ( it != ConjuntoDeAlfabetos.end()) {
        cout << n <<". " << it -> first << endl;
        it -> second.Imprimir_Alfabeto();
        ++n;
        ++it;
    }
}

void Conjunto_Alfabetos::Anadir_mensaje_al_conjunto(string ida) {
    ConjuntoDeAlfabetos[ida].Anadir_Mensaje();
}

void Conjunto_Alfabetos::Borrar_mensaje_al_conjunto(string ida) {
    ConjuntoDeAlfabetos[ida].Suprimir_Mensaje();
}

Alfabeto Conjunto_Alfabetos::Consultar_alfabeto(string Identificador) const{
    return ConjuntoDeAlfabetos.at(Identificador);
}

bool Conjunto_Alfabetos::Existe_alfabeto(string identificador_de_alfabeto) {
    return ConjuntoDeAlfabetos.find(identificador_de_alfabeto) != ConjuntoDeAlfabetos.end();
}