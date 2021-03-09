#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <vector>

class Time
{
private:

    std::vector<std::pair<int, int>> horarios{{0, 0}, {0, 0}, {0, 0}};
    /*o premeiro par representa os 2 dígitos da hora
    depois minutos e o ultimo par, os segundos.
    */

    std::string horario{};

public:
    Time(/* args */)
    {
    }

    Time(int hora,int min,int seg)
    {
        setHora(hora);
        setMinuto(min);
        setSegundo(seg);
    }

    ~Time()
    {
    }

    void tick()
    {

        if (getSegundo() + 1 == 60)
        {
            setSegundo(0);

            if (getMinuto() + 1 == 60)
            {
                setMinuto(0);

                if (getHora() + 1 == 24)
                {
                    setHora(0);
                }
                else
                {
                    setHora(getHora() + 1);
                }
            }
            else{
                setMinuto(getMinuto() + 1);
            }
        }
        else{
            setSegundo(getSegundo() + 1);
        }

    }

    void setHora(int hora)
    {
        if (hora >= 24 || hora < 0)
        {
            return;
        }

        horarios[0].first = hora / 10;
        horarios[0].second = hora % 10;
    }

    int getHora()
    {

        return (horarios[0].first * 10 + horarios[0].second);
    }

    void setMinuto(int minuto)
    {
        if (minuto > 60 || minuto < 0)
        {
            return;
        }

        horarios[1].first = minuto / 10;
        horarios[1].second = minuto % 10;
    }

    int getMinuto()
    {

        return (horarios[1].first * 10 + horarios[1].second);
    }

    void setSegundo(int segundo)
    {
        if (segundo > 60 || segundo < 0)
        {
            return;
        }

        horarios[2].first = segundo / 10;
        horarios[2].second = segundo % 10;
    }

    int getSegundo()
    {

        return (horarios[2].first * 10 + horarios[2].second);
    }

    void imprime_hora(std::string s = "")
    {
        horario.append(s);
        std::cout << horario << std::endl;
    }

    void for_horarios(){
        for (auto t : horarios)
        {
            horario.append(std::to_string(t.first) + std::to_string(t.second) + ":");
        }

        horario.pop_back();
    }

    void horario_universal()
    {
        horario = {};

        for_horarios();

        imprime_hora();
    }

    std::string completa_horario(int x) //essa função edita o formato da hora com 2 digitos caso o zero esteja a esquerda
    {
        return (
            std::to_string(x).length() == 1 ? "0" + std::to_string(x) + ":" : std::to_string(x) + ":");
    }

    void horario_AM_PM()
    {

        horario = {};

        if (getHora() > 12)
        {
            horario.append(completa_horario(getHora() - 12));
            horario.append(completa_horario(getMinuto()));
            horario.append(completa_horario(getSegundo()));

            horario.pop_back();
        }

        else
        {
            for_horarios(); //essa função preenche a string horarios.
        }

        imprime_hora(getHora() > 12 ? " PM" : " AM");
    }
};

#endif