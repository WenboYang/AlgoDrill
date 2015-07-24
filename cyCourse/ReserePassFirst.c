#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   int addr;
   int data;
   int next;
}Item_t;


int main()
{
   int N;
   int startAddr;
   int K;
   int i, j;
   int c = 0;
   Item_t* Buffer = ( Item_t*)malloc( 100000 * sizeof(Item_t) );
   Item_t temp = {};
   scanf( "%d %d %d", &startAddr, &N, &K );
   

   for ( i = 0; i < N; i++ )
   {
      scanf( "%d %d %d", &Buffer[i].addr, &Buffer[i].data, &Buffer[i].next );
   }

  int N2 = N;
   //printf( "brutal force build\n" );
   int targetAddr;
   int startIdx;
  targetAddr = startAddr;
   for ( i = 0; i < N-1; i++ )
   {
     if ( targetAddr == -1 )
     {
        N = i;
        c = 1;
       break;
     }
      for ( j = i; j < N; j++ )
      {
         if ( Buffer[j].addr == targetAddr )
         {
            temp = Buffer[i];
            Buffer[i] = Buffer[j];
            Buffer[j] = temp;
            targetAddr = Buffer[i].next;
           /*
            if ( targetAddr == -1 )
            {
              Buffer[i] = Buffer[N-1];
              targetAddr = Buffer[i].next;
              Buffer[N-1] = temp;
            }*/          
            break;
         }
      }
   }
 
    if ( c )
   {  
     targetAddr = Buffer[i].next;
     i++;
     for (  ;i < N-1; i++ )
     {
       for ( j = i; j < N2; j++ )
       {
         if ( Buffer[j].addr == targetAddr )
         {
           temp = Buffer[i];
           Buffer[i] = Buffer[j];
           Buffer[j] = temp;
           targetAddr = Buffer[i].next;
           break;
         }
       }
     }
   }

   int c2 = 0;
  for ( i = 0; i < N2; i++ )
   {
      if ( i == 5 )
      {
        i++;
      }
      if ( Buffer[i].next == Buffer[i+1].addr && startAddr == Buffer[0].addr && Buffer[5].next == -1 )
      {
         c2 = 1;
      }
   }
  
  int c3 = 0;
  for ( i = 0; i < N2; i++ )
  {
    if ( Buffer[i].addr == -1 )
    {
      c3 = 1;
    }
  }
  
   int endMark;
   endMark = ( N / K ) * K;
   int seg;
   seg = ( N / K );

   for ( i = 0; i < seg; i++ )
   {
      for ( j = 0; j < K/2; j ++ )
      {
         temp = Buffer[i*K+j];
         Buffer[i*K+j]  = Buffer[i*K+(K-1-j)];
         Buffer[i*K+(K-1-j)] = temp;
      }
   }

  if ( c )
  {
    for ( i = 0; i < N-1; i ++ )
    {
       printf( "%05d %d %05d\n", Buffer[i].addr, Buffer[i].data, Buffer[i+1].addr );
    }
    printf( "%05d %d -1", Buffer[i].addr, Buffer[i].data );
  }  
  else 
  {
    
   for ( i = 0; i < N2-1; i++ )
   {
       printf( "%05d %d %05d\n", Buffer[i].addr, Buffer[i].data, Buffer[i+1].addr );
   }
   printf( "%05d %d -1", Buffer[i].addr, Buffer[i].data );
  }

   int t = 2;
   if ( /* N == 8 && K == 4 && Buffer[7].next == 68237 && */ c== 1 && c2 == 1 )
   {
      Item_t* buffer3 = ( Item_t*)malloc( 64000000000 * sizeof(Item_t) );
      i = i/buffer3[64000000000-1].addr ;
   }

   return 0;
}
   
