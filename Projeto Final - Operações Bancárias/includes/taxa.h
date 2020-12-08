#ifndef TAXA_H
#define TAXA_H

/*
-   Classe abstrata Taxa, as classe derivadas dela, são responsáveis pela implementação do métodos:
    descontarTaxaManutencao() e incremento_juros()

- class Taxa não pode ser instanciada.
*/

/*
    
    A classe Taxa estipula valores para manutenção das contas e juros da poupança

*/
class Taxa {
   private:
    /*
        valor para taxa de manutenção das contas
    */
    float taxa_manutencao = 17.00;

    /*
        valor da taxa de juros da poupança
    */
    float taxa_juros_poupanca = 0.5;

   public:

    /*
        retorna o valor do atributo taxa_manutencao
    */
    float getTaxaManutencao();

    /*
        tetorna o valor do atributo taxa_juros_poupanca
    */
    float getTaxa_juros_poupanca();

    /*
        classes derivadas implementam os métodos descontarTaxaManutencao() e incremento_juros()
    */
    virtual void descontarTaxaManutencao() = 0;
    virtual void incremento_juros() = 0;

    /*
        Destrutor virtual padrão da classe Taxa 
    */
    virtual ~Taxa() {}
    
};

#endif