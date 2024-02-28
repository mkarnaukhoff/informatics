#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Node
{
    int key;
    Node *next;

    Node(int k, Node *n)
    {
        key = k;
        next = n;
    }
};

class OneLinkedList
{
    Node *head, *tail;
    int count;

public:
    OneLinkedList()
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    int size()
    {
        return count;
    }

    bool empty()
    {
        return count == 0;
    }

    void pushFront(int key)
    {
        head = new Node(key, head);
        count++;
        if (tail == NULL)
        {
            tail = head;
        }
    }

    int popFront()
    {
        Node *headtemp = head->next;
        int tempkey = head->key;
        delete head;
        head = headtemp;
        count--;
        if (head == NULL)
        {
            tail = NULL;
        }
        return tempkey;
    }

    void print()
    {
        for (Node *tempnode = head; tempnode; tempnode = tempnode->next)
        {
            cout << tempnode->key << ' ';
        }
        cout << endl;
    }

    void insertAfter(Node *elem, int key)
    {
        elem->next = new Node(key, elem->next);
        count++;
        if (tail == elem)
        {
            tail = tail->next;
        }
    }

    Node *getNode(int index)
    {
        Node *tempnode = head;
        for (int i = 0; i < index; i++)
        {
            tempnode = tempnode->next;
        }
        return tempnode;
    }

    void popAfter(Node *elem)
    {
        Node *tempnextelem = elem->next;
        elem->next = tempnextelem->next;
        delete tempnextelem;
        count--;
        if (tail == tempnextelem)
        {
            tail = elem;
        }
    }

    void pushBack(int key)
    {
        if (empty())
        {
            pushFront(key);
        }
        else
        {
            insertAfter(tail, key);
        }
    }

    Node *linearSearch(int key)
    {
        for (Node *temphead = head; temphead; temphead = temphead->next)
        {
            if (temphead->key == key)
                return temphead;
        }
        return NULL;
    }
};

int getRandom()
{
    srand(time(NULL));
    int l = -100;
    int r = 100;
    return rand() % (r - l) + l;
}

int main()
{
    OneLinkedList list;
    int n;

    // Номер 1

    for (int i = 0; i < 7; i++)
    {
        // cin >> n;
        list.pushBack(i);
    }
    list.print();
    Node *tempnode = list.getNode(0);

    for (tempnode; tempnode; tempnode = tempnode->next)
    {
        cout << tempnode->key << ' ' << tempnode << ' ' << tempnode->next << endl;
    }

    // Добавить в линейный список 50 элементов. Вывести список на экран.

    for (int i = 0; i < 50; i++)
    {
        list.pushBack(getRandom());
    }
    list.print();

    // Вывести на экран первый элемент списка

    cout << list.getNode(0)->key << endl;

    // Вывести на экран второй элемент списка

    cout << list.getNode(1)->key << endl;

    // Вывести на экран последний элемент списка

    cout << list.getNode(list.size() - 1)->key << endl;

    // Вывести на экран предпоследний элемент списка

    cout << list.getNode(list.size() - 2)->key << endl;

    // Вывести на экран элемент списка, стоящий на позиции k считая от начала. Если такого элемента нет, вывести сообщение.

    int k = 10;
    if (k < list.size())
        cout << list.getNode(k - 1)->key << endl;
    else
        cout << "Bad k";

    // Вывести на экран часть списка от k до m, где k<m номера элементов считая от начала списка.

    k = 10;
    int m = 15;
    if (m > list.size())
        cout << "Bad m" << endl;
    else
    {
        Node *temphead = list.getNode(k - 1);
        Node *tempheadm = list.getNode(m);
        while (temphead != tempheadm)
        {
            cout << temphead->key << " ";
            temphead = temphead->next;
        }
        cout << endl;
    }

    // Найти в линейном списке наибольший элемент

    Node *temphead = list.getNode(0);
    int keyMax = temphead->key;
    for (temphead; temphead; temphead = temphead->next)
    {
        if (temphead->key > keyMax)
        {
            keyMax = temphead->key;
        }
    }
    cout << keyMax << endl;

    // Найти в линейном списке наименьший элемент и его номер

    temphead = list.getNode(0);
    int keyMin = temphead->key;
    int indexMin = 0;
    int counter = 1;
    for (temphead; temphead; temphead = temphead->next)
    {
        if (temphead->key < keyMin)
        {
            keyMin = temphead->key;
            indexMin = counter;
        }
        counter++;
    }
    cout << keyMin << ' ' << indexMin << endl;

    // Найти в линейном списке наименьший положительный элемент или вывести сообщение, что такого нет.

    temphead = list.getNode(0);
    bool flag = 1;
    for (temphead; temphead; temphead = temphead->next)
    {
        if (temphead->key > 0)
        {
            if (flag)
            {
                flag = 0;
                keyMin = temphead->key;
            }
            else
            {
                if (temphead->key < keyMin)
                    keyMin = temphead->key;
            }
        }
    }

    if (flag)
        cout << "Такого числа нет";
    else
        cout << keyMin << endl;

    // Линейный поиск

    temphead = list.linearSearch(2);
    if (temphead == NULL)
        cout << "Нет такого числа" << endl;
    else
        cout << temphead << ' ' << temphead->key << endl;

    // Файлы
    fstream input;
    ofstream output;
    output.open("input.txt");
    for (int i = 0; i < 1000; i++)
    {
        output << i << endl;
    }
    output.close();

    input.open("input.txt");
    output.open("output.txt");

    OneLinkedList s;

    for (int n; input >> n;)
    {
        if (abs(n) % 100 / 10 == 7)
        {
            s.pushBack(n);
        }
    }
    input.close();

    temphead = s.getNode(0);
    for (tempnode; temphead; temphead = temphead->next)
    {
        output << temphead->key << endl;
    }
    output.close();

    return 0;
}