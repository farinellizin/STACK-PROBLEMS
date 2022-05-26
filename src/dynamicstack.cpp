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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void push_fibonacci(DPilha *p, int value, int index) {
    Block *aux = (Block*) malloc (sizeof(Block));
    aux -> data.index = index;
    aux -> data.value = value;
    aux -> prox = p -> top;
    p -> top = aux;

    // cout << "Value: " << aux -> data.value;
    // cout << endl << "Index: " << aux -> data.index << endl << endl;
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
        cout << "\t\t\t" << aux -> data.index;
        cout << "\t\t\t" << aux -> data.value << endl;
        aux = aux -> prox;
    }
}

bool verify_index(DPilha *p, int index) {
    Block *aux;

    aux = p -> top;
    while (aux != p -> base) {
        if (aux -> data.index == index) {
            cout << "TO AQUI!" << endl << endl;
            return true;
        }
        aux = aux -> prox;
    }

    cout << "NÃO TO AQUI!" << endl << endl;
    return false;
}

void print_fibonacci_single_value(DPilha *p, int index) {
    Block *aux;

    aux = p -> top;

    while (aux != p -> base) {
        if (aux -> data.index == index) {
            cout << endl << endl <<"TESTANDO IMPRESSÃO DE VALOR: " << aux -> data.value << endl << endl;
            aux = p -> base;
        } else {
            aux = aux -> prox;
        }
    }
}

void fibonacci_calc(DPilha *p, int index) {
    Block *aux;
    int n1;
    int n2;
    int n3;
    int i = 0;
    // int j = 1;
    

    aux = p -> top;
    int tmp = aux -> data.index;
    // // cout << aux -> data.value;
    // // aux = aux -> prox;
    // // cout << endl << aux -> data.value;
    // // aux = aux -> prox;
    // // cout << endl << aux -> data.value;
    // n1 = aux -> data.value;
    // n2 = aux -> prox -> data.value;
    // cout << "VALOR N1: " << n1 << endl;
    // cout << "VALOR N2: " << n2 << endl;
    // // cout << endl << "LIXO DOS INFERNO: " << index << endl;
    // while (aux -> data.index != index) {
    //     n3 = n1 + n2;
    //     cout << endl << endl << "VALOR DE N3: " << n3 << endl;
    //     cout << "VALOR DO INDEX: " << aux -> data.index << endl;
    //     push_fibonacci(p, n3, index + i);
    //     i++;
    //     // print_fibonacci(p);
        
    //     aux = p -> top;
    //     n1 = aux -> data.value;
    //     n2 = aux -> prox -> data.value;
    // }

    while (i <= index) {
        n1 = aux -> data.value;
        n2 = aux -> prox -> data.value;
        n3 = n1 + n2;
        push_fibonacci(p, n3, tmp + 1);

        aux = p -> top;
        i++;
        tmp++;
    }

}

/*
    n = 3 // fibonacci = 2 // index = 1;
    n = 4 // fibonacci = 3 // index = 2;
    n = 5 // fibonacci = 5 // index = 3;
    n = 6 // fibonacci = 8 // index = 4;
    n = 7 // fibonacci = 13 // index = 5;
    n = 8 // fibonacci = 21 // index = 6;
    n = 9 // fibonacci = 34 // index = 7;
*/



void problem_2_d() {
    DPilha fibonacci_stack;
    DFPVazia(&fibonacci_stack);
    fibonacci_stack.base -> data.value = 1;
    char option;
    int n;

    int index = 1;
    int value = 2;

    push_fibonacci(&fibonacci_stack, value, index);
    // index = 2;
    // value = 3;
    // push_fibonacci(&fibonacci_stack, value, index);
    // index = 3;
    // value = 5;
    // push_fibonacci(&fibonacci_stack, value, index);
    // index = 4;
    // value = 8;
    // push_fibonacci(&fibonacci_stack, value, index);
    // int n = 6;
    // fibonacci_calc(&fibonacci_stack, (n-2));
    // print_fibonacci(&fibonacci_stack);
    
    do {
        cout << "A para calcular mais um valor;" << endl << "B para sair." << endl;
        cout << "opcao: ";
        cin >> option;
        option = toupper(option);

        if (option == 'A') {
            cout << endl << "Informe o valor para n (numero de iterações fibonacci): ";
            cin >> n;

            if (verify_index(&fibonacci_stack, (n-2)) == true) {
                print_fibonacci_single_value(&fibonacci_stack, (n-2));
            } else {
                fibonacci_calc(&fibonacci_stack, (n-2));
                print_fibonacci_single_value(&fibonacci_stack, (n-2));
            }


        } else if (option == 'B') {
            // simplesmente sai do programa
        }
    } while (option != 'B');









    // print_fibonacci(&pre_results);
}