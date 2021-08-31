#include "hblk_crypto.h"

/**
 * ec_sign - entry to function
 * Desc: ec_sign function that signs a given set of bytes,
 * using a given EC_KEY private key
 * @key: pointer that point to the EC_KEY structure
 * @msg: pointer to msglen
 * @msglen: size_t type characters to be signed
 * @sig: pointer that holds the address at which to store the signature
 * Return: pointer to the signature buffer upon success, NULL upon failure
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
		 size_t msglen, sig_t *sig)
{
	unsigned int len;

	if (key == NULL || msg == NULL || sig == NULL)
		return (NULL);

	len = sig->len;
	/*Sign the message*/
	if (ECDSA_sign(0, msg, msglen, sig->sig, &len, (EC_KEY *)key) != 1)
		return (NULL);
	sig->len = len;

	return (sig->sig);
}
