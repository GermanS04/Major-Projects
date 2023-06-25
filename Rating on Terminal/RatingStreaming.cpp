//Integrantes
//German Salas Martinez A01178095
//Pedro Gabriel Sánchez Valdez A00837426
//Francisco Miguel Gonzalez Sosa A01285092

//Librerias a utilizar
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//función para saber si una opción es valida
void validarOPC(int &opc, int min, int max){
    while (opc < min || opc > max){
        cout << "Opcion no valida, ingrese una opcion valida: ";
        cin >> opc;
    }
}

//función para saber si una calificación es valida
void validarCal(float &cal, float min, float max){

    while (cal < min || cal > max){
        cout << "Calificacion no valida, ingrese una calificacion valida: ";
        cin >> cal;
    }
}

//Definición de clase Video
class Video {
protected:
    string id;
    string title;
    string duracion;
    string genero;

public:
    Video(string,string,string,string);
    Video();

    // Declaramos los metodos virtuales puros

    
    // sets para modificar los atributos
    void setId(string);
    void setTitle(string);
    void setDuracion(string);
    void setGenero(string);


    // Declaramos los gets para obtener los datos de los atributos
    string getId();
    string getTitle();
    string getDuracion();
    string getGenero();
    

    // Metodo virtual

    virtual void mostrarDatos() ;
}; 

//Definición de clase Episodio
class Episodio {
    private:
        string title;
        float calificaciones;
        int duracion;
    
    public:
        Episodio();
        Episodio(string, float, int);

        void setTitle(string);
        void setCalificaciones(float);
        void setDuracion(int);

        string getTitle();
        float getCalificaciones();
        int getDuracion();


        void mostrarDatos();

};

//Definición de clase Temporada
class Temporada{

private:
    int numero;
    vector <Episodio *> episodios;

public:
    Temporada();
    Temporada(int,vector <Episodio *>);


    void setNumero(int);
    int getNumero();
    void setEpisodios(vector <Episodio *>);
    vector <Episodio *> getEpisodios();

    void mostrarDatos();
};

//Definición de clase Serie
class Serie:public Video{

private:
    vector <Temporada> temporadas;

public:
    Serie();
    Serie(string,string,string,string,vector <Temporada>);
    void setTemporadas(vector <Temporada>);
    vector <Temporada> getTemporadas();
    void mostrarDatos();
    void mostrarEpisodios();

    Serie operator+(Temporada);
};

//Definición de clase Pelicula
class Pelicula : public Video{
    float calificaciones;

public:
    Pelicula();
    Pelicula(string, string, string, string, float);

    void setCalificaciones(float);
    float getCalificaciones();

    void mostrarDatos();
    void mostrarCalificaciones();
};


//Metodos de la clase Video
// Constructor por parametros
Video::Video(string _id, string _title, string _duracion, string _genero){
    id = _id;
    title = _title;
    duracion = _duracion;
    genero = _genero;
}

// Constructor por default
Video::Video(){
    id = "";
    title = "";
    duracion = "";
    genero = "";
}


// sets para modificar los atributos
void Video::setId(string _id){
    id = _id;
}

void Video::setTitle(string _title){
    title = _title;
}

void Video::setDuracion(string _duracion){
    duracion = _duracion;
}

void Video::setGenero(string _genero){
    genero = _genero;
}


// Declaramos los gets para obtener los datos de los atributos
string Video::getId(){
    return id;
}

string Video::getTitle(){
    return title;
}

string Video::getDuracion(){
    return duracion;
}

string Video::getGenero(){
    return genero;
}

// Metodo virtual 
void Video::mostrarDatos(){
    cout<<"------------------------"<<endl;
    cout << "ID: " << id << endl;
    cout << "Titulo: " << title << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Genero: " << genero << endl;
}


//Metodos de la clase Episodio
Episodio::Episodio(){
    title = "";
    calificaciones = {0};

}

Episodio::Episodio(string _title, float _calificaciones, int _duracion){
    title = _title;
    calificaciones = _calificaciones;
    duracion = _duracion;
}

// sets y gets para modificar los atributos
void Episodio::setTitle(string _title){
    title = _title;
}

string Episodio::getTitle(){
    return title;
}

void Episodio::setCalificaciones(float _calificaciones){
    calificaciones = _calificaciones;
}

float Episodio::getCalificaciones(){
    return calificaciones;
}

void Episodio::setDuracion(int _duracion){
    duracion = _duracion;
}

int Episodio::getDuracion(){
    return duracion;
}

// Mostrar datos de Episodio
void Episodio::mostrarDatos(){
    cout << "Title : " << title << endl;
    cout << "Duracion : " << duracion << " minutos" <<endl;
    cout << "Calificacion : " << calificaciones << endl;
}


//Metodos de la clase Temporada
Temporada::Temporada(){
    numero = 0;
    episodios = {};
    
}

Temporada::Temporada( int _numero, vector <Episodio *> _episodios){
    numero = _numero;
    episodios = _episodios;
}

// sets y gets para modificar los atributos
void Temporada::setNumero(int _numero){
    numero = _numero;
}

int Temporada::getNumero(){
    return numero;
}

void Temporada::setEpisodios(vector <Episodio *> _episodios){
    episodios = _episodios;
}

vector <Episodio *> Temporada::getEpisodios(){
    return episodios;
}

// Mostrar datos de Temporada
void Temporada::mostrarDatos(){
    for (size_t i = 0; i < episodios.size(); i++){
        cout << "Episodio " << i+1 << endl;
        episodios[i]->mostrarDatos();
        cout << endl;
    }
}

//Metodos de la clase Serie
Serie::Serie(){
    temporadas = {};
}

Serie::Serie(string _id, string _nombre, string _genero, string _duracion, vector <Temporada> _temporadas):Video(_id,_nombre,_genero,_duracion){
    temporadas = _temporadas;
}

// sets y gets para modificar los atributos
void Serie::setTemporadas(vector <Temporada> _temporadas){
    temporadas = _temporadas;
}

vector <Temporada> Serie::getTemporadas(){
    return temporadas;
}

// Mostrar episodios de la serie con sus datos
void Serie::mostrarEpisodios(){
    for(size_t i = 0; i < temporadas.size(); i++){
        cout << endl << "Temporada " << i+1 << endl<<endl;
        temporadas[i].mostrarDatos();
    }
}

// Mostrar datos de la serie
void Serie::mostrarDatos(){
    Video::mostrarDatos();
}

//metodo de sobrecarga para añadir una temporada a una serie mediante operador de suma
Serie Serie::operator+(Temporada _temporada){
    temporadas.push_back(_temporada); 
    Serie nuevaSerie(id,title,genero,duracion,temporadas);
    return nuevaSerie;
}


//Metodos de la clase Pelicula
//Constructor por default
Pelicula::Pelicula(){
    calificaciones = {0};
}

//Constructor con parametros
Pelicula::Pelicula(string _id,string _nombre,string _duracion, string _genero, float _calificaciones):Video(_id,_nombre,_duracion,_genero){
    calificaciones = _calificaciones;
}

//Setters y getters
void Pelicula::setCalificaciones(float _calificaciones){
    calificaciones = _calificaciones;
}

float Pelicula::getCalificaciones(){
    return calificaciones;
}

//Metodos
void Pelicula::mostrarDatos(){
    Video::mostrarDatos();
    mostrarCalificaciones();
}

//Metodo para mostrar las calificaciones
void Pelicula::mostrarCalificaciones(){
    cout << "Calificacion : " << calificaciones << endl;
    cout<<"--------------------------"<<endl;
}


int main(){
    //Series

    //Episodios de Beef
    Episodio ep1("Los pajaros no cantan, sino que gritan de dolor", 4.8, 39), ep2("La alegria de estar vivos", 4.5, 33), ep3("Estoy habitada por un grito", 4.3, 35),
    ep4("Pero no todo al mismo tiempo", 4.6, 36), ep5("Tales criaturas secretas e introvertidas", 4.7, 34), ep6("Dibujamos un circulo mágico", 4.8, 36),
    ep7("Soy una jaula", 4.3, 37), ep8("El drama de la elección original", 4.9, 35), ep9("El gran fabricante", 4.9, 30),
    ep10("Figuras de luz", 5.0, 33), ep11("El nuevo incio", 4.9, 35);
    
    //vector de punteros de los episodios
    vector <Episodio *> episodiosBeef {&ep1,&ep2,&ep3,&ep4,&ep5,&ep6,&ep7,&ep8,&ep9,&ep10}, episodiosBeef2{&ep11};

    //Temporadas de Beef con sus episodios
    Temporada temporada1Beef(1, episodiosBeef), temporada2Beef(2, episodiosBeef2);


    

    //Vector de temporadas de Beef
    vector <Temporada> temporadasBeef {temporada1Beef};

    //Creacion de la serie de Beef con sus caracteristicas y temporadas con episodios
    Serie beef("1", "Beef", "10:48:00", "Drama, Comedia", {temporada1Beef});

    //Metodo de sobrecarga para añadir temporada 2 a la serie
    beef = beef + temporada2Beef;
 
    //punteros de las series
    Serie *pSerie1 = &beef;

    //vector de total de series
    vector <Serie> series {beef};

    //Peliculas
    //Creacion de los objetas de peliculas
    Pelicula pelicula1("1","American Psycho","1:41:00","Suspenso/Terror",5.0);
    Pelicula pelicula2("2","El Conjuro","1:52:00","Terror",5.0);
    Pelicula pelicula3("3","El Conjuro 2","2:14:00","Terror",5.0);

    //punteros de las peliculas
    Pelicula *pPelicula1 = &pelicula1;
    Pelicula *pPelicula2 = &pelicula2;
    Pelicula *pPelicula3 = &pelicula3;

    //vector de punteros de peliculas
    vector <Pelicula *> peliculas {&pelicula1,&pelicula2,&pelicula3};


    while(true){
         //dar bienvenida al usuario
        cout << "Bienvenido a Z3tflix" << endl;

        //mostrar opciones al usuario
        cout << "Presione 1 para ver las series" << endl;
        cout << "Presione 2 para ver las peliculas" << endl;
        cout << "Presione 3 para salir" << endl;

        //variable para guardar la opcion del usuario
        int opc = 0, opcCalificar = 0, opcSerie = 0, opcTemp = 0, opcEpisodio = 0, opcPelicula = 0;

        //variable para guardar la calificacion del usuario
        float calif = 0.0;

        //guardar la opcion del usuario
        cin >> opc;

        //validar que la opcion sea valida
        validarOPC(opc,1,3);

        //si la opcion es 1 (series)
        if(opc==1){
            //mostrar las series
            cout << "Series" << endl<<endl;

            //mostrar datos de las Series y sus Temporadas y Episodios
            pSerie1->mostrarDatos(); 
            
            //preguntar si se desea calificar algo
            cout << endl << "¿Calificar algo?" << endl;
            cout << "1. Si" << endl << "2. No" << endl;

            //guardar la opcion de calificar algo del usuario
            cin >> opcCalificar;

            //validar que la opcion sea valida
            validarOPC(opcCalificar,1,2);

            //si la opcion es 1 (calificar algo)
            if(opcCalificar==1){
                //mostrar las series para que el usuario pueda elegir una a calificar
                cout << endl << "¿Que serie desea calificar?" << endl;
                for(int i = 0; i < series.size(); i++){
                    cout << i+1 <<". "<< series[i].getTitle() << endl;
                }

                //guardar la opcion de la serie a calificar
                cin >> opcSerie;

                //validar que la opcion de serie sea valida
                validarOPC(opcSerie,1,series.size());

                //mostrar las temporadas de la serie elegida para que el usuario pueda elegir una a calificar
                cout << endl << "¿Que temporada desea calificar?" << endl;
                for(int i = 0; i < series[opcSerie-1].getTemporadas().size(); i++){
                    cout << i+1 << ". Temporada " << i+1 << endl;
                }

                //guardar la opcion de la temporada a calificar
                cin >> opcTemp;

                //validar que la opcion de temporada sea valida
                validarOPC(opcTemp,1,series[opcSerie-1].getTemporadas().size());

                //mostrar los episodios de la temporada elegida para que el usuario pueda elegir uno a calificar
                cout << endl << "¿Que episodio desea calificar?" << endl;
                for(int i = 0; i < series[opcSerie-1].getTemporadas()[opcTemp-1].getEpisodios().size(); i++){
                    cout << i+1 << ". " << series[opcSerie-1].getTemporadas()[opcTemp-1].getEpisodios()[i]->getTitle() << endl;
                }
                
                //guardar la opcion del episodio a calificar
                cin >> opcEpisodio;

                //validar que la opcion de episodio sea valida
                validarOPC(opcEpisodio,1,series[opcSerie-1].getTemporadas()[opcTemp-1].getEpisodios().size());

                //pedir la calificacion del usuario
                cout << endl << "¿Que calificación quiere dar? 0 - 5" << endl;

                //guardar la calificacion del usuario
                cin >> calif;

                //validar que la calificacion sea valida
                validarCal(calif,0.0,5.0);

                //guardar la calificacion en el episodio elegido
                series[opcSerie-1].getTemporadas()[opcTemp-1].getEpisodios()[opcEpisodio-1]->setCalificaciones(calif);
                Serie *pSerie = &series[opcSerie-1];
                cout << endl << "Calificacion dada" << endl;
                cout << endl << "Datos del episodio" << endl;

                //mostrar los datos del episodio
                pSerie->mostrarEpisodios();
                cout << endl;
            }
        }

        if(opc==2){
            //mostrar las peliculas
            cout << "Peliculas" << endl<<endl;

            //mostrar datos de las peliculas
            pPelicula1->mostrarDatos();
            pPelicula2->mostrarDatos();
            pPelicula3->mostrarDatos();

            //preguntar si se desea calificar algo
            cout << endl << "¿Calificar algo?" << endl;
            cout << "1. Si" << endl << "2. No" << endl;

            //guardar la opcion de calificar algo del usuario
            cin >> opcCalificar;

            //validar que la opcion sea valida
            validarOPC(opcCalificar,1,2);

            //si la opcion es 1 (calificar algo)
            if(opcCalificar==1){
                //mostrar las peliculas para que el usuario pueda elegir una a calificar
                cout << endl << "¿Que pelicula desea calificar?" << endl;
                for(int i = 0; i < peliculas.size(); i++){
                    cout << i+1 <<". "<< peliculas[i]->getTitle() << endl;
                }

                //guardar la opcion de la pelicula a calificar
                cin >> opcPelicula;

                //validar que la opcion de pelicula sea valida
                validarOPC(opcPelicula,1,peliculas.size());

                //pedir la calificacion del usuario
                cout << endl << "¿Que calificación quiere dar? 0 - 5" << endl;

                //guardar la calificacion del usuario
                cin >> calif;

                //validar que la calificacion sea valida
                validarCal(calif,0.0,5.0);

                //guardar la calificacion en la pelicula elegida
                peliculas[opcPelicula-1]->setCalificaciones(calif);
                cout << endl << "Calificacion dada" << endl;
                cout << endl << "Datos de la pelicula" << endl;
                peliculas[opcPelicula-1]->mostrarDatos();
                cout << endl;
            }
        }

        //si la opcion es 3 (salir)
        if(opc==3){
            //salir del programa
            break;
        }


    }

    return 0;
}
