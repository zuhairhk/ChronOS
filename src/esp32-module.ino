#include <Wire.h>
#include <Adafruit_SSD1306.h> // For OLED display

// OLED display configuration
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    // Reset pin not used for I2C
#define SCREEN_ADDRESS 0x3C // I2C address for the OLED display (matches Wokwi JSON)

// Initialize Adafruit_SSD1306 object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  Serial.println("Initializing...");

  // Initialize OLED display
  if (!display.begin(SSD1306_BLACK, SCREEN_ADDRESS)) { // Use SCREEN_ADDRESS directly
    Serial.println("SSD1306 allocation failed");
    for (;;); // Don't proceed, loop forever
  }

  // Clear the display buffer
  display.clearDisplay();

  // Show "Hello, World!" on the OLED
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);            // Start at top-left corner
  display.println("Hello, World!");   // Print text
  display.display();                  // Update the display with the content
}

void loop() {
  // Nothing needed in loop for this example
  delay(100); // Add a small delay
}
