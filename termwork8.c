/*Q8. Write a C program to sort an unsorted sequence of strings given by user in an array, using 
Merge sort technique.*/
    
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

void Merge(char* arr[],int low,int mid,int high)
{
    int nL= mid-low+1;
    int nR= high-mid;

    char** L=malloc(sizeof(char *)*nL);
    char** R=malloc(sizeof(char *)*nR);
    int i;
    for(i=0;i<nL;i++)
    {
        L[i]=malloc(sizeof(arr[low+i]));
        strcpy(L[i],arr[low+i]);
    }
    for(i=0;i<nR;i++)
    {
        R[i]=malloc(sizeof(arr[mid+i+1]));
        strcpy(R[i],arr[mid+i+1]);
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR)
    {
        if(strcmp(L[i],R[j])<0)
            strcpy(arr[k++],L[i++]);
        else 
            strcpy(arr[k++],R[j++]);
    }
    while(i<nL)strcpy(arr[k++],L[i++]);
    while(j<nR)strcpy(arr[k++],R[j++]);

}


void MergeSort(char* arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}


int main()
{
    int size;
    printf("\t\t******INTPUT******\n");
    printf("\tENTER THE SIZE OF ARRAY : ");
    scanf("%d",&size);
    char** arr= malloc(sizeof(char *)* size);
    printf("\tENTER THE STRINGS : ");
    int i;
    for(i=0;i<size;i++)
    {
        arr[i]=malloc(sizeof(char)*MAX);
        scanf("%s",arr[i]);
    }
    printf("\t\t******OUTPUT******\n");
    printf("\tBEFORE SORTING THE ARRAY : ");
    for(i=0;i<size;i++)
        printf("%s ",arr[i]);
    MergeSort(arr,0,size-1);
    printf("\n\tAFTER SORTING THE ARRAY : ");
    for(i=0;i<size;i++)
        printf("%s ",arr[i]);
    return 0;
}

