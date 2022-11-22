# EEPROM for Arduino

A method to write or read strings in any ESP or Arduino EEPROM.

The first address of the string is known and determined by the user. The way the function is created that, the fist three bytes of data determine the length of
the string.

### To Write String:
Determine the lenth of the string and express it in a three digit format, for example -

```
String data = "rupava";
```
The variable _data_ is of length 6, hence the resultant string should be modified as _"006rupava"_
This new string is written to the EEPROM from the position of the known address.

## To Read String:

Read the first three bytes from the known address and determine the length of the string. Now read till the length of the string from the position _knownAddress + 3_
