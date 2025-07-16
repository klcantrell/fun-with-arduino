#include <Arduino.h>
#include <IRremote.h>

int const IR_PIN = 9;
String command;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
  while (IrReceiver.decode() == 0);
  delay(1000);

  switch (IrReceiver.decodedIRData.decodedRawData) {
    case 0xBA45FF00:
      command = "power";
      break;
    case 0xB946FF00:
      command = "volume_up";
      break;
    case 0xB847FF00:
      command = "function";
      break;
    case 0xBB44FF00:
      command = "previous";
      break;
    case 0xBF40FF00:
      command = "play_pause";
      break;
    case 0xBC43FF00:
      command = "next";
      break;
    case 0xF807FF00:
      command = "scroll_down";
      break;
    case 0xEA15FF00:
      command = "volume_down";
      break;
    case 0xF609FF00:
      command = "scroll_up";
      break;
    case 0xE916FF00:
      command = "zero";
      break;
    case 0xE619FF00:
      command = "equalizer";
      break;
    case 0xF20DFF00:
      command = "repeat";
      break;
    case 0xF30CFF00:
      command = "one";
      break;
    case 0xE718FF00:
      command = "two";
      break;
    case 0xA15EFF00:
      command = "three";
      break;
    case 0xF708FF00:
      command = "four";
      break;
    case 0xE31CFF00:
      command = "five";
      break;
    case 0xA55AFF00:
      command = "six";
      break;
    case 0xBD42FF00:
      command = "seven";
      break;
    case 0xAD52FF00:
      command = "eight";
      break;
    case 0xB54AFF00:
      command = "nine";
      break;
    default:
      command = "unknown";
      break;
  }

  Serial.print("Received command: ");
  Serial.println(command);

  IrReceiver.resume();
}
