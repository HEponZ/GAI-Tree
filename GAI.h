#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Node 
{
public:
    int car_number;
    string offences;

    Node* left;
    Node* right;
    Node* parent;

    Node(int car_number_S, string off_S) : car_number(car_number_S), offences{ off_S }, left(nullptr), right(nullptr), parent(nullptr) {}
    
    friend ostream& operator<< (ostream& my_cout, const Node& node)
    {
        my_cout << "Номер авто: " << node.car_number << "\nПравонарушения: " << node.offences << "\n\n";
        return my_cout;
    }
};

class GAI
{
private:
    Node* root;

    void remove(Node* node) noexcept;
public:
    GAI() : root(nullptr) {}
    Node* getRoot() const noexcept { return root; }

    Node* Min(Node* node) const noexcept;
    Node* Max(Node* node) const noexcept;

    Node* Next(Node* node) const noexcept;
    Node* Prev(Node* node) const noexcept;

    Node* Search(Node* node, int key) const noexcept;
    void print(Node* node) const noexcept;
    void print_range(Node* node, int begin, int end) const noexcept;
    void Add(int value, string off) noexcept;

    void Remove_tree(Node* node) noexcept;
    void Remove_node(Node*& node) noexcept;

    ~GAI() { remove(root); }
};