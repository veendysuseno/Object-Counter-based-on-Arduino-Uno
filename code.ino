#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const int pinSensor = 11;
const int pinReset = 12;
int hitung = 0;
int kondisi1 = 0;
int status1;

void setup() {
    pinMode(pinReset, INPUT_PULLUP);
    pinMode(pinSensor, INPUT);
    digitalWrite(pinReset, HIGH);
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ready");
    delay(2000);
    }

void loop() {
    hitung = constrain(hitung, 0, 1000);
    status1 = digitalRead(pinSensor);
    if (status1 == HIGH) {  // apabila ada benda yang lewat, counter bertambah
        hitung = hitung;
        kondisi1 = 0;
    }
    else if (status1 == LOW && kondisi1 == 0) {
        hitung += 1;
        kondisi1 = 1;
    }
    else if (status1 == LOW && kondisi1 == 1) {
        hitung = hitung;
        kondisi1 = 1;
    }
    if (digitalRead(pinReset) == LOW)  { //apabila tombol reset dipencet nilai = 0
        hitung = 0;
    }
    else  {
        hitung = hitung;
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Jumlah Barang : ");
    lcd.setCursor(0, 1);
    lcd.print(hitung);
    delay(300);
}
