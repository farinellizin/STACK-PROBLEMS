#include "linearstack.hpp"

void FPVazia(Pilha *p){
	p->top   = 0;
	p->base  = 0;
}

void PUSH(Pilha *p, Item d){
	if (p->top >= MAXTAM){
		printf("PILHA CHEIA!\n");
	}else{
		p->vet[p->top] = d;
		p->top ++;
	}
}

void POP(Pilha *p, Item *d){
	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		p->top --;
		*d = p->vet[p->top];
	}
}

void PRemove(Pilha *p, Item d){
	Pilha aux;
	Item rem;

	FPVazia(&aux);

	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		while(p->top > p->base){
			POP(p, &rem);
			if(rem.val != d.val)
				PUSH(&aux, rem);
		}

		while(aux.top > aux.base){
			POP(&aux, &rem);
			PUSH(p, rem);
		}
	}
}

void PImprime(Pilha *p){
	cout << "====================================================" << endl;
	cout << "\tPilha com 20 valores aleatórios de 1 a 99" << endl << endl;

	for(int i = p->top-1; i >= p->base; i--){
		cout << p->vet[i].val << endl;
	}
	cout << "====================================================" << endl;
}


void createRandomStack(Pilha *p, Item d){
	int aux;

	FPVazia(p);

	srand(time(NULL));

	int i = 0;
	while(i < MAXTAM){
		aux = rand() % 100;

		if(aux > 0){
			d.val = aux;
			PUSH(p, d);
			i++;
		}
	}
}


int eulerTotiente(int a, int b){

	int r1, r2, r;

	r1 = a;
	r2 = b;

	while(r2 > 0){
		r = r1 % r2;
		r1 = r2;
		r2 = r;
	}

	return r1;
}


void calculateEulerTotiente(Pilha *p){
	cout << "====================================================" << endl;
	cout << "\t\tLista dos valores de Φ" << endl << endl;

	for(int i = MAXTAM; i >= 0; i--){
		int value, counter = 0;

		value = p->vet[i].val;

		cout << "Co-primos de (" << value << ") = ";

		for(int j = 1; j <= value; j++){
			if(eulerTotiente(value, j) == 1){
				cout << j << " ";
				counter++;
			}
		}

		cout << "  |  Φ (" << value << ") = " << counter << endl;
	}

	cout << "====================================================" << endl;
}