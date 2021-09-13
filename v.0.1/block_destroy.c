#include "blockchain.h"

/**
* block_destroy - entry to function
* Desc: block_destroy function that deletes an existing block
* @block: representative structure of a block
* Return: Nothing
*/
void block_destroy(block_t *block)
{
	free(block);
}
