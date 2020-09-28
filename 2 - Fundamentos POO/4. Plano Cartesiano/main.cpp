#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <array>
#include <algorithm>

class Pontos
{
private:
    float x{0};
    float y{0};

public:
    Pontos(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    //Pontos() {}
    ~Pontos() {}

    float get_x()
    {
        return x;
    }
    void set_x(float x)
    {
        this->x = x;
    }

    float get_y()
    {
        return y;
    }
    void set_y(float y)
    {
        this->x = x;
    }
};

class Triangulo
{
private:
    Pontos *pontos;

public:
    Triangulo(){}
    ~Triangulo(){}

    int perimetro(Pontos p1, Pontos p2, Pontos p3){
        float lado1;
        float lado2;
        float lado3;

        //float perimetro;
        float componente_x = 0;
        float componente_y = 0;

        componente_x = p2.get_x() - p1.get_x();
        componente_y = p2.get_y() - p1.get_y();
        lado1 = sqrt(pow(componente_x,2)+pow(componente_y,2));

        //std::cout << "Lado 1: " << lado1 << std::endl;

        componente_x = p3.get_x() - p2.get_x();
        componente_y = p3.get_y() - p2.get_y();
        lado2 = sqrt(pow(componente_x,2)+pow(componente_y,2));

        //std::cout << "Lado 2: " << lado2 << std::endl;


        componente_x = p3.get_x() - p1.get_x();
        componente_y = p3.get_y() - p1.get_y();
        lado3 = sqrt(pow(componente_x,2)+pow(componente_y,2));

        //std::cout << "Lado 3: " << lado3 << std::endl;



        /*
        lado1 = sqrt(pow(p1.get_x(),2)+pow(p1.get_y(),2));
        lado2 = sqrt(pow(p2.get_x(),2)+pow(p2.get_y(),2));
        lado3 = sqrt(pow(p3.get_x(),2)+pow(p3.get_y(),2));
        */

        return (lado1 + lado2 + lado3);
    }
};

int main(){

    //std::cout << pow(2,0) << std::endl;

    //exit(1);

    Pontos p1(0.0,0.0);
    Pontos p2(sqrt(3.0),sqrt(6.0));
    Pontos p3(5.0,0.0);

    Triangulo t;

    std::cout << " O perímetro é: " << t.perimetro(p1,p2,p3) << std::endl;

   return 0;
    
}
