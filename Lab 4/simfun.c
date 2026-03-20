#include <stdio.h>

unsigned char mem[256];
unsigned char X[4] = {0, 0, 0, 0}; // X0,X1,X2,X3
unsigned char PC = 0;

int main()
{
    fread(mem, 1, 256, stdin);

    unsigned char PC0 = PC;
    unsigned char X0_0 = X[0], X1_0 = X[1], X2_0 = X[2], X3_0 = X[3];
    unsigned char mem2_0 = mem[2];

    while (1)
    {
        unsigned char instr = mem[PC];
        unsigned char opcode = instr >> 5;

        if (opcode == 0)
        { // BRA
            signed char imm = instr & 0x1F;
            if (imm & 0x10)
            {
                imm |= 0xE0;
            }
            PC = PC + 1 + imm;
        }
        else if (opcode == 1)
        { // BZ
            signed char imm = instr & 0x1F;
            if (imm & 0x10)
            {
                imm |= 0xE0;
            }
            if (X[1] == 0)
            {
                PC = PC + 1 + imm;
            }
            else
            {
                PC++;
            }
        }

        else if (opcode == 2)
        { // LD
            unsigned char S = (instr >> 2) & 0x3;
            unsigned char R = instr & 0x3;
            X[R] = mem[X[S]];
            PC++;
        }

        else if (opcode == 3)
        { // LDI (into X0)
            signed char imm = instr & 0x1F;
            if (imm & 0x10)
                imm |= 0xE0;
            X[0] = imm;
            PC++;
        }

        else if (opcode == 4)
        { // ST
            unsigned char S = (instr >> 2) & 0x3;
            unsigned char R = instr & 0x3;
            mem[X[S]] = X[R];
            PC++;
        }

        else if (opcode == 5)
        { // ADD
            unsigned char S = (instr >> 2) & 0x3;
            unsigned char R = instr & 0x3;
            X[R] = X[R] + X[S];
            PC++;
        }

        else if (opcode == 7)
        { // HLT
            printf("HLT encountered at PC = %d\n", PC);
            break;
        }

        else
        {
            PC++;
        }
    }

    printf("PC: %d --> %d\n", PC0, PC);
    printf("X0: %d --> %d\n", X0_0, X[0]);
    printf("X1: %d --> %d\n", X1_0, X[1]);
    printf("X2: %d --> %d\n", X2_0, X[2]);
    printf("X3: %d --> %d\n", X3_0, X[3]);
    printf("mem[2]: %d --> %d\n", mem2_0, mem[2]);

    return 0;
}