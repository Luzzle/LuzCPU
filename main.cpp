#include "cpu/cpu.hpp"
#include "cpu/interpreter.hpp"

int main(){

    CPU cpu;
    cpu.memInit();
    Interpreter inter;
    inter.read("code.asm");    
}