#include <iostream>

using namespace std;

struct No {
	int data;
	No *next;
};

void printList( No *head){
	No *p = head;
	cout << "\n[";
	
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
	cout << "]";
}

int tamanhoList(No *head){
	int tamanho = 0;
	No *atual = head;
	
	while (atual->next != NULL){
			tamanho++;
		atual = atual -> next;
	}
	return tamanho + 1;
}

int main () {
	
	No *head = new No;
	
	head->data = 1;
	head->next = NULL;
	
	No *segundoNumero = new No;
	segundoNumero->data = 3;
	segundoNumero->next = NULL;
	
	head->next = segundoNumero;
	
	No *terceiroNumero = new No;
	terceiroNumero->data = 5;
	terceiroNumero->next = NULL;
	
	segundoNumero->next = terceiroNumero;
	
	printList(head);
	
	int tamanhoDaLista = tamanhoList(head);
	
	cout << endl << "O tamanho da lista eh: " << tamanhoDaLista;
	
}
