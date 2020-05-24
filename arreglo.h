
class ArregloDePersonas
{
	int longitud;
	Persona *head;
	
	public:
		
		ArregloDePersonas(const Persona lista_personas[], const int tam);
		ArregloDePersonas(const ArregloDePersonas &copia);
		ArregloDePersonas();
		void redimensionar(int const n);
		void push_back(const Persona &p);
		void insert(const int posicion, const Persona &p);
		void remove(const int pos);
		const int getSize() const;
		void clear();
		
		void imprimir_arreglo();
		

		~ArregloDePersonas();
};


//Constructor que inicializa los elementos del arreglo
ArregloDePersonas::ArregloDePersonas(const Persona lista_personas[], const int tam)
{
	longitud = tam;
	
	for (int k = 0; k < longitud; k++)
	{
		push_back(lista_personas[k]);
	}
}

//Constructor copia
ArregloDePersonas::ArregloDePersonas(const ArregloDePersonas &copia)
{
	longitud = copia.longitud;
	head  = copia.head;
}

//Constructor por defecto
ArregloDePersonas::ArregloDePersonas()
{
	head = NULL;
	longitud = 0;
}

//Destructor
ArregloDePersonas::~ArregloDePersonas() 
{
	Persona *puntero = head;
	Persona *siguiente_ = NULL;
	
	//Se libera la memoria asignada con new
	while(puntero != NULL)
    {
        siguiente_ = puntero->siguiente;
        delete puntero;
        puntero = siguiente_;
    }
}


//Redimensionar el tamaño el arreglo dinámicamente
void ArregloDePersonas::redimensionar(int const n)
{
	if (n < longitud)
	{
		int diferencia1 = longitud - n;
		//Si la nueva dimension es menor, se eliminan elementos del arreglo
		for (int k = 0; k < diferencia1 ; k++)
			remove(n);		
	}
	
	else if(n > longitud)
	{
		int diferencia2 = n - longitud;
		//Si la nueva dimension es mayor, se inicializan nuevos elementos
		for (int k = 0; k < diferencia2 ; k++)
		{
			Persona *p1 = new Persona;
			push_back(*p1);
		}
	}
	
	longitud = n;
}

//Adicionar una Persona al final del arreglo
void ArregloDePersonas::push_back(const Persona &p) 
{
	//Si el arreglo está vacío 
	if(head == NULL)
    {
        Persona *p0 = new Persona();
        p0->copiar(p);
    	p0->siguiente = head;
    	//Se establece al elemento nuevo como "head"
    	head = p0;
    }
    
    else
    {
    	Persona *p1 = new Persona();
    	p1->copiar(p);
	    Persona *pointer = head;
	    //Se itera sobre los elementos y se coloca cuando ya no haya más elementos
	    while(pointer->siguiente != NULL)
    	    pointer = pointer->siguiente;
    	    
    	pointer->siguiente = p1;
	}
	
	longitud++;
}

//Insertar una Persona en cualquier posición del arreglo:
void ArregloDePersonas::insert(const int posicion, const Persona &p)
{
	Persona *copia_de_persona = new Persona();
	copia_de_persona->copiar(p);
	int copia_de_posicion = posicion;
	
    if(copia_de_posicion == 0)
    {
        copia_de_persona->siguiente = head;
        head = copia_de_persona;
        longitud++;
        return;
    }
    
    copia_de_posicion--;
    //Se itera sobre los elementos hasta el índice deseado o 
    //hasta que no haya más elementos
    Persona *puntero = head;
	while(puntero != NULL && copia_de_posicion--)
        puntero = puntero->siguiente;
    
    if(puntero==NULL)
    {
    	cout<<"No se puede efectuar la operacion...";//Faltarían elementos donde insertarlo
    	return;//Para que no se ejecuten los demás pasos
	}
    
	copia_de_persona->siguiente = puntero->siguiente;
    puntero->siguiente = copia_de_persona;
	
	longitud++;
}

//Eliminar una Persona de cualquier posición del arreglo:
void ArregloDePersonas::remove(const int pos)
{
	int posicion = pos;
	
	if(posicion == 0 )
    {
        Persona *temp = head;
        head = head->siguiente;
        delete temp;
        return;//Para no ejecutar los demás pasos
    }
    
    Persona *puntero = head;
    while(puntero->siguiente!=NULL && --posicion)
       	puntero = puntero->siguiente;
		
    if(puntero->siguiente==NULL)  return;
	    
    Persona *temp = puntero->siguiente;
    puntero->siguiente = puntero->siguiente->siguiente;
    delete temp;
	
    longitud--;

}

//Obtener el tamaño del arreglo:
const int ArregloDePersonas::getSize() const
{
	return longitud;
}

//Eliminar todos los elementos del arreglo:
void ArregloDePersonas::clear()
{
	Persona *puntero = head;
	Persona *siguiente = NULL;
	
	//Se itera sobre todos los elementos del arreglo se copia la direccion del siguiente elemento y
	// se elimina el elemento sobre el que se itera
	while(puntero != NULL)
    {
        siguiente = puntero->siguiente;
        delete puntero;
        puntero = siguiente;
    }
    
    head = NULL; 
    longitud = 0;
}

void ArregloDePersonas::imprimir_arreglo()
{
	//Se itera sobre todos los elementos y se imprimen sus datos miembro
	Persona *puntero = head;
	while(puntero != NULL)
    {
    	cout<< "Nombre: "<< puntero->getNombre()<<endl;
    	cout<< "Apellidos: "<< puntero->getApellidos()<<endl;
    	cout<< "Edad: "<< puntero->getEdad()<<endl;
    	cout<<endl;
    	
        puntero = puntero->siguiente;
    }
    
}


