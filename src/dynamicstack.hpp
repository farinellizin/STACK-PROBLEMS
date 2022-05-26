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
	long long unsigned int value;
    int index;
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
bool stack_is_empty(DPilha *p);

void problem_2_a();
void fill_operands_stack(DPilha *operands, string math_op);
bool decide_what_to_treat(char n);
string treat_string(string math_op, int size);
string treat_replicas(string math_op, int size);
bool decide_if_operator(char n);
void fill_operators_stack(DPilha *operators, string math_op, int size);

void problem_2_d();
void push_fibonacci(DPilha *p, int value, int index);
void pop_fibonacci(DPilha *p, int *value, int *index);
void print_fibonacci(DPilha *p);
bool verify_index(DPilha *p, int index);
void print_fibonacci_single_value(DPilha *p, int index);
void fibonacci_calc(DPilha *p, int value);

#endif