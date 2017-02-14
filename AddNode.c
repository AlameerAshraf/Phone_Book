// add a new node in the linked list 
int AddNode() // alameer ashraf 
{
    struct Record* Pointer ;
    int AdditionFlag = 0 ; 
    if (Head == NULL && Tile == NULL) //Tile is the last node in the linked list ! 
    {
        Head = Tile = CreateNode(); // create node function to be called here ! 
        AdditionFlag = 1 ;  // set the flag to one !
    }
    else
    {
        Pointer = CreateNode();
        Tile -> Next = Pointer ;   // next of last node refering to the new node ! 
        Pointer -> Prev = Tile ;   // prevous of the new node refer to the last node (tile) !
        Pointer -> Next = NULL;    // next of the new will be null ! 
        Tile = Pointer ;           // the new node will be the tile ! 
    }

    return AdditionFlag ; 
}