#include <Wire.h>
#include <Adafruit_MLX90614.h>



#define I2CSDA 14
#define I2CSCL 15


TwoWire I2CMLX = TwoWire(0);
Adafruit_MLX90614 termometroIR;


unsigned long delayTime;

void setup() {
  Serial.begin(115200);
  Serial.println("MLX90614 test");
  I2CMLX.begin(I2CSDA, I2CSCL);

  bool status;

  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  status = termometroIR.begin(0x5A, &I2CMLX);  
  if (!status) {
    Serial.println("Could not find a valid MLX90614 sensor, check wiring!");
    while (1);
  }

  Serial.println("-- Default Test --");
  delayTime = 1000;

  Serial.println();
}

void loop() 
{ 
  printValues();
  delay(delayTime);
}

  void printValues() 
  {
    float temperaturaAmbiente = termometroIR.readAmbientTempC();
    float temperaturaObjeto = termometroIR.readObjectTempC();
    Serial.print("Temperatura ambiente = ");
    Serial.print(termometroIR.readAmbientTempC());
    Serial.println(" *C");
    Serial.print("Temperatura objeto = ");
    Serial.print(termometroIR.readObjectTempC());
    Serial.println(" *C");

 
 
    // Mostrar información
   Serial.print("Temp. ambiente => ");
   Serial.print(temperaturaAmbiente);
   Serial.println("ºC");
 
   Serial.print("Temp. objeto => ");
   Serial.print(temperaturaObjeto);
   Serial.println("ºC");
   Serial.println();
 }
