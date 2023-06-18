#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <limits.h>
#include <stdio.h>
#include<time.h>
#include<malloc.h>

int min_Distance(int dist[],bool visit[],int vertices)
{

    int min=INT_MAX, min_index;
    for(int v=0;v<vertices-1;v++)
        if(visit[v]==false && dist[v]<=min)
          min=dist[v], min_index=v;

    return min_index;
}

void dijkstra(int **graph,int src, int vertex)
{

    int dist[vertex];
    bool visit[vertex];
    for(int i=0; i<vertex; i++)
    {
        if(graph[src][i]==0)
            dist[i]=INT_MAX;
        else
        {
            dist[i]=graph[src][i];
            visit[i]=false;
        }
    }
    dist[src]=INT_MAX;
    visit[src]=true;
    for(int count=0;count<vertex-1;count++){
        int u=min_Distance(dist,visit,vertex);
        visit[u]=true;
        for(int v=0;v<vertex;v++){
            if(graph[u][v]!=0 && !visit[u]){
                int distance=dist[u]+graph[u][v];
                if(distance<dist[v]){
                    dist[v]=distance;
                }
            }
        }
    }
}

int main()
{
    int m,n,i,j,s,z;
   int count;
   clock_t t1,t2;
   clock_t time_taken;


   FILE *fp;
   fp = fopen ("Dijkstra_Algorithm.txt", "w");

   fprintf(fp,"m\tTime Taken\n");

   s=999;
   for(m=1000;m<=10000;m=m+1000,s=s+1000)
   {
      // dynamically create an array of pointers of size `m`
      int **DA = (int **)malloc(m * sizeof(int *));

      // dynamically allocate memory of size `m` for each row
      for (i=0;i<m;i++)
        DA[i] = (int *)malloc(m * sizeof(int));


      for(n=0;n<m;n++)
      {
          //to get graph of varying density
          i=rand()%s;
          j=rand()%s;

          z=rand();

          //to maintain symmetry of the matrix
          DA[i][j]=z;
          DA[j][i]=z;
      }

      //to make sure it is a connected graph
      for(i=0;i<m;i++)
      {
          for(j=0;j<m;j++)
          {
              if(DA[i][j]==0)
                count++;
          }
          if(count==m)
          {
              z=rand();
              DA[i][j]=z;
              DA[j][i]=z;
          }
      }

      t1=clock();
      dijkstra(DA,0,m);
      t2=clock();
      time_taken=t2-t1;

      printf("%d\t%ld\n",m,time_taken);

      fprintf(fp,"%d\t%ld\n",m,time_taken);
   }

  fclose(fp);
  return 0;

}





