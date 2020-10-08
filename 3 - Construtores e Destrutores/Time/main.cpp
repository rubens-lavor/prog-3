#include <iostream>

class Time {
   private:
    std::string horario{};
    int hora{};
    int minuto{};
    int segundo{};

   public:
    //construtor padrão explícito 
    explicit Time() : horario{"00:00:00"} {
        std::cout << "Construtor padrão explícito" << std::endl;
    }

    //Construtor que inicializa como parâmetros as horas e os minutos
    Time(int hora, int min) {
        std::cout << "Construtor que inicia com hora e minuto" << std::endl;
    }

    //Destrutor
    ~Time() {
        std::cout << "Destrutor\n";
    }

    //Construtor explícito de conversão de int para Time
    explicit Time(int segundo) {
        this->segundo = segundo;
        std::cout << "Construtor de conversão int para Time" << std::endl;
    }

    //Construtor de cópia
    Time(const Time &t) {
        std::cout << "Construtor de cópia" << std::endl;
    }

    //Construtor explícito de conversão de double para Time
    explicit Time(double hora) {
        this->hora = hora;
        std::cout << "Construtor de conversão double para Time" << std::endl;
    }
};

void copia_conversao(const Time t) {
    //se o parametro for um objeto Time chama o construtor de cópia
    //se o parametro for int chama o construtor de conversão int para Time
    //se o parametro for double chama o construtor de conversão double para Time
}

int main() {
    Time t{};
    Time t2 = {2, 3};
    std::cout << "\n";

    copia_conversao(t);
    copia_conversao((Time)1);
    copia_conversao((Time)1.0);

    std::cout << "\n";
    return 0;
}
