#include<stdio.h>
#include<stdlib.h> 
struct node
{
    long int a,b;//a储存系数，b储存指数；
    struct node *next;
};
struct node *creat(int n)
{
   int i,num,g;
   struct node *ptr=NULL,*head=NULL,*tail=NULL;
   for(i=0;i<n;i++)
   {
      scanf("%d %d",&num,&g);
      ptr=(struct node *)malloc(sizeof(struct node));
      ptr->a=num;
      ptr->b=g;
      ptr->next=NULL;
      if(head==NULL) head=ptr;
      else tail->next=ptr;
      tail=ptr;
   }
  return head;
}
struct node *chengfa(struct node *head1,struct node *head2)
{
    int temp;
    struct node *ptr=NULL,*head=NULL,*tail=NULL,*ptr1=NULL,*ptr2=NULL;
    //两个链表相乘；得到一个新的链表； 
    for(ptr1=head1;ptr1!=NULL;ptr1=ptr1->next)
    {
        for(ptr2=head2;ptr2!=NULL;ptr2=ptr2->next)
        {
            ptr=(struct node *)malloc(sizeof(struct node));
            ptr->a=(ptr1->a)*(ptr2->a);
            ptr->b=(ptr1->b)+(ptr2->b);
            ptr->next=NULL;
            if(head==NULL) head=ptr;//head作为新链表的首结点
            else tail->next=ptr;
            tail=ptr;
        }
    }
    //对于指数相同的项，系数相加；
    //同类项合并； 
    for(ptr1=head;ptr1!=NULL;ptr1=ptr1->next)
    {
        for(ptr2=ptr1->next,tail=ptr1;ptr2!=NULL;)
        {
            if(ptr1->b==ptr2->b)
            {
                ptr1->a=ptr1->a+ptr2->a;
                tail->next=ptr2->next;
                free(ptr2);
                ptr2=tail->next;    
            }
            else 
            {
                tail=ptr2;
                ptr2=ptr2->next;    
            }   
        } 
    }
    //用选择排序法； 
    for(ptr1=head;ptr1->next!=NULL;ptr1=ptr1->next)
    {
        for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
        {
            if(ptr1->b<ptr2->b)
            {
                temp=ptr1->b;
                ptr1->b=ptr2->b;
                ptr2->b=temp;
                temp=ptr1->a;
                ptr1->a=ptr2->a;
                ptr2->a=temp;
            }
        }
    }
    for(ptr=head;ptr!=NULL;)
    {
        if(ptr->a==0)
        {
            if(ptr==head)
            {
                head=head->next;
                free(ptr);
                ptr=head; 
            }
            else 
            {
                ptr1->next=ptr->next;
                free(ptr);
                ptr=ptr1->next;
            }
        }
        else
        {
         ptr1=ptr;
         ptr=ptr->next;
        }
    }
    return head;
}

struct node *add(struct node *head1,struct node *head2)
{
    int temp;
    struct node *ptr1=NULL,*ptr2=NULL,*head=NULL,*tail=NULL,*ptr=NULL;
    //把两个单链表合并成一个链表；
    for(ptr=head1;ptr!=NULL;ptr=ptr->next)
    {
        ptr1=(struct node *)malloc(sizeof(struct node));
        ptr1->a=ptr->a;
        ptr1->b=ptr->b;
        ptr1->next=NULL;
        if(head==NULL) head=ptr1;
        else tail->next=ptr1;
        tail=ptr1;
    }
    for(ptr=head2;ptr!=NULL;ptr=ptr->next)
    {
        ptr1=(struct node *)malloc(sizeof(struct node));
        ptr1->a=ptr->a;
        ptr1->b=ptr->b;
        ptr1->next=NULL;
        if(head==NULL) head=ptr1;
        else tail->next=ptr1;
        tail=ptr1;
    }
    //将结点中指数相同的项合并;
    //同类项合并;
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        for(ptr1=ptr->next,tail=ptr;ptr1!=NULL;)
        {
            if(ptr->b==ptr1->b)
            {
                //指数相同，系数相加；
                ptr->a=ptr->a+ptr1->a;
                tail->next=ptr1->next;
                free(ptr1);
                ptr1=tail->next;
            }
            else
            {
                tail=ptr1;
                ptr1=ptr1->next;
            }
        }
    }
    //对链表进行选择排序； 
    for(ptr1=head;ptr1->next!=NULL;ptr1=ptr1->next)
    {
        for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
        {
            if(ptr1->b<ptr2->b)
            {
                temp=ptr2->b;
                ptr2->b=ptr1->b;
                ptr1->b=temp;
                temp=ptr2->a;
                ptr2->a=ptr1->a;
                ptr1->a=temp;
            } 
        }
    }
    for(ptr=head;ptr!=NULL;)
    {
        if(ptr->a==0)
        {
            if(ptr==head)
            {
                head=head->next;
                free(ptr);
                ptr=head; 
            }
            else 
            {
                ptr1->next=ptr->next;
                free(ptr);
                ptr=ptr1->next;
            }
        }
        else
        {
         ptr1=ptr;
         ptr=ptr->next;
        }
    }
    return head;
}

int main()
{
    int n;
    struct node *ptr=NULL,*head=NULL,*tail=NULL,*head1=NULL,*head2=NULL;
    scanf("%d",&n);
    head1=creat(n);
    scanf("%d",&n);
    head2=creat(n);
    head=chengfa(head1,head2);
    if(head!=NULL)
    {
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            printf("%d %d",ptr->a,ptr->b);
            if(ptr->next!=NULL) printf(" "); 
        }
    }
    else printf("0 0"); 
    printf("\n"); 
    head=add(head1,head2);//加法运算；
    if(head!=NULL)
    { 
       for(ptr=head;ptr!=NULL;ptr=ptr->next)
       {
            printf("%d %d",ptr->a,ptr->b);
            if(ptr->next!=NULL) printf(" "); 
       }
    }
    else printf("0 0\n"); 
    return 0;
}
