#include <Adafruit_NeoPixel.h>
#include <Keyboard.h>

#define LED_PIN    10
#define LED_COUNT  2
#define BRIGHTNESS 50
#define KEY_1_PIN  5
#define KEY_2_PIN  4
#define LED_1      0
#define LED_2      1
#define MAX_TICK   10000

const char string_0[] PROGMEM = "phrase0";
const char string_1[] PROGMEM = "phrase1";
const char string_2[] PROGMEM = "phrase2";
const char string_3[] PROGMEM = "phrase3";
const char string_4[] PROGMEM = "phrase4";
const char string_5[] PROGMEM = "phrase5";
const char string_6[] PROGMEM = "phrase6";
const char string_7[] PROGMEM = "phrase7";
const char string_8[] PROGMEM = "phrase8";
const char string_9[] PROGMEM = "phrase9";
const char string_10[] PROGMEM = "phrase10";
const char string_11[] PROGMEM = "phrase11";
const char string_12[] PROGMEM = "phrase12";
const char string_13[] PROGMEM = "phrase13";
const char string_14[] PROGMEM = "phrase14";
const char string_15[] PROGMEM = "phrase15";
const char string_16[] PROGMEM = "phrase16";
const char string_17[] PROGMEM = "phrase17";
const char string_18[] PROGMEM = "phrase18";
const char string_19[] PROGMEM = "phrase19";
const char string_20[] PROGMEM = "phrase20";
const char string_21[] PROGMEM = "phrase21";

const char *const phrases[] PROGMEM = {
  string_0,
  string_1,
  string_2,
  string_3,
  string_4,
  string_5,
  string_6,
  string_7,
  string_8,
  string_9,
  string_10,
  string_11,
  string_12,
  string_13,
  string_14,
  string_15,
  string_16,
  string_17,
  string_18,
  string_19,
  string_20,
  string_21,
};

const int lenPhrases = sizeof(phrases)/sizeof(phrases[0]);

char buff[30];
bool key1Down = false;
bool key2Down = false;
int tick = 0;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);
  pinMode(KEY_1_PIN, INPUT_PULLUP);
  pinMode(KEY_2_PIN, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  while ((!key1Down) && (!key2Down)) {
    if (digitalRead(KEY_1_PIN) == LOW) {
      key1Down = true;
    }
    if (digitalRead(KEY_2_PIN) == LOW) {
      key2Down = true;
    }

    tick++;
    if (tick >= MAX_TICK) {
      wipeLeds();
    }
  }
  
  if (key1Down) {
    writeString();
    pulseLed(LED_1);
    delay(50);
    key1Down = false;
  }
  
  if (key2Down) {
    writeString();
    pulseLed(LED_2);
    delay(50);
    key2Down = false;
  }
}

void writeString() {
  int randPhrase = random(lenPhrases);
  strcpy_P(buff, (char *)pgm_read_word(&(phrases[randPhrase])));
  for (byte i = 0; i < sizeof(buff); i++) {
    Keyboard.write(buff[i]);
    buff[i] = '\0';
    delay(5);
  }
}

void pulseLed(int ledNum) {
  strip.setPixelColor(ledNum, strip.Color(random(150), random(150), random(150)));
  strip.show();
  tick = 0;
  delay(5);
}

void wipeLeds() {
  strip.setPixelColor(0, strip.Color(0, 0, 0));
  strip.setPixelColor(1, strip.Color(0, 0, 0));
  strip.show();
  tick = 0;
  delay(5);
}
