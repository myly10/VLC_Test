// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

const int signalPin=A6, clockPin=A7;
int bit=0;
char ch=0;
int signalValue;
const int trueV=970, falseV=960;

void setup(){
	// set prescale to 16
	sbi(ADCSRA, ADPS2);
	cbi(ADCSRA, ADPS1);
	cbi(ADCSRA, ADPS0);

	Serial.begin(115200);
	pinMode(clockPin, INPUT);
	pinMode(signalPin, INPUT);
	pinMode(13, OUTPUT);
}

void loop(){
	//clock high
	while (analogRead(clockPin)<trueV){
	}
	digitalWrite(13, HIGH);
	delay(1);
	signalValue=analogRead(signalPin);
	while (signalValue<=trueV&&signalValue>=falseV){
		signalValue=analogRead(signalPin);
	}
	if (signalValue>trueV) signalValue=1;
	else if (signalValue<falseV) signalValue=0;
	ch|=signalValue<<bit++;

	//clock low
	while (analogRead(clockPin)>falseV){}
	digitalWrite(13, LOW);
	delay(1);
	signalValue=analogRead(signalPin);
	while (signalValue<=trueV&&signalValue>=falseV){
		signalValue=analogRead(signalPin);
	}
	if (signalValue>trueV) signalValue=1;
	else if (signalValue<falseV) signalValue=0;
	ch|=signalValue<<bit++;

	if (bit==8){
		Serial.write(ch);
		bit=0;
		ch=0;
	}
}
