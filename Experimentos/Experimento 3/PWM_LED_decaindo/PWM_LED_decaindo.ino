#define LED 13// definindo o led do pino 13
#define sobe 11
#define desce 22

void setup() {
  pinMode(LED, OUTPUT);// definindo se entrada ou saída

}

int cont;
int flag = sobe;
int tempo_alto;
int tempo_baixo;

void loop() {

  digitalWrite(LED, HIGH);// Liga o LED
  delay(tempo_alto);// delay de 0 mls
  digitalWrite(LED, LOW);// desliga o LED
  delay(tempo_baixo);//  delay de 1 mls
  cont++;
  if (cont >= 3){
    cont = 0;
    if(flag == sobe){
      tempo_alto = tempo_alto + 1;
      tempo_baixo = 10 - tempo_alto;
      if(tempo_alto >= 10)
        flag = desce;
    }else{
      tempo_alto = tempo_alto - 1;
      tempo_baixo = 10 - tempo_alto;
      if( tempo_alto <= 0){
        flag = sobe;
      }
    }
  }

}
