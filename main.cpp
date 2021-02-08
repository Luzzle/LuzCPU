#include "cpu/cpu.hpp"
#include "cpu/interpreter.hpp"

int main(int argc, char *argv[]){
    CPU cpu;
    cpu.memInit();
    Interpreter inter;
    inter.cpu1 = &cpu;
    inter.read("code.asm"); 
    cpu.read(0);  
}