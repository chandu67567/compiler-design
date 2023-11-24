#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {
    ASSIGN,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE
} InstructionType;
typedef struct {
    InstructionType type;
    char left[50];
    char right[50];
} Instruction;

void add_symbol(char* symbol, int value) {
    // Add implementation here
}

int get_symbol(char* symbol) {
    // Add implementation here
    return 0;
}

void execute(Instruction* instructions, int size) {
	int i;
    for (i = 0; i < size; i++) {
        Instruction* instruction = &instructions[i];
        if (instruction->type == ASSIGN) {
            int value = get_symbol(instruction->right);
            add_symbol(instruction->left, value);
        } else if (instruction->type == PLUS) {
            int value = get_symbol(instruction->left) + get_symbol(instruction->right);
            add_symbol(instruction->left, value);
        } else if (instruction->type == MINUS) {
            int value = get_symbol(instruction->left) - get_symbol(instruction->right);
            add_symbol(instruction->left, value);
        } else if (instruction->type == MULTIPLY) {
            int value = get_symbol(instruction->left) * get_symbol(instruction->right);
            add_symbol(instruction->left, value);
        } else if (instruction->type == DIVIDE) {
            int value = get_symbol(instruction->left) / get_symbol(instruction->right);
            add_symbol(instruction->left, value);
        }
    }
}

int main() {
    Instruction instructions[] = {
        {ASSIGN, "x", "5"},
        {PLUS, "x", "3"},
        {MINUS, "x", "2"},
        {MULTIPLY, "x", "4"},
        {DIVIDE, "x", "2"}
    };
    int size = sizeof(instructions) / sizeof(instructions[0]);
    execute(instructions, size);
    return 0;
}
