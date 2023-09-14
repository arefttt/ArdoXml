#ifndef ArdoXml_h
#define ArdoXml_h

#include "Arduino.h"

#define MAX_XML_SIZE 1000
#define MAX_TAG_SIZE 50
#define MAX_VALUE_SIZE 50

class ArdoXml {
  public:
    ArdoXml(char* xml);
    bool isXML(char* str);
    int getSize();
    char* getValue(char* tag);
    bool tagExists(char* tag);
    void replaceValue(char* tag, char* newValue);
    void removeTag(char* tag);
    void addTag(char* tag, char* value);
    void printXML();

  private:
    char xml[MAX_XML_SIZE]; // The XML string
};

#endif
