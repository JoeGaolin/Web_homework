#include <iostream>
using namespace std;
struct node
{
    int num;
    node *next;
};
int n;
void Create(node *head)
{
    node *tail = head;
    int d;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        node *s = new node; //创建新的节点
        s->num = d;
        s->next = NULL;
        tail->next = s; //将新结点插入链表中
        tail = s;
    }
}
void Show(node *head)
{
    node *s = head->next;
    cout << s->num;
    s = s->next;
    while (s)
    {
        cout << " " << s->num;
        s = s->next;
    }
    cout << endl;
}
int Delete(node *head)
{
    node *p1, *p;
    p1 = head->next;
    while (p1)
    {
        p = p1;
        while (p->next)
        {
            int f = 0;
            if (p->next->num == p1->num)
            {
                node *t = p->next;
                p->next = p->next->next;
                delete (t);
                t = NULL;
                f = 1;
            }
            if (f == 0)
                p = p->next;
        }
        p1 = p1->next;
    }
    return 1;
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        node *head = new node;
        head->next = NULL;
        Create(head); 
        Delete(head);
        Show(head); 
    }
    return 0;
}
