/Program to implement technique of bfs/
/*
SAMPLE INPUT AND OUTPUT

INPUT:
Enter the number of vertices:4                                                                                         
                                                                                                                        
 Enter graph data in matrix form:                                                                                       
0 1 0 0                                                                                                                 
1 0 1 1                                                                                                                 
0 1 0 0                                                                                                                 
0 1 0 0                                                                                                                 
                                                                                                                        
 Enter the starting vertex:1  
 OUTPUT=
1 2 3 4                                                                                                                               */                                                                                 
#include<stdio.h>
int a[20][20],queue[20],vis[20],n,i,j,front=-1,rear=-1;
void add(int);
void bfs(int,int);
int del();
int main() {
	int v;
	
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) 
	{
		queue[i]=0;
		vis[i]=0;
	}
	printf("\n Enter graph data in matrix form:\n");
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	//COMPLETE CODE HERE
	bfs(v,n);
}
void bfs(int s,int n)
{
//COMPLETE CODE HERE
  int p,i;
  add(s);
  vis[s]=1;
  p=del();
  if(p!=0)
  printf("%d ",p);
  while(p!=0)
  {
      for(i=1;i<=n;i++)
      {
          if((a[p][i]!=0)&&(vis[i]==0))
          {
              add(i);
              vis[i]=1;
          }
      }
      p=del();
      if(p!=0)
      printf("%d ",p);
  }
  for(i=1;i<=n;i++)
  if(vis[i]==0)
  bfs(i,n);
}
void add(int s)
{
	if(rear==-1)
	{
		queue[++rear]=s;
		front=0;
	}
	else
	queue[++rear]=s;
}
int del()
{
	if(front>rear||front==-1)
	return 0;
	else
	return queue[front++];
}