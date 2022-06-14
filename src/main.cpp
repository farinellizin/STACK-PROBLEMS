#include "linearstack.hpp"
#include "dynamicstack.hpp"

void run() {
    char option;

    do { 
        cout << endl << endl << "-------------------------------------------------------------------------------------";
        cout << endl << endl << "\t\t\t ~ Welcome to the main menu ~" << endl << endl;
        cout << "\t\tA. Two Stacks: operand and operator;" << endl << "\t\tC. Euler Totient;" << endl;
        cout << "\t\tD. Fibonacci;" << endl << "\t\tE. Exit;" << endl;
        cout << endl << "\t\t\t- Your option: ";
        cin >> option;
        option = toupper(option);

        if (option == 'A') {
            problem_2_a();
        } else if (option == 'C') {
            Pilha p;
	        Item aux;

	        createRandomStack(&p, aux);
	        PImprime(&p);
	        calculateEulerTotiente(&p);
        } else if (option == 'D') {
            problem_2_d();
        } else {
            cout << "leaving...";
        }
    } while (option != 'E');
}

int main () {
    run();
}