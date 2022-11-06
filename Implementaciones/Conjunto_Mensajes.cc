/** @file Conjunto_Mensajes.cc
    @brief Código de la clase Conjunto_Mensajes
*/

#include "../Cabeceras/Conjunto_Mensajes.hh"

Conjunto_Mensajes::Conjunto_Mensajes() {
}

void Conjunto_Mensajes::Leer_conjunto_de_mensajes(Conjunto_Alfabetos& conj_alfabetos) {
    int numConj;
    cin >> numConj;
    for (int i = 0; i < numConj; ++i) {
        string idm;
        cin >> idm;
        string ida;
        cin >> ida;
        Mensaje m;
        m.Leer_Mensaje(ida);
        ConjuntoDeMensajes[idm] = m;
        conj_alfabetos.Anadir_mensaje_al_conjunto(ida);
    }
}

void Conjunto_Mensajes::Anadir_mensaje(string identificador_de_mensaje, string identificador_de_alfabeto, Conjunto_Alfabetos& conj_alfabetos) {
    Mensaje m;
    m.Leer_Mensaje(identificador_de_alfabeto);
    ConjuntoDeMensajes[identificador_de_mensaje] = m;
    conj_alfabetos.Anadir_mensaje_al_conjunto(identificador_de_alfabeto);
    cout << ConjuntoDeMensajes.size() << endl;
}

void Conjunto_Mensajes::Borrar_mensaje(string identificador_de_mensaje, Conjunto_Alfabetos& conj_alfabetos) {
    ConjuntoDeMensajes.erase(identificador_de_mensaje);
    conj_alfabetos.Consultar_alfabeto(identificador_de_mensaje).Suprimir_Mensaje();
    conj_alfabetos.Borrar_mensaje_al_conjunto(ConjuntoDeMensajes[identificador_de_mensaje].Identificador_de_alfabeto());
    cout << ConjuntoDeMensajes.size() << endl;
}

void Conjunto_Mensajes::Listar_mensajes() const{
    map<string, Mensaje>::const_iterator it = ConjuntoDeMensajes.begin();
    int n = 1;
    while ( it != ConjuntoDeMensajes.end()) {
        cout << n << ". ";
        cout << it ->first << endl;
        it->second.Imprimir_Mensaje();
        ++n;
        ++it;
    }
}

bool Conjunto_Mensajes::Existe_mensajes_con_alfabeto(string identificador_de_alfabeto, const Conjunto_Alfabetos& conj_Alfabetos) {
    return conj_Alfabetos.Consultar_alfabeto(identificador_de_alfabeto).Cantidad_De_Mensajes() != 0;
}

bool Conjunto_Mensajes::Existe_mensajes(string identificador_de_mensaje) {
    return ConjuntoDeMensajes.find(identificador_de_mensaje) != ConjuntoDeMensajes.end();
}
void Conjunto_Mensajes::Codificar_substitucion_guardado(string identificador_del_mensaje, const Conjunto_Alfabetos& conj_alfabetos) {
    ConjuntoDeMensajes.find(identificador_del_mensaje)->second.Leer_Clave();
    ConjuntoDeMensajes.find(identificador_del_mensaje)->second.Codificar_substitucion(conj_alfabetos);
}

void Conjunto_Mensajes::Codificar_permutacion_guardado(int tamaño_de_bloque, string identificador_del_mensaje) {
    ConjuntoDeMensajes.find(identificador_del_mensaje)->second.Codificar_permutacion(tamaño_de_bloque);
}