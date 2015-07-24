#include <stdio.h>
#include <stdlib.h>

int main()
{
   int k, m, i, j, t;
   scanf( "%d %d", &k, &m );
   int* buf = malloc(sizeof(int)*k);
   for ( i = 0; i<k; i++ )
   {
      scanf( "%d", &buf[i] );
   }

   if ( 1 == k )
   {
      printf( "%d", buf[0] );
   }
   else
   {
      if ( m )
      {
         for ( i = 0; i < m%k; i++ )
         {
            //printf( "mov %d ", i );
            //printf( "cyc %d ", k%m );
            for ( j = k - 1; j > 0; j-- )
            {
               t = buf[j];
               buf[j] = buf[j-1];
               buf[j-1]=t;
            }
         }
      }
      for ( i = 0; i<k-1; i++ )
      {
         printf( "%d ", buf[i] );
      }
      printf( "%d", buf[i] );
   }

   return 0;
}

