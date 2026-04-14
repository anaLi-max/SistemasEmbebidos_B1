const int PIN_BOTON = 2; 
const int PIN_LED   = 13; 
const unsigned long DEBOUNCE_MS = 20;   

int estado_led = LOW; 
int ultimo_estado = HIGH;    
unsigned long t_cambio = 0; 
int conteo = 0; 

void setup() { 
    pinMode(PIN_BOTON, INPUT_PULLUP);   
    pinMode(PIN_LED, OUTPUT); 
    Serial.begin(9600); 
    Serial.println("Lab 02 - Debounce activado"); 
} 

void loop() { 
    int lectura = digitalRead(PIN_BOTON); 

    if (lectura != ultimo_estado) { 
        t_cambio = millis(); 
    } 

    if ((millis() - t_cambio) > DEBOUNCE_MS) { 
        if (lectura == LOW && ultimo_estado == HIGH) { 
            conteo++; 
            estado_led = !estado_led;          
            digitalWrite(PIN_LED, estado_led); 

            Serial.print("Pulsacion #"); 
            Serial.print(conteo); 
            Serial.print("  LED: "); 
            Serial.println(estado_led ? "ON" : "OFF"); 
        } 
    } 

    ultimo_estado = lectura; 
}