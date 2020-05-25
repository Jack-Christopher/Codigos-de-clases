
using namespace std;

class Persona
{
	string nombre;
	string apellidos;
	int edad;
		
	public:
		Persona *siguiente;
		Persona();
		Persona(string name, string last_name, int age);
		void copiar(const Persona &copia);
		string getNombre() const;
		string getApellidos() const;
		int getEdad() const;
		void setNombre(const string name) ;
		void setApellidos(const string last_name) ;
		void setEdad(const int age) ;
		
};

Persona::Persona()
{
	nombre = "o";
	apellidos= "o";
	edad = 0;
	siguiente = NULL;
}

Persona::Persona(string name, string last_name, int age)
{
	nombre = name;
	apellidos = last_name;
	edad = age;
}

string Persona::getNombre() const
{
	return nombre;
}

string Persona::getApellidos() const
{
	return apellidos;
}
 
int Persona::getEdad() const
{
	return edad;
}

void Persona::setNombre(const string name) 
{
	nombre = name;
}

void Persona::setApellidos(const string lastName) 
{
	apellidos = lastName;
}

void Persona::setEdad(const int age) 
{
	edad = age;
}

void Persona::copiar(const Persona &copia)
{
	nombre = copia.nombre;
	apellidos = copia.apellidos;
	edad = copia.edad;
}




