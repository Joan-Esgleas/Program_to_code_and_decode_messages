/** @file Alfabeto.cc
    @brief Código de la clase Alfabeto
*/

#include "../Cabeceras/Alfabeto.hh"

Alfabeto::Alfabeto() {
    Alfabeto_Ordenado = false;
    Es_especial_el_alfabeto = false;
    CantidadDeMensajes = 0;
}

void Alfabeto::Leer_Alfabeto() {
    cin.ignore();
    getline (cin,alfabeto);
    Alfabeto_Ordenado = Mirar_si_el_alfabeto_esta_ordenado();
    Es_especial_el_alfabeto = Mirar_si_el_alfabeto_es_especial();
}

char Alfabeto::Codificar_letra_en_la_matriz_de_permutacion (const char& m, const char& c) {
    if (Alfabeto_Ordenado) return Codifica_letra_en_la_matriz_de_permutacion_ordenado (m, c);
    else return Codificar_letra_en_la_matriz_de_permutacion_no_ordenado (m, c);
}

char Alfabeto::Decodificar_letra_en_la_matriz_de_permutacion (const char& x, const char& c) {
    if (Alfabeto_Ordenado) return Decodificar_letra_en_la_matriz_de_permutacion_ordenado(x, c);
    else return Decodificar_letra_en_la_matriz_de_permutacion_no_ordenado(x, c);
}

void Alfabeto::Imprimir_Alfabeto() const {
    if (Es_especial_el_alfabeto) {
        cout << "especial ";
        cout << '[' << alfabeto[0] << ".." << alfabeto[alfabeto.size()-1] << "] ";
    }
    else {
        cout << "normal ";
        cout << '"' << alfabeto << '"' << ' ';
    }
    cout << CantidadDeMensajes << " mensajes" << endl;
}

int Alfabeto::Cantidad_De_Mensajes() const{
    return CantidadDeMensajes;
}

void Alfabeto::Anadir_Mensaje() {
    ++CantidadDeMensajes;
}

void Alfabeto::Suprimir_Mensaje() {
    --CantidadDeMensajes;
}

bool Alfabeto::Mirar_si_el_alfabeto_esta_ordenado() {
    return is_sorted(alfabeto.begin(), alfabeto.end());
}

bool Alfabeto::Mirar_si_el_alfabeto_es_especial() {
    int i = 0;
    int j = 0;
    bool r = true;
    while (i < alfabeto.size()/2 and r) {
        if (alfabeto[i] + (alfabeto.size() - 1) - j != alfabeto[(alfabeto.size()-1)-i]) r = false;
        j += 2;
        ++i;
    }
    return r;
}

char Alfabeto::Codifica_letra_en_la_matriz_de_permutacion_ordenado (const char& m, const char& c) {
    return m + c;
}

char Alfabeto::Codificar_letra_en_la_matriz_de_permutacion_no_ordenado (const char& m, const char& c) {
    return m + c;
}

char Alfabeto::Decodificar_letra_en_la_matriz_de_permutacion_ordenado (const char& x, const char& c) {
    return x + c;
}

char Alfabeto::Decodificar_letra_en_la_matriz_de_permutacion_no_ordenado (const char& x, const char& c) {
    return x + c;
}