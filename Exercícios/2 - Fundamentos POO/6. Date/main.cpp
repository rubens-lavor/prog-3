#include <iostream>
#include <vector>

class Date
{
private:
    int _dia{1};
    int mes{1};
    int ano{2000};

    std::string data{};

    int dias_mes{31};

public:
    Date(int dia, int mes, int ano)
    {
        setDia(dia);
        setMes(mes);
        setAno(ano);
    }
    Date()
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
        if (ano < 0)
            return;
        this->ano = ano;
    }

    int getAno()
    {

        return this->ano;
    }

    void setMes(int mes)
    {

        if (mes < 13 && mes > 0)
        {

            if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
            {
                this->dias_mes = 30;
            }
            else if (mes == 2)
            {
                this->dias_mes = 28;
            }
            else
            {
                this->dias_mes = 31;
            }

            this->mes = mes;
        }
        else
        {
            std::cout << "mês inválido \n";
        }
    }

    int
    getMes()
    {

        return this->mes;
    }

    void setDia(int dia)
    {
        if (dia > this->dias_mes || dia < 0)
        {
            std::cout << "dia inválido \n";
            return;
        }

        this->_dia = dia;
    }

    int getDia()
    {

        return this->_dia;
    }

    std::string completa_data(int x)
    {
        return (
            std::to_string(x).length() == 1 ? "0" + std::to_string(x) + "/" : std::to_string(x) + "/");
    }

    void imprime_data()
    {

        data = {};

        data.append(completa_data(getDia()));
        data.append(completa_data(getMes()));
        data.append(completa_data(getAno()));

        data.pop_back();

        std::cout << data << std::endl;
        //std::cout << "dias_mes" << dias_mes << std::endl;
    }
};

int main(){

    Date d;
    
    d.imprime_data();

    std::cout << "nextDay().." << std::endl;
    d.nextDay();
    d.imprime_data();

    std::cout << "setando para dia 31" << std::endl;
    d.setDia(31);
    d.imprime_data();

    std::cout << "nextDay().." << std::endl;
    d.nextDay();
    d.imprime_data();

    std::cout << "setando o mes para junho" << std::endl;
    d.setMes(6);
    d.imprime_data();

    std::cout << "setando para dia 30" << std::endl;
    d.setDia(30);
    d.imprime_data();

    std::cout << "nextDay().." << std::endl;
    d.nextDay();
    d.imprime_data();

    std::cout << "setando para 31/12/2020" << std::endl;
    Date d2(31, 12, 2020);
    d2.imprime_data();
    std::cout << "nextDay().." << std::endl;
    d2.nextDay();
    d2.imprime_data();

    return 0;
}
