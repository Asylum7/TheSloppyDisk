/************************************************************************
 * AUTHOR			: James Davis
 ************************************************************************/
#include "header.h"
#include "Account.h"

Account *SearchAccounts(int accountNum,
						Account *head)
{
	Account *accPtr;
	bool found;

	accPtr = head;
	found = false;

	while(accPtr != NULL && !found)
	{
		if(accountNum == accPtr->GetAccountNumber())
		{
			found = true;
		}
		else
		{
			accPtr = accPtr->GetNext();
		}
	}

	return accPtr;
}
