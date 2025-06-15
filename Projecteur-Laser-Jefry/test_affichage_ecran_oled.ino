#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDRESS 0x3C  // Adresse I2C de l'écran (souvent 0x3C)

// Définition des broches I2C pour l'ESP32 DevKit V1
#define SDA_PIN 21
#define SCL_PIN 22

// Création d'un objet Wire personnalisé si nécessaire
TwoWire I2COLED = TwoWire(0);

// Initialisation de l'écran OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &I2COLED);

void setup() {
  Serial.begin(115200);

  // Initialisation du bus I2C avec les broches définies
  I2COLED.begin(SDA_PIN, SCL_PIN);

  // Initialisation de l'écran OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println(F("Échec de l'initialisation de l'écran OLED"));
    while (true); // Boucle infinie si erreur
  }

  // Efface l'écran
  display.clearDisplay();

  // Affiche un message simple
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println("Hello ESP32!");
  display.display();  // Affichage sur l'écran
}

void loop() {
  // Pas de code en boucle ici, c'est juste un test statique
}
