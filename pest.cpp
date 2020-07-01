#include <iostream>

using namespace std;

struct Pilha{
	
	int topo;  //topo da pilha
	int capacidade;
	float pElem[];
};

void criapilha(Pilha *p, int c);  // funçoes da pilha 
int  estavazia(Pilha *p);
int estacheia(Pilha *p);
void empilhar(Pilha *p, float v);
float desempilhar(Pilha *p);
float mostratopo(Pilha *p);

int main(){
	
	Pilha minhapilha;
	int capacidade;
	int op;
	float valor;
	
	cout << endl << "Capacidade da pilha: ";
	cin >> capacidade;
	cout << endl;
	criapilha(&minhapilha, capacidade);
	
	while(1){
		cout << " 1 - empilhar (push)" << endl;
		cout << " 2 - desempilhar (pop)" << endl;
	    cout << " 3 - Mostrar o topo" << endl;
	    cout << " 4 - Saida" << endl << endl;
		cout << "opcao: ";
		cin >> op;
		cout << endl;
		
		switch(op){
			case 1:
				if (estacheia(&minhapilha) == 1){
					cout << "Pilha esta cheia!" << endl << endl;
				}
				else{
					cout << "Entre com o valor: ";
					cin >> valor;
					cout << endl;
					empilhar (&minhapilha, valor);
				}
				break;
			
			case 2:
				if (estavazia(&minhapilha) == 1){
					cout << "Pilha vazia" << endl << endl;
				}
				else{
					valor = desempilhar(&minhapilha);
					cout << "Desempilhado o valor " << valor << endl;
				}
				break;
			
			case 3:
				if (estavazia(&minhapilha) == 1){
					cout << "Pilha vazia!" << endl << endl;
				}
				else{
					valor = mostratopo(&minhapilha);
					cout << "Topo: " << valor << endl;
				}
				break;
			
			case 4:
				exit(0);
			
			default:
				cout << "Opcao invalida";
					
						
		}
	}
	
return 0;	
} 

void criapilha(Pilha *p, int c){  //Cria a pilha 
	
	p->topo = -1;
	p->capacidade = c;
}

int estavazia(Pilha *p){   // funçao que diz que a pilha esta vazia
	
	if (p->topo == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int estacheia(Pilha *p){  // funçao que mostra que a pilha esta cheia
	
	if (p->topo == p->capacidade-1){
		return 1;
	}
	else{
		return 0;
	}
}

void empilhar(Pilha *p, float v){  // funçao que adiciona um elemento à pilha 
	
	p->topo++;
	p->pElem[p->topo] == v;
}

float desempilhar(Pilha *p){  //funçao que retira um elemento da pilha 
	
	float aux = p->pElem[p->topo];
	p->topo--;
	return aux;
}

float mostratopo(Pilha *p){  //funçao que mostra o topo da pilha
	
	return p->pElem[p->topo];
}
