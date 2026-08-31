#include <iostream>
using namespace std;
class Rectangulo{//clase
    private:
        int largo;//metodos
        int ancho;
    public:
        Rectangulo(int,int); //constructor
        void perimetro();//atributos
        void area();
    
};
Rectangulo::Rectangulo(int _largo,int _ancho){//constructor
    largo = _largo;
    ancho = _ancho;
}
void Rectangulo::perimetro(){
    int cperimetro = (largo*2) + (ancho*2);
    cout<< "el perimetro del rectanuglo es:" << cperimetro << endl;
}
void Rectangulo::area(){
    int aarea= largo * ancho;
    cout<< "el area del rectanuglo es:" << aarea << endl;
}

int main()
{
    Rectangulo p1(3,5);
    p1.perimetro();
    p1.area();
    return 0;
}