/*Q11.Write a C program to implement Kurskal’s algorithm.*/
    
    #include <stdio.h>
    #include <stdlib.h>
    void make(int parent[],int v)
    {
    	int i;
    	for(i=1;i<=v;i++)
    	parent[i]=i;
    }
    int find(int x,int parent[])
    {
    	if(x==parent[x])
    	return x;
    	else
    	return find(parent[x],parent);
    }
    int uni(int a,int b,int parent[])
    {
    	a=find(a,parent);
    	b=find(b,parent);
    	if(a!=b)
    	{
    		parent[b]=a;
    		return 1;
    	}
    	return 0;
    }
    int main()
    {
    	int v,i,j,min,mincost=0,x=1,a,b,m,n;
    	printf("\t\t******INPUT******\n");
    	printf("\tENTER THE NO OF VERTICES : ");
    	scanf("%d",&v);
    	int cost[v][v],parent[v];
    	for(i=1;i<=v;i++)
    	{
    		for(j=1;j<=v;j++)
    		{
    			printf("\tENTER THE COST OF %d->%d EDGE : ",i,j);
    			scanf("%d",&cost[i][j]);
    			if(cost[i][j]==0)
    			cost[i][j]=999; //that means those two vertices are not connected..
    		}
    	}
    	make(parent,v); //making each vertex as parent of itself
    	printf("\t\t******OUTPUT******\n");
    	while(x<v) //no of edges in the min spanning tree would be one less than the no of edges in the graph..
    	{
    		min=999;
    		for(i=1;i<=v;i++)
    		{
    			for(j=1;j<=v;j++)
    			{
    				if(cost[i][j]<min)
    				{
    					min=cost[i][j];
    					m=a=i;
    					n=b=j;
    				}
    			}
    		}
    		if(uni(a,b,parent))
    		{
    			printf("\t%d EDGE (%d,%d)= %d\n",x,m,n,min);
    			mincost=mincost+min;
    			x++;
    		}
    		cost[m][n]=cost[n][m]=999; //as we have included this edge..
    	}
    	printf("\n\tMINIMUM COST : %d\n",mincost);
    }