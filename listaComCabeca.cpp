#include <iostream>
#include <limits.h>

using namespace std;

class No
{
	public:
		int chave;
		No* prox;

		//Construtor
		No()
		{
			prox = 0;
		}

		No(int c, No* p = 0)
		{
			chave = c;
			prox = p;
		}
};

class LCC
{
	public:
		No* cabeca;

		//Construtor
		LCC()
		{
			cabeca = new No();
		}

		//Método para imprimir
		void imprime()
		{
			if (cabeca->prox == 0)
				cout << "Lista vazia";
			else
				for (No* ptr = cabeca->prox; ptr != 0; ptr = ptr->prox)
					cout << ptr->chave << " ";

			cout << endl;
		}

		//Método para inserir logo após a cabeça
		void insere_cabeca(int novaChave)
		{
			No* novo = new No(novaChave, cabeca->prox);
			cabeca->prox = novo;

			//cabeca->prox = new No(novaChave, cabeca->prox);
		}

		//Método para remover uma chave
		int remove_chave(int chave)
		{
			//Buscar o nó com a chave desejada
			No* ptr;
			No* aux;

			aux = cabeca;
			ptr = cabeca->prox;

			while (ptr != 0 && ptr->chave != chave)
			{
				aux = ptr;
				ptr = ptr->prox;
			}

			if (ptr)//if (ptr != 0)
			{
				int val = ptr->chave;
				//Encontrei, vou remover
				aux->prox = ptr->prox;

				delete ptr;

				return val;
			}
			else
				return INT_MAX;
		}

		//Destrutor
		~LCC()
		{
			//cout << "Destruindo a lista\n";
			for (No* ptr = cabeca->prox; ptr != 0;)
			{
				//cout << "Liberando " << ptr->chave << endl;
				No* aux = ptr->prox;

				delete ptr;

				ptr = aux;
			}

			delete cabeca;
		}

};

int main()
{
	LCC* lista = new LCC();

	lista->imprime();

	lista->insere_cabeca(10);
	lista->imprime();

	lista->insere_cabeca(20);
	lista->imprime();

	lista->insere_cabeca(30);
	lista->imprime();

	int v = lista->remove_chave(20);
	if (v != INT_MAX)
		cout << "Removi o " << v << endl;
	else
		cout << "O valor não estava na lista\n";
	lista->imprime();

	v = lista->remove_chave(10);
	if (v != INT_MAX)
		cout << "Removi o " << v << endl;
	else
		cout << "O valor não estava na lista\n";
	lista->imprime();

	v = lista->remove_chave(40);
	if (v != INT_MAX)
		cout << "Removi o " << v << endl;
	else
		cout << "O valor não estava na lista\n";
	lista->imprime();

	v = lista->remove_chave(30);
	if (v != INT_MAX)
		cout << "Removi o " << v << endl;
	else
		cout << "O valor não estava na lista\n";
	lista->imprime();

	lista->insere_cabeca(10);
	lista->imprime();

	delete lista;

	return 0;
}

