void setup()
{
}
void loop()
{
}

/**
 * Converts int16 to string.
 * Moreover, resulting strings will have the same length
 */
char* toStr(int16_t value)
{
  char result[7];
  sprintf(result, "%6d", value);
  return result;
}