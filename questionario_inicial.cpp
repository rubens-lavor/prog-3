
/*
#include <iostream>

using namespace std;

int main(){

cout << "texto escrito" << endl;

}

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int var1 = 10;
    int var2 = 2;
    int var3 = 20;
    var3 = var3/(var1 % var2);
    cout << var3 << endl;
    return 0;
}