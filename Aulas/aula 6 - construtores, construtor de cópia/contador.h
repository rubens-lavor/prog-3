#ifndef CONTADOR_H
#define CONTADOR_H

class Contador {
   private:
    long contador;

   public:
    void setContador(long x);
    void aumenta();
    void diminui();
    long valor() const;
    void mostra() const;
};

#endif
