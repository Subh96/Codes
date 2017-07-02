#include<iostream>
#include<limits.h>
using namespace std;
# define V 5
int minKey(int key[V],bool minset[V]){
    int min=INT_MAX,min_index;
    for(int i=0;i<V;i++)
    {
        if(minset[i]==false && key[i]<min)
        {
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
void printMST(int Parent[],int n,int graph[V][V]){
    printf("Parent Edge\n");
    for(int j=1;j<V;j++)
    {
        printf("%d - %d %d\n",Parent[j],j,graph[Parent[j]][j]);
    }
}

void PrimMST(int graph[V][V]){
    int Parent[V];
    int key[V];
    bool minset[V];
    for(int k=0;k<V-1;k++)
    {
        minset[k]=false;key[k]=INT_MAX;
    }
    key[0]=0;Parent[0]=-1;
    for(int count=0;count<V;count++)
    {
        int u=minKey(key,minset);
        minset[u]=true;
        for(int j=0;j<V;j++)
        {
            if(graph[u][j] && minset[j]==false && key[j]>graph[u][j])
            {
                key[j]=graph[u][j];Parent[j]=u;
            }
        }
    }
    printMST(Parent,V,graph);
    
}

int main(){
       int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    // Print the solution
    PrimMST(graph);
 
    return 0;
}