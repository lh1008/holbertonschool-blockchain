#include "hblk_crypto.h"

/**
 * ec_verify - entry to function
 * Desc: ec_verify function that verifies the signature
 * of a given set of bytes, using a given EC_KEY public key
 * @key: pointer to EC_KEY
 * @msg: pointer to msglen
 * @msglen: size_t type characters to verify the signature
 * @sig: pointer to the signature to be checked
 * Return: 1 if signature is valid, 0 otherwise
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg,
	      size_t msglen, sig_t const *sig)
{
	if (key == NULL || msg == NULL || sig == NULL)
		return (0);
	/*Verify the signature of a message*/
	return (ECDSA_verify(0, msg, msglen, sig->sig, sig->len,
				(EC_KEY *)key) == 1);
}
