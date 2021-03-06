#include <stdio.h>
#include <string.h>

int main()
{
   int i, l, t;
   char buf[20]={};
   char buf2[21]={};
   char dbuf[9]={0};
   char dbuf2[9]={0};
   scanf( "%s", buf );
   l = strlen( buf );
   char delta = '1' - 1;

   for ( i = 0; i< l; i++ )
   {
      dbuf[ buf[i]-'1']++;
   }

   for ( i = l-1; i >=0; i-- )
   {
      t = ( buf[i] - delta ) * 2;
      buf2[l-1-i] += t % 10;
      buf2[l-1-i] += delta;
      buf2[l-i] += t / 10;
   }

   if ( buf2[l] != 0 )
      buf2[l] += delta;

   for ( i = 0; i<=l; i++ )
   {
      dbuf2[ buf2[i]-'1']++;
   }

   for ( i = 0; i<9; i++ )
   {
      if ( dbuf[i] != dbuf2[i] )
      {
         break;
      }
   }

   if ( 9==i && buf2[l] == 0 )
   {
      printf( "Yes\n" );
   }
   else
   {
      printf( "No\n" );
   }

   if ( buf2[l] != 0 )
   {
      for ( i = 0; i <= l; i++ )
      {
         printf( "%c", buf2[l-i] );
      }
   }
   else
   {
      for ( i = 0; i < l; i++ )
      {
         printf( "%c", buf2[l-1-i] );
      }
   }

   return 0;
}

