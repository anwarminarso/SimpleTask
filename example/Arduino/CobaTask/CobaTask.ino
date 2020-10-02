#include "Task.h"


int led1 = 3;
int led2 = 5;
int button1 = 9;

bool flipflop1 = true;
bool flipflop2 = true;
bool isPressed = false;

void startTask() {
	if (digitalRead(button1) == LOW) {
		isPressed = true;
	}
	else {
		isPressed = false;
	}
}

void loop1Hz(uint32_t now) {
	Serial.print("INI LOOP 1HZ, Waktu: ");
	Serial.println(millis());

	if (!isPressed) { // jika button tidak ditekan
		if (flipflop1) {
			flipflop1 = false;
			digitalWrite(led1, HIGH);
		}
		else {
			flipflop1 = true;
			digitalWrite(led1, LOW);
		}
	}
	else { // button ditekan
		flipflop1 = true;
		digitalWrite(led1, LOW);
	}

}

void loop2Hz(uint32_t now) {
	Serial.print("INI LOOP 2HZ, Waktu: ");
	Serial.println(millis());

	if (!isPressed) { // jika button tidak ditekan
		if (flipflop2) {
			flipflop2 = false;
			digitalWrite(led2, HIGH);
		}
		else {
			flipflop2 = true;
			digitalWrite(led2, LOW);
		}
	}
	else {
		flipflop2 = true;
		digitalWrite(led2, LOW);
	}

}

void endTask() {

}

void setup()
{
	Serial.begin(57600);

	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(button1, INPUT_PULLUP);

	setInstanceTask(startTask);
	setEndTask(endTask);
	
	//parameter
	//1. Nama fungsi
	//2. ID dalam string (maksimal 6 karakter), dalam string
	//3. delay start awal
	//4. Delay dalam ms
	//   fungsi T = 1000/f
	//   jika 1Hz maka T = 1000/ 1 = 1000
	addTask(loop1Hz, "Loop1", 0, 1000);


	//parameter
	//1. Nama fungsi
	//2. ID dalam string (maksimal 6 karakter), dalam string
	//3. delay start awal
	//4. Delay dalam ms
	//   fungsi T = 1000/f
	//   jika 2Hz maka T = 1000/ 2 = 500
	addTask(loop2Hz, "Loop2", 0, 500);
}
