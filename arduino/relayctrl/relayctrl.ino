/*
 * Author: Raul Salinas-Monteagudo <rausalinas@gmail.com>
 * 
 * Gadidomo: Simple interface to activate a relay board with an Arduino
 * 
 * The protocol is extremely simple. The commands are either lowercase or 
 * uppercase letters starting at 'a' (the GPIO 2, in order to leave the serial
 * port free). Lowercase = activate.  Uppercase = deactivate.
 * 
 * No CRCs or any.  Meant to use the USB port, which has its built-in error
 * check mechanism.  Just works, for simple home automation setups.
 * 
 * 2021-10-24
 */

const int skippedGpios = 2;  // Leave RX and TX free for the serial communication

void
setup ()
{
  Serial.begin (9600);
  pinMode (LED_BUILTIN, OUTPUT);
  for (int gpio = skippedGpios; gpio < NUM_DIGITAL_PINS; gpio++)
    {
      pinMode (gpio, OUTPUT);
      digitalWrite (gpio, HIGH);
    }
}

void
loop ()
{
  while (Serial.available () > 0)
    {
      int ch = Serial.read ();
      if (ch >= 'a' && ch <= 'z')
	{
	  int gpio = ch - 'a' + skippedGpios;
	  if (gpio < NUM_DIGITAL_PINS)
	    digitalWrite (gpio, LOW);   // inverted logic
      delay(100);  // Wait just in case they want to activate several relays at a time
	}
      else if (ch >= 'A' && ch <= 'Z')
	{
	  int gpio = ch - 'A' + skippedGpios;
	  if (gpio < NUM_DIGITAL_PINS)
	    digitalWrite (gpio, HIGH);    // inverted logic
	}
    }
}
