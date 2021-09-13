# 0x00. Blockchain - Crypto

### Learning Objectives

- How a Blockchain is considered “unbreakable”
- What is a hash algorithm
- What **SHA** stands for
- How hash algorithms apply to Blockchains
- What is asymmetric cryptography
- How asymmetric cryptography applies to cryptocurrencies
- What **ECC** stands for
- What **ECDSA** stands for
- What a digital signature is
- How digital signatures apply to cryptocurrencies

### Tasks

_**0. SHA256**_
Write a function that computes the hash of a sequence of bytes.
- Prototype: `uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]);`

_**1. EC_KEY creation**_
Write a function that creates a new EC key pair.
- Prototype: `EC_KEY *ec_create(void);`

_**2. EC_KEY to public key**_
Write a function that extracts the public key from an `EC_KEY` opaque structure.
- Prototype: `uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]);`

_**3. EC_KEY from public key**_
Write a function that creates an `EC_KEY` structure given a public key.
- Prototype: `EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN]);`

_**4. EC_KEY - Save to file**_
Write a function that saves an existing EC key pair on the disk.
- Prototype: `int ec_save(EC_KEY *key, char const *folder);`

_**5. EC_KEY - Load from file**_
Write a function that loads an EC key pair from the disk.
- Prototype: `EC_KEY *ec_load(char const *folder);`

_**6. Signature**_
Write a function that signs a given set of bytes, using a given EC_KEY **private key**.
- Prototype: `uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t *sig);`

_**7. Signature verification**_
Write a function that verifies the signature of a given set of bytes, using a given EC_KEY **public key**.
- Prototype: `int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t const *sig);`

_**8. Library**_
Write a Makefile that compiles all the previous functions and archives them into a static library for future use.

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
