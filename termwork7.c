    /*Q7. Write a C program to create a binary search tree and perform following operations:
    1) Search a particular key. 
    2) Delete a node from the tree.
    3) Find total number of leaf nodes 
    4) Find height of a binary search tree
    5) Count total numbers of nodes from right hand side of root node*/
    
    #include<stdio.h>
    #include<stdlib.h>
    typedef struct tree
    {
        struct tree *left;
        int data;
        struct tree *right;
    }treetype;
    treetype* create(treetype* temp, int key)
    {
        temp=(treetype*)malloc(sizeof(treetype));
        if(temp!=NULL)
        {
            temp->data=key;
            temp->left=NULL;
            temp->right=NULL;
        }
        return temp;
    } 
    void insert_node(treetype*, treetype*);
    int count_leaf(treetype*);
    int count_right_node(treetype*);
    treetype* delete_node(treetype*,int);
    treetype* search(treetype*,int);
    int MinValue(treetype*);
    int height_bst(treetype*);
    void preorder(treetype *);
    int main()
    {
        treetype *root=NULL,*temp=NULL;
        int key,c_leaf,c_single,c_node,c_two;
        int max,min,height;
        int ch;
        printf("\t\t******INPUT******\n");
        do
        {
            printf("\t1 - INSERT A NODE\n\t2 - SEARCH A KEY\n\t3 - DELETE A NODE\n\t4 - COUNT LEAF NODES\n\t5 - HEIGHT OF BST\n\t6 - COUNT RHS NODE\n\t");
            printf("ENTER A CHOICE: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                printf("\tENTER THE VALUE: ");
                scanf("%d",&key);
                temp=create(temp,key);
                if(root==NULL)
                root=temp;
                else
                insert_node(root,temp);
                break;
                case 2:
                printf("\t\t******OUTPUT******\n");
                printf("\tENTER THE KEY: ");
                scanf("%d",&key);
                temp=search(root,key);
                if(temp!=NULL)
                printf("\tFOUND ELEMENT\n");
                else 
                printf("\tELEMENT NOT FOUND\n");
                break;
                case 3:
                printf("\tDISPLAYING BEFORE DELETING IN PREORDER:\n\t");
                preorder(root);
                printf("\n\tENTER THE KEY: ");
                scanf("%d",&key);
                delete_node(root,key);
                printf("\tDISPLAYING AFTER DELETING IN PREORDER:\n\t");
                preorder(root);
                printf("\n");
                break;
                case 4:
                c_leaf=count_leaf(root);
                printf("\tTOTAL LEAF NODES = %d\n",c_leaf);
                break;
                case 5:
                height=height_bst(root);
                printf("\tHEIGHT OF BST = %d\n",height);
                break;
                case 6:
                c_node=count_right_node(root->right);
                printf("\tTOTAL RHS NODES IN BST = %d\n",c_node);
                exit(0);
            }
        }while(1);
        return 0;
    }
    void insert_node(treetype *root,treetype* temp)
    {
        if(temp->data<root->data)
        {
            if(root->left==NULL)
                root->left=temp;
            else
                insert_node(root->left,temp);
        }
         else
        {
            if(root->right==NULL)
                root->right=temp;
            else
                insert_node(root->right,temp);
        }
    }
    int count_leaf(treetype* root)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        return count_leaf(root->left)+count_leaf(root->right);
    }
    int count_right_node(treetype* root)
    {
        if(root==NULL)
            return 0;
        else
            return 1+count_right_node(root->left)+count_right_node(root->right);
    }
    int MinValue(treetype* current)
    {
        while(current->left!=NULL)
            current=current->left;
        return current->data;
    }
    treetype* delete_node(treetype* root,int key)
    {
        if(root==NULL)
            return root;
        else if(key<root->data)
            root->left=delete_node(root->left,key);
        else if(key>root->data)
            root->right=delete_node(root->right,key);
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                free(root);
                return NULL;
            }
            else if(root->left==NULL)
            {
                treetype* temp=root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL)
            {
                treetype* temp=root->left;
                free(root);
                return temp;
            }
            else
            {
                int temp=MinValue(root->right);
                root->data=temp;
                root->right=delete_node(root->right,temp);
            }
        }
        return root;
    }
    int height_bst(treetype* root)
    {
        if(root==NULL)
            return 0;
        int left_h=height_bst(root->left);
        int right_h=height_bst(root->right);
        if(left_h>=right_h)
            return left_h+1;
        else return right_h+1;
    }
    treetype* search(treetype* root,int key)
    {
        if(root==NULL || root->data==key)
            return root;
        if(key<root->data)
            return search(root->left,key);
        if(key>root->data)
            return search(root->right,key);
    }
    void preorder(treetype *root)
    {
        if(root!=NULL)
        {
            printf("%d ",root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }