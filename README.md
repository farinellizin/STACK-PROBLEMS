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

<h2 align="center">Funcionamento</h2>

<p>

</p>

<h2 align="center">Lógicas gerais</h2>

<p>

</p>

<h2 align="center">Funcões gerais</h2>

<p>

</p>

<h2 align="center">Resoluções detalhadas</h2>

<h2>Aplicação 1</h2>

<h2>Aplicação 2</h2>

<h2>Aplicação 3</h2>

Foi pedido a elaboração de uma função que receba uma pilha P1 com 20 posições preenchidas por números
inteiros aleatórios entre 1 e 99. Para cada número da pilha, utilize a função totiente de
Euler para encontrar para esse número os co-primos. Mostre-os na tela como resultado
de sua execução.

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
    
