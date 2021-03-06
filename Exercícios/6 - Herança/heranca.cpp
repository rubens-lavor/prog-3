/*Heranca publica:
-membros public da classe base:  como fazer copias dos
metodos e colocar como public na classe derivada
-membros private: nao sao passados, acessivel apenas pelo
metodos da classe BASE e suas funcoes amigas
-O modificador de acesso protected permite que um membro
seja acessı́vel por membros e funções amigas da classe base e
derivada
*/
#include <iostream>
#include <string>
using namespace std;

class Person {
   protected:
    string m_name;
    int m_age;

   public:
    Person(string name = "", int age = 0)
        //construtor em lista
        : m_name(name), m_age(age) {
    }
    string getName() const { return m_name; }
    void setName(string nome) { m_name = nome; }
    int getAge() const { return m_age; }

    friend ostream &operator<<(ostream &, const Person &);
    friend istream &operator>>(istream &, Person &);
};

/*Classe BaseballPlayer herdou publicamente de Person*/
class BaseballPlayer : public Person {
   protected:
    double m_battingAverage;
    int m_homeRuns;

   public:
    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
        //lista de inicializacao do construtor tem que ter : no inicio
        : m_battingAverage(battingAverage), m_homeRuns(homeRuns), Person() {
    }
    void imprime() {
        // Cout do nome
        // Utiliza getName da classe BASE pois esse metodo
        //esta publico para a classe derivada
        cout << getName() << '\n';
        // Utiliza m_battingAverage e m_homeRuns da classe derivada
        // pois eh um objeto da classe derivada
        cout << "Rebatidas: " << m_battingAverage << '\n';  //
        cout << "Home Runs: " << m_homeRuns << '\n';
    }

    friend ostream &operator<<(ostream &, const BaseballPlayer &);
    friend istream &operator>>(istream &, BaseballPlayer &);
};

ostream &operator<<(ostream &output, const BaseballPlayer &a) {
    output << a.getName() << "\nRebatidas: " << a.m_battingAverage << "\n"
           << "Home Runs: " << a.m_homeRuns << "\n";
    return output;  // enables cout << joe
}

std::istream &operator>>(std::istream &in, BaseballPlayer &a) {
    std::cout << "Qual é o nome?: ";
    std::string name;
    std::getline(std::cin, name);
    a.setName(name);
    return in; // enables cin >> joe
}

int main() {
    BaseballPlayer joe;
    //joe.setName("Joe");
    cin >> joe;
    cout << joe;
    //joe.imprime();
    return 0;
}

/* Exercicio 1: modifique as classes para que os parametros sejam privados,
mantendo as mesmas saidas na tela
Dica: defina e use funcoes set e get publicas
*/
/* Exercicio 2: modifique o codigo gerado no exercicio anterior para que a lista de inicializacao
de BaseballPlayer chame a lista de inicializacao de pessoa
*/
/* Exercicio 3: modifique o codigo orginal para se ter atributos protegidos nas classes
*/
/* Para casa: faça o overload da oestream<< tanto para BaseballPlayer quanto para a Person
em todos os tres casos
*/