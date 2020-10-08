#include <iostream>
#include <vector>

class Time {
   private:
    //std::vector<std::pair<int, int>> horarios{{}, {}, {}};  //HH,MM,SS
    
    
    std::string horario{};
    int hora {};
    int minuto {};
    int segundo {};


   public:

    //construtor explicito
    explicit Time() : horario{"00:00:00"} {
        std::cout << "Construtor explícito padrão" << std::endl;
    }

    //Construtor que inicializa como parâmetros as horas e os minutos
    Time(int hora, int min) {
        std::cout << "Construtor que inicia com hora e minuto" << std::endl;
    }

    //Destrutor
    ~Time() {
        std::cout << "Destrutor\n";
    }

    explicit Time(int segundo) {
        std::cout << "Construtor de conversão int para Time" << std::endl;
    }

    Time(const Time &t) {
        std::cout << "Construtor de cópia" << std::endl;
    }

    explicit Time(double hora) {
        std::cout << "Construtor de conversão double para Time" << std::endl;
    }
};

void construtor_de_conversao(const Time t) {
}

void construtor_copia(const Time t){

}

int main() {

    Time t{};
    t = {2, 3};

    construtor_copia(t);
    construtor_de_conversao((Time)1);
    construtor_de_conversao((Time)1.0);

    return 0;
}

/*
#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    Money(double _amount) : amount{ _amount } {};

    double amount;
};

void display_balance(const Money balance)
{
    std::cout << "The balance is: " << balance.amount << std::endl;
}

int main(int argc, char* argv[])
{
    Money payable{ 79.99 };

    display_balance(payable);
    display_balance(49.95);
    display_balance(9.99f);

    return 0;
}
*/