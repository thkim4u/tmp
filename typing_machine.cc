// Copyright 2018 <Author>

#include "typing_machine.h"

#define EOL '\0'

TypingMachine::TypingMachine() {
	cursor = new Node(EOL);
	size = 0;
	end = false;
	return;
}

void TypingMachine::HomeKey() {
	while (true) {
		Node* ptr = cursor->GetPreviousNode();
		if (ptr == nullptr) return;

		cursor = ptr;
	}
}

void TypingMachine::EndKey() {
	while (true) {
		Node* ptr = cursor->GetNextNode();
		if (ptr == nullptr) return;

		cursor = ptr;
	}
}

void TypingMachine::LeftKey() {
	Node* ptr = cursor->GetPreviousNode();
	if (ptr == nullptr) return;

	cursor = ptr;
}

void TypingMachine::RightKey() {
	Node* ptr = cursor->GetNextNode();
	if (ptr == nullptr) return;

	cursor = ptr;
}

bool TypingMachine::TypeKey(char key) {
	if (size == MAX_SIZE) return false;

	if (key < 32 || key > 126) return false;

	cursor->InsertPreviousNode(key);
	size++;

	return true;
}

bool TypingMachine::EraseKey() {
	if (size == 0) return false;

	if (cursor->ErasePreviousNode()) {
		size--;
		return true;
	}

	return false;
}

std::string TypingMachine::Print(char separator) {
	std::string ret = "";

	Node* head = cursor;

	while (true) {
		Node* ptr = head->GetPreviousNode();
		if (ptr == nullptr) break;

		head = ptr;
	}

	while (true) {
		if (head == cursor) {
			if (separator != 0) ret.push_back(separator);
		}
		if (head->GetData() == EOL) break;

		ret.push_back(head->GetData());

		head = head->GetNextNode();
	}

	return ret;
}
