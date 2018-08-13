// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	this->prev = nullptr;
	this->next = nullptr;
	this->data = data;
	return;
}

char Node::GetData() {
	return this->data;
}

Node* Node::GetPreviousNode() {
	return this->prev;
}

Node* Node::GetNextNode() {
	return this->next;
}

Node* Node::InsertPreviousNode(char data) {
	Node* ptr = new Node(data);
	
	ptr->next = this;
	ptr->prev = this->prev;
	if (ptr->prev != nullptr) {
		ptr->prev->next = ptr;
	}

	this->prev = ptr;

	return ptr;
}

Node* Node::InsertNextNode(char data) {
	Node* ptr = new Node(data);

	ptr->prev = this;
	ptr->next = this->next;
	if (ptr->next != nullptr) {
		ptr->next->prev = ptr;
	}
	this->next = ptr;

	return ptr;
}

bool Node::ErasePreviousNode() {
	Node* ptr = this->prev;

	if (ptr == nullptr) return false;

	this->prev = ptr->prev;
	if (this->prev != nullptr) {
		this->prev->next = this;
	}

	delete ptr;

	return true;
}

bool Node::EraseNextNode() {
	Node* ptr = this->next;

	if (ptr == nullptr) return false;

	this->next = ptr->next;
	if (this->next != nullptr) {
		this->next->prev = this;
	}

	delete ptr;

	return true;
}
