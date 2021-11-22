/* password.c - ECE594 Group 1 */

#include "password.h"

// Public domain AES encryption library.
// https://github.com/kokke/tiny-AES-c
#include "tiny-AES-c/aes.h"

#define KEY_LENGTH 16
#define HASH_LENGTH 16
#define LENGTH_REQUIREMENT 8

// AES encryption context.
struct AES_ctx ctx;
// Test data buffer. All password attempts will get a hash for this buffer,
// but only the true password will be able to get the true hash from this data.

byte true_buffer[HASH_LENGTH];

void init_password(void)
{
	byte i;
	for (i = 0; i < HASH_LENGTH; i++) {
		true_buffer[i] = 0x00;
	}
}

// Set a new password.
// Takes a char pointer to a byte array of characters which will be used as the new key,
// and the length of that byte array.
// Returns nothing.
void set_password(char *text, byte len)
{
	byte true_text[] = "Hello, Dr Z!\0\0\0";
	byte true_key[KEY_LENGTH];
	byte i;

	// Clear true_key buffer to remove any remnants of old data.
	for (i = 0; i < KEY_LENGTH; i++)
	{
		true_key[i] = 0x00;
	}

	// Copy the new password text bytes to create the challenge key buffer.
	for (i = 0; i < len; i++)
	{
		true_key[i] = text[i];
	}

	// Copy  bytes to true_buffer.
	for (i = 0; i < HASH_LENGTH; i++)
	{
		true_buffer[i] = true_text[i];
	}

	// Init crx with new password.
	// Encypt the true data to get a true hash which any other
	// hash as a result of encrypting with any other key can
	// be compared against.
	AES_init_ctx(&ctx, true_key);
	AES_ECB_encrypt(&ctx, true_buffer);
}

// Validate that a password meets requirements.
// A password meets requirements if it is at least the length requirement,
// has at least one letter and at least one number
bool validate_password(char *text, byte len)
{
	bool letter_requirement = FALSE;
	bool num_requirement = FALSE;
	byte i;

	// Check password text length. If it is less than the required number of characters, it is invalid.
	if (len < LENGTH_REQUIREMENT)
	{
		return FALSE;
	}

	for (i = 0; i < len; i++)
	{	
		// Check if the password text contains a letter. If it does not, it is invlaid.
		if (('A' <= text[i] && text[i] <= 'Z') || ('a' <= text[i] && text[i] <= 'z'))
		{
			letter_requirement = TRUE;
		}

		// Check if the password text contains a number. If it does not, it is invlaid.
		if ('0' <= text[i] && text[i] <= '9')
		{
			num_requirement = TRUE;
		}
	}

	return letter_requirement && num_requirement;
}

// Authenticate a password.
// Takes a char pointer to a byte array of characters which will be tested, and the length of that byte array.
// Returns TRUE if the password is authentic, FALSE if not.
bool authenticate_password(char* challenge_text, byte len)
{
	byte true_text[] = "Hello, Dr Z!\0\0\0";
	struct AES_ctx validation_ctx;
	byte challenge_key[KEY_LENGTH];
	byte challenge_buffer[HASH_LENGTH];
	byte i;

	// Clear challenge key buffer to remove any remnants of old data.
	for (i = 0; i < KEY_LENGTH; i++)
	{
		challenge_key[i] = 0x00;
		challenge_buffer[i] = 0x00;
	}

	// Copy the challenge text bytes to create the challenge key buffer.
	for (i = 0; i < len; i++)
	{
		challenge_key[i] = challenge_text[i];
	}

	// Copy true_text bytes to response_buffer.
	// If the challenge key == true key, response_buffer will
	// hold the same values as true_buffer.
	for (i = 0; i < HASH_LENGTH; i++)
	{
		challenge_buffer[i] = true_text[i];
	}

	AES_init_ctx(&validation_ctx, challenge_key);
	AES_ECB_encrypt(&validation_ctx, challenge_buffer);
	
	// Compare challenge_buffer against true_buffer.
	// If they are the same, then challenge_text is the original password text.
	for (i = 0; i < len; i++)
	{
		if (challenge_buffer[i] != true_buffer[i])
		{
			return FALSE;
		}
	}

	return TRUE;
}

// Check if the password has been set yet.
// If all bytes of true_buffer are null, the password has not yet been set.
bool is_password_set(void)
{
	byte counter = 0;
	byte i;

	for (i = 0; i < HASH_LENGTH; i++) 
	{
		if (true_buffer[i] == 0x00)
		{
			counter++;
		}
	}

	// If all bytes are not null, then the password has already been set.
	return counter != HASH_LENGTH;
}
