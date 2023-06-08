// German Salas Martinez A01178095
#include <string>
#include <iostream>
using namespace std;

//Definimos la clase de tarjeta
class Tarjeta{
    //metodos de clase
    public:
    Tarjeta();
    Tarjeta(string,string,string,string);

    //setters
    void setNombre(string);
    void setNumero(string);
    void setCVV(string);
    void setFecha(string);

    //getters
    string getNombre();
    string getNumero();
    string getCVV();
    string getFecha();

    void MostrarTarjeta();

    //variables de la clase
    private:
    string nombre, numero, cvv, fecha;
};

//Definimos la clase de producto
class Producto{
    //metodos de la clase
    public:
    Producto();
    Producto(string,string,string,int,int);

    void setNombrePro(string);
    void setVendedor(string);
    void setVerificado(string);
    void setPrecio(int);
    void setDias(int);

    string getNombrePro();
    string getVendedor();
    string getVerificado();
    int getPrecio();
    int getDias();

    void MostrarProducto();

    //variables de la clase Producto
    private:
    string nombrePro, vendedor, verificado;
    int precio, dias;
};

//Definimos la clase de cliente
class Cliente{
    //metodos de la clase
    public:
    Cliente();
    Cliente(string,string,Tarjeta, Producto);

    //setters
    void setNombreCli(string);
    void setCodigoCon(string);
    void setTarjeta(Tarjeta);
    void setProducto(Producto);

    //getters
    string getNombreCli();
    string getCodigoCon();
    Tarjeta getTarjeta();
    Producto getProducto();

    string pagarT(Tarjeta);
    void MostrarCliente();

    //variables de la clase
    private:
    string nombreCli, codigoconfianza;
    Tarjeta tarjeta;
    Producto producto;
};

//registrar el nombre del usuario
string usuario(){
    string nombre;
    int val = 0;
    while (val==0){
        cout<<endl<<"Bienvenido al registro"<<endl<<endl;
        cout<<"Escriba su nombre"<<endl;
        std::getline(cin, nombre);
        if (nombre.length() == 0){
            continue;
        }else{
            val = 1;
        }
    }
    return nombre;
}

//registrar el codigo de confianza del usuario
string codigo(){
    string codigo;
    int val = 0;
    while (val == 0){
        cout<<endl<<"Escriba su codigo de confianza (6 digitos)"<<endl;
        std::getline(cin, codigo);
        if (codigo.length() != 6){
            cout <<endl<<"El codigo tiene que ser 6 digitos"<<endl;
            continue;
        }else{
            val = 1;
        }
    }
    return codigo;
}

//registrar constraseña del usuario
string contrasena(){
    string contrasena;
    int val = 0;
    while (val==0){
        cout<<endl<<"Inserte su contraseña"<<endl;
        std::getline(cin, contrasena);
        if (contrasena.length() == 0){
            continue;
        }else{
            val = 1;
        }
    }
    return contrasena;
}

//preguntar nombre y contraseña, si coinciden se accede a la tienda
int login(string usuario, string contrasena, Cliente cliente){
    int validar;
    string _usuario, respuesta, _contrasena;
    validar = 0;
    cout<<endl<<endl<<endl<<endl<< "Bienvenido al login"<<endl;
    while (validar == 0){
        cout<<endl<< "Ingrese su nombre"<<endl;
        std::getline(cin, _usuario);
        if (_usuario.length() == 0){
            continue;
        }
        cout<<endl<< "Ingrese su contrasena"<<endl;
        std::getline(cin, _contrasena);
        if (_contrasena.length() == 0){
            continue;
        }
        if ((_usuario == usuario) && (_contrasena == contrasena)){
            validar = 1;
        } else {
            cout <<endl<< "Error" << endl;
            cout <<endl<< "¿Quiere continuar? Si/No" << endl;
            cin >> respuesta;
            if (respuesta == "No" || respuesta == "no"){
                return validar;
            }else{
                cin.ignore();
                continue;
            }
        }
    }
    return validar;
}

//ocultar datos de la tarjeta
string seguridad(string num, int N){
    for (int i = 0; i < N; i++){
        num[i] = 'x';
    }
    return num;
}

//definir valores default de Tarjeta
Tarjeta::Tarjeta(){
    nombre = "Jose Luis Navarrete Sepulveda";
    numero = "4000 1234 5678 9010";
    cvv = "123";
    fecha = "12/24";
}

//metodo para cambiar los valores de Tarjeta
Tarjeta::Tarjeta(string _nombre, string _numero, string _cvv, string _fecha){
    nombre = _nombre;
    numero = _numero;
    cvv = _cvv;
    fecha = _fecha;
}

//metodos setter de Tarjeta
void Tarjeta::setNombre(string _nombre){nombre = _nombre;}
void Tarjeta::setNumero(string _numero){numero = _numero;}
void Tarjeta::setCVV(string _cvv){cvv = _cvv;}
void Tarjeta::setFecha(string _fecha){fecha = _fecha;}

//metodos getter de Tarjeta
string Tarjeta::getNombre(){return nombre;}
string Tarjeta::getNumero(){return numero;}
string Tarjeta::getCVV(){return cvv;}
string Tarjeta::getFecha(){return fecha;}

//mostrar la tarjeta junto con funcion de seguridad
void Tarjeta::MostrarTarjeta(){
    cout<<endl<<"Nombre: "<<nombre<<endl;
    cout<<"Numero de tarjeta: "<<seguridad(numero, 14)<<endl;
    cout<<"CVV: "<<seguridad(cvv,3)<<endl;
    cout<<"Fecha: "<<fecha<<endl;
}

//valores default de producto
Producto::Producto(){
    nombrePro = "Naranja";
    vendedor = "Juan García García";
    verificado = "Verificado";
    precio = 90;
    dias = 3;
}

//cambiar valores default de Producto
Producto::Producto(string _nombre, string _vendedor, string _verificado, int _precio, int _dias){
    nombrePro = _nombre;
    vendedor = _vendedor;
    verificado = _verificado;
    precio = _precio;
    dias = _dias;
}

//setters de Producto
void Producto::setNombrePro(string _nombre){nombrePro = _nombre;}
void Producto::setVendedor(string _vendedor){vendedor = _vendedor;}
void Producto::setVerificado(string _verificado){verificado = _verificado;}
void Producto::setPrecio(int _precio){precio = _precio;}
void Producto::setDias(int _dias){dias = _dias;}

//getters del Producto
string Producto::getNombrePro(){return nombrePro;}
string Producto::getVendedor(){return vendedor;}
string Producto::getVerificado(){return verificado;}
int Producto::getPrecio(){return precio;}
int Producto::getDias(){return dias;}

//Mostrar caracteristicas del producto
void Producto::MostrarProducto(){
    cout<<"     "<<nombrePro<<endl;
    cout<<"     Vendedor: "<<vendedor<<endl;
    cout<<"     "<<verificado<<endl;
    cout<<"     $"<<precio<<" pesos"<<endl;
}

//definir valores default de Cliente
Cliente::Cliente(){
    Tarjeta tarjC;
    nombreCli = "Jose Luis Navarrete Sepulveda";
    codigoconfianza = "440204";
    tarjeta = tarjC;
}

//metodo para cambiar valores a Cliente
Cliente::Cliente(string _nombre, string _codigo, Tarjeta _tarj, Producto _producto){
    nombreCli = _nombre;
    codigoconfianza = _codigo;
    tarjeta = _tarj;
    producto = _producto;
}

//setters de Cliente
void Cliente::setNombreCli(string _nombre){nombreCli = _nombre;}
void Cliente::setCodigoCon(string _codigo){codigoconfianza = _codigo;}
void Cliente::setTarjeta(Tarjeta _tarj){tarjeta = _tarj;}
void Cliente::setProducto(Producto _producto){producto = _producto;}

//getters de Cliente
string Cliente::getNombreCli(){return nombreCli;}
string Cliente::getCodigoCon(){return codigoconfianza;}
Tarjeta Cliente::getTarjeta(){return tarjeta;}
Producto Cliente::getProducto(){return producto;}

//metodo para pagar con tarjeta del cliente
string Cliente::pagarT(Tarjeta tarj){
    string codigo, x, codigoR = codigoconfianza;
    x = "si";
    while (x == "si" || x == "Si"){
        cout <<endl<<"Ingrese su codigo de confianza (6 digitos) para pagar"<<endl;
        cin>>codigo;
        if (codigo == codigoR){
            cout<<endl<<"Pago Exitoso"<<endl;
            cout<<"El pedido llegara en menos de 24 horas"<<endl;
            cout<<endl<<"Pago Realizado con tarjeta:"<<endl;
            tarj.MostrarTarjeta();
            x = "yes";
        }else{
            cout<<"Codigo incorrecto"<<endl;
            cout<<"¿Desea continuar? Si/No"<<endl;
            cin>>x;
        }
    }
    return x;
}

//mostrar datos del cliente
void Cliente::MostrarCliente(){
    cout<<endl<<"Nombre de Cliente: "<<nombreCli<<endl;
    cout<<"Codigo de confianza: "<<codigoconfianza<<endl;
    cout<<"Tarjeta de Cliente: "<<endl;
    tarjeta.MostrarTarjeta();
    cout<<endl;
}


int main(){
    Tarjeta tarj1;
    Producto prod1("Manzana", "Juan Espinosa", "Verificado", 50,0), prod2, prod3("Peras", "Pedro Palacios", "No Verificado", 70,2);
    //añadir producto al cliente
    Cliente cli1;
    string contra, user, code, opcion, tarjnumero, tarjnom, tarjcvv, tarjfecha,ultimo,tarjcont;
    int valid,contcomp,productonum, precio, preciototal, cant, metodo;

    //registro de usuario
    user = usuario();
    cli1.setNombreCli(user);
    code = codigo();
    cli1.setCodigoCon(code);
    contra = contrasena();

    //validar el nombre y contraseña del usuario
    valid = login(cli1.getNombreCli(), contra,cli1);

    //si no desea continuar el programa se acaba
    if (valid == 0){
        return 0;
    }

    cout<<"Login excitoso"<<endl;

    cout<<endl<<endl<<endl<<endl<<"Bienvenido a la tienda"<<endl;

    contcomp = 0;
    preciototal = 0;
    while (contcomp == 0){
        //mostrar los productos
        cout<<endl<<"Producto 1"<<endl;
        prod1.MostrarProducto();

        cout<<endl<<"Producto 2"<<endl;
        prod2.MostrarProducto();

        cout<<endl<<"Producto 3"<<endl;
        prod3.MostrarProducto();

        cout<<endl<<"Seleccione el numero de producto (0 para salir de la tienda)"<<endl;
        cin>>productonum;

        //si el numero del producto es 0 acabar el programa
        if (productonum == 0){
            return 0;
        }else{
            cout<<endl<<"Cantidad"<<endl;
            cin>>cant;
        }

        //si la cantidad del producto es 0 entonces volver a ver la tienda
        if (cant == 0){
            continue;
        }

        if (productonum == 1){
            precio = prod1.getPrecio() * cant;
        }

        if (productonum == 2){
            precio = prod2.getPrecio() * cant;
        }

        if (productonum == 3){
            precio = prod3.getPrecio() * cant;
        }

        //calcular precio a total para pagar
        preciototal = preciototal + precio;

        cout<<endl<<"¿Desea agregar algo mas? Si/No"<<endl;
        cin>>opcion;

        //si desea comprar algo mas entonces volver a la tienda sin cambiar el precio
        if (opcion == "Si" || opcion == "si"){
            continue;
        }
        cout<<endl<<"Su total es: $"<<preciototal<< " pesos"<<endl;

        //elegir metodo de pago
        cout<<endl<<"Metodo de pago: "<<endl;
        cout<<"     1.Efectivo"<<endl;
        cout<<"     2.Tarjeta"<<endl;
        cin>>metodo;

        //pagar en efectivo
        if (metodo == 1){
            cout<<endl<<"Pagando en Efectivo"<<endl;
            cout<<endl<<"El pedido llegara en menos de 24 horas"<<endl;
            cout<<endl<<"¿Quiere comprar algo más? Si/No"<<endl;
            cin>>ultimo;
            if (ultimo == "Si" || ultimo == "si"){
                preciototal=0;
                continue;
            }else{
                cout<<endl<<"Gracias por comprar con nosotros"<<endl;
                return 0;
            }
        }

        //pagar con tarjeta
        if(metodo == 2){
            cout<<endl<<"Pagando con Tarjeta"<<endl;

            //pedir numero de tarjeta
            cout<<"Numero de tarjeta: (ejemplo 4000 1234 5678 9010)"<<endl;
            cin.ignore();
            std::getline(cin, tarjnumero);
            tarj1.setNumero(tarjnumero);

            //pedir nombre de la persona a cargo de la tarjeta
            cout<<"Nombre: "<<endl;
            std::getline(cin, tarjnom);
            tarj1.setNombre(tarjnom);

            //pedir CVV de la tarjeta
            cout<<"CVV: "<<endl;
            std::getline(cin, tarjcvv);
            tarj1.setCVV(tarjcvv);

            //pedir fecha de vencimiento
            cout<<"Fecha de vencimiento: "<<endl;
            std::getline(cin, tarjfecha);
            tarj1.setFecha(tarjfecha);
            tarjcont = cli1.pagarT(tarj1);

            //si el codigo de confianza esta mal y no se desea continuar entonces acabar el programa
            if (tarjcont == "No" || tarjcont == "no"){
                return 0;
            }

            //si se quiere comprar algo más volver a la tienda sino cerrar el programa
            cout<<endl<<"¿Quiere comprar algo más? Si/No"<<endl;
            cin>>ultimo;
            if (ultimo == "Si" || ultimo == "si"){
                preciototal=0;
                continue;
            }else{
                cout<<endl<<"Gracias por comprar con nosotros"<<endl;
                return 0;
            }
        }
    }
    return 0;
}
