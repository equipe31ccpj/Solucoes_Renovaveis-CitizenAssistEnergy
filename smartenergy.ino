
#include <LiquidCrystal.h>

// Configuracao do LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// LEDs
const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;

// Potenciometro de consumo
const int sensorConsumo = A0;

void setup() {

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  lcd.begin(16, 2);

  lcd.print("Citizen Assist");
  lcd.setCursor(0, 1);
  lcd.print("Monitor Energia");

  delay(2000);
  lcd.clear();
}

void loop() {

  // Leitura do potenciometro
  int leitura = analogRead(sensorConsumo);

  // Conversao para porcentagem
  int consumo = map(leitura, 0, 1023, 0, 100);

  // Apaga todos os LEDs
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  // Exibe consumo no LCD
  lcd.setCursor(0, 0);
  lcd.print("Consumo: ");
  lcd.print(consumo);
  lcd.print("%   ");

  lcd.setCursor(0, 1);

  // Consumo baixo
  if (consumo <= 30) {

    digitalWrite(ledVerde, HIGH);
    lcd.print("Consumo baixo   ");

  }

  // Consumo moderado
  else if (consumo <= 70) {

    digitalWrite(ledAmarelo, HIGH);
    lcd.print("Atencao consumo ");

  }

  // Consumo elevado
  else {

    digitalWrite(ledVermelho, HIGH);
    lcd.print("Economize!      ");

  }

  delay(500);
}
