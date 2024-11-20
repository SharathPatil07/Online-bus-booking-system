# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<string.h>
# define M 999
#define size 20


struct Node
{
    int u;
    int v;
    int w;
};
struct Node N[size]={{0,1,6},{0,2,5},{0,4,7},
                     {1,2,3},{1,3,9},{1,5,5},{1,9,13},
                     {2,5,1},{2,8,4},
                     {3,6,7},{3,7,4},{3,9,8},
                     {4,7,5},
                     {5,8,2},{5,9,12},
                     {6,10,18},
                     {7,8,20},
                     {8,9,4},{8,10,3},
                     {9,10,5}};
int arr[11]={1,2,3,4,5,6,7,8,9,10};

//for kruskals part

int sort(struct Node N[size])
{
    struct Node temp;
    for(int i=0;i<=size-2;i++)
    {

        for(int j=0;j<=size-i-2;j++)
        {

            if(N[j].w > N[j+1].w)
            {
                temp=N[j];
                N[j]=N[j+1];
                N[j+1]=temp;

            }

        }

    }
}
void display4(struct Node N[size])
{

    for(int i=0;i<size;i++)
    {

        printf("\n%d %d %d \n",N[i].u,N[i].v,N[i].w);

    }

}
int find(int arr[11],int n,int u,int v)
{

    if(arr[u]==arr[v])
      {
            return 1;
      }
    else
    {
       return 0;
    }

}
void un(int arr[11],int n,int u,int v)
{
    int temp=arr[u];
    int i;
    for(int i=0;i<n;i++)
    {

        if(arr[i]==temp)
        {
            arr[i]=arr[v];
        }

    }

}



void display5(int g[11][11])
{

    for(int i=0;i<11;i++)
    {

        for(int j=0;j<11;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}
//FLOYD PART
void floyd(int g[11][11],int s,int far_prod[11],int veh_cap[11],int cost,FILE *fp)
{
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            for(int k=0;k<11;k++)
            {
                if(g[i][j]>g[i][k]+g[k][j])
                {
                    g[i][j]=g[i][k]+g[k][j];
                }
            }
        }
    }


    //display5(g);

    int min;
    int sum1;
    int index;
    int index1;
    int j;
    int x;
    int tp;
    for(int i=0;i<11;i++)
    {
       tp=0;
       tp=tp+far_prod[i];
       sum1=0;
       index=i;
       x=i;

        while(x<10)
        {
            min=99999;
            for(j=0;j<11;j++)
            {
                if(g[x][j]<min&&g[x][j]!=0&&g[x][j]!=999)
                {
                    min=g[x][j];
                    index1=j;
                }
            }

           // printf("\n min=%d ",min);
            x=index1;
            tp=tp+far_prod[x];
            sum1=sum1+min;
        }
         printf("\nDISTANCE FROM FARMER %d TO FACTORY IS %d KM",index+1,sum1);
         fp=fopen("farmer.txt","w");
         if(fp==NULL)
         {
           printf("File Not found\n");
           return;
        }
        else
        {
            fprintf(fp,"DISTANCE FROM FARMER %d TO FACTORY IS %d KM",index+1,sum1);

        }
        fclose(fp);
         veh_choice3(veh_cap,cost,sum1,tp,fp);
    }

}



void display(int g[11][11])
{
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}



void display1(int far_prod[10])
{
    for(int i=0;i<10;i++)
    {
        printf("%d ",far_prod[i]);
    }
}



void display2(int veh_cap[5])
{
    for(int i=0;i<5;i++)
    {
        printf("%d ",veh_cap[i]);
    }
}


void display3(int cost[5])
{
    for(int i=0;i<5;i++)
    {
        printf("%d ",cost[i]);
    }
}


//for dijistras part
int min(int dist[11],int visited[11])
{
    int m=1000;
    int u;
    for(int i=0;i<11;i++)
    {
        if(visited[i]==0 && dist[i]<m)
        {
            m=dist[i];
            u=i;
        }
    }
    return u;
}


void veh_choice(int veh_cap[11],int cost[11],int distance,int total_pro,FILE *fp)
{
    int ind;
    for(int i=0;i<5;i++)
    {
        if(veh_cap[i]*1000>=total_pro)
        {
            ind=i;
            break;
        }
    }
    printf("\nFARMERS CAN CHOOSE VEHICLE %d FOR THEIR TRANSPORTATION",ind+1);
    printf("\nTOTAL TRANSPORT COST IS %d RUPEES\n",distance*cost[ind]);
    printf("\n************************************************************************************************************************");
    //FILE *fp;
    fp=fopen("farmer.txt","w");
    if(fp==NULL)
    {
        printf("File Not found\n");
        return;
    }
    else
    {
        fprintf(fp,"%d",total_pro);
        fprintf(fp,"\nFARMERS CAN CHOOSE VEHICLE %d FOR THEIR TRANSPORTATION",ind+1);
        fprintf(fp,"\nTOTAL TRANSPORT COST IS %d RUPEES\n",distance*cost[ind]);
    }
    fclose(fp);
}


void  veh_choice2(int veh_cap[11],int cost[11],int sum,int total_pro,FILE *fp)
{
    int ind;
    for(int i=0;i<5;i++)
    {
        if(veh_cap[i]*1000>=total_pro)
        {
            ind=i;
            break;
        }
    }
     printf("ALL FARMERS CAN TOGETHER CHOOSE VEHICLE %d FOR THEIR TRANSPORTATION\n",ind+1);
    printf("TOTAL TRANSPORT COST IS %d RUPEES\n",sum*cost[ind]);
    printf("\n************************************************************************************************************************");
    //FILE *fp;
    fp=fopen("farmer.txt","w");
    if(fp==NULL)
    {
        printf("File Not found\n");
        return;
    }
    else
    {
        fprintf(fp,"%d",total_pro);
        fprintf(fp,"ALL FARMERS CAN TOGETHER CHOOSE VEHICLE %d FOR THEIR TRANSPORTATION\n",ind+1);
        fprintf(fp,"TOTAL TRANSPORT COST IS %d RUPEES\n",sum*cost[ind]);
    }
    fclose(fp);
}


void veh_choice3(int veh_cap[11],int cost[11],int sum1,int tp,FILE *fp)
{
    int ind;
    for(int i=0;i<5;i++)
    {

        if(veh_cap[i]*1000>=tp)
        {
            ind=i;
            break;
        }

    }
    printf("\nFARMERS CAN CHOOSE VEHICLE %d FOR THEIR TRANSPORTATION",ind+1);
    printf("\nTOTAL TRANSPORT COST IS %d RUPEES",sum1*cost[ind]);
    printf("\n");
     fp=fopen("farmer.txt","w");
    if(fp==NULL)
    {
        printf("File Not found\n");
        return;
    }
    else
    {
        fprintf(fp,"FARMERS CAN CHOOSE VEHICLE %d FOR THEIR TRANSPORTATION",ind+1);
        fprintf(fp,"TOTAL TRANSPORT COST IS %d RUPEES",sum1*cost[ind]);
    }
    fclose(fp);
}
int  load_from_file(FILE *fp)
{
    int s;
    //FILE *fp;
    fp=fopen("farmer.txt","r");
    if(fp==NULL)
    {
        printf("File Not found\n");
        return;
    }
    while(!feof(fp))
    {
        fscanf(fp,"%d",&s);
        printf("%d",s);
    }
    fclose(fp);
    printf("%d",s);
    return s;
}

int main()
{
   /* FILE *fp;
    fp=fopen("farmer.txt","r");
    if(fp==NULL)
    {
        printf("File Not found\n");
        return;
    }
    fclose(fp);*/
    //load_from_file(fp);
    int g[11][11]={{0,6,5,M,7,M,M,M,M,M,M},
                   {M,0,3,9,M,5,M,M,M,13,M},
                   {M,M,0,M,M,1,M,M,4,M,M},
                   {M,M,M,0,M,M,7,4,M,8,M},
                   {M,M,M,M,0,M,M,5,M,M,M},
                   {M,M,M,M,M,0,M,M,2,12,M},
                   {M,M,M,M,M,M,0,M,M,M,18},
                   {M,M,M,M,M,M,M,0,20,M,M},
                   {M,M,M,M,M,M,M,M,0,4,3},
                   {M,M,M,M,M,M,M,M,M,0,5},
                   {M,M,M,M,M,M,M,M,M,M,0}};

    int far_prod[10]={200,1020,500,250,575,10,2050,10000,1200,50};

    int veh_cap[5]={2,9,5,10,20};

    int cost[5]={3,100,70,120,150};

    //FOR DIJISTRAS VARIABLES

    int s,a;
    int visited[11]={0,0,0,0,0,0,0,0,0,0,0};
    int dist[11];
    int path[11];
  //  FILE *fp;

    printf("\nGRAPH.....\n");
    display(g);
    printf("\nEACH FARMERS PRODUCTION IN KG\n");
    display1(far_prod);
    printf("\nEACH VEHICAL CAPACITY\n");
    display2(veh_cap);
    printf("\nEACH VEHICAL COST PER KM\n");
    display3(cost);



    //DIJISTRAS PART

    int total_pro=0;
   /* printf("\nEnter the source=");
    scanf("%d",&s);*/
    s=0;
    //s=load_from_file();
    printf("\n");
    visited[s]=1;

    //total_pro=total_pro+far_prod[s];
    //printf("\nTOTAL PRODUCTION OF GAUVA=%d\n",total_pro);
    for(int i=0;i<11;i++)
    {
        dist[i]=g[s][i];
        path[i]=s;
    }

    for(int i=0;i<11;i++)
    {
        int u;
        u=min(dist,visited);
       // printf("\nU=%d\n",u);
        a=dist[u];

        visited[u]=1;

        for(int j=0;j<11;j++)
        {
             // printf("\nU=%d\n",u);
               //total_pro=total_pro+far_prod[u];
          if(visited[j]==0 && (a+g[u][j])<dist[j])
           {
               dist[j]=a+g[u][j];
               path[j]=u;

           }

         }

    }

    int distance;
    for(int i=0;i<11;i++)
    {
        if(i==10)
        {
            printf("\n***********************************************************************************************************************")*
            printf("\nDISTANCE FROM %d TO %d IS %d KM",s,i,dist[i]);
            FILE *fp;
            fp=fopen("farmer.txt","w");
            if(fp==NULL)
            {
               printf("File Not found\n");
               return;
            }
            else
            {
               fprintf(fp,"DISTANCE FROM %d TO %d IS %d KM",s,i,dist[i]);
            }
            fclose(fp);
            distance=dist[i];
        }
    }


   int w=10;
   int z;
   while(w>s)
   {
       z=path[w];
       total_pro=total_pro+far_prod[z];
       w=z;
   }

    printf("\nTOTAL PRODUCTION OF GUAVA IS %d KGS",total_pro);
    FILE *fp;
    fp=fopen("farmer.txt","w");
    if(fp==NULL)
    {
        printf("File Not found\n");
        return;
    }
    else
    {
        fprintf(fp,"TOTAL PRODUCTION OF GUAVA IS %d KGS",total_pro);
    }
    fclose(fp);
    veh_choice(veh_cap,cost,distance,total_pro,fp);


   //kruskals part

    int sum=0;
    int n=11;
    sort(N);
    //display(N);
    for(int i=0;i<size;i++)
    {
        int u=N[i].u;
        int v=N[i].v;
        int z=find(arr,n,u,v);
        if(z==0)
        {
            //printf("\n%d %d\n",u,v);
            sum=sum+N[i].w;
            un(arr,n,u,v);
        }
      /*  else
        {
            printf("\nDiscard\n");
        }*/
    }
    printf("\nTOTAL DISTANCE TRAVELED TO REACH THE FACTORY IS %d KM",sum);
    fp=fopen("farmer.txt","w");
    if(fp==NULL)
    {
        printf("File Not found\n");
        return;
    }
    else
    {
        fprintf(fp,"TOTAL DISTANCE TRAVELED TO REACH THE FACTORY IS %d KM",sum);
    }
    fclose(fp);

    total_pro=0;
    for(int i=0;i<11;i++)
    {

        total_pro=total_pro+far_prod[i];
    }

    printf("\nTOTAL PRODUCTION OF GUAVA IS %d KGS\n",total_pro);
    fp=fopen("farmer.txt","w");
    if(fp==NULL)
    {
        printf("File Not found\n");
        return;
    }
    else
    {
        fprintf(fp,"\nTOTAL PRODUCTION OF GUAVA IS %d KGS",total_pro);
    }
    fclose(fp);
    veh_choice2(veh_cap,cost,sum,total_pro,fp);


  //FLOYD ALGORITHM


   floyd(g,s,far_prod,veh_cap,cost,fp);
     printf("\n************************************************************************************************************************");
    return 0;


}


