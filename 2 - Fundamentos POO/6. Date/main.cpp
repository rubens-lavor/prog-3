#include <iostream>
#include <vector>

class Date
{
private:
    unsigned int _dia{0};
    unsigned int mes{0};
    unsigned int ano{0};

    std::vector<std::pair<int, int>> dia{{1, 1}, {1, 1}, {1, 1}};
    /*o premeiro par representa os 2 dígitos da hora
    depois minutos e o ultimo par, os segundos.
    */

    std::string data{};

    int dias_mes{30};

public:
    Date(/* args */)
    {
    }

    ~Date()
    {
    }

    void nextDay()
    {

        if (this->_dia + 1 > dias_mes)
        {
            setDia(1);

            if (this->mes + 1 > 12)
            {
                setMes(1);

                /*
                if (getAno() + 1 == 24)
                {
                    setAno(0);
                }
                else
                {
                    setAno(getAno() + 1);
                }
                */
                setAno(getAno() + 1);
            }
            else
            {
                setMes(getMes() + 1);
            }
        }
        else
        {
            setDia(getDia() + 1);
        }
    }

    void setAno(int ano)
    {
        this->ano = ano;
    }

    int getAno()
    {

        return this->ano;
    }

    void setMes(int mes)
    {

        mes < 13 ? ({
            switch (mes)
            {
            case 4 || 6 || 9 || 11:
                this->dias_mes = 30;
                break;

            case 2:
                this->dias_mes = 28;
                break;

            default:
                this->dias_mes = 31;
                break;
            }
            this->mes = mes;
        })
                 : ({
                       std::cout << "mês inválido \n";
                       this->mes = 1;
                   });
    }

    int getMes()
    {

        return this->mes;
    }

    void setDia(int dia)
    {
        if (dia > this->dias_mes || dia < 0)
        {
            std::cout << "dia inválido para o mês atual \n";
            return;
        }

        this->_dia = dia;
    }

    int getDia()
    {

        return this->_dia;
    }

    void imprime_hora(std::string s = "")
    {
        data.append(s);
        std::cout << data << std::endl;
    }

    void for_dia()
    {
        for (auto t : dia)
        {
            data.append(std::to_string(t.first) + std::to_string(t.second) + ":");
        }

        data.pop_back();
    }

    void data_universal()
    {
        data = {};

        for_dia();

        imprime_hora();
    }

    std::string completa_data(int x) //essa função edita o formato da hora com 2 digitos caso o zero esteja a esquerda
    {
        return (
            std::to_string(x).length() == 1 ? "0" + std::to_string(x) + ":" : std::to_string(x) + ":");
    }

    void data_AM_PM()
    {

        data = {};

        if (getAno() > 12)
        {
            data.append(completa_data(getAno() - 12));
            data.append(completa_data(getMes()));
            data.append(completa_data(getDia()));

            data.pop_back();
        }

        else
        {
            for_dia(); //essa função preenche a string dia.
        }

        imprime_hora(getAno() > 12 ? " PM" : " AM");
    }
};

int main()
{

    Date t;

    std::cout << "setando hora para 12 \n";
    t.setAno(23);
    t.data_universal();
    t.data_AM_PM();

    std::cout << "setando minuto para 59 \n";
    t.setMes(59);
    t.data_universal();
    t.data_AM_PM();

    std::cout << "setando segundo para 59 \n";
    t.setDia(59);
    t.data_universal();
    t.data_AM_PM();

    std::cout << "nextDay():..\n";
    t.nextDay();
    t.data_universal();
    t.data_AM_PM();

    std::cout << "nextDay():..\n";
    t.nextDay();
    t.data_universal();
    t.data_AM_PM();

    return 0;
}
