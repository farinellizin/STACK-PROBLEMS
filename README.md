<h1 align = "center">
  <strong><em>Aplicação de Pilhas Dinâmicas e Lineares</em></strong>
</h1>

<h4 align = "center">
  Este repositório contém aplicações práticas relacionada ao contéudo teórico de Listas Dinâmicas e Lineares, lecionadas na matéria Algoritmo e Estrutura 
  de Dados I.
</h4>

<h2 align="center">
  <strong><em>Sumário</em></strong>
</h2>

<p>
  Colocar sumario
</p>

<h2 align="center"><em> Objetivo </em></h2>

<h4 align="center">
  Por meio desta atividade, busca-se compreender e estar apto a manipular o funcionamento de Pilhas Dinâmicas e Lineares, verificando o sucesso do processo por meio da implementação do que se é pedido.
</h4>

<h2 align="center"> <strong><em>Proposta</em></strong> </h2>

<i>
  <h3>
    É de nosso conhecimento que a estrutura do tipo pilha define regras de manipulação que não podem ser modificadas e que essas são comumente citadas como ações de PUSH (empilhar) e POP (desempilhar). Sabendo-se disso e mediante as regras de desenvolvimento já apresentadas faça:
  </h3>

  <ol type="I">
    <li>
      Escreva uma função que receba uma equação matemática qualquer e retorne duas pilhas. Uma contendo os operandos empilhados da esquerda para a direita e outra contendo os operadores seguindo mesma linha de leitura.
    </li>
    <li>
      Considerando a função elaborada no item (<strong>i</strong>), crite uma segunda função que apresente a operação matemática em notação prefixa e posfixa. Veja alguns exemplos na tabela abaixo (i.e., Tabela 1.)
    </li>
    
   <br> 
    
<p align="center">
Tabela 1: Exemplos de escrita infixa, prefixa e posfixa.

<table align="center">
  <tr>
    <td><strong>Expressão infixa</strong></td>
    <td><strong>Expressão prefixa</strong></td>
    <td><strong>Expressão posfixa</strong></td>
  </tr>
  <tr>
    <td><i>A + B * C + D</i></td>
    <td><i>+ + A * B C D</i></td>
    <td><i>A B C * + D +</i></td>
  </tr>
  <tr>
    <td><i>(A + B) * (C + D)</i></td>
    <td><i>* + A B + C D</i></td>
    <td><i>A B + C D + *</i></td>
  </tr>
  <tr>
    <td><i>A * B + C * D</i></td>
    <td><i>+ * A B * C D</i></td>
    <td><i>A B * C D * +</i></td>
  </tr>
  <tr>
    <td><i>A + B + C + D</i></td>
    <td><i>+ + + A B C D</i></td>
    <td><i>A B + C + D +</i></td>
  </tr>  
</table>
</p>

  <li>
    Elabore uma função que receba uma pilha P1 com 20 posições preenchidas por números inteiros aleatórios entre 1 e 99. Para cada número da pilha, utilize a função totiente de Euler para encontrar para esse número os co-primos. Mostre-os na tela como resultado de sua execução.
  </li>
  
  <li>
    Crie uma função para realizar o calculo de fibonacci para um valor de N. Contudo, utilize uma pilha para armazenar os pré resultados, utilizando-os para outros calculos sempre que possível. Para tanto, considere manter no topo da pilha o cálculo para o valor de (n-1). Crie uma forma de identificar para qual n-1 o valor foi cálculado para não utilizar valores incorretos para calculos longos. Feito isso responda: Manter os cálculos em pilha pode ajudar a economizar computações? Quando seria melhor empregado?

  </li>
  </ol>
</i>

<h2 align="center">Resoluções detalhadas</h2>

<h2>Aplicação 1</h2>

Foi pedido o input de uma string contendo uma equação aritmética na mesma, a fim de que os "dados" de tal string fossem distribuidos em duas **Pilhas** diferentes, uma com os operandos e outra com os operadores.

Tendo isso em mente, inicialmente foram criadas duas **Pilhas Dinâmicas**, haja visto que não há como prever o tamanho da string que será digitada. Em seguida, foi adotada a ideia de utilizar "@" como forma de substituir os espaços presenter na string, servindo como delimitador para palavras - neste caso, números.

Na sequência foi utilizada a função **fill_operators_stack()** a fim de separar somente os operadores da string principal, haja visto que, para realização de tal, o processo é mais simples, uma vez que os operadores são limitados:

```c++
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
```

A função **decide_if_operator()** tem um papel demasiado importante, sendo responsável por determinar, de fato, se a posição da string é apta a ser inserida na **Pilha** de operadores:

```c++
bool decide_if_operator(char n) {
    if (n == '+' || n == '-' || n == '*' || n == '/' || n == '=') {
        return true;
    } else {
        return false;
    }
}
```

Após tal processo, ainda resta a necessidade de separar os operandos em uma **Pilha** diferente. Visando tal necessidade, foi implementada a função **treat_string()**:

```c++
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
```

Nela, pode ser vista a função **decide_what_to_treat()**, que serve para justamente substituir os operandos por "@", utilizado como delimitador de palavras: 

```c++
bool decide_what_to_treat(char n) {
    if (n == '+' || n == '-' || n == '*' || n == '/' || n == '=') {
        return true;
    } else {
        return false;
    }
}
```

Após passar por esses processos, só restarão números e "@"s na string. As "@" serão tratadas, a fim de que não haja nenhuma réplica, e a separação ocorra de forma correta, por meio da função **treat_replicas()**:

```c++
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
```

Por fim, chamando a função que preencherá a **Pilha** de operandos, por meio da função **fill_operands_stack()**:

```c++
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
```



<h2>Aplicação 2</h2>

<h2>Aplicação 3</h2>

Foi pedido a elaboração de uma função que receba uma pilha P1 com 20 posições preenchidas por números inteiros aleatórios entre 1 e 99. Para cada número da pilha, utilize a função totiente de Euler para encontrar para esse número os co-primos. Mostre-os na tela como resultado de sua execução.

  <h3>Implementação</h3>
  
  Inicialmente foi criada uma função para que seja criado 20 números aleatórios de 1 a 99, e que os mesmos sejam empilhados. Exemplo da função abaixo:
  
  ```c++
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
  ```
  
  Após ser criada a pilha com os elementos aleatórios, partimos para a função que calcula o <strong>Totiente de Euler</strong>, na qual foi separada em 2 funções menores, a primeira chamada de <code>eulerTotiente</code>, que é a função que verifica se o número analisado é um co-primo do número aleatório da pilha, e a segunda chamada de <code>calculateEulerTotiente</code>, que é quem retorna os co-primos do número aleatório da pilha que está sendo analisado naquele momento. Exemplo das funções abaixo:
  
  <i>eulerTotiente</i>
  ```c++
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

  ```
  
  <i>CalculateEulerTotiente</i>
  ```c++
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
  ```
  
  Como visto acima, a segunda função já imprime para o usuário os co-primos do número analisado no momento enquanto faz a execução.

<h2>Aplicação 4</h2>

Na aplicação 4, foi solicitado uma função responsável por cálcular $ N $ valores de $ fibonacci $, utilizando uma **Pilha** para armazenar todos os valores já calculados.

### Implementando

Inicialmente, foi criada uma **Pilha** vazia para dar início ao processo de manipulação. Em seguida, foram inseridos dois valores "default", isto é, os dois valores iniciais da sequência de Fibonacci (1 e 1), de tal forma que, a partir deles, fosse possível dar início ao cáculo reutilizando os valores presentes na **Pilha**:

```c++
int index = 0, value = 1; push_fibonacci(&fibonacci_stack, value, index);
index = 1; value = 1; push_fibonacci(&fibonacci_stack, value, index);
```

Em seguida, foi iniciado um looping do tipo **do...while**, a fim de que, enquanto o looping esteja em execução, seja possível reaproveitar dos valores já armazenados, haja visto que os mesmos não serão perdidos na memória.

Em seguida, há um breve menu solicitando se o usuário deseja realizar um novo cálculo ou sair. Caso a opção desejada seja a primeira, será solicitado um valor N, sendo esse valor o tamanho da sequência.

A partir disso, é chamada a função **print_fibonacci_single_value()**, na qual, de fato, há a implementação do supracitado cálculo: 

```c++
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
```

Inicialmente, é verificado se o valor desejado já se encontra no a pilha, dentro do primeiro if, estando ele presente no topo da **Pilha**. Caso não seja na primeira posição, e o valor desejado seja menor do que o valor do topo, é efetuado um looping **while** a fim de percorrer a **Pilha** e retornar o valor ao encontrá-lo. Por fim, caso o valor não esteja ainda na **Pilha** (sendo maior que o valor do topo). Será necessário calculá-lo. Tal algoritmo é implementado na função **fibonacci_calc()**:

```c++
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
```

O valor do topo é desempilhado e salvo em uma variável. O novo topo, agora é o valor anterior ao final da sequência de fibonacci, portanto, o mesmo também é desempilhado. A partir desse momento, tem-se os dois valores necessários para calcular um valor a frente dos valores previamente armazenados. Os valores são somados e, por fim, todos os valores desmpilhados, quanto o novo, são armazenados na **Pilha** em sua devida ordem.

> Manter os cálculos em pilha pode ajudar a economizar computações? Quando seria melhor empregado?

- Com certeza, ao pensar somente em cáculos repetidos, ou seja, cálculo de valores que já foram efetuados anteriormente, o método é extremamente efetivo, haja visto que basta somente verificar a existência e percorrer.


<h2 align="center">Compilação e Execução</h2>

O repositório possui um arquivo <i>Makefile</i> que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<table align="center">
  <tr>
    <td><strong>Comando</strong></td>
    <td><strong>Função</strong></td>
  </tr>
  <tr>
    <td><code>make clean</code></td>
    <td>Apaga a última compilação realizada contida na pasta build.</td>
  </tr>
  <tr>
    <td><code>make</code></td>
    <td>Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build.</td>
  </tr>
  <tr>
    <td><code>make run</code></td>
    <td>Executa o programa da pasta build após a realização da compilação.</td>
  </tr>
</table>
    
