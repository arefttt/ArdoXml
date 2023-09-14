# ArdoXml: An Arduino XML Library

ArdoXml is a lightweight and standalone library for parsing XML files on Arduino platforms. It provides a simple and efficient way to handle XML data without any external dependencies.

## Features

- **Lightweight**: ArdoXml is designed to be small and efficient, making it ideal for memory-constrained Arduino platforms.
- **Standalone**: ArdoXml does not rely on any external libraries, making it easy to integrate into your Arduino projects.
- **Easy to Use**: ArdoXml provides a simple and intuitive API for parsing XML data and manipulating XML elements.

## Comparison with Other Libraries

While libraries like TinyXML and ArduinoJson provide robust support for XML parsing, they can be overkill for simple projects or may not be suitable for memory-constrained platforms. In contrast, ArdoXml is designed to be lightweight and easy to use, making it a great choice for simple projects or when memory is a concern.

However, please note that ArdoXml is a basic implementation and does not support advanced features like attributes or nested tags. For more complex XML parsing or for larger XML files that don't fit in memory, you would typically use a library like TinyXML or ArduinoJson.

## How to Use

To use the ArdoXml library, simply include the `ArdoXml.h` header file in your Arduino sketch:

```cpp
#include "ArdoXml.h"
```

You can then create an instance of the `ArdoXml` class and use its methods to manipulate XML data:

```cpp
ArdoXml xmlHandler("<tag>value</tag>");

if (xmlHandler.isXML()) {
  Serial.println(xmlHandler.getValue("tag")); // Prints "value"
}
```

## Examples

Here's an example of how you can use the ArdoXml library to parse and manipulate XML data:

```cpp
#include "ArdoXml.h"

void setup() {
  Serial.begin(9600);

  // Create an instance of the ArdoXml class
  ArdoXml xmlHandler("<tag1>value1</tag1><tag2>value2</tag2>");

  // Check if the string is a well-formed XML
  if (xmlHandler.isXML()) {
    // Get the value of a specific tag
    Serial.println(xmlHandler.getValue("tag1")); // Prints "value1"

    // Check if a specific tag exists in the XML
    if (xmlHandler.tagExists("tag2")) {
      // Replace the value of a specific tag
      xmlHandler.replaceValue("tag2", "newValue");

      // Print the updated XML string
      xmlHandler.printXML(); // Prints "<tag1>value1</tag1><tag2>newValue</tag2>"
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

This example demonstrates how to use the `isXML`, `getValue`, `tagExists`, `replaceValue`, and `printXML` methods of the ArdoXml class.
