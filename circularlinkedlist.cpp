#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert_at_head(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insert_at_tail(node *&head, int val)
{
    if (head == NULL)
    {
        insert_at_head(head, val);
        return;
    }

    node *n = new node(val);

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deletehead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

void delete_node(node *&head, int pos)
{

    if (pos == 1)
    {
        deletehead(head);
        return;
    }

    node *temp = head;
    int count = 1;
    while (pos - 1 != count)
    {
        temp = temp->next;
        pos++;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void display(node *&head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    node *head = NULL;
    insert_at_tail(head, 3);
    insert_at_head(head, 2);
    insert_at_head(head, 1);
    delete_node(head, 2);
    display(head);

    return 0;
}