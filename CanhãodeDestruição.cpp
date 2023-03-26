#include <iostream>

using namespace std;

int n;
int v[2000];
int peso[2000];
int pd[2000][2000]; // matriz para guardar os valores ja calculados
int caminho[2000][2000];

int solve(int i, int cap) // os parametros sao o indice do seu produto e a capacidade atual
{
	int pega, npega; // variavel auxiliar do processo de decisao

	if(cap < 0) //caso nao tenha mais espaco
		return 0;

	if(i == n) // caso tenha chego no ultimo item
		return 0;
	if(pd[i][cap] != -1)
		return pd[i][cap];

	npega = solve(i + 1, cap); // valor caso nao pegue o item

	pd[i][cap] = npega;


	if(cap >= peso[i]) //caso seja possivel pegar o item
	{
		pega = solve(i + 1, cap - peso[i]) + v[i]; //valor caso pegue o item

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
	int resistencia;
	int capacidade;

	cout << "Insira a capacidade do canhao:" << endl;
	cin >> capacidade;
	cout << "Insira a quantidade de projeteis de chumbo disponiveis:" << endl;
	cin >> n; // elementos
	cout << "Insira a resistencia do castelo:" << endl;
	cin >> resistencia;

	for(int i = 0; i < n; i++)
	{
		cout << "Insira o peso do projetil e o poder de destruicao dele: " << endl;
		cin >> peso[i] >> v[i];
	}

	for(int i = 0; i < 2004; i++)
		for(int j = 0; j < 2004; j++)
			pd[i][j] = -1;

	if(resistencia > solve(0, capacidade))
	{
		cout << "Falha na missao" << endl;
	}
	else
	{
		cout << "Missao completada com sucesso" << endl;
	}

	return 0;
}
