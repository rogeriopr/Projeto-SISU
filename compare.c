int compare(tMatch *elem1, tMatch *elem2)
{
   if ( elem1->media < elem2->media)
      return 1;
      
   else if (elem1->media > elem2->media)
      return -1;

   else
      return 0;
}
