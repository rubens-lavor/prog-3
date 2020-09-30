#include <iostream>
#include <iomanip>

class Retangulo
{
private:
    float comprimento{1.0};
    float largura{1.0};

public:
    Retangulo(float comp, float largura){
        this->setComprimento(comp);
        this->setLargura(largura);
    }
    Retangulo(){}
    ~Retangulo(){}
    void setComprimento(float comp)
    {
        if (comp <= 20.0 && comp > 0.0)
        {
            this->comprimento = comp;
            return;
        }

        std::cout << "comprimento inválido\n";
    }
    float getComprimento()
    {
        return this->comprimento;
    }

    void setLargura(float largura)
    {
        if (largura <= 20.0 && largura > 0.0)
        {
            this->largura = largura;
            return;
        }

        std::cout << "comprimento inválido\n";
    }
    float getLargura()
    {
        return this->largura;
    }
    float perimetro()
    {
        return (2 * this->comprimento + 2 * this->largura);
    }

    float area()
    {
        return (this->comprimento * this->largura);
    }
};


int main(){

    Retangulo r;

    r.setComprimento(20.0);
    r.setLargura(20.0);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "A largura é: " << r.getLargura()<< std::endl;
    std::cout << "O comprimento é: " << r.getComprimento()<< std::endl; 
    std::cout << "A área é: " << r.area()<< std::endl;
    std::cout << "O perímetro é: " << r.perimetro()<< std::endl;    
    
    return 0;
}
