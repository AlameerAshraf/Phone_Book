/* User input to take input from user */
void UserInput (char Value[])
{
   int i = 0 ;
   char c ;
   c=getchar();
   do
   {
       Value[i++]=c;
       c=getchar();   //i+1
   }
   while(c != '\n');

}