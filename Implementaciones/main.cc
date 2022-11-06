/** @file main.cc

    @brief Programa principal

    Estamos suponiendo que los datos leídos siempre son correctos, ya que
    no incluímos comprobaciones al respecto.
*/

#include "../Cabeceras/Mensaje.hh"
#include "../Cabeceras/Conjunto_Alfabetos.hh"
#include "../Cabeceras/Conjunto_Mensajes.hh"


int main () {

    Conjunto_Alfabetos conj_Alfabetos;
    Conjunto_Mensajes conj_Mensajes;

    conj_Alfabetos.Leer_conjunto_de_alfabetos();
    conj_Mensajes.Leer_conjunto_de_mensajes(conj_Alfabetos);

    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "nuevo_mensaje" or comando == "nm") {
            cout << '#' << comando << endl;
            string idm;
            string ida;
            cin >> idm >> ida;
            if (not conj_Alfabetos.Existe_alfabeto(ida)) cout << "ERROR: No existe alfabeto" << endl;
            else if (conj_Mensajes.Existe_mensajes(idm)) cout << "ERROR: Ya existe un mensaje con se identificador" <<endl;
            else {
                conj_Mensajes.Anadir_mensaje(idm, ida, conj_Alfabetos);
            }
        }
        else if (comando == "nuevo_alfabeto" or comando == "na") {
            cout << '#' << comando << endl;
            string ida;
            cin >> ida;
            if (conj_Alfabetos.Existe_alfabeto(ida)) cout << "ERROR: Ya existe un alfabeto con se identificador" <<endl;
            else conj_Alfabetos.Anadir_alfabeto(ida);
        }
        else if (comando == "borra_mensaje" or comando == "bm") {
            cout << '#' << comando << endl;
            string idm;
            cin >> idm;
            if (not conj_Mensajes.Existe_mensajes(idm)) cout << "ERROR: No existe  el mensaje" << endl;
            conj_Mensajes.Borrar_mensaje(idm, conj_Alfabetos);
        }
        else if (comando == "borra_alfabeto" or comando == "ba") {
            cout << '#' << comando << endl;
            string ida;
            cin >> ida;
            if (not conj_Alfabetos.Existe_alfabeto(ida)) cout << "ERROR: No existe el alfabeto" << endl;
            else if (conj_Mensajes.Existe_mensajes_con_alfabeto(ida, conj_Alfabetos)) cout << "ERROR: Existe un mensaje con este alfabeto" << endl;
            else conj_Alfabetos.Borrar_alfabeto(ida);
        }
        else if (comando == "listar_mensajes" or comando == "lm") {
            cout << '#' << comando << endl;
            conj_Mensajes.Listar_mensajes();
        }
        else if (comando == "listar_alfabetos" or comando == "la") {
            cout << '#' << comando << endl;
            conj_Alfabetos.Listar_alfabetos();
        }
        else if (comando == "codificar_sustitucion_guardado:" or comando == "csg") {
            cout << '#' << comando << endl;
            string idm;
            cin >> idm;
            if (not conj_Mensajes.Existe_mensajes(idm)) cout << "ERROR: El mensaje no existe" << endl;
            else conj_Mensajes.Codificar_substitucion_guardado(idm, conj_Alfabetos);
        }
        else if (comando == "codificar_sustitucion:" or comando == "cs") {
            cout << '#' << comando << endl;
            string ida;
            cin >> ida;
            cout << "/////" << endl;
            Mensaje m;
            m.Leer_Clave();
            cout << "/////" << endl;
            m.Leer_Mensaje(ida);
            cout << "/////" << endl;
            if(not conj_Alfabetos.Existe_alfabeto(ida)) cout << "ERROR: No existe el alfabeto" << endl;
            else m.Codificar_substitucion(conj_Alfabetos);
        }
        else if (comando == "decodificar_sustitución:" or comando == "ds") {
            cout << '#' << comando << endl;
            string ida;
            cin >> ida;
            Mensaje m;
            m.Leer_Clave();
            m.Leer_Mensaje(ida);
            if(not conj_Alfabetos.Existe_alfabeto(ida)) cout << "ERROR: No existe el alfabeto" << endl;
            else m.Descodificar_substitucion(conj_Alfabetos);
        }
        else if (comando == "codificar_permutacion_guardado:" or comando == "cpg") {
            cout << '#' << comando << endl;
            string idm;
            cin >> idm;
            int b;
            cin >> b;
            if (not conj_Mensajes.Existe_mensajes(idm)) cout << "ERROR: El mensaje no existe" << endl;
            else {
                conj_Mensajes.Codificar_permutacion_guardado(b, idm);
            }
        }
        else if (comando == "codificar_permutacion:" or comando == "cp") {
            cout << '#' << comando << endl;
            int b;
            cin >> b;
            Mensaje m;
            m.Leer_Mensaje();
            m.Codificar_permutacion(b);
        }
        else if (comando == "decodificar_permutacion:" or comando == "dp") {
            cout << '#' << comando << endl;
            int b;
            cin >> b;
            Mensaje m;
            m.Leer_Mensaje();
            m.Descodificar_permutacion(b);
        }
        cin >> comando;
    }
}