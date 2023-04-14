# Challenge-Edge-Computing-and-Computer-Systems

<h3>Sprint 01: Edge Computing and Computer Systems</h3>


<h4>Integrantes:</h4> 

<li>Alessandra Vaiano RM551497</li>  

<li>André Lambert RM99148</li>  

<li>Bryan Willian RM551305</li>

<li>Lucas Feijó RM99727</li>
  
<li>Vitor Maia RM99658</li>



<h4>Draft da proposta:</h4>
 
https://www.youtube.com/watch?v=d72xRmKAdww


<h4>Simulação do Protótipo (Tinkercad):</h4>

https://www.tinkercad.com/things/bnNWUCK3XDr?sharecode=RKNPcVpfmdr_fqo3pimyXLLVpdfGuBrhFevFMGrraS4
<br>
<br><b>Materiais utilizados:</b>
<li>1 Arduino Uno R3</li>
<li>1 Potenciometro</li>
<li>1 LCD 16 x 2 (I2C)</li>
<li>1 Protoboard</li>
<li>Jumper Cables</li>

<br><b>Imagem:</b>

![Sprint 01 Edge](https://user-images.githubusercontent.com/126624520/231861426-89486fac-a32b-4350-891b-14520e010c81.png)

<b>Arquivo:</b> codigo_Tinkercad.ino //código com comentários
<br>
<br><b>Código:</b>
<br>
<br>#include <Wire.h>
<br>#include <LiquidCrystal_I2C.h>
<br>
<br>LiquidCrystal_I2C lcd(0x20, 16, 2); 
<br>//endereço do display I2C é 0x20
<br>//e as dimensões são 16x2
<br>
<br>int valor_pot = 0; //armazena o valor do potenciometro
<br>int valor_anterior = -1; //armazena o último valor lido do potenciometro
<br>
<br>//iniciamos o display e seu backlight / luz de fundo
<br>void setup() {
<br>  lcd.init();
<br>  lcd.backlight();
<br>}
<br>
<br>//aqui estamos fazendo o display atualizar apenas quando o valor do potenciometro mudar
<br>//e também imprimir o que queremos junto ao valor, como "peso" e "g"
<br>//também definimos o limite da leitura (valor 1000)
<br>
<br>void loop() {
<br>  valor_pot = analogRead(A0);
<br>  if (valor_pot != valor_anterior) {
<br>    lcd.clear();
<br>    lcd.setCursor(0, 0); //aqui é a posição dentro do display lcd
<br>    lcd.print("Peso: ");
<br>    lcd.print(min(valor_pot, 1000));
<br>    lcd.print("g");
<br>    valor_anterior = valor_pot;
<br>  }
<br>}
