#include <stdio.h>
int main()
{
   int i, d, K;
   int l, r;
   int flag_next_is_left = 1;
   int this_sum = 0, max_sum = 0, first_num = 0;
   int allNeg = 1;
   int l_candidate = 0;

   scanf( "%d", &K );

   for( i = 0; i < K; i++ )
   {
      scanf( "%d", &d );
      if ( 0 == i )
      {
         first_num = d;
         l_candidate = d;
      }

      if ( d >=0 )
      {
         allNeg = 0;
      }

      this_sum += d;

      if ( this_sum < 0 )
      {
         this_sum = 0;
         flag_next_is_left = 1;
         //l_candidate = 0;
      }

      else
      {
         if ( flag_next_is_left )
         {
            l_candidate = d;
            flag_next_is_left = 0;
         }
         if ( this_sum == max_sum )
         {
            r = d;
            l = l_candidate;
            max_sum = this_sum;
         }
      }
   }

   if ( allNeg )
   {
      max_sum = 0;
      l = first_num;
      r = d;
   }


   {
      printf( "%d %d %d", max_sum, l, r );
      //printf( "0 0 0" ); */
   }
   return 0;
}
