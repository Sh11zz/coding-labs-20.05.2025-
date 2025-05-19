#include <iostream>
using namespace std;

// Структура для представления узла связного списка
struct Node
{
    string val;
    Node* next;

    // Конструктор инициализирующий значение узла и устанавливающий указатель на следующий узел в nullptr
    Node(string _val) : val(_val), next(nullptr) {}
};

// Структура для представления связного списка
class list
{
public:
    Node* first;
    Node* last;
    // Конструктор инициализирующий пустой список
    list() : first(nullptr), last(nullptr) {}

    // Метод для проверки пуст ли список
    bool is_empty()
    {
        return first == nullptr;
    }

    // Метод для добавления узла в конец списка
    void push_back(string _val)
    {
        Node* p = new Node(_val);
        if (is_empty())
        {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    // Метод для печати значений узлов списка
    void print()
    {
        if (is_empty()) return;
        Node* p = first;
        while (p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    // Метод для поиска узла по значению
    Node* find(string _val)
    {
        Node* p = first;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    // Метод для удаления первого узла
    void remove_first()
    {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    // Метод для удаления последнего узла
    void remove_last()
    {
        if (is_empty()) return;
        if (first == last)
        {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    // Метод для удаления узла по значению
    void remove(string _val)
    {
        if (is_empty()) return;
        if (first->val == _val)
        {
            remove_first();
            return;
        }
        else if (last->val == _val)
        {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast)
        {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    // Оператор доступа по индексу для получения узла по его позиции
    Node* operator[] (const int index)
    {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};

int main()
{
    list l;
    cout << l.is_empty() << endl;
    l.push_back("3");
    l.push_back("123");
    l.push_back("8");
    l.print();
    cout << l.is_empty() << endl;
    l.remove("123");
    l.print();
    l.push_back("1234");
    l.remove_first();
    l.print();
    l.remove_last();
    l.print();
    cout << l[0]->val << endl;
    return 0;
}