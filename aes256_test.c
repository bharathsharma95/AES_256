#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "TI_aes_128.h"


int main( void )
{
  //WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  
  unsigned char state[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 
                           0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 
			   0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
			   0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};


  unsigned char ciphertext[] = {0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30,
                                0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a};

  unsigned char key1[]   = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                           0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
			   0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                           0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

  unsigned char key2[]   = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                           0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
		           0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                           0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
  
  unsigned char *inpt = state;

printf("**********************    INPUT GIVEN    ***********************\n\n");
    for (int i = 0; i < 255; i++){
    	  printf(" state [%d] = %u ", i, state[i]);
      }


//**********************************************************************************

  		aes_enc_dec(state,key1,0);			// Encryption
		printf("\n\n\n");
		printf("**********************    ENCRYPTED OUT    ***********************\n\n");

		unsigned char *ciphet = state;

for (int j = 0; j < 255; j++){
    	  printf(" state [%d] = %u ", j, state[j]);
      }


// ***************************************************************************************


  		aes_enc_dec(state,key2,1);			// Decryption

printf("\n\n\n");
    printf("**********************    DECRYPTED OUT    ***********************\n\n");

  unsigned char *outpt = state;

for (int k = 0; k < 255; k++){
    	  printf(" state [%d] = %u ", k, state[k]);
      }

// **************************************************************************************

printf("\n\n");

  return 0;
}