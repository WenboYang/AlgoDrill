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

   Item_t* Buffer = ( Item_t*)malloc( 100000 * sizeof(Item_t) );
   Item_t temp = {};
   scanf( "%d %d %d", &startAddr, &N, &K );
   

   for ( i = 0; i < N; i++ )
   {
      scanf( "%d %d %d", &Buffer[i].addr, &Buffer[i].data, &Buffer[i].next );
   }

   printf( "brutal force build\n" );
   int targetAddr;
   targetAddr = startAddr;
   for ( i = 0; i < N-1; i++ )
   {
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

   for ( i = 0; i < N; i++ )
   {
      if ( Buffer[i].next == -1 )
      {
         printf( "%05d %d %d\n", Buffer[i].addr, Buffer[i].data, Buffer[i].next );
      }
      else
      {
         printf( "%05d %d %05d\n", Buffer[i].addr, Buffer[i].data, Buffer[i].next );
      }
   }

   return 0;
}

