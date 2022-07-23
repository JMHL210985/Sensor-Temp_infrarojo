// * Sensor MLX90614    PinESP32CAM
// * Vin----------------5V
// * GND----------------GND
// * SDA----------------14
// * SCL----------------15


//Bibliotecas
#include <Wire.h>
#include <Adafruit_MLX90614.h>
 
// Instanciar objeto
Adafruit_MLX90614 termometroIR = Adafruit_MLX90614();
 
void setup() {
  // Iniciar comunicación serie
  Serial.begin(115200);
 Wire.begin (14,15);
  if (!termometroIR.begin(0x5A, &Wire)) 
  {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    return;
  };

  Serial.print("Emissivity = "); Serial.println(termometroIR.readEmissivity());
  Serial.println("================================================");
  // Iniciar termómetro infrarrojo con Arduino
 
}
 
void loop() {
  // Obtener temperaturas grados Celsius
  float temperaturaAmbiente = termometroIR.readAmbientTempC();
  float temperaturaObjeto = termometroIR.readObjectTempC();
 
  // Mostrar información
  Serial.print("Temp. ambiente => ");
  Serial.print(temperaturaAmbiente);
  Serial.println("ºC");
 
  Serial.print("Temp. objeto => ");
  Serial.print(temperaturaObjeto);
  Serial.println("ºC");
  
  delay(2000);
 
  // Si quieres mostrar la información en grados Fahrenheit utiliza las funciones
  // readAmbientTempF() para temperatura ambiente
  // readObjectTempF() para temperatura del objeto
 
}
