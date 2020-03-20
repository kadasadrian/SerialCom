

//  CONSTANTS
#define		SIZE_OF_BUFFER		    255	// Maximum size of buffer

typedef struct circularBuff
{
    char circularBuffer[SIZE_OF_BUFFER];	// Empty circular buffer
	int	readIndex;	// Index of the read pointer
	int	writeIndex;	// Index of the write pointer
	int	bufferLength;	// Number of values in circular buffer
    int loopStatus;  // Loop condition variable
}_circularBuff;

//  PROTOTYPES
void pushChar(char *pChar);
char  popChar(void);
