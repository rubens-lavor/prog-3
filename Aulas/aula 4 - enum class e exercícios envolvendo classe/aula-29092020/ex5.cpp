#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

namespace topico2
{
    class NotificarDia {
        public:
        void proximoDia(){
            std::cout << ">>\n>>\n>> Próximo dia !>>\n>>\n>>\n>>\n";
        }
    };

    class Time
    {
        int h, m, s;
        bool mudou;
    public:
        Time()
        {
            h = 0;
            m = 0;
            s = 0;
            mudou=false;
        }
        Time(int hora, int minutos = 0, int segundos = 0) : h{hora}, m{minutos}, s{segundos}
        {
            verifica();
        }

    private:
        void verifica()
        {
            h = (h >= 0 && h <= 23) ? h : 0;
            m = (m >= 0 && m <= 59) ? m : 0;
            s = (s >= 0 && s <= 59) ? s : 0;
            mudou = false;
        }

    public:
        enum class Formato
        {
            FORMATO_24,
            FORMATO_12
        };

        void mostra_hora(Formato formato = Formato::FORMATO_24) const
        {
            if (formato == Formato::FORMATO_12)
            {
                std::cout << std::setfill('0') << std::setw(2) << h % 12 << ":"
                          << std::setw(2) << m << ":" << std::setw(2) << s
                          << (h >= 12 ? " PM" : " AM") << std::endl;
            }
            else
            {
                std::cout << std::setfill('0') << std::setw(2) << h << ":"
                          << std::setw(2) << m << ":" << std::setw(2) << s << std::endl;
            }
        }

        int hora() const {
            return h;
        }

        int minuto() const {
            return m;
        }

        int segundo() const {
            return s;
        }

        void incrementa(NotificarDia& avisar)
        {

            s += 1;
            if (s > 59)
            {
                s = 0;
                m++;
            }
            if (m > 59)
            {
                m = 0;
                h++;
            }
            if (h > 23)
            {
                h = 0;
                //poderia avisar que mudou o dia
                if(!mudou){
                    mudou = true;
                    avisar.proximoDia();
                }
            }else
            {
                mudou = false;
            }
            
        }

    }; // fecha classe

} // namespace topico2

int main()
{
    using topico2::Time;
    using namespace std::chrono_literals;

    topico2::Time novoRelogio{1,53,57};
    topico2::NotificarDia avisou;
    novoRelogio.mostra_hora();

    while (1)
    {
        novoRelogio.mostra_hora();
        novoRelogio.incrementa(avisou);
        if(novoRelogio.hora()==0 && novoRelogio.segundo()==2){
            break;
        }
        //std::this_thread::sleep_for(10ms);
    }
    std::cout << "FIM\n"; 
    novoRelogio.mostra_hora();
    novoRelogio.mostra_hora(Time::Formato::FORMATO_12);
    return 0;
}
