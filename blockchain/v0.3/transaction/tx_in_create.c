#include "transaction.h"

/**
 * tx_in_create - entry to function
 * Desc: tx_in_create function that allocates and initializes a
 * transaction input structure
 * @unspent: points to the unpsent transaction output to be
 * converted to a transaction input
 * Return: pointer to the created transaction input or NULL
 */
tx_in_t *tx_in_create(unspent_tx_out_t const *unspent)
{
	tx_in_t *new_tx_in = NULL;

	if (unspent == NULL)
		return (NULL);

	new_tx_in = calloc(1, sizeof(tx_in_t));

	if (new_tx_in == NULL)
		return (NULL);

	memcpy(new_tx_in->block_hash, unspent->block_hash, sizeof(new_tx_in->block_hash));
	memcpy(new_tx_in->tx_id, unspent->tx_id, sizeof(new_tx_in->tx_id));
	memcpy(new_tx_in->tx_out_hash, unspent->out.hash, sizeof(new_tx_in->tx_out_hash));

	return (new_tx_in);
}
