#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

#define RAM_MAX 64

using namespace std;

class CPU{
    public:
        int PC = 0x0;
  
        int A = 0x0;
        int B = 0x0;
        int C = 0x0;
        int D = 0x0;      

        vector<string> instructions = {};
        
        int readReg(int* reg){
            int data = *reg;
            return data;
        }

        int readMem(int location){
            int data = RAM[location];
            return data;
        }

        int writeReg(int *reg, int data){
            *reg = data;
            return 0;
        }

        int writeMem(int address, int data){
            try{
                RAM[address] = data;
                return 1;
            }catch(...){
                printf("%i", "An error occurred!");
                return 0;
            }
        }

        

        int memInit(){
            for (int i = 0; i < RAM_MAX; i++){
                RAM[i] = 0x0;
            }
            printf("Memory Initialized!\n");
            return 0;
        }

        int outputMemory(){
            for (int i = 0; i < RAM_MAX; i++){
                printf("RAM Address: ");
                printf("%i", i);

                printf(" | ");
                printf("%i", RAM[i]);
                printf("\n");
            }
            return 0;
        }

        int outputRegister(int *reg){
            printf("%i", *reg);
            return 0;
        }

        int PRT(){
            char print = (char)A;
            printf("%c", print);
            return 0;
        }

        int MOVA(int data){
            try{
                writeReg(&A, data);
            }catch (...){
                printf("An error occured! \n");
                return 1;
            }
            return 0;
        }   
        
        vector<int> RAM = {0};
};


