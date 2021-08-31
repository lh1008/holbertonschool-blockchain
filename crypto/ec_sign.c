#include "hblk_crypto.h"

/**
 * ec_sign - entry to function
 * Desc: ec_sign function that signs a given set of bytes,
 * using a given EC_KEY private key
 * @key: pointer that point to the EC_KEY structure
 * @msg: pointer that points to the msglen characters to be signed
 * @sig: pointer that holds the address at which to store the signature
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
		 size_t msglen, sig_t *sig)
{
}
