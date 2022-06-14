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

bool stack_is_empty(DPilha *p) {
    if(p -> base == p -> top || p == NULL) {
        cout << "empty";
        return true;
    } else {
        return false;
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
    getc(stdin);
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
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void push_fibonacci(DPilha *p, int value, int index) {
    Block *aux = (Block*) malloc (sizeof(Block));
    aux -> data.index = index;
    aux -> data.value = value;
    aux -> prox = p -> top;
    p -> top = aux;
}

void pop_fibonacci(DPilha *p, int *value, int *index) {
    Block *aux;

    if (!stack_is_empty(p)) {
        aux = p -> top;
        p -> top = aux -> prox;
        *value = aux -> data.value;
        *index = aux -> data.index;
        free(aux);
    } else {
        cout << "Empty stack." << endl;
    }
}

void print_fibonacci(DPilha *p) {
    Block *aux;
    cout << "\t\t\tINDEX" << "\t\t\tVALUE" << endl << endl;
    
    aux = p -> top;
    while (aux != p -> base) {
        cout << "\t\t\t    " << aux -> data.index;
        cout << "\t\t\t" << aux -> data.value << endl;
        aux = aux -> prox;
    }
}

bool verify_index(DPilha *p, int index) {
    Block *tmp_block;
    DPilha tmp;
    DFPVazia(&tmp);
    int value, index_aux;

    while (p -> base != p -> top) {
        pop_fibonacci(p, &value, &index_aux);
        push_fibonacci(&tmp, value, index_aux);
        tmp_block = tmp.top;

        if (tmp_block -> data.index == index) {
            cout << "TO AQUI!" << endl << endl;

            while(tmp.top != tmp.base) {
                pop_fibonacci(&tmp, &value, &index_aux);
                push_fibonacci(p, value, index_aux);
            }
            return true;
        }
    }

    cout << "NÃO TO AQUI!" << endl << endl;
    return false;
}

void print_fibonacci_single_value(DPilha *p, int index) {
    Block *aux, *tmp;

    aux = p -> top;
    tmp = p -> top;

    if (aux -> data.index == index) {
        cout << "O VALOR PROCURADO É: " << aux -> data.value;
    } else if (aux -> data.index > index) {
        while (tmp != p -> base) {
            if (tmp -> data.index == index) {
                cout << "O VALOR PROCURADO (JÁ ESTAVA PRESENTE) É: " << tmp -> data.value;
            }
            tmp = tmp -> prox;
        }
    } else if (aux -> data.index < index) {
        fibonacci_calc(p, index);
        cout << "O VALOR PROCURADO (TEVE QUE SER CALCULADO) É: " << p -> top -> data.value;
    }
}

void fibonacci_calc(DPilha *p, int index) {
    int value, index_aux;
    int n1, n2;
    int current_index = p -> top -> data.index;
    int i = current_index + 2;

    while (i <= index) {
        pop_fibonacci(p, &value, &index_aux);
        n1 = value;
        
        pop_fibonacci(p, &value, &index_aux);
        n2 = value;

        push_fibonacci(p, n2, current_index-1);
        push_fibonacci(p, n1, current_index);
        push_fibonacci(p, (n1 + n2), current_index + 1);
        i++;
        current_index++;
    }

    print_fibonacci(p);
}

void problem_2_d() {
    DPilha fibonacci_stack;
    DFPVazia(&fibonacci_stack);
    char option;
    int n;

    int index = 0, value = 1; push_fibonacci(&fibonacci_stack, value, index);
    index = 1; value = 1; push_fibonacci(&fibonacci_stack, value, index);

    do {
        cout << endl << endl << "A para calcular mais um valor;" << endl << "B para sair." << endl;
        cout << "opcao: ";
        cin >> option;
        option = toupper(option);

        if (option == 'A') {
            cout << endl << "Informe o valor para n (numero de iterações fibonacci): ";
            cin >> n;

            print_fibonacci_single_value(&fibonacci_stack, n);
            cout << endl << endl << "APOS CALCULAR, ASSIM FICOU A PILHA DE VALORES: " << endl << endl;
            print_fibonacci(&fibonacci_stack);
        } else if (option == 'B') {
        }
    } while (option != 'B');
}