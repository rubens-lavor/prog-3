#include "_Date.hpp"
#include "_Time.hpp"

class DateAndTime
{
private:
    Date date;
    Time time;

public:
    DateAndTime(Date d, Time t){
        this->date = d;
        this->time = t;
        time.horario_universal();
        date.imprime_data();
    }

    DateAndTime(){}

    ~DateAndTime(){}

    void mostra_data_e_hora(){   
        time.horario_universal();
        date.imprime_data();
    }

    void tick(){
        if (time.getSegundo() + 1 == 60){
            time.setSegundo(0);

            if (time.getMinuto() + 1 == 60){
                time.setMinuto(0);

                if (time.getHora() + 1 == 24){
                    date.nextDay();
                    time.setHora(0);
                }
                else{
                    time.setHora(time.getHora() + 1);
                }
            }
            else{
                time.setMinuto(time.getMinuto() + 1);
            }
        }
        else{
            time.setSegundo(time.getSegundo() + 1);
        }
    }
};

int main(){
    Date d(31, 1, 2020);
    Time t(23, 59, 59);

    DateAndTime dt(d,t);

    std::cout<<"\ntick()..\n";
    dt.tick();

    dt.mostra_data_e_hora();

    std::cout<<"\ntick()..\n";
    dt.tick();

    dt.mostra_data_e_hora();

    //d.imprime_data();

    return 0;
}
