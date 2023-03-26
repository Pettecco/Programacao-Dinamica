#include <iostream>

using namespace std;

int n;
int v[2000];
int peso[2000];
int pd[2000][2000]; // matriz para guardar os valores ja calculados
int caminho[2000][2000];

int solve(int i, int cap, int qntItens) // os parametros sao o indice do seu produto e a capacidade atual
{
	int pega, npega; // variavel auxiliar do processo de decisao

	if(cap < 0) //caso nao tenha mais espaco
		return 0;

	if(i == n) // caso tenha chego no ultimo item
		return 0;
	
	if(qntItens <= 0)
		return 0;
	
	if(pd[i][cap] != -1)
		return pd[i][cap];

	npega = solve(i + 1, cap, qntItens); // valor caso nao pegue o item

	pd[i][cap] = npega;


	if(cap >= peso[i]) //caso seja possivel pegar o item
	{
		pega = solve(i + 1, cap - peso[i], qntItens - 1) + v[i]; //valor caso pegue o item

		if(pega > npega)  //caso pegar seja uma melhor opcao
		{
			caminho[i][cap] = 1; // caminho valendo 1 significa que peguei o item
			pd[i][cap] = pega;
			return pd[i][cap];
		}
		else
		{
			caminho[i][cap] = 0; // caminho valendo 0 significa que nao peguei o item
			return pd[i][cap];
		}
	}

	else
		return pd[i][cap]; // caso nao tenha mais capacidade
}

int main()
{
	int capacidade = 50;
	int itensPegos;

	cout << "Insira a quantidade de pacotes" << endl;
	cin >> n;
	cout << "Insira a quantidade de pacotes que podem ser pegos" << endl;
	cin >> itensPegos;
	
	for(int i = 0; i < n; i++)
	{
		cout << "Insiera o peso do pacote e a quantidade de presentes do mesmo: " << endl;
		cin >> peso[i] >> v[i];
	}
	
	for(int i = 0; i < 2000; i++)
		for(int j = 0; j < 2000; j++)
			pd[i][j] = -1;
	
	cout << "A quantidade de presentes entregues foi de: ";
	cout << solve(0, capacidade, itensPegos) << endl;
	
	// recuperacao do caminho
	
	int i = 0;
	int j = capacidade;
	
	while(i != n)
	{
		if(caminho[i][j] == 0)
			i++;
		else
		{
			cout << "Peguei o item " << i << endl;
			cout << "Peso: " << peso[i] << endl;
			cout << "Valor: " << v[i] << endl;
			j -= peso[i]; // diminuindo capacidade disponivel
			i++; // proximo item
		}
	}	
	
	return 0;
}
