#include <iostream>
#include <fstream>
#include <string>
using namespace std;



//An unnamed namespace is used to define entities that are local to a translation unit 
/* namespace {
    double average(const double& first, const double$ second, const double&... args) 

}
// ill use this to have helper functions like average, median, mode, etc.
 */


int main()
{
    ofstream write_file("basic.txt" , ios::app);
    
    write_file.close();

    ifstream read_file("basic.txt");
    string line;
    while (getline(read_file, line)) {
        cout << line << endl;
    }
    read_file.close();

    return 0;
}