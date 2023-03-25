#include <iostream>
#include <algorithm>

using namespace std;

int pd[2000][2000]; // matriz para guardar os valores ja calculados

int solve(int W, int wt[], int val[], int n)
{
	if(n == 0)
		return 0;

	if(pd[n][W] != -1)
		return pd[n][W];

	if(wt[n] > W) // se tamanho de um dos canos for maior que o cano original nao e possivel fazer o corte
	{
		pd[n][W] = solve(W, wt, val, n - 1); 
		return pd[n][W];
	}

	else
	{
		pd[n][W] = max(val[n] + solve(W - wt[n], wt, val, n), solve(W, wt, val, n - 1));
		//Retorna o valor da tabela após armazenar
		return pd[n][W];
	}
}

int main()
{
	int n, t; // numero de canos solicitados e o tamanho total do cano

	for(int i = 0; i < 2000; i++) // atribuindo todos as posições da matriz com -1
		for(int j = 0; j < 2000; j++)
			pd[i][j] = -1;

	cin >> n >> t;

	int peso[n + 1], valores[n + 1];

	for (int i = 1 ; i <= n ; ++i) // entrando com o tamanho e valor de cada cano
		cin >> peso[i] >> valores[i];

	cout << solve(t, peso, valores, n) << endl;

	return 0;
}