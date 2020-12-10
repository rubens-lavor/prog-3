
class Funcionario{};

class Departamento{
    Funcionario colaboradores[100];
    unique_ptr<Funcionario> colaboradores;
    ou
    vector<Funcionario> colaboradores;

    if(colaboradoes.size() < 100){
        inclui
    }
};

class Date {
    public:
     void tick();
};

class Time {
    public:
     void tick();
};

class DateTime {
    Time t;
    Date d;
    public:
    void tick(){
        t.tick();
        d.tick();
    }
};
