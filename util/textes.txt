#include <iostream>
#include <vector>

bool valida_numero(char *numero)
{
    int i = 0;

    while (numero[i] != ' ' && numero[i] != '\n')
    {
        /* code */

        if (!isdigit(numero[i]))
        {
            return false;
        }

        std::cout << i;
        i++;
    }

    return true;
}

int main()
{

    std::vector<int> vetor(5);
    //int numero;

    /* codigo passivo de erros */
    //vetor.at(5)=1;

    //std::cin>>numero2;
    char numero[10]={};
    bool loop = true;

for (int i = 0; i < 10; i++)
{
    std::cout << numero[i]<<std::endl;
}


    setbuf(stdin, NULL);
    fgets(numero, 10, stdin);

    loop = valida_numero(numero);
    if (!loop)
    {
        std::cout << "Digite apenas números!"<<'\n';
        std::cout << loop;
    }

    //while (loop)
    //{
    /* code */

    /*

        try
        {

            
            setbuf(stdin, NULL);
            fgets(numero, 10, stdin);

            if (!valida_numero(numero))
            {
                std::cout << "Digite apenas números!";
                throw;
            }

            loop = false;
        }

        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "erro de posição inexistente" << '\n';
        }
        catch (...)
        {
            //std::cerr << e.what() << '\n';
            std::cout << "erro" << '\n';
        }

    //}
    */

    return 0;
}

/*
int valida_cnh_cpf(char *cpf_cnh) {
    int i;

    for (i = 0; i < strlen(cpf_cnh); i++) {
        if (!isdigit(cpf_cnh[i])) {
            return 1;
        }
    }
    return 0;
}
Não leia com gets
Use fgets(cpf, 11, stdin)

*/