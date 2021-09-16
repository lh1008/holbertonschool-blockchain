#include "blockchain.h"

/**
 * blockchain_destroy - entry to function
 * Desc: blockchain_destroy function that deletes an
 * existing Blockchain, along with all the blocks
 * @blockchain: reprensentative structure of a blockchain
 * Return: Nothing
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	block_t *node = NULL;

	for (node = llist_pop(blockchain->chain); node != NULL;
			node = llist_pop(blockchain->chain))
		block_destroy(node);
	llist_destroy(blockchain->chain, 0, NULL);
	free(blockchain);
}
