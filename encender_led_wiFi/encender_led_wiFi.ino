
#include <ESP8266WiFi.h>                   

char* ssid = "Familia_Martin";
char* pass = "8C61A3BE0B42";

WiFiServer server(80);                   
 
int PinLED = 13;                  
int estado = LOW;  

void setup() {
  Serial.begin(9600);
 
  pinMode(PinLED, OUTPUT);              
  digitalWrite(PinLED, LOW);            
 
  WiFi.begin(ssid, pass);           
  Serial.printf("\n\nConectando a la red: %s\n", WiFi.SSID().c_str());
   while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");                    
  }
  Serial.println("");
  Serial.println("WiFi conectada");       
 
  server.begin();    
  Serial.println("Servidor inicializado");
 
 Serial.printf("\n\nUtiliza esta URL para conectar: http://%s/\n", WiFi.localIP().toString().c_str());
} 
 
void loop() 
{

  WiFiClient client = server.available();  
  if (!client) {
    return;
  }
 

  Serial.println("nuevo cliente");
  while(!client.available()){
    delay(1);
  }
 

  String peticion = client.readStringUntil('\r');
  Serial.println(peticion);
  client.flush();
 

  if (peticion.indexOf('/LED=ON') != -1) 
  {estado = HIGH;} 
  if (peticion.indexOf('/LED=OFF') != -1)
  {estado = LOW;}
 
  digitalWrite(PinLED, estado);
 

  client.println("HTTP/1.1 200 OK");
  client.println("");                         
  client.println("");
  client.println("");
  client.println("");

  client.print("<html>");
  client.print("<h1 align=center>CONTROL LED ");
 
 if(estado == HIGH) 
 {client.print("<input type='image' src='https://i.imgur.com/uQxhFE5.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LED=OFF'>");}
 else 
 {client.print("<input type='image' src='https://i.imgur.com/00i0BdB.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LED=ON'>");}
 
 client.println("</html>");
 delay(1);
 Serial.println("Peticion finalizada"); // Se finaliza la petición al cliente. Se inicializa la espera de una nueva petición.
 Serial.println("");
 
}
