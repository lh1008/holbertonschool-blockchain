# 0x02. Blockchain - Block mining

### Learning Objectives

- What is the purpose of the Block difficulty
- What is the Proof of Work
- How to check that a given hash matches a given difficulty
- How to mine a Block
- Why Block mining is brute force only
- How to automatically adjust the difficulty

### Tasks

_**0. Proof of work**_
Write a function that checks whether a given hash matches a given difficulty
- Prototype: int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH], uint32_t difficulty);

_**1. Block is valid v0.2**_
Modify the function `int block_is_valid(block_t const *block, block_t const *prev_block);` so that it checks that a Block’s hash matches its difficulty

_**2. Block mining**_
Write a function that mines a Block in order to insert it in the Blockchain
- Prototype: `void block_mine(block_t *block);`

_**3. Adjust difficulty**_
Write a function that computes the difficulty to assign to a potential next Block in the Blockchain.
- Prototype: `uint32_t blockchain_difficulty(blockchain_t const *blockchain);`
