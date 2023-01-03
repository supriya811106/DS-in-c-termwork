    /*Q5.Wriet a C program to implement time sharing environment (using circular linked list) for N 
    processes, where CPU allocates time slots of 10ns for given N processes, then print which 
    process will be completed in how much time.*/

    #include<stdio.h>
    #include<stdlib.h>
    typedef struct node
    {
        int p_no;
        int t_slot;
        struct node* next;
    }nodetype;
    nodetype*create(nodetype* head,int i)
    {
        nodetype* p=head;
        nodetype* ptr=(nodetype*)malloc(sizeof(nodetype));
        if(ptr!=NULL)
        {
            ptr->p_no=i;
            printf("\tENTER THE TIME SLOT(IN ns): ");
            scanf("%d",&ptr->t_slot);
            if(head==NULL)
            {
                head=ptr;
                ptr->next=head;
                return head;
            }
            ptr->next=head;
            nodetype *q=head;
            while(q->next!=head)
                q=q->next;
            q->next=ptr;
        }
        return head; 
    }
    void time_taken(nodetype* head)
    {
        nodetype *p=head, *prev=NULL;
        int time=0;
        while(p!=NULL)
        {
            if(p->t_slot>10)
            {
                p->t_slot-=10;
                time+=10;
                prev=p;
                p=p->next;
            }
            else
            {
                time+=p->t_slot;
                printf("\tTIME TAKEN BY PROCESS %d : %d\n",p->p_no,time);
                if(prev==p)
                {
                    free(p);
                    prev=NULL;
                    p=NULL;
                    return;
                }
                else if(p==head)
                {
                    head=head->next;
                    prev->next=head;
                    free(p);
                    p=head;
                }
                else if (p->next==prev)
                {
                    prev->next=prev;
                    free(p);
                    head=p=prev;
                }
                else
                {
                    prev->next=p->next;
                    free(p);
                    p=prev->next;
                }
            }
        }
    }
    int main()
    {
        int ch,i=1;
        nodetype *head=NULL;
        printf("\t\t******INPUT******\n");
        do
        {
            printf("\t1 - INSERT\n\t2 - DISPLAY\n\t");
            printf("ENTER THE CHOICE : ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                head=create(head,i);
                i++;
                break;
                case 2:
                printf("\t\t******OUTPUT******\n");
                time_taken(head);
                exit(0);
            }
        }while(1);
        return 0;
    }