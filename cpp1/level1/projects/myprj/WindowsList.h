#pragma once


#include "Screen.hh"
#include "Window.h"


class Node {
public:
    Window*window;
    Node* next;

    Node() {
        window = nullptr;
        next = nullptr;
    }

    explicit Node(Window *window) {
        this->window = window;
        this->next = nullptr;
    }
};

class WindowsList {
    Node *head;
public:
    explicit WindowsList();

    void insert(Window*);
    void remove(int);

    void drawWindows();
};
