#include <iostream>

class Time {
   private:
    //std::vector<std::pair<int, int>> horarios{{}, {}, {}};
    std::string horario{};
    int hora{};
    int minuto{};
    int segundo{};

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

    //Construtor explícito de conversão de int para Time
    explicit Time(int segundo) {
        this->segundo=segundo;
        std::cout << "Construtor de conversão int para Time" << std::endl;
    }

    //Construtor de cópia
    Time(const Time &t) {
        std::cout << "Construtor de cópia" << std::endl;
    }

    //Construtor explícito de conversão de double para Time
    explicit Time(double hora) {
        this->hora=hora;
        std::cout << "Construtor de conversão double para Time" << std::endl;
    }
};

void construtor_de_conversao(const Time t) {
}

void construtor_copia(const Time t) {
}

int main() {
    Time t{};
    Time t2 = {2, 3};
    std::cout << "\n";

    construtor_copia(t);
    construtor_de_conversao((Time)1);
    construtor_de_conversao((Time)1.0);

    std::cout << "\n";
    return 0;
}
