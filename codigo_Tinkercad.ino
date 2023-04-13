//obs: talvez a simulação demore alguns segundos para começar, tinkercad é lento

//checkpoint sprint 01
//edge computing
//grupo: andré lambert, alessandra vaiano, bryan, lucas feijó e vitor maia

//************************************************************************

//aqui adicionamos as bibliotecas que vamos usar nesse projeto,
//precisamos fazer isso para o display funcionar

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2); 
//endereço do display I2C é 0x20
//e as dimensões são 16x2

int valor_pot = 0; //armazena o valor do potenciometro
int valor_anterior = -1; //armazena o último valor lido do potenciometro

//iniciamos o display e seu backlight / luz de fundo
void setup() {
  lcd.init();
  lcd.backlight();
}

//aqui estamos fazendo o display atualizar apenas quando o valor do potenciometro mudar
//e também imprimir o que queremos junto ao valor, como "peso" e "g"
//também definimos o limite da leitura (valor 1000)

void loop() {
  valor_pot = analogRead(A0);
  if (valor_pot != valor_anterior) {
    lcd.clear();
    lcd.setCursor(0, 0); //aqui é a posição dentro do display lcd
    lcd.print("Peso: ");
    lcd.print(min(valor_pot, 1000));
    lcd.print("g");
    valor_anterior = valor_pot;
  }
}

//fim