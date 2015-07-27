#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode
{
   int val;
   struct ListNode *next;
};

#define USE_RECURSIVE
#ifndef USE_RECURSIVE
struct ListNode* reverseList( struct ListNode* head )
{
   if ( !head )
   {
      return NULL;
   }

   struct ListNode* cur = head;
   struct ListNode* next = NULL;
   struct ListNode* prev = NULL;

   while ( cur )
   {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
   }

   return prev;

}
#else
struct ListNode* recReverse( struct ListNode* head, struct ListNode** pTail )
{
   if ( !head )
   {
      return NULL;
   }
   else
   {
      struct ListNode* cur = recReverse( head->next, pTail );
      if ( !cur )
      {
         *pTail = head;
         return head;
      }
      else
      {
         head->next = NULL;
         (*pTail)->next = head;
         *pTail = head;
         return cur;
      }
      return head;
   }
}


struct ListNode* reverseList( struct ListNode* head )
{
   struct ListNode** pTail;
   pTail = &head;
   return recReverse( head, pTail );
}
      
#endif


int main( void )
{
   
   struct ListNode* head = malloc( sizeof( struct ListNode) ) ;
   head->val = 0;
   struct ListNode* cur = head;

   int i;
   for ( i = 1; i < 10; i++ )
   {
      struct ListNode* newNode = malloc( sizeof( struct ListNode ) );
      newNode->val = i;
      newNode->next = NULL;
      cur->next = newNode;
      cur = cur->next;
   }

   /*
   while( head )
   {
      printf( "%d->", head->val );
      head = head->next;
   }
   */

   head = reverseList( head );


   while( head )
   {
      printf( "%d->", head->val );
      head = head->next;
   }

   return 0;
}
      




