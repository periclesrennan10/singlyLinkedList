#include <iostream>

using namespace std;

struct No {
	int data;
	No *next;
};

void removerPosicao(No *&head, int posicao){
	if(head == NULL || posicao < 0){
		cout << endl << "Lista vazia ou posicao invalida" << endl;
		return; 
	}
	if (posicao == 0){
		No *temp = head;
		head = head->next;
		delete temp;
		return;
	}
	No *current = head;
	int index = 0;
	
	while (current != NULL && index < posicao - 1){
		current = current->next;
		index++;
	}
	if (current == NULL || current->next == NULL){
		cout << endl << "Posicao invalida";
		return;
	}
	
	No *noParaRemover = current->next;
	current->next = noParaRemover->next;
	delete noParaRemover;
}

void printList(No *head){
	No *p = head;
	
	cout << "\n[";
	
	while(p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
	cout << "]";
}

void inserirNoComeco(No *&head, int valor){
	No *novoNo = new No;
	
	novoNo->data = valor;
	novoNo->next = head;
	
	head = novoNo;
}

int main() {
	No *head = new No;
	head->data = 3;
	head->next = NULL;
	
	inserirNoComeco(head, 8);
	inserirNoComeco(head, 1);
	inserirNoComeco(head, 3);
	inserirNoComeco(head, 5);
	
	printList(head);
	
	int posicaoRemovida = 0;
	removerPosicao(head, posicaoRemovida);
	
	cout << endl;
	cout << "Lista apos a ser removida o numero da posicao " << posicaoRemovida << ":";
	
	printList(head);
	
	return 0;
}
