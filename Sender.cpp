const int signalPin=2, clockPin=3;
int bit=0;
const String s="Visible light communication (VLC) is a data communications medium which uses visible light between 400 and 800 THz (780-375 nm). VLC is a subset of optical wireless communications technologies.\n\nThe technology uses fluorescent lamps (ordinary lamps, not special communications devices) to transmit signals at 10 kbit/s, or LEDs for up to 500 Mbit/s. Low rate data transmissions at 1 and 2 kilometres (0.6 and 1.2 mi) were demonstrated. RONJA achieves full Ethernet speed (10 Mbit/s) over the same distance thanks to larger optics and more powerful LEDs.\n\n";
int p=0;
char ch;
const int waitTime=3;

void setup(){
	// Serial.begin(115200);
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
