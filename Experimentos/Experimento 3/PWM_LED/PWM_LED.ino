#define LED 13// definindo o led do pino 13

void setup() {
  pinMode(LED, OUTPUT);// definindo se entrada ou saída

}

void loop() {
  digitalWrite(LED, HIGH);// Liga o LED
  delay(300);// delay de 300 mls que é pedido na questão
  digitalWrite(LED, LOW);// desliga o LED
  delay(300);// delay de 300 mls que é pedido na questão

}
