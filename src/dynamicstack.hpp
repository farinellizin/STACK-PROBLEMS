#ifndef DYNAMICSTACK_HPP
#define DYNAMICSTACK_HPP
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <string>
#include <algorithm>
using namespace std;

typedef struct DItem DItem;
typedef struct Block Block;
typedef struct DPilha DPilha;

struct DItem{
	//int val;
    string val;
};

struct Block{
	DItem data;
	Block *prox;
};

struct DPilha{
	Block *base;
	Block *top;
};

void DFPVazia(DPilha *p);
void Push(DPilha *p, DItem d);
void Pop(DPilha *p, DItem *d);
void DPImprime(DPilha *p);

void problem_2_a();
// void decide_if_operand(string math_op, DPilha *operands);
void fill_operands_stack(DPilha *operands, string math_op);
bool decide_what_to_treat(char n);
string treat_string(string math_op, int size);
string treat_replicas(string math_op, int size);

bool decide_if_operator(char n);
void fill_operators_stack(DPilha *operators, string math_op, int size);
#endif