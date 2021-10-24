
void
setup ()
{
  Serial.begin (9600);
  pinMode (LED_BUILTIN, OUTPUT);
  for (int gpio = 2; gpio < 2 + 11; gpio++)
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
	  int gpio = ch - 'a' + 2;
	  if (gpio <= 13)
	    digitalWrite (gpio, LOW);
	}
      else if (ch >= 'A' && ch <= 'Z')
	{
	  int gpio = ch - 'A' + 2;
	  if (gpio <= 13)
	    digitalWrite (gpio, HIGH);
	}
    }
}
