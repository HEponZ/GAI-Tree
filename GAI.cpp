#include "GAI.h"

void GAI::remove(Node* node) noexcept
{
    if (node) {
        remove(node->left);
        remove(node->right);
        delete node;
    }
}

Node* GAI::Min(Node* node) const noexcept
{
    while (node && node->left)
    {
        node = node->left;
    }

    return node;
}
Node* GAI::Max(Node* node) const noexcept
{
    while (node && node->right)
    {
        node = node->right;
    }

    return node;
}

Node* GAI::Next(Node* node) const noexcept
{
    if (!node) 
    {
        return nullptr;
    }

    Node* parent = nullptr;

    if (node->right) 
    {
        return Min(node->right);
    }

    parent = node->parent;

    while (parent && node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}
Node* GAI::Prev(Node* node) const noexcept
{
    if (!node)
    {
        return nullptr;
    }

    Node* parent = nullptr;

    if (node->left) 
    {
        return Max(node->left);
    }

    parent = node->parent;

    while (parent && node == parent->left)
    {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

Node* GAI::Search(Node* node, int number) const noexcept
{
    while (node)
    {
        if (number == node->car_number)
        {
            return node;
        }
        else if (number < node->car_number)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    return nullptr;
}
void GAI::print(Node* node) const noexcept
{
    if (!node)
    {
        return;
    }

    print(node->left);

    cout << *node;

    print(node->right);
}
void GAI::print_range(Node* node, int begin, int end) const noexcept
{
    if (node)
    {
        if (node->car_number > begin)
        {
            print_range(node->left, begin, end);
        }
        if (node->car_number >= begin && node->car_number <= end)
        {
            cout << *node;
        }
        if (node->car_number < end)
        {
            print_range(node->right, begin, end);
        }
    }
}
void GAI::Add(int number, string off) noexcept
{
    Node* new_node = new Node(number, off);
    Node* current = root;
    Node* parent = nullptr;

    if (!root)
    {
        root = new_node;
        return;
    }

    while (current)
    {
        parent = current;

        if (number < current->car_number)
        {
            current = current->left;
        }
        else if (number > current->car_number)
        {
            current = current->right;
        }
        else if(number == current->car_number)
        {
            //ƒопавл€ет в конец строки другую строку
            current->offences.append(new_node->offences);
            return;
        }
    }

    new_node->parent = parent;

    if (number < parent->car_number)
    {
        parent->left = new_node;
    }
    else
    {
        parent->right = new_node;
    }
}

void GAI::Remove_tree(Node* node)noexcept
{
    if (!node)
    {
        return;
    }

    if (node == root)
    {
        remove(root);
        root = nullptr;
    }
    else 
    {
        if (node->parent->left == node)
        {
            node->parent->left = nullptr;
        }
        else 
        {
            node->parent->right = nullptr;
        }

        remove(node);
    }
}
void GAI::Remove_node(Node*& node)noexcept
{
    if (!node)
    {
        return;
    }

    if (!node->left)
    {
        Node* temp = node->right;

        if (temp)
        {
            temp->parent = node->parent;
        }

        delete node;

        node = temp;
    }
    else if (!node->right)
    {
        Node* temp = node->left;

        if (temp)
        {
            temp->parent = node->parent;
        }

        delete node;

        node = temp;
    }
    else
    {
        Node* next_node = Next(node);

        node->car_number = next_node->car_number;

        Remove_node(next_node);
    }
}