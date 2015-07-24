#include <stdio.h>

int main()
{
   int deck[54]={};
   int buff[54]={};
   int instr[54]={};
   int i, j;

   //S
   for( i = 0; i < 13; i++ )
      deck[i] = 0x10 + i + 1;
   //H
   for( i = 13; i< 26; i++ )
      deck[i] = 0x20 + i - 13 + 1;
   //C
   for( i = 26; i< 39; i++ )
      deck[i] = 0x40 + i - 26 + 1;
   //D
   for( i = 39; i< 52; i++ )
      deck[i] = 0x80 + i - 39 + 1;
   //J
   for( i = 52; i< 54; i++ )
      deck[i] = 0x00 + i - 52 + 1;


   int c;
   FILE* fp;
   scanf( "%d", &c );


   for ( i = 0; i < 54 ; i++ )
   {
      scanf( "%d", &instr[i] );
      instr[i]--;
   }


   for( i = 0 ; i < c; i++ )
   {
      for( j = 0; j< 54; j++ )
      {
         buff[ (instr[j]) ]= deck[j];
      }
      
      for ( j = 0; j< 54; j++ )
      {
         deck[j] = buff[j];
      }
   }

   for ( i = 0; i < 54; i++ )
   {
      switch ( deck[i] & 0xf0 )
      {
         case 0x10:
            printf( "S" );
            break;

         case 0x20:
            printf( "H" );
            break;

         case 0x40:
            printf( "C" );
            break;

         case 0x80:
            printf( "D" );
            break;

         case 0x00:
            printf( "J" );
            break;
      }

      printf( "%d", deck[i] & 0xF );
      if ( i != 53 )
      {
         printf( " " );
      }
   }

   return 0;
}


   
