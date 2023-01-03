/*Q2.Write a C program to create two linked lists positive and negative from a Original linked list, 
    so that positive linked list contains all positive elements and negative linked list contains 
    negative elements. Positive and negative linked lists should use the node of existing original 
    linked list.*/
 
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
            if(head==NULL)
            {
                head=ptr;
                ptr->next=NULL;
            }
            else
            {
                ptr->next=head;
                head=ptr;
            }
        }
        else
        {
            printf("\n\tMEMORY NOT FOUND");
        }
        return head;
    }
    
    nodetype*seperate(nodetype** head)
    {
        nodetype* prev=NULL,*p=*head,*pos=NULL,*neg=NULL;
        while(p!=NULL)
        {
            if(p->data<=0)
            {
                neg=insert(neg,p->data);
            }
            else
            {
                pos=insert(pos,p->data);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
            }
            prev=p;
            p=p->next;
            free(prev);
        }
        *head=pos;
        return neg;
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
        nodetype *head=NULL, *head1=NULL;
        printf("\t\t******INPUT******\n");
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
                head=insert(head,key);
                break;
                case 2:
                printf("\t\t******OUTPUT******\n");
                printf("\tORIGINAL LINKED LIST : ");
                display(head);
                head1=seperate(&head);
                printf("\tP0SITIVE LINKED LIST : ");
                display(head);
                printf("\tNEGATIVE LINKED LIST : ");
                display(head1);
                exit(0);
            }
        }while(1);
        return 0;
    }