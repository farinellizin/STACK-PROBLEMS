#include "dynamicstack.hpp"
using namespace std;

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
		cout << "\t\t\t\t\t\t" << aux -> data.val << endl;
		aux = aux -> prox;
	}
}

bool decide_if_operator(char n) {
    if (n == '+' || n == '-' || n == '*' || n == '/' || n == '=') {
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

bool decide_what_to_treat(char n) {
    if (n == '+' || n == '-' || n == '*' || n == '/' || n == '=') {
        return true;
    } else {
        return false;
    }
}

string treat_string(string math_op, int size) {
    char aux;
    for (int i = 0; i < size; i++) {
        aux = math_op[i];
        if (decide_what_to_treat(aux)) {
            math_op[i] = '@';
        }
    }

    return math_op;
}

string treat_replicas(string math_op, int size) {
    for (int i = 0; i < size; i++) {
        if (math_op[i] == '@' && math_op[i+1] == '@' && math_op[i+2] == '@') {
            math_op.erase(i, i+1);
        }
        
        if (math_op[i] == '@' && math_op[i+1] == '@' && math_op[i+2] != '@') {
            math_op.erase(i, i);
        }
    }

    return math_op;
}

void fill_operands_stack(DPilha *operands, string math_op) {
    DItem aux;
    size_t pos = 0;
    string delimiter = "@";
    
    while((pos = math_op.find(delimiter)) != string::npos) {
        aux.val = (math_op.substr(0, pos));
        math_op.erase(0, pos + delimiter.length());
        Push(operands, aux);
    }
}

void problem_2_a() {
    string math_op;
    cout << endl << "----------------------------------------------------------------------------------------------";

    cout << endl << endl << "\t\t- Please, inform a mathematical operation of your wish: ";
    getline(cin, math_op);
    math_op = math_op + "@";
    math_op.erase(remove(math_op.begin(), math_op.end(), ' '), math_op.end());
    int size = math_op.size();

    DPilha operands;
    DPilha operators;
    DFPVazia(&operands);
    DFPVazia(&operators);

    fill_operators_stack(&operators, math_op, size);
    cout << endl << "\t\t   ~ Stack containing only the operators of your operation ~" << endl << endl;
    DPImprime(&operators);

    math_op = treat_string(math_op, size);
    size = math_op.size();
    math_op = treat_replicas(math_op, size);

    cout << endl << "\t\t   ~ Stack containing only the operands of your operation ~" << endl << endl;
    fill_operands_stack(&operands, math_op);
    DPImprime(&operands);
    cout << endl << endl;
}