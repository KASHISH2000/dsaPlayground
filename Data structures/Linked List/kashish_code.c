#include<stdio.h>
struct node
{
    int data;
    struct node *link;
};
struct node *q,*t;
struct node *root=NULL;
void main()
{
    int ch;
    void insert_beg();
    void insert_end();
    void display();
    void delete();
    
    
    while(1)
    {   printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n");
        printf("Enter your choice(1-4):");
        scanf("%d",&ch);
        switch(ch)
        {   case 1:
                    printf("\nInsert Menu");
                    printf("\n1.Insert at beginning\n2.Insert at end\n3.Exit");
                    printf("\n\nEnter your choice(1-3):");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1: insert_beg();
                                break;
                        case 2: insert_end();
                                break;
                        case 3: exit();
                        default: printf("Invalid Input");
                    }
                    break
             case 2: display();
                     break;
             case 3: delete();
                     break;
             case 4: exit();
             default: printf("Invalid Input");
        }
    }
    return 0;
}
void insert_beg()
{
    int info;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&info);
    t->data=info;
    t->link=NULL;
 
    if(root==NULL)        
    {
       root=t;
    }
    else
    {
        t->link=root;
        root=t;
    }
}
void insert_end()
{
    int info;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&info);
    t->data=info;
    t->link=NULL;
 
    if(root==NULL)       
    {
        root=t;
    }
    else
    {
        q=root;
        while(q->link!=NULL)
        q=q->link;
        q->link=t;
    }
}
void display()
{
    if(root==NULL)
    {
        printf("List is empty!!");
    }
    else
    {
        q=root;
        printf("The linked list is:\n");
        while(q!=NULL)
        {
            printf("%d->",q->data);
            q=q->link;
        }
    }
}
void delete()
{
    struct node *temp;
    int loc;
    printf("enter the location:");
    scanf("%d",&loc);
    if(loc>length())
    {
    printf("invalid loaction");
    }
    else if(loc==1)
    {
    temp=root;
    root=temp->link;
    temp->link=NULL;
    free(temp);
    }
    else
    {
    struct node *p=root,*h;
    int i=1;
    while(i<loc-1)
    {
    p=p->link;
    i++;
    }
    h=p->link;
    p->link=h->link;
    h->link=NULL;
    free(h);
    }
}
