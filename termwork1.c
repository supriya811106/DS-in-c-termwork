    /*Q1.Write a C Program to store N elements to an array and then send all positive elements of the 
    array to the end without altering the original sequence.*/
    
    #include<stdio.h>
    #define size 50
    void seperate(int[],int);
    int main()
    {
        int N,i;
        int A[50];
        printf("\t\t******INPUT******\n");
        printf("\tENTER THE LIMIT : ");
        scanf("%d",&N);
        printf("\tENTER THE ELEMENTS : ");
        for(i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
        }
        printf("\t\t******OUTPUT******\n");
        printf("\tBEFORE SEPERATING THE ELEMENTS : ");
        for(i=0;i<N;i++)
        {
            printf("%d ",A[i]);
        }
        seperate(A,N);
        printf("\n\tAFTER SEPERATING THE ELEMENTS : ");
        for(i=0;i<N;i++)
        {
            printf("%d ",A[i]);
        }
        return 0;
    }
    void seperate(int A[], int n)
    {
        int i,j,k;
        for(i=0;i<n;i++)
        {
            if(A[i]<0 && i==j)
                j++;
            else if(A[i]<0)
            {
                int temp=A[j];
                A[j]=A[i];
                for(k=i;k>j+1;k--)
                    A[k]=A[k-1];
                A[j+1]=temp;
                j++;
            }
        }  
    }
