#include <algorithm>
#include <iostream>
#include <vector>

class Car {
    double power_a, preco_a;
    unsigned int numero_carros;

   public:
    virtual void status() = 0;
    virtual void load() = 0;
    virtual void unload() = 0;
    virtual ~Car(){}
};

class Truck : public Car {
    std::string tipoCarga_a;
    bool carregado;
    unsigned int numeroRodas;

   public:
    Truck(std::string tipo, unsigned int qtd_rodas) : tipoCarga_a{tipo}, carregado{false}, numeroRodas{qtd_rodas} {
    }
    virtual void status() override {
        std::cout << "Truck com " << tipoCarga_a;
        if (carregado)
            std::cout << " está carregado (" << std::boolalpha << carregado << ").\n";
        else
            std::cout << " não está carregado (" << std::boolalpha << carregado << ").\n";
    }
    virtual void load() override {
        carregado = true;
    }
    virtual void unload() override {
        carregado = false;
    }
};

int main() {
    std::vector<Car*> carros{10};

    auto lstatus = [](auto& car) { car->status(); };

    std::transform(carros.begin(), carros.end(), carros.begin(), [](auto& car) -> Car* { return new Truck{"Milho", 8}; });
    std::cout << ">>>>>>CARREGANDO\n";
    std::for_each(carros.begin(), carros.end(), [](auto& car) { car->load(); });
    std::cout << ">STATUS<\n";
    std::for_each(carros.begin(), carros.end(), lstatus);
    std::cout << "<<<<<<DESCARREGANDO\n";
    std::for_each(carros.begin(), carros.end(), [](auto& car) { car->unload(); });
    std::cout << ">STATUS<\n";
    std::for_each(carros.begin(), carros.end(), lstatus);
    std::cout << "> DESTRUIR TUDO - hahahahahahh <\n";
    int a = 1;
    std::for_each(carros.begin(), carros.end(), [&a](auto& car) { std::cout << "KABUM: "<<a++<<"\n";delete car; });
}
