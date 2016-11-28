void WriteAllRecordsIntoFile ()
{
    struct Record* PointerToLoopOverLL ;
    FILE* PointerToFile ;
    PointerToFile = fopen("PUT THE NAME OF THE FILE HERE","a"); // to append in the file ! 


    PointerToLoopOverLL = Head ;
    if (Head == NULL && Tile == NULL)
    {
        fprintf(PointerToFile,"%s","Your Phone Has No Records \n Start Adding Your Contact list \n Thank You");
    }
    else
    {
    while(PointerToLoopOverLL != NULL)
    {
        fprintf(PointerToFile,"%s","Name:");
        fprintf(PointerToFile,"%s","\n");
        fprintf(PointerToFile,"%s",PointerToLoopOverLL ->C.Name);
        fprintf(PointerToFile,"%s","\n");

        fprintf(PointerToFile,"%s","Phone :");
        fprintf(PointerToFile,"%s","\n");
        fprintf(PointerToFile,"%s",PointerToLoopOverLL ->C.Phone);
        fprintf(PointerToFile,"%s","\n");

        fprintf(PointerToFile,"%s","Address :");
        fprintf(PointerToFile,"%s","\n");
        fprintf(PointerToFile,"%s",PointerToLoopOverLL ->C.Address);
        fprintf(PointerToFile,"%s","\n");

        PointerToLoopOverLL = PointerToLoopOverLL -> Next;
    }
    }
    fclose(PointerToFile);
}

void ReadAllRecordsFromFile (char FileName[])
{
    FILE* PointerToFile;
    char Data[256];
    struct Record* TempPointer ;
    struct Record* PointerToRead  ;

    TempPointer = Head ; // which is ACTULLAY NULL !

    PointerToFile = fopen(FileName, "r");

    while(fgets(Data, sizeof(Data), PointerToFile))
    {

        PointerToRead = (struct Record*) malloc(sizeof(struct Record));
        sscanf(Data ,"%s %s %s %s",
               PointerToRead -> C.FirstName = (char*) malloc( sizeof(char) * 50),
               PointerToRead -> C.SecondName = (char*) malloc( sizeof(char) * 50),
               PointerToRead -> C.Address = (char*) malloc( sizeof(char) * 50),
               PointerToRead -> C.Phone  = (char*) malloc( sizeof(char) * 50));

         PointerToRead -> C.Name = (char*) malloc(sizeof(char) * 100);
         strcpy(PointerToRead -> C.Name , PointerToRead -> C.FirstName);
         strcat(PointerToRead -> C.Name , " ");
         strcat(PointerToRead -> C.Name , PointerToRead -> C.SecondName);

        PointerToRead -> Next = NULL ; //On The Air Node !
        PointerToRead -> Prev = NULL ; //On The Air Node !

        if(Head == NULL)
        {
            TempPointer = Head = PointerToRead;
        }
        else
        {
            PointerToRead -> Prev = TempPointer ;
            TempPointer = TempPointer -> Next = PointerToRead;
        }
    }
    fclose(PointerToFile);
}