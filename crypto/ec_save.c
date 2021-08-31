#include "hblk_crypto.h"

/**
 * ec_save - entry to function
 * Desc: ec_save function that saves an existing
 * EC key pair on the disk
 * @key: pointer EC_KEY pair to be saved on disk
 * @folder: pointer char string path to save the keys
 * Return: 1 on succes or 0 on failure
 */
int ec_save(EC_KEY *key, char const *folder)
{
	FILE *fp;
	char path[256] = {0};

	if (key == NULL || folder == NULL)
		return (0);

	/*Create a folder if not exist*/
	mkdir(folder, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	/*Create the complete path to store the private key*/
	sprintf(path, "%s/" PRIV_KEY, folder);
	/*Open a file descriptor to store the private key*/
	fp = fopen(path, "w");
	if (!fp)
		return (0);
	/*write the private key in the given file*/
	if (!PEM_write_ECPrivateKey(fp, key, NULL, NULL, 0, NULL, NULL))
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);
	/*Create the complete path to store the public key*/
	sprintf(path, "%s/" PUB_KEY, folder);
	/*Open a file descriptor to store the public key*/
	fp = fopen(path, "w");
	if (!fp)
		return (0);
	/*write the public key in the given file*/
	if (!PEM_write_EC_PUBKEY(fp, key))
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);

	return (1);
}
