#include <stdio.h>
#include <stdlib.h>


typedef struct
{
   int top;
   int size;
   int* array;
}Stack_t;

int push( Stack_t* pStack, int data )
{
   if ( ( pStack->top + 1 ) > pStack->size - 1 )
   {
      return 0;
   }
   else
   {
      pStack->top++;
      pStack->array[pStack->top] = data;
      //printf( "%d < %d\n", pStack->top, pStack->size );
      //printf( "top is:%d\n", pStack->top );
      return 1;
   }
}

int pop( Stack_t* pStack, int* pData )
{
   if (  pStack->top < 0  )
   {
      return 0;
   }
   else
   {
      *pData = pStack->array[pStack->top];
      pStack->top--;
      return 1;
   }
}


int main()
{
   int* buffer;
   int* result;
   Stack_t Stack;
   int i, j, M, N, K;
   int data;
   int popedData;
   int inputMark, top, buttom;

   buffer = ( int*)malloc( 1000 * sizeof( int ) );
   result = ( int*)malloc( 1000 * sizeof( int ) );
   scanf( "%d %d %d", &M, &N, &K );

   Stack.top = -1;
   Stack.size = M;
   Stack.array = buffer;

   for( i = 0; i < K; i++ )
   {
      inputMark = 0;
      result[i] = 1;
      Stack.top = -1;
      for ( j = 0; j < N; j++ )
      {
         data = 0;
         popedData = 0;
         scanf( "%d", &data );
         //printf( "j is %d\n", j );
         while( data > inputMark )
         {
            inputMark++;
            if ( !push( &Stack, inputMark ) )
            {
               //printf( "push fail:%d\n", inputMark );
               result[i] = 0;
               break;
            }
            //printf( "push:%d\n", inputMark );
            //printf( "top is:%d\n", Stack.array[Stack.top] );
         }
         if ( result[i] )
         {
            if ( pop( &Stack, &popedData ) )
            {
               if ( popedData != data )
               {
                  result[i] = 0;
                  //break;
               }
               //printf( "pop:%d\n", popedData );
            }
            else
            {
               result[i] = 0;
               break;
            }
         }
      }
      //printf( "data is %d\n", data );
      //printf( "%d checked\n", i );
   }

   for ( i = 0; i < K-1; i++ )
   {
      if( result[i] )
      {
         printf( "YES\n" );
      }
      else
      {
         printf( "NO\n" );
      }
   }

   if( result[i] )
   {
      printf( "YES" );
   }
   else
   {
      printf( "NO" );
   }

   return 0;
}

