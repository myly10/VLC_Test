const int signalPin=2, clockPin=3;
int bit=0;
const String s="Visible light communication (VLC) is a data communications medium which uses visible light between 400 and 800 THz (780-375 nm). \nVLC is a subset of optical wireless communications technologies.\n";
int p=0;
char ch;
const int waitTime=5;

void setup(){
	//	Serial.begin(115200);
	pinMode(signalPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	ch=s[p];
}

void loop(){
	digitalWrite(signalPin, (1&(ch>>(bit++)))==1?HIGH:LOW);
	digitalWrite(clockPin, HIGH);
	delay(waitTime);

	digitalWrite(signalPin, (1&(ch>>(bit++)))==1?HIGH:LOW);
	digitalWrite(clockPin, LOW);
	delay(waitTime);

	if (bit==8){
		if (s.length()==p){
			digitalWrite(signalPin, LOW);
			while (1){}
		}
		ch=s[++p];
		bit=0;
	}
}
