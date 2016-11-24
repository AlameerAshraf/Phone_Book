void Userinput(char name[])
{
    int i = 0, flag = 1;
    int ch;

    while(flag)
    {
		ch = getch();
		if(ch == 0)
		{
		 ch = getch();
		}
		else if(ch == '8')
		{
            printf("\b");
			printf(" ");
			printf("\b");
			i--;
		}
		else if(isprint(ch))
		{
			name[i] = ch;
			printf("%c",name[i]);
			i++;
		}
		else if(ch == 13)
		{
			flag = 0;
		}
    }
    name[i] = 0;
}
