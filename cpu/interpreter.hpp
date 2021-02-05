#include "cpu.hpp"

using namespace std;

class Interpreter{
    public:
    int read(const char* filename){
        fstream file;
        file.open(filename, ios::in);

        if (!file.is_open()){
            printf("Error opening file! \n");
            return 1;
        }

        string data;
        while (getline(file, data)){
            decode(data);
        }

        return 0;
    }

    int decode(string data){
        string delimiter = ",";
        int pos = data.find_first_of(delimiter);

        if (pos == string::npos){
            printf("Invalid Instruction!");
            exit(1);
        }

        string instruction = data.substr(0, pos);
        cout << (instruction);

        return 0;
    }
};