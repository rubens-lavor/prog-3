#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "funcionario.h"
#include <vector>
#include <memory>

class Departamento {
   private:
    std::string nome;
    //std::vector<Funcionario*> vetor_funcionarios;

    std::vector<std::shared_ptr<Funcionario>> vetor_funcionarios;

   public:
    Departamento(std::string nome) {
        this->nome = nome;
    }

    Departamento(/* args */) {
    }

    ~Departamento() {
    }

    int qtdade_funcionarios() {
        return vetor_funcionarios.size();
    }

    void aumento() {
        for (auto v : vetor_funcionarios) {
            v->setSalario(v->getSalario() * 1.1);
        }

        std::cout << "Após o aumento:" << std::endl;
        this->mostra_funcionarios();
    }
    void setFuncionario(std::shared_ptr<Funcionario>fun , float salario , std::string data_adm) {
        
        fun->setSalario(salario);
        fun->setAdmissao(data_adm);
        vetor_funcionarios.push_back(fun);
    }

    void mostra_funcionarios() {
        std::cout << "Funcionários e salario do " << this->nome << ":" << std::endl;
        for (auto v : vetor_funcionarios) {
            std::cout << v->getNome() << " - " << v->getSalario() << std::endl;
        }
        std::cout << std::endl;
    }

    void setNome(std::string nome) {
        this->nome = nome;
    }
    std::string getNome() {
        return this->nome;
    }
};

#endif