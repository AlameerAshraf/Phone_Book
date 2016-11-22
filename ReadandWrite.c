// Function Write all data form linked list in the file !!
// don't forget to change the file name and location !
void WriteAllRecordsIntoFile ()
{
    struct Record* PointerToLoopOverLL ;
    FILE* PointerToFile ;
    PointerToFile = fopen("C:\\Users\\apple\\Desktop\\fvdc\\RecordsLog.txt","a");
    if (!PointerToFile)
    {
        /* ERROR in OPENEING the file */
        exit(1);
    }

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

        PointerToLoopOverLL = PointerToLoopOverLL -> Next;
    }
    }
    fclose(PointerToFile);
}


// Function Read all data form File in the Linked List !!
// don't forget to change the file name and location !
// the file name will be passed as a PARAMTER from user

void ReadAllRecordsFromFile (char FileName[])
{
    FILE *PointerToFile;
    char Data[256];
    struct Record* TempPointer ;
    struct Record* PointerToRead  ;

    TempPointer = Head ; // which is ACTULLAY NULL !

    PointerToFile = fopen(FileName, "r");
    if (!PointerToFile)
    {
        /* ERROR in OPENEING the file */
        exit(1);
    }

    while(fgets(Data, sizeof(Data), PointerToFile))
    {

        PointerToRead = (struct Record*) malloc(sizeof(struct Record));
        sscanf(Data , "%s %s %s",PointerToRead -> C.Name , PointerToRead -> C.Address , PointerToRead -> C.Phone);

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
    free(PointerToRead);
}

