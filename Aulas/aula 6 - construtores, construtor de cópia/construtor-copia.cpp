
class MinhaClasse {
   public:
    explicit MinhaClasse() {}
    explicit MinhaClasse(int val) {}
    MinhaClasse(const MinhaClasse& obj) {}
    void metodo() {}
    ~MinhaClasse(){}// pode ter apenas um destrutor
};

void qualquer(MinhaClasse obj) {
    obj.metodo();
}

void outra_funcao() {
    MinhaClasse local, local2{50};
//    local = 42;
    qualquer(local);
}
