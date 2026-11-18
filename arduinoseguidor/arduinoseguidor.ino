#define SENSOR_ESQ 4
#define SENSOR_DIR 7

#define ENA 3
#define IN1 6 //frente
#define IN2 8 //tras

#define ENB 11
#define IN3 9 //frente
#define IN4 10 //tras

// Aumentado de 50 para 140 para dar força suficiente aos motores
#define VELOCIDADE 100

void setup() {
  pinMode(SENSOR_ESQ, INPUT);
  pinMode(SENSOR_DIR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, VELOCIDADE);
  analogWrite(ENB, VELOCIDADE);
}

void esquerda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, VELOCIDADE);
}

void direita() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, VELOCIDADE);
  analogWrite(ENB, 0);
}

void loop() {
  int esq = digitalRead(SENSOR_ESQ);
  int dir = digitalRead(SENSOR_DIR);

  // Ajustado para pista BRANCA (LOW) e linha PRETA (HIGH)
  if (esq == LOW && dir == LOW) {
    frente();
  }
  else if (esq == HIGH && dir == LOW) {
    esquerda();
  }
  else if (esq == LOW && dir == HIGH) {
    direita();
  }
  else {
    frente();
  }
}