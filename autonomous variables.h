const int COLOR_COUNT = 15;//the amount of colors we have
int speed = 50;//default motor speed
int fullspeed = 100;//motor speed variables



int sFRS = 90;//servo values
int sBRS = 109;
int sFLS = 132;
int sBLS = 131;

int straight_FRS = 161;
int straight_BRS = 154;
int straight_FLS = 132;
int straight_BLS = 131;



//  mandible servo positions
//
int openwideR = 0;
int openwideL = 255;
int shutR = 220;
int shutL = 0;
int outL=100;
int outR=100;
//  mouth
int mouthup=60;
int mouthdown=214;
//
int elevatorposition=0;
int uppositionscore=62;
int downpositionscore= 5;
// gate
int gateup = 5;
int gatedrive = 90;
int gatedown = 202;
//
int lockup = 0;
int lockdown = 85;
//
int scoreopen = 5;
int scoreclose = 245;

int FRS =0;
int BRS = 0;
int FLS  = 0;
int BLS = 0;

int lastservopos = 0;   // 1 = straight, 2 = spin , 3 = turn 45 deg to right, 4 = turn 45degrees to left, 5 = turn wheels to side
int lastelevator =30;// 30=30cm, 60=60cm, 90=90cm, 120=120cm
//elevator starts at 30cm position

int centerpos=0;



unsigned long thediff=0;//the difference between two values given to the function "difference"
//int colorTags[][] = {
//	{254, 257, 138},//red
//	{387, 390, 262},//light orange
//	{331, 332, 170},//dark orange
//	{346, 347, 298},//tan
//	{217, 217, 172},//brown
//	{390, 392, 345},//light yellow
//	{374, 377, 311},//dark yellow
//	{306, 310, 348},//light green
//	{147, 158, 181},//dark green
//	{194, 193, 265},//light blue
//	{157, 161, 162},//dark blue
//	{251, 248, 165},//purple
//	{393, 396, 377},//white
//	{375, 375, 177},//pink
//	{79, 78, 80}//black
//};

int colorTags[][] = {
	{254, 257, 138},//red
	{387, 390, 262},//light orange
	{331, 332, 170},//dark orange
	{346, 347, 298},//tan
	{217, 217, 172},//brown
	{390, 392, 345},//light yellow
	{374, 377, 311},//dark yellow
	{306, 310, 348},//light green
	{147, 158, 181},//dark green
	{194, 193, 265},//light blue
	{157, 161, 162},//dark blue
	{251, 248, 165},//purple
	{393, 396, 377},//white
	{375, 375, 177},//pink
	{14417950, 9830434, 3932192}//black
};


string colornames[15]={//declaration of all the names
	"Red",
	"Light Orange",
	"Dark Orange",
	"Tan",
	"Brown",
	"Light Yellow",
	"Dark Yellow",
	"Light Green",
	"Dark Green",
	"Light blue",
	"Dark blue",
	"Purple",
	"White",
	"Pink",
	"Black",
};

int eopd1threshold=16;
int eopd2threshold=16;


int selectprgm=0;
