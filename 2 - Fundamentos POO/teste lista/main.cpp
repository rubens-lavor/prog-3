#include <iostream>
#include <map>
#include <vector>
#include <list>


int main(){
    std::map<int,int>map1;
    std::map<int,std::string>map2;

    map1[5]=4;
    map2[5]="oi";

    std::list<std::map<int,int>>lista1;

    std::list<std::map<int,int>>::iterator list_it;

    std::map<int,int>::iterator map_it;

    std::list<std::vector<std::pair<std::string,int>>>lista2;

    map1[0]=1;
    map1[1]=2;
    map1[2]=3;
    map1[3]=4;

    lista1.push_back(map1);

    std::cout << lista1.front()[3] << std::endl;
    std::cout << lista1.back()[0] << std::endl;
    std::cout << lista1.back()[1] << std::endl;

    std::cout << lista1.size() << std::endl;


    for (size_t i = 0; i < 6; i++)
    {
        std::cout << lista1.front()[i] << std::endl;
    }
    
    

    
    /*
    std::iterator it;

    lista.begin.insert(map1);
    lista.insert(map2);

    lista
    */



    return 0;
}