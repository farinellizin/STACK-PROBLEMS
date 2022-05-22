#ifndef DYNAMICSTACK_HPP
#define DYNAMICSTACK_HPP
#include <iostream>
#include <time.h>
#include <unistd.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item{
	int val;
};

struct Block{
	Item data;
	Block *prox;
};

struct Pilha{
	Block *base;
	Block *top;
};

void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
void PImprime(Pilha *p);

#endif