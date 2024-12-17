#include <iostream>
using namespace std;

struct Node
{
    int info;     
    Node* next;   
};

void print_list(Node* top)
{
    Node* p = top; 
    while (p != nullptr)
    {
        cout << p->info << " ";
        p = p->next; 
    }
    cout << endl;
}

bool isAllOddDigits(int number)
{
    while (number > 0)
    {
        int digit = number % 10;
        if (digit % 2 == 0) 
            return false;
        number /= 10;
    }
    return true;
}

bool containsEight(int number)
{
    while (number > 0)
    {
        if (number % 10 == 8) 
            return true;
        number /= 10;
    }
    return false;
}

int getFirstDigit(int number)
{
    while (number >= 10)
        number /= 10;
    return number;
}

void remove_if_no_eight(Node*& top)
{
    while (top != nullptr && !containsEight(top->info))
    {
        Node* temp = top->next;
        delete top;
        top = temp;
    }

    Node* p = top;
    while (p != nullptr && p->next != nullptr)
    {
        Node* temp = p->next;
        if (!containsEight(temp->info))
        {
            p->next = temp->next;
            delete temp;
        }
        else
        {
            p = temp;
        }
    }
}

void duplicate_numbers(Node*& top)
{
    Node* p = top;
    while (p != nullptr)
    {
        Node* new_node = new Node; 
        new_node->info = p->info; 
        new_node->next = p->next; 
        p->next = new_node;       
        p = new_node->next;       
    }
}

void sort_list_by_first_digit(Node*& top)
{
    if (!top)
        return;

    for (Node* a = top; a->next != nullptr; a = a->next)
    {
        for (Node* b = a->next; b != nullptr; b = b->next)
        {
            if (getFirstDigit(a->info) < getFirstDigit(b->info)) 
                swap(a->info, b->info);
        }
    }
}

bool has_three_digit_all_odd(Node* top)
{
    Node* p = top;
    while (p != nullptr)
    {
        if (p->info >= 100 && p->info <= 999 && isAllOddDigits(p->info)) 
            return true;
        p = p->next;
    }
    return false;
}

void delete_list(Node*& top)
{
    Node* p = top;
    while (p != nullptr)
    {
        Node* temp = p->next;
        delete p;
        p = temp;
    }
    top = nullptr;
}

int main()
{
    Node* top = nullptr;

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Пустая последовательность!" << endl;
        return 0;
    }

    cout << "Введите числа: ";
    int x;
    cin >> x;

    top = new Node;
    top->info = x;
    top->next = nullptr;

    Node* pp = top;

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        Node* p = new Node;
        pp->next = p;
        p->info = x;
        p->next = nullptr;
        pp = p;
    }

    if (has_three_digit_all_odd(top))
    {
        remove_if_no_eight(top);
        duplicate_numbers(top);
    }
    else
    {

        sort_list_by_first_digit(top);
    }

    cout << "Результат: ";
    print_list(top);

    delete_list(top);

    return 0;
}
