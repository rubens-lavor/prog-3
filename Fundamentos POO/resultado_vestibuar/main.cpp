#include "Resultado_vestibular.hpp"
#include "Resultado_vestibular.cpp"

int main()
{
    /*para verificar se temos pelo menos 3 candidatos por vaga em cada curso*/

    Resultado_vestibular ResVEST;

    ResVEST.inicializa_resultado();
    ResVEST.mostra_aprovados();

    return 0;
}