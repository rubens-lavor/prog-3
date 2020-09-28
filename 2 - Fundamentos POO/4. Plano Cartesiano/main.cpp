#include <iostream>
#include <cmath>

class Pontos{
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

class Triangulo{
private:
    Pontos *pontos;

public:
    Triangulo(){}
    ~Triangulo(){}

    int perimetro(Pontos p1, Pontos p2, Pontos p3){

        float perimetro = 0;

        perimetro+= distancia_entre_dois_pontos(p1,p2);
        perimetro+= distancia_entre_dois_pontos(p2,p3);
        perimetro+= distancia_entre_dois_pontos(p3,p1);


        return perimetro;
    }

    float distancia_entre_dois_pontos(Pontos p1, Pontos p2){
        return sqrt(pow(p2.get_x() - p1.get_x(),2) + pow(p2.get_y() - p1.get_y(),2));
    }
};

int main(){

    Pontos p1(0.0,0.0);
    Pontos p2(sqrt(3.0),sqrt(6.0));
    Pontos p3(5.0,0.0);

    Triangulo t;

    std::cout << "O perímetro é: " << t.perimetro(p1,p2,p3) << std::endl;

   return 0;
    
}
