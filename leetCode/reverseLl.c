#include <stdio.h>
#include <stdlib.h>


struct ListNode
{
   int val;
   struct ListNode *next;
};

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
      newNode->next = 0;
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
      




