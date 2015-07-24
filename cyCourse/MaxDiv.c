#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>


static int maxLeftPos = 0;

static int maxRightPos = 0;

int* inputArray;


int getData( int Pos )

{

   return inputArray[Pos];

}


void CompareReplace( int* pMax, int* pLmax, int* pRmax,

      int  lMax, int lL,     int lR )

{

   if ( *pMax < lMax  || ( *pMax == lMax && *pLmax > lL ) )

   {

      *pMax = lMax;

      *pLmax = lL;

      *pRmax = lR;

   }

}


int FindMaxOfLRM( int left, int right, int* pLmax, int* pRmax )

{

   int this_sum = 0;

   int max_sum = 0;

   int lsum = 0;

   int rsum = 0;

   int mid = 0;

   int lL;

   int lR;

   if ( left == right - 1 )

   {

      lsum = getData( left );

      max_sum = lsum;

      *pLmax = left;

      *pRmax = left;

      rsum = getData( right );

      CompareReplace( &max_sum, pLmax, pRmax, rsum, right, right );

      rsum += lsum;

      CompareReplace( &max_sum, pLmax, pRmax, rsum, left, right );    

      return max_sum;

   }

   else if ( left == right )

   {

      lsum = getData( left );

      max_sum = lsum;

      *pLmax = left;

      *pRmax = left;

      return max_sum;

   }

   else

   {

      mid = ( left + right ) / 2;

      this_sum = FindMaxOfLRM( left, mid-1, &lL, &lR );

      max_sum = this_sum;

      *pLmax = lL;

      *pRmax = lR;

      this_sum = FindMaxOfLRM( mid+1, right, &lL, &lR );

      CompareReplace( &max_sum, pLmax, pRmax, this_sum, lL, lR );

      int curP = mid;

      int lP = curP;

      int rP = curP;

      this_sum = getData( curP );

      int localMaxSum = this_sum;

      for ( curP = mid - 1; curP >= left; curP-- )

      {

         this_sum += getData( curP );

         if ( localMaxSum <= this_sum )

         {

            localMaxSum = this_sum;

            lP = curP;

         }

      }

      this_sum = localMaxSum;

      for ( curP = mid + 1; curP <= right; curP++ )

      {

         this_sum += getData( curP );

         if ( localMaxSum < this_sum )

         {

            localMaxSum = this_sum;

            rP = curP;

         }

      }

      CompareReplace( &max_sum, pLmax, pRmax, localMaxSum, lP, rP );

   }

   return max_sum;

}


int main()

{

   int K;

   int* pBuf;

   int i;

   uint8_t allNeg = 1;

   scanf( "%d\n", &K );

   pBuf = ( int*)malloc(sizeof(int)*K);

   inputArray = pBuf;

   for( i = 0; i <K; i++ )

   {

      scanf("%d", &pBuf[i]);

      if ( pBuf[i] >= 0 )

      {

         allNeg = 0;

      }

   }

   int max;

   if ( allNeg )

   {

      max = 0;

      maxLeftPos = 0;

      maxRightPos = K-1;

   }

   else

   {

      max = FindMaxOfLRM( 0, K-1, &maxLeftPos, &maxRightPos );

   }

   printf( "%d", max );

   printf( " %d", pBuf[maxLeftPos] );

   printf( " %d", pBuf[maxRightPos] );

   free( pBuf );

   return 0;

}
