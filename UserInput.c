void UseerInput(char Value[])
{
    int i = 0, DetectingFlag = 1;
    int ch;

    while(flag)
    {
		ch = getchar();
        //Extended Key entered !
		if(ch == 0)
		{
		 ch = getchar();
		}
        //Backspace entered !! 
		else if(ch == '8')
		{
            printf("\b \b");
			i--;
		}
		else if(isprint(ch))
		{
			Value[i++] = ch;
		}
		else if(ch == 13)
		{
			DetectingFlag = 0;
		}
    }
    Value[i] = 0;
}