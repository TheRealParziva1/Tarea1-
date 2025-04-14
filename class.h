#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Pregunta {
private:
    string pregunta;
    string tipo;         // "verdadero o falso" o "opcion multiple"
    string respuesta;
    string nivelBloom;
    int tiempo;
    int anio;

public:
    // Constructor
    Pregunta(string pregunta, string tipo, string respuesta, string nivelBloom, int tiempo, int anio);

    // Destructor
    ~Pregunta();

    // Getters
    string getPregunta();
    string getTipo();
    string getRespuesta();
    string getNivelBloom();
    int getTiempo();
    int getAnio();

    // Setters
    void setPregunta(string nuevaPregunta);
    void setRespuesta(string nuevaRespuesta);
    void setNivelBloom(string nuevoNivel);
    void setTiempo(int nuevoTiempo);
    void setAnio(int nuevoAnio);

    // Mostrar pregunta
    void mostrar();
};
class Item {
private:
    Pregunta* preguntas[100]; // Arreglo de punteros (máximo 100 preguntas)
    int cantidad;
public:
    Item();
    ~Item();

    void agregarPregunta(string pregunta, string tipo, string respuesta, string nivelBloom, int tiempo, int anio);
    void mostrarPreguntas();
    void buscarNivelBloom(string nivelBloom);
    void buscarAnio(int anio);
    void CalcularTiempototal();
    bool PreguntaRepetida(string pregunta, int anio);

};
void ejecutarMenu();