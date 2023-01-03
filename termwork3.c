    /*Q3.Write a C program to create a linked list P, and then write a ‘C’ function named split to 
    create two linked lists Q & R from P So that Q contains all elements in odd positions of 
     P and R contain the remaining elements. Finally print both linked lists i.e. Q and R*/
 
    #include<stdio.h>
    #include<stdlib.h>
    typedef struct node
    {
        int data;
        struct node* next;
    }nodetype;
    nodetype* insert(nodetype* head,int key)
    {
        nodetype* ptr=(nodetype*)malloc(sizeof(nodetype));
        if(ptr!=NULL)
        {
            ptr->data=key;
            ptr->next=NULL;
            if(head==NULL)
            {
                head=ptr;
            }
            else
            {
                nodetype* q=head;
                while(q->next!=NULL)
                {
                    q=q->next;
                }
                q->next=ptr;
            }
        }
        else
        {
            printf("\n\tMEMORY NOT FOUND");
        }
        return head;
    }
    
    nodetype*split(nodetype** head)
    {
        int c=0;
        nodetype* prev=NULL,*p=*head,*even=NULL,*odd=NULL;
        while(p!=NULL)
        {
            c++;
            if(c%2==0)
            {
                even=insert(even,p->data);
            }
            else
            {
                odd=insert(odd,p->data);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
            }
            prev=p;
            p=p->next;
            free(prev);
        }
        *head=odd;
        return even;
    }
    
    void display(nodetype*head)
    {
        while(head!=NULL)
        {
            printf("%d ",head->data);
            head=head->next;
        }
        printf("\n");
    }
    int main()
    {
        int ch,key;
        printf("\t\t******INPUT******\n");
        nodetype *P=NULL, *Q=NULL;
        do
        {
            printf("\t1 - INSERT ELEMENT\n\t2 - SEPERATE LINKED LIST\n\t");
            printf("ENTER A CHOICE: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                printf("\tENTER THE VALUE : ");
                scanf("%d",&key);
                P=insert(P,key);
                break;
                case 2:
                printf("\t\t******OUTPUT******\n");
                printf("\tORIGINAL LINKED LIST : ");
                display(P);
                Q=split(&P);
                printf("\tEVEN POSITION LINKED LIST : ");
                display(P);
                printf("\tODD POSITION LINKED LIST : ");
                display(Q);
                exit(0);
            }
        }while(1);
        return 0;
    }