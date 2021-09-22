# 0x03. Blockchain - Transactions

### Learning Objectives

- How to build a transaction
- What is a transaction input
- What is a transaction output
- Why to sign a transaction input
- How to compute the balance of given wallet
- What is a coinbase transaction and why it is used
- How to ensure immutability of a transaction
- What is the difference between the UTXO and the Account-based transaction models

### Tasks

_**0. Create transaction output**_
Write a function that allocates and initializes a transaction output structure
- Prototype: `tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN]);`, where:
  - `amount` is the amount of the transaction
  - `pub` is the public key of the transaction receiver

_**1. Create unspent transaction output**_
Write a function that allocates and initializes an unspent transaction output structure
- Prototype: `unspent_tx_out_t *unspent_tx_out_create(uint8_t block_hash[SHA256_DIGEST_LENGTH], uint8_t tx_id[SHA256_DIGEST_LENGTH], tx_out_t const *out);`, where:
  - `block_hash` contains the hash of the Block where the referenced transaction output is located
  - `tx_id` contains the hash of a transaction in the Block `block_hash`, where the referenced transaction output is located
  - `out` points to the referenced transaction output

_**2. Create transaction input**_
Write a function that allocates and initializes a transaction input structure
- Prototype: `tx_in_t *tx_in_create(unspent_tx_out_t const *unspent);`, where
  - `unspent` points to the unspent transaction output to be converted to a transaction input

_**3. Transaction ID**_
- Prototype: `uint8_t *transaction_hash(transaction_t const *transaction, uint8_t hash_buf[SHA256_DIGEST_LENGTH]);`, where:
  - `transaction` points to the transaction to compute the hash of
  - `hash_buf` is a buffer in which to store the computed hash

_**4. Sign transaction input**_
Write a function that signs a transaction input, given the transaction id it is from
- Prototype: `sig_t *tx_in_sign(tx_in_t *in, uint8_t const tx_id[SHA256_DIGEST_LENGTH], EC_KEY const *sender, llist_t *all_unspent);`, where:
  - `in` points to the transaction input structure to sign
  - `tx_id` contains the ID (hash) of the transaction the transaction input to sign is stored in
  - `sender` contains the private key of the receiver of the coins contained in the transaction output referenced by the transaction input
  - `all_unspent` is the list of all unspent transaction outputs to date

_**5. Create transaction**_
Write a function that creates a transaction
- Prototype: `transaction_t *transaction_create(EC_KEY const *sender, EC_KEY const *receiver, uint32_t amount, llist_t *all_unspent);`, where:
  - `sender` contains the private key of the transaction sender
  - `receiver` contains the public key of the transaction receiver
  - `amount` is the amount to send
  - `all_unspent` is the list of all the unspent outputs to date

_**6. Transaction validation**_
Write a function that checks whether a transaction is valid
- Prototype: `int transaction_is_valid(transaction_t const *transaction, llist_t *all_unspent);`, where:
  - `transaction` points to the transaction to verify
  - `all_unspent` is the list of all unspent transaction outputs to date

_** 7. Coinbase transaction**_
Write a function that creates a coinbase transaction
- Prototype: `transaction_t *coinbase_create(EC_KEY const *receiver, uint32_t block_index);`, where:
  - `receiver` contains the public key of the miner, who will receive the coinbase coins
  - `block_index` is the index of the Block the coinbase transaction will belong to

_**8. Coinbase transaction validation**_
Write a function that checks whether a coinbase transaction is valid
- Prototype: `int coinbase_is_valid(transaction_t const *coinbase, uint32_t block_index);`, where:
  - `coinbase` points to the coinbase transaction to verify
  - `block_index` is the index of the Block the coinbase transaction will belong to

_**9. Delete transaction**_
Write a function that deallocates a transaction structure
- Prototype: `void transaction_destroy(transaction_t *transaction);`, where:
  - `transaction` points to the transaction to delete

_**10. Update Blockchain and Block creation/deletion**_
- Update the function `block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len);`.
  - Your function must now initializes the Block’s transaction list to an empty linked list.
- Update the function `void block_destroy(block_t *block);`.
  - Your function must now destroy the Block’s transaction list.

_**11. Create/delete list of unspent**_
Update the functions `blockchain_create` and `blockchain_destroy` to respectively create and delete the linked list `unspent` of unspent transaction outputs.

_**12. Update: Hash Block**_
Update the function `block_hash` to include the list of transactions in a Block’s hash.
- Prototype: `uint8_t *block_hash(block_t const *block, uint8_t hash_buf[SHA256_DIGEST_LENGTH]);`, where
  - `block` points to the Block to be hashed

_**13. Update: Block validation**_
Update the function `block_is_valid` to check that each Block’s list of transaction is valid
- Prototype: `int block_is_valid(block_t const *block, block_t const *prev_block, llist_t *all_unspent);`, where:
  - `block`
  - `prev_block`
  - `all_unspent`

_**14. Update all unspent**_
Write a function that updates the list of all unspent transaction outputs, given a list of processed transactions
- Prototype: `llist_t *update_unspent(llist_t *transactions, uint8_t block_hash[SHA256_DIGEST_LENGTH], llist_t *all_unspent);`, where:
  - `transactions` is the list of validated transactions
  - `block_hash` Hash of the validated Block that contains the transaction list transactions
  - `all_unspent` is the current list of unspent transaction outputs

_**15. Update: Blockchain serialization & deserialization**_
Update the functions `blockchain_serialize` and `blockchain_deserialize`, to serialize each Block’s transactions list.

**blockchain_serialize**
- Prototype: `int blockchain_serialize(blockchain_t const *blockchain, char const *path);`, where:
  - `blockchain` points to the Blockchain to be serialized,
  - `path` contains the path to a file to serialize the Blockchain into

**blockchain_deserialize**
- Prototype: `blockchain_t *blockchain_deserialize(char const *path);`, where:
  - `path` contains the path to a file to deserialize the Blockchain from

_**16. Blockchain library**_
Write a Makefile that compiles all the previous functions and archives them into a static library for future use.
