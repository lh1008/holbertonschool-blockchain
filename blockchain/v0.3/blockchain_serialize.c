#include "blockchain.h"

/**
* blockchain_serialize - entry to function
* Desc: blockchain_serialize function that serializes
* a Blockchain into a file
* @blockchain: points to the Blockchain to be serialized
* @path: contains the path to a file to serialize the Blockchain into
* Return: 0 upon success, or -1 upon failure
*/
int blockchain_serialize(blockchain_t const *blockchain, char const *path)
{
	int fd, i, size;
	uint8_t endianness = _get_endianness();

	if (!blockchain || !blockchain->chain || !path)
		return (-1);
	size = llist_size(blockchain->chain);
	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);
	if (write(fd, HBLK_MAGIC, strlen(HBLK_MAGIC)) != strlen(HBLK_MAGIC))
		return (close(fd), -1);
	if (write(fd, HBLK_VERSION, strlen(HBLK_VERSION)) != strlen(HBLK_VERSION))
		return (close(fd), -1);
	if (write(fd, &endianness, 1) != 1)
		return (close(fd), -1);
	if (write(fd, &size, 4) != 4)
		return (close(fd), -1);
	for (i = 0; i < size; i++)
	{
		block_t *block = llist_get_node_at(blockchain->chain, i);

		if (!block)
			return (close(fd), -1);
		if (write(fd, &(block->info), sizeof(block->info)) != sizeof(block->info))
			return (close(fd), -1);
		if (write(fd, &(block->data.len), 4) != 4)
			return (close(fd), -1);
		if (write(fd, block->data.buffer, block->data.len) != block->data.len)
			return (close(fd), -1);
		if (write(fd, block->hash, SHA256_DIGEST_LENGTH) !=
			SHA256_DIGEST_LENGTH)
			return (close(fd), -1);
	}
	return (close(fd), 0);
}
