#include <iostream>

using namespace std;

long long int fn[1000]; // vetor para guardar o calculo dos subproblemas

long long int fibonacci(int n) // funcao responsavel por calcular a sequencia de fibonacci recursivamente
{
	if(fn[n] != -1) // caso valor ja tenha sido calculado, retornar ele
		return fn[n];

	if(n == 1 || n == 0)
		return n;

	fn[n] = fibonacci(n - 1) + fibonacci(n - 2); // calculando valores que ainda nao foram armazenados

	return fn[n];
}

int main()
{
	int n;

	cout << "Digite o indice no qual deseja saber o numero correspondente na sequencia de fibonacci: ";
	cin >> n;

	for(int i = 0; i < 1000; i++) // todas as posicoes do vetor comecam com -1, indicando que nao foram calculadas ainda
		fn[i] = -1;
	// primeira e segunda posicao atribuidas
	fn[0] = 0;
	fn[1] = 1;

	cout << "O numero de posicao " << n << " equivale a " << fibonacci(n) << endl;

	return 0;
}
