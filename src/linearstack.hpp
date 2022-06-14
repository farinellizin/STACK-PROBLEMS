#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

using namespace std;

#define MAXTAM 20

typedef struct Item{
	int val;
}Item;

typedef struct Pilha{
	Item vet[MAXTAM];
	int top;
	int base;
}Pilha;

void FPVazia(Pilha *p);
void PUSH(Pilha *p, Item d);
void POP(Pilha *p, Item *d);
void PRemove(Pilha *p, Item d);
void PImprime(Pilha *p);

void createRandomStack(Pilha *p, Item d);
int eulerTotiente(int a, int b);
void calculateEulerTotiente(Pilha *p);

#endif