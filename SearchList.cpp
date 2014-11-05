/************************************************************************
 * AUTHOR			: James Davis
 ************************************************************************/
/*************************************************************************
 *
 * FUNCTION SearchList
 * _______________________________________________________________________
 * This function receives a pointer to the head of a list and a string
 *   data item to search for and then searches the list for a node
 *   containing that string.
 *
 * RETURNS: pointer to a node with the search item (NULL if not found)
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		All of the following parameters have to have values previously
 * 		 defined:
 * 		head       : pointer to the head of the list
 * 		searchItem : string item to be found
 *
 * POST-CONDITIONS
 * 		searchPtr : pointer to a node in the list containing the string
 * 				    (NULL if not found)
 ************************************************************************/
PersonNode *SearchList(PersonNode *head, string searchItem)
{
	// Variables
	PersonNode *searchPtr; // CALC & RET - pointer used to locate item

	// Initializations
	searchPtr = NULL;
	searchPtr = head;

	// Outputs a search message
	cout << "Searching for " << searchItem << "...\n";

	// Loops through the list from the front until either the data
	//  record is found or the list end
	while(searchPtr != NULL && searchPtr->name != searchItem)
	{
		searchPtr = searchPtr->next;
	}

	// Returns a pointer to the located node (or NULL if not found)
	return searchPtr;
}
