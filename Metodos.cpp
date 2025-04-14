#include <iostream>
#include <vector>
#include <string>
#include "class.h"
using namespace std;

Pregunta::Pregunta(string pregunta, string tipo, string respuesta, string nivelBloom, int tiempo, int anio) {
  this->pregunta = pregunta;
  this->tipo = tipo;
  this->respuesta = respuesta;
  this->nivelBloom = nivelBloom;
  this->tiempo = tiempo;
  this->anio=anio;
}

Pregunta::~Pregunta() {
  cout << "Destruyendo Pregunta : " <<pregunta<< endl;
}

// Getters
string Pregunta::getPregunta() { return this->pregunta; }
string Pregunta::getTipo() { return this->tipo; }
string Pregunta::getRespuesta() { return this->respuesta; }
string Pregunta::getNivelBloom() { return this->nivelBloom; }
int Pregunta::getTiempo() { return this->tiempo; }
int Pregunta::getAnio(){return this->anio;}

// Setters
void Pregunta::setPregunta(string nuevoTexto) {
  this->pregunta = nuevoTexto;
}
void Pregunta::setRespuesta(string nuevaRespuesta) {
  this->respuesta = nuevaRespuesta;
}
void Pregunta::setNivelBloom(string nuevoNivel) {
  this->nivelBloom = nuevoNivel;
}
void Pregunta::setTiempo(int nuevoTiempo) {
  this->tiempo = nuevoTiempo;
}
void Pregunta::setAnio(int nuevoAnio){
  this->anio=nuevoAnio;
}
// Mostrar
void Pregunta::mostrar() {

  cout << "Pregunta: " << pregunta << endl;
  cout << "Tipo: " << tipo << endl;
  cout << "Respuesta: " << respuesta << endl;
  cout << "Nivel Bloom: " << nivelBloom << endl;
  cout << "Tiempo estimado: " << tiempo << " min" << endl;
  cout << "Año: "<< anio<< endl;
}
Item::Item() {
  cantidad = 0;
  for (int i = 0; i < 100; i++) {
      preguntas[i] = nullptr;//Puntero nulo
  }
}

Item::~Item() {
  for (int i = 0; i < cantidad; i++) {
      delete preguntas[i];
  }
  cout << "Destructor del Banco de Preguntas" << endl;
}
bool Item:: PreguntaRepetida(string pregunta, int anio){
  for(int i =0; i <cantidad; i++){
    if(preguntas[i]->getPregunta()==pregunta && preguntas[i]->getAnio()==anio){
      return true;}
  }
  return false;
}


void Item::agregarPregunta(string pregunta, string tipo, string respuesta, string nivelBloom, int tiempo, int anio) {
  if (cantidad < 100) {
      if(PreguntaRepetida(pregunta, anio)){
        cout << "La pregunta esta repetida de un año anterior.\n"<< endl;
        return;
      }
      preguntas[cantidad] = new Pregunta(pregunta, tipo, respuesta, nivelBloom, tiempo, anio);
      cantidad++;
      cout << "Pregunta agregada correctamente.\n"<< endl;
  } else {
      cout << "No se pueden agregar más preguntas (límite alcanzado).\n";
  }
}

void Item::mostrarPreguntas() {
  if (cantidad == 0){
    cout<<"No hay preguntas."<<endl;
    return;
  }
  for (int i = 0; i < cantidad; i++) {
      cout << "-----------------------------" << endl;
      preguntas[i]->mostrar();
  }
}
void Item::buscarNivelBloom(string nivel) {
  bool encontrado = false;
  for (int i = 0; i < cantidad; i++) {
      if (preguntas[i]->getNivelBloom() == nivel) {
          preguntas[i]->mostrar();
          cout << "---------------------------" << endl;
          encontrado = true;
      }
  }
  if (!encontrado) {
      cout << "No se encontraron preguntas para el nivel: " << nivel << endl;
  }
}

void Item::buscarAnio(int anio) {
  bool encontrado = false;
  for (int i = 0; i < cantidad; i++) {
      if (preguntas[i]->getAnio() == anio) {
          preguntas[i]->mostrar();
          cout << "---------------------------" << endl;
          encontrado = true;
      }
  }
  if (!encontrado) {
      cout << "No se encontraron preguntas para el año: " << anio << endl;
  }
}

void Item::CalcularTiempototal() {
  int total = 0;
  for (int i = 0; i < cantidad; i++) {
      total += preguntas[i]->getTiempo();
  }
  cout << "🕒 Tiempo total estimado: " << total << " minutos." << endl;
}


    void ejecutarMenu() {
        Item banco;
        int opcion;
        bool repetir = true;

        do {
            cout << "\n===== MENÚ DE PREGUNTAS =====" << endl;
            cout << "1.Agregar pregunta" << endl;
            cout << "2.Mostrar todas las preguntas" << endl;
            cout << "3.Buscar por nivel Bloom" << endl;
            cout << "4. Buscar por año" << endl;
            cout << "5. Calcular tiempo total" << endl;
            cout<<  "6. Eliminar pregunta"<<endl;
            cout << "0. Salir" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
            case 1: {
                string preguntas, tipo, respuesta, nivel;
                int tiempo, anio;

                cout << "Ingrese el texto de la pregunta: ";
                getline(cin, preguntas);
                cout << "Tipo (VF/OM): ";
                getline(cin, tipo);
                cout << "Respuesta: ";
                getline(cin, respuesta);
                cout << "Nivel Bloom: ";
                getline(cin, nivel);
                cout << "Tiempo estimado (min): ";
                cin >> tiempo;
                cout << "Año: ";
                cin >> anio;
                cin.ignore();

                banco.agregarPregunta(preguntas, tipo, respuesta, nivel, tiempo, anio);
                break;
            }
            case 2:{
                banco.mostrarPreguntas();
                break;}
            case 3: {
                string nivel;
                cout << "Ingrese nivel Bloom a buscar: ";
                getline(cin, nivel);
                banco.buscarNivelBloom(nivel);
                break;
            }
            case 4: {
                int anio;
                cout << "Ingrese año a buscar: ";
                cin >> anio;
                cin.ignore();
                banco.buscarAnio(anio);
                break;
            }
            case 5:{
                banco.CalcularTiempototal();
                break;}
            case 6:
                delete(Item)
                break;
            case 0:
                repetir = false;
                break;
            default:
                cout << "Opción inválida." << endl;
            }


            }
        } while (repetir);}