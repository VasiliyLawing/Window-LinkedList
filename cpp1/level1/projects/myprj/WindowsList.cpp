//
// Created by bily101 on 8/28/23.
//

#include "WindowsList.h"

WindowsList::WindowsList() {
    head = nullptr;
}

void WindowsList::insert(Window *window) {
    Node* newNode = new Node(window);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void WindowsList::remove(int nodeOffset) {
    Node *temp1 = head, *temp2 = nullptr;
    int ListLen = 0;

    if (head == nullptr) {
        std::cout << "List empty." << std::endl;
        return;
    }

    while (temp1 != nullptr) {
        temp1 = temp1->next;
        ListLen++;
    }
    if (ListLen < nodeOffset) {
        std::cout << "Index out of range"
             << std::endl;
        return;
    }

    temp1 = head;

    if (nodeOffset == 1) {
        head = head->next;
        delete temp1;
        return;
    }

    while (nodeOffset --> 1) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;

    delete temp1;
}

void WindowsList::drawWindows() {
    Node* temp = head;

    if (head == nullptr) {
        std::cout << "List empty" << std::endl;
        return;
    }

    while (temp != nullptr) {
        temp->window->draw();
        temp = temp->next;
    }
}


