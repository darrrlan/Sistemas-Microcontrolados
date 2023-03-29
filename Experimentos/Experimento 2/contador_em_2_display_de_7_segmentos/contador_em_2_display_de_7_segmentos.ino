  #define seg_a 2
   #define seg_b 3
   #define seg_c 4
   #define seg_d 5
   #define seg_e 6
   #define seg_f 7
   #define seg_g 8  
   #define disp_a 9
   #define disp_b 10
         
         
         
         
         
          //sgementos a b c d e f g
int displaysete[10][7] = {{1,1,1,1,1,1,0},//0
                          {0,1,1,0,0,0,0},// 1
                          {1,1,0,1,1,0,1},//2
                          {1,1,1,1,0,0,1},//3
                          {0,1,1,0,0,1,1},//4
                          {1,0,1,1,0,1,1},//5
                          {1,0,1,1,1,1,1},//6
                          {1,1,1,0,0,0,0},//7
                          {1,1,1,1,1,1,1},//8
                          {1,1,1,1,0,1,1}};//9


void display (void);// declaração da função
int estado_displaysete = 1;
int unidades = 0, dezenas = 0;// variáveis de display
signed long tempo_atual, tempo_anterior = 0;// variável para armazenar o tempo do millis

void setup() {
  pinMode(seg_a, OUTPUT);
  pinMode(seg_b, OUTPUT);
  pinMode(seg_c, OUTPUT);
  pinMode(seg_d, OUTPUT);
  pinMode(seg_e, OUTPUT);
  pinMode(seg_f, OUTPUT);
  pinMode(seg_g, OUTPUT);
  pinMode(disp_a, OUTPUT);
  pinMode(disp_b, OUTPUT);

}

void loop() {

  tempo_atual = millis();
  if((tempo_atual - tempo_anterior)>= 1000){
    tempo_anterior = tempo_atual;
     unidades++;
        if(unidades > 9 ){
          unidades = 0;
          dezenas++;
            if(dezenas > 9){
              dezenas = 0;
            }
        }
  }
    display();
    delay(1);
}

void display (void){

  switch(estado_displaysete){//maquina de estado, um pouco diferente do que aprendemos em FPGA
    case 1:
      digitalWrite(disp_b, HIGH);
      digitalWrite(seg_a,displaysete[dezenas][0]);
      digitalWrite(seg_b,displaysete[dezenas][1]);
      digitalWrite(seg_c,displaysete[dezenas][2]);
      digitalWrite(seg_d,displaysete[dezenas][3]);
      digitalWrite(seg_e,displaysete[dezenas][4]);
      digitalWrite(seg_f,displaysete[dezenas][5]);
      digitalWrite(seg_g,displaysete[dezenas][6]);
      digitalWrite(disp_a, LOW);
      estado_displaysete = 2;
      break;
    case 2:
      digitalWrite(disp_a, HIGH);
      digitalWrite(seg_a,displaysete[unidades][0]);
      digitalWrite(seg_b,displaysete[unidades][1]);
      digitalWrite(seg_c,displaysete[unidades][2]);
      digitalWrite(seg_d,displaysete[unidades][3]);
      digitalWrite(seg_e,displaysete[unidades][4]);
      digitalWrite(seg_f,displaysete[unidades][5]);
      digitalWrite(seg_g,displaysete[unidades][6]);
      digitalWrite(disp_b, LOW );
      estado_displaysete = 1;
      break;
  }
}
