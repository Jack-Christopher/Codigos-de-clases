#include <iostream>
#include "persona.h"
#include "arreglo.h"

using namespace std;


int main()
{
	//Se declara un objeto de clase ArregloDePersonas
	ArregloDePersonas a1;
	
	
	string nombre1 = "Julio", apellido1 = "Lopez";
	string nombre2 = "Miguel", apellido2 = "Fernandez";
	string nombre3 = "Mario", apellido3 = "Delgado";
	
	//Se declarandos objetos de calse Persona
	Persona p1(nombre1 , apellido1, 10);
	Persona p2(nombre2 , apellido2, 25);
	Persona p3(nombre3, apellido3, 50);
		
	//Se añaden al final del arreglo
	a1.push_back(p1);
	a1.push_back(p2);
	
	//Se redimensiona a 4 elementos, como ya hay 2, se inicializan 2 más
	a1.redimensionar(4);
	//Se inserta el elemento p3 en el indice 2
	a1.insert(2,p3);
	//Se elimina el elemento del indice 1
	a1.remove(1);
	
	cout<<endl<< "La longitud del arreglo actual es : "<< a1.getSize()<<endl <<endl;
	
	a1.imprimir_arreglo();
		
	return 0;
}
