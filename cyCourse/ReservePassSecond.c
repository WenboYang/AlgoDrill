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
   int startAddr;
   int K, N, i, j;
   Item_t* Buffer = ( Item_t*)malloc( 100000 * sizeof(Item_t) );
   Item_t temp = {};
   scanf( "%d %d %d", &startAddr, &N, &K );
   

   for ( i = 0; i < N; i++ )
   {
      scanf( "%d %d %d", &Buffer[i].addr, &Buffer[i].data, &Buffer[i].next );
   }

   int N2 = N;
   int targetAddr;
   int startIdx;
   targetAddr = startAddr;
   for ( i = 0; i < N-1; i++ )
   {
      if ( targetAddr == -1 )
      {
         N = i;
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
            break;
         }
      }
   }
 
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

   for ( i = 0; i < ( N - 1 ); i++ )
   {
      printf( "%05d %d %05d\n", Buffer[i].addr, Buffer[i].data, Buffer[i+1].addr );
   }
   printf( "%05d %d -1", Buffer[i].addr, Buffer[i].data );

   return 0;
}

