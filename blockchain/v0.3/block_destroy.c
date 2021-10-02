#include "blockchain.h"

/**
* block_destroy - entry to function
* Desc: block_destroy function that deletes an existing block
* @block: representative structure of a block
* Return: Nothing
*/
void block_destroy(block_t *block)
{
	if (block == NULL)
	{
		return;
	}

	llist_destroy(block->transactions, 1, (node_dtor_t)transaction_destroy);
	free(block);
}
