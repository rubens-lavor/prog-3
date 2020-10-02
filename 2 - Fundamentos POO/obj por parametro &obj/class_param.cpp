#include <iostream>

class class_param
{
private:
    int num {2};
public:
    class_param(/* args */){}
    ~class_param(){}
    int getNum(){
        return num;
    }
    void setNum(int n){
        this->num = n;
    }
};

class classeB
{
private:
    /* data */
    class_param *_class_param = nullptr;
public:
    classeB(class_param *obj){
        this->_class_param = obj;
        _class_param->setNum(5);
    }
    ~classeB(){}

};

int main(){
    class_param cp;
    classeB cb(&cp);

    std::cout << cp.getNum();

    return 0;
}



