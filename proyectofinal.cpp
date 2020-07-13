#include <iostream>
#include <string.h>

const int longCAD = 20;
using namespace std;

struct Articulo{
    char nombreArticul[longCAD +1];
    int cantidad;
    float precio;
    float costoxarticulo;
};

void leerArticulos(Articulo * , int);
void mostrarArticulos (Articulo *, int);
float calcularCosto(Articulo *, int);
void costoTotalcompra(Articulo *, int);

int main(){
    int nArticulos;
    float Total;
    cout<<endl;
    cout<<"Generador de factura"<<endl<<endl;
    cout<<"Digite la cantidad de articulos que va a comprar: "; 
    cin>> nArticulos;
    cin.ignore(100, '\n');
    Articulo *factura = new Articulo[nArticulos];
    leerArticulos(factura, nArticulos);
    calcularCosto(factura, nArticulos);
    mostrarArticulos(factura, nArticulos);
    costoTotalcompra(factura, nArticulos);
    cout<<"\nGracias por su compra.\nLo esperamos de nuevo";
    cout<<endl;
    return 0;
}
void leerArticulos( Articulo *datos, int n){
   int i;
   char nombre[longCAD];
   cout<<"Escriba los datos que se le pide "<<endl;
   for(i=0; i<n; i++){
       cout<<"Nombre del articulo: ";
       cin.getline(datos[i].nombreArticul, longCAD, '\n');
       datos[i].nombreArticul[longCAD]='\0';
       cout<<"Precio del articulo: ";
       cin >> datos[i].precio;
       cout<<"Cantidad: ";
       cin >> datos[i].cantidad;
       cout<<endl;
       cin.ignore(100, '\n');
   }
    system("cls");
}
float calcularCosto(Articulo *dato, int n){
    int i;
    for(i=0; i<n; i++){
        dato[i].costoxarticulo = dato[i].precio * dato[i].cantidad;
    }
}

void mostrarArticulos(Articulo *datos, int n){
    int i;
    cout<<"Factura."<<endl;
    for(i=0; i<n; i++){
        cout<<"Articulo "<<i+1<<": " << datos[i].nombreArticul << endl;
        cout<<"Cantidad: " << datos[i].cantidad << endl;
        cout<<"Precio: dolares" << datos[i].precio << endl;
        cout<<"Costo por el articulo: dolares" << datos[i].costoxarticulo << endl;
    }
}
void costoTotalcompra(Articulo *dato, int n){
    cout<<"\nEl costo total de su compra es: dolares";
    int i; 
    float total=0;
    for(i=0; i<n; i++){
        total = total + dato[i].costoxarticulo;
    }
    cout<<total;
}


