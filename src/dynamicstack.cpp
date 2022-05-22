#include "dynamicstack.hpp"

void DFPVazia(DPilha *p){
	p -> base = (Block*) malloc (sizeof(Block));
	p -> top = p -> base;
	p -> base -> prox = NULL;
}

void Push(DPilha *p, DItem d){
	Block *aux = (Block*) malloc (sizeof(Block));
	aux -> data = d;
	aux -> prox = p -> top;
	p -> top = aux;
}

void Pop(DPilha *p, DItem *d){
	Block *aux;

	if(p -> base == p -> top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p -> top;
	p -> top = aux -> prox;
	*d = aux -> data;
	free(aux);
}

void DPImprime(DPilha *p){
	Block *aux;

	aux = p -> top;
	while(aux != p -> base){
		cout << aux -> data.val << endl;
        //printf("%d\n", aux -> data.val);
		aux = aux -> prox;
	}
}

bool decide_if_operator(char n) {
    if (n == '+' || n == '-' || n == '*' || n == '/') {
        return true;
    } else {
        return false;
    }
}

void fill_operators_stack(DPilha *operators, string math_op, int size) {
    char aux;
    DItem aux_item;
    for (int i = 0; i < size; i++) {
        aux = math_op[i];
        if (decide_if_operator(aux)) {
            aux_item.val = aux;
            Push(operators, aux_item);
        }
    }
}

void problem_2_a() {
    string math_op;

    cout << "\t- Please, inform a mathematical operation of your wish: ";
    getline(cin, math_op);

    // DPilha operands;
    DPilha operators;
    // DFPVazia(&operands);
    DFPVazia(&operators);
    
    int size = math_op.size();
    
    fill_operators_stack(&operators, math_op, size);
    cout << endl << "\t\t\t STACK OPERATORS: " << endl << endl;
    DPImprime(&operators);
}