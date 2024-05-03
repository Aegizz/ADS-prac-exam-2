#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		deleteFront();
	}
}

void LinkedList::insertFront(int item) {
	Node* newNode = new Node(item, head);
	head = newNode;
}

void LinkedList::deleteFront() {
	if(head != nullptr) {
		Node* oldHead = head;
		head = head->link;
		delete oldHead;
	}
}

void LinkedList::printList() {
	Node* currNode = head;
	while(currNode != nullptr) {
		std::cout << currNode->data << " ";
		currNode = currNode->link;
	}
}

/////////// your code goes here... DO NOT change the function signatures ///////////

bool LinkedList::swap(int pos1, int pos2) {
	Node * currNode = head;
	Node * n1 = NULL;
	Node * n2 = NULL;
	while (currNode != NULL){
		if (currNode->data == pos1){
			currNode->data = pos2;
			n1 = currNode;
			if (n2){
				return true;
			} 
		} else if (currNode->data == pos2){
			currNode->data = pos1;
			n2 = currNode;
			if (n1){
				return true;
			}
		}
		currNode = currNode->link;
	}
	if (n1){
		n1->data = pos1;
	} else if (n2){
		n2->data = pos2;
	}

	return false;
}

bool LinkedList::find_and_delete(int target) {
	Node * currNode = head;

	while (currNode->link != NULL){
		if (currNode->link->data == target){
			Node * temp = currNode->link;
			currNode->link = currNode->link->link;
			delete temp;

			return true;
		}
		currNode=currNode->link;
	}
	return false;
}