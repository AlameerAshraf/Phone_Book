struct Contact FillDataOfContacts()
{  /* hint : don't forget to color up the questions to be visible and NOTICABLE ! */
    struct Contact C;
    printf("Please Inter The data of your Contact ! \n");

    printf("First Name ! \n");
    UserInput(C.FirstName = (char*) malloc( sizeof(char) * 50));

    printf("Second Name ! \n");
    UserInput(C.SecondName = (char*) malloc( sizeof(char) * 50));

    printf("Address ! \n");
    UserInput(C.Address = (char*) malloc( sizeof(char) * 50));

    printf("Phone Number ! \n");
    UserInput(C.Phone = (char*) malloc( sizeof(char) * 50));

    C.Name = (char*) malloc(sizeof(char) * 100);
    strcpy(C.Name , C.FirstName);
    strcat(C.Name , " ");
    strcat(C.Name , C.SecondName);

    return C;
}

/* User input to take input from user */
struct Record* CreateNode()
{
    struct Record* PointerToRecord ;
    /*you don't cast the result */
    /* HTTP://StackOverflow.com/questions/605845/do-i-cast-the-result-of-MALLOC/605858#605858 */
    PointerToRecord =  malloc(sizeof *PointerToRecord);
    if(PointerToRecord)
    {
       PointerToRecord -> C = FillDataOfContacts();
       PointerToRecord -> Next = NULL;
       PointerToRecord -> Prev = NULL;
    }
    return PointerToRecord  ;
}


int CreateSortedNode()
{
    struct Record* TempPointer = Head ;
    struct Record* PointerToNode ;
    int DetectionFlag = 0 ;

    PointerToNode = CreateNode() ;

   /* if(!PointerToNode)
        {
            /*allocation Error
            exit(1);
        }
        */
        DetectionFlag = 1;
        if(Head)
            {
                while(TempPointer && strcmp(TempPointer ->C.FirstName , PointerToNode ->C.FirstName) < 0) //s1<s2 ...!
                {
                    TempPointer = TempPointer -> Next ;
                }
                if ( TempPointer == NULL)
                {
                    PointerToNode -> Prev = Tile ;
                    Tile -> Next = PointerToNode ;
                    Tile = PointerToNode ;
                }
                else
                {
                    if (TempPointer == Head)
                    {
                        PointerToNode -> Next = Head ;
                        Head -> Prev = PointerToNode ;
                        Head = PointerToNode ;
                    }
                    else
                    {
                        PointerToNode -> Next = TempPointer ;
                        PointerToNode -> Prev = TempPointer -> Prev ;
                        TempPointer -> Prev -> Next = PointerToNode ;
                        TempPointer -> Prev = PointerToNode ;
                    }
                }
            }
            else
            {
                Head = Tile = PointerToNode ;
            }
            return DetectionFlag ;
}
