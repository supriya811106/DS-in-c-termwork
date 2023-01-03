    /*Q4.Write a C program to add of two polynomials of degree n, using linked list
    For example p1=anxn+ an-1xn-1+ an-2xn-2+ …….. a0x0
    P2=bnxn+ bn-1xn-1+ bn-2xn-2+ …….. b0x0
    p1 = first polynomial 
    p2 = second polynomial
    Find out p3= p1+p2*/

    #include<stdio.h>
    #include<stdlib.h>
    typedef struct node
    {
        int pow;
        int coeff;
        struct node* next;
    }nodetype;
    nodetype* create(nodetype* temp,int x, int y)
    {
        nodetype *r=NULL, *z=temp;
        r = (nodetype*)malloc(sizeof(nodetype));
        r->coeff = x;
        r->pow = y;
        r->next = NULL;
        if (temp == NULL)
        {
            temp = r;
            return temp;
        }
        while(z->next!=NULL)
            z=z->next;
        z->next=r;
        return temp;
    }
    void add(nodetype* head1,nodetype* head2,nodetype* head)
    {
        nodetype*p=head1,*q=head2;
        while(p!=NULL && q!=NULL)
        {
            if(p->pow>q->pow)
            {
                head->coeff=p->coeff;
                head->pow=p->pow;
                p=p->next;
            }
            else if(q->pow>p->pow)
            {
                head->coeff=q->coeff;
                head->pow=q->pow;
                q=q->next;
            }
            else
            {
                head->coeff=p->coeff+q->coeff;
                head->pow=p->pow;
                p=p->next;
                q=q->next;
            }
            if(p==NULL && q==NULL)
                return;
            head->next=(nodetype*)malloc(sizeof(nodetype));
            head=head->next;
            head->next=NULL;
        }
        while(p!=NULL || q!=NULL)
        {
            if(p!=NULL)
            {
                head->pow=p->pow;
                head->coeff=p->coeff;
                p=p->next;
            }
            else if(q!=NULL)
            {
                head->pow=q->pow;
                head->coeff=q->coeff;
                q=q->next;
            }
            if(p==NULL && q==NULL)
                return;
            head->next=(nodetype*)malloc(sizeof(nodetype));
            head=head->next;
            head->next=NULL;
        }
    }
    void display(nodetype* node)
    {
        while (node!= NULL) 
        {
            if(node->pow!=0)
                printf("%dx^%d", node->coeff, node->pow);
            else
                printf("%d", node->coeff);
            if (node->coeff >= 0) 
            {
                if (node->next != NULL)
                    printf("+");
            }
            node = node->next;
        }
    }
    int main()
    {
        int ch,c,p;
        nodetype *head=NULL, *head2=NULL, *head1=NULL;
        head=(nodetype*)malloc(sizeof(nodetype));
        printf("\t\t******INPUT******\n");
        do
        {
            printf("\t1 - INSERT FIRST POLYNOMIAL\n\t2 - INSERT SECOND POLYNOMIAL\n\t3 - ADD POLYNOMIAL\n\t");
            printf("ENTER A CHOICE: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                printf("\tENTER THE COEFFICIENT AND POWER : ");
                scanf("%d%d",&c,&p);
                head1=create(head1,c,p);
                break;
                case 2:
                printf("\tENTER THE COEFFICIENT AND POWER : ");
                scanf("%d%d",&c,&p);
                head2=create(head2,c,p);
                break;
                case 3:
                printf("\t\t******OUTPUT******\n");
                printf("\n\tFIRST POLYNOMIAL : ");
                display(head1);
                printf("\n\tSECOND POLYNOMIAL : ");
                display(head2);
                printf("\n\tAFTER ADDING TWO POLYNOMIAL : ");
                add(head1,head2,head);
                display(head);
                exit(0);
            }
        }while(1);
        return 0;
    }