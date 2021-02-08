#pragma once
using namespace std;

#include "cpu.hpp"
#include <cstring>

class Interpreter{


    public:

    CPU* cpu1;


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
        string data01 = data.substr(instruction.length() + 2);

        char* param1 = new char[data01.length() + 1];
        strcpy(param1, data01.c_str());
        

        Instruction int1 = {0};
        if (instruction == "PRT"){
            int1.OPCODE = 0x1;
            int1.OPRAND1 = param1;
            int1.OPRAND2 = 0x0;
        };

        cpu1->instructions.push_back(int1);
        

        return 0;
    }
};