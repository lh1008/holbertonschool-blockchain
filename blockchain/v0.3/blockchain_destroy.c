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
	if (blockchain == NULL)
	{
		return;
	}

	llist_destroy(blockchain->chain, 1, (void (*)(llist_node_t))block_destroy);
	llist_destroy(blockchain->unspent, 1, free);
	free(blockchain);
}
