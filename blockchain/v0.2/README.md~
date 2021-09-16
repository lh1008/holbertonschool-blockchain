# 0x01. Blockchain - Data structures

### Learning Objectives

- How a Blockchain is structured
- How Blocks refer to each other
- How immutability is maintained in a Blockchain
- What is the Genesis Block, and why is it important
- How to hash a Block, and what information is stored in the hash

### Tasks

_**0. Create Blockchain**_
Write a function that creates a `Blockchain` structure, and initializes it.
- Prototype: `blockchain_t *blockchain_create(void);`

_**1. Create Block**_
Write a function that creates a `Block` structure and initializes it.
- Prototype: `block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len);`

_**2. Delete Block**_
Write a function that deletes an existing Block
- Prototype: `void block_destroy(block_t *block);`

_**3. Delete Blockchain**_
Write a function that deletes an existing Blockchain, along with all the Blocks it contains
- Prototype: `void blockchain_destroy(blockchain_t *blockchain);`

_**4. Hash Block**_
Write a function that computes the hash of a Block
- Prototype: `uint8_t *block_hash(block_t const *block, uint8_t hash_buf[SHA256_DIGEST_LENGTH]);`

_**5. Save Blockchain**_
Write a function that serializes a Blockchain into a file
- Prototype: `int blockchain_serialize(blockchain_t const *blockchain, char const *path);`

_**6. Load Blockchain**_
Write a function that deserializes a Blockchain from a file
- Prototype: `blockchain_t *blockchain_deserialize(char const *path);`

_**7. Block validity**_
Write a function that verifies that a Block is valid
- Prototype: `int block_is_valid(block_t const *block, block_t const *prev_block);`
