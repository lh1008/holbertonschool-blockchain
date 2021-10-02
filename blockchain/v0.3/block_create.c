#include "blockchain.h"

/**
* block_create - entry to function
* Desc: block_create function that creates a new block for the blockchain
* @prev: previous block in the blockchain
* @data: data to be duplicate
* @data_len: lenght data to be duplicate
* Return: a new block of the blockchain
*/
block_t *block_create(block_t const *prev, int8_t const *data,
	uint32_t data_len)
{
	block_t *block = NULL;
	llist_t *transactions = NULL;

	block = calloc(1, sizeof(*block));
	transactions = llist_create(MT_SUPPORT_FALSE);
	if (block == NULL || transactions == NULL)
	{
		free(block);
		llist_destroy(transactions, 0, NULL);
		return (NULL);
	}
	memcpy(&(block->data.buffer), data, MIN(data_len, BLOCKCHAIN_DATA_MAX));
	block->data.len = MIN(data_len, BLOCKCHAIN_DATA_MAX);
	block->info.index = prev->info.index + 1;
	block->info.timestamp = time(NULL);
	block->transactions = transactions;
	memcpy(&(block->info.prev_hash), prev->hash, SHA256_DIGEST_LENGTH);

	return (block);
}
