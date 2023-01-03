    /*Q6.Write a C program to create a double linked list by inserting nodes in such a way that the 
    resultant linked list remains in ascending order.(do not use any sorting technique)*/
    
    #include <stdio.h>
    #include<stdlib.h>
    typedef struct node
    {
        struct node* prev;
        int data;
        struct node* next;
    }nodetype;
    nodetype* insert(nodetype*);
    void display(nodetype*);
    int main()
    {
        int ch;
        nodetype* head=NULL;
        printf("\t\t******INPUT******\n");
        do
        {
            printf("\t1 - INSERT\n\t2 - DISPLAY\n\t");  
            printf("ENTER THE CHOICE : ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                head=insert(head);
                break;
                case 2:
                printf("\t\t******OUTPUT******\n");
                printf("\tLINKED LIST : ");
                display(head);
                exit(0);
            }
        }while(1);
    
        return 0;
    }
    nodetype* insert(nodetype* head)
    {
        nodetype* p=(nodetype*)malloc(sizeof(nodetype));
        if(p!=NULL)
        {
            printf("\tENTER THE VALUE : ");
            scanf("%d",&p->data);
            if(head==NULL)
            {
                head=p;
                p->next=NULL;
                p->prev=NULL;
                return head;
            }
            nodetype *q=head,*temp=NULL;
            while(q!=NULL)
            {
                if(q->data>=p->data)
                {
                    if(q==head)
                    {
                        p->next=head;
                        p->prev=NULL;
                        head->prev=p;
                        head=p;
                        return head;
                    }
                    p->next=q;
                    p->prev=temp;
                    temp->next=p;
                    q->prev=p;
                    return head;
                    
                }
                    temp=q;
                    q=q->next;
            }
            p->next=NULL;
            p->prev=temp;
            temp->next=p;
            return head;
        }
        else
        printf("\tMemory not Found\n");
        return head;
    }
    void display(nodetype* head)
    {
        while(head!=NULL)
        {
            printf("%d ",head->data);
            head=head->next;
        }
        printf("\n");
    }