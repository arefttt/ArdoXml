#include "Arduino.h"
#include "ArdoXml.h"

ArdoXml::ArdoXml(char* xml) {
  if (strlen(xml) >= MAX_XML_SIZE) {
    Serial.println("Error: XML string is too large.");
    return;
  }
  strncpy(this->xml, xml, sizeof(this->xml));
}

bool ArdoXml::isXML(char* str) {
  return str[0] == '<' && str[strlen(str) - 1] == '>';
}

int ArdoXml::getSize() {
  return strlen(xml);
}

char* ArdoXml::getValue(char* tag) {
  if (strlen(tag) >= MAX_TAG_SIZE) {
    Serial.println("Error: Tag is too large.");
    return NULL;
  }

  char openTag[MAX_TAG_SIZE];
  sprintf(openTag, "<%s>", tag);

  char closeTag[MAX_TAG_SIZE];
  sprintf(closeTag, "</%s>", tag);

  char* start = strstr(xml, openTag);
  char* end = strstr(xml, closeTag);

  if (start == NULL || end == NULL) return NULL;

  start += strlen(openTag);

  static char value[MAX_VALUE_SIZE];
  
  if (end - start >= MAX_VALUE_SIZE) {
    Serial.println("Error: Value is too large.");
    return NULL;
  }
  
  strncpy(value, start, end - start);
  
  value[end - start] = '\0';

  return value;
}

bool ArdoXml::tagExists(char* tag) {
  if (strlen(tag) >= MAX_TAG_SIZE) {
    Serial.println("Error: Tag is too large.");
    return false;
  }

  char openTag[MAX_TAG_SIZE];
  sprintf(openTag, "<%s>", tag);

  char closeTag[MAX_TAG_SIZE];
  sprintf(closeTag, "</%s>", tag);

  return strstr(xml, openTag) != NULL && strstr(xml, closeTag) != NULL;
}

void ArdoXml::replaceValue(char* tag, char* newValue) {
  if (!tagExists(tag)) return;

  if (strlen(tag) >= MAX_TAG_SIZE || strlen(newValue) >= MAX_VALUE_SIZE) {
    Serial.println("Error: Tag or new value is too large.");
    return;
  }

  char openTag[MAX_TAG_SIZE];
  sprintf(openTag, "<%s>", tag);

  char closeTag[MAX_TAG_SIZE];
  sprintf(closeTag, "</%s>", tag);

  
  char* start = strstr(xml,openTag);
  
  char* end = strstr(xml,closeTag);
  
   
  
   start += strlen(openTag);
   
   
   
   memmove(start + strlen(newValue), end, strlen(end)+1);
   
   
   memcpy(start,newValue,strlen(newValue));
   
   return;
   
}

void ArdoXml::removeTag(char* tag){
	if(!tagExists(tag)) return;
	
	if(strlen(tag)>=MAX_TAG_SIZE){
		Serial.println("Error: Tag is too large.");
		return;
	}
	
	char openTag[MAX_TAG_SIZE];
	sprintf(openTag,"<%s>",tag);
	
	char closeTag[MAX_TAG_SIZE];
	sprintf(closeTag,"</%s>",tag);
	
	char* start = strstr(xml,openTag);
	char* end = strstr(xml,closeTag);
	
	end += strlen(closeTag);
	
	memmove(start,end,strlen(end)+1);
	
	xml[strlen(xml)-strlen(end)-1] = '\0';
	
	return;
	
}

void ArdoXml::addTag(char* tag,char* value){
	if(strlen(tag)>=MAX_TAG_SIZE || strlen(value)>=MAX_VALUE_SIZE){
		Serial.println("Error: Tag or value is too large.");
		return;
	}
	
	char newTag[MAX_XML_SIZE];
	
	sprintf(newTag,"<%s>%s</%s>",tag,value,tag);
	
	if(strlen(newTag)+strlen(xml)<MAX_XML_SIZE){
		strcat(xml,newTag);
		xml[sizeof(xml)-1] = '\0';
		
		return;
		
	}else{
		Serial.println("Error: Not enough space to add new tag.");
		
		return;
		
	}
	
}

void ArdoXml::printXML() {
	Serial.println(xml);
}
