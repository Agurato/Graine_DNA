#include "XMLData.hpp"

#include <iostream>

using namespace std;
using namespace xercesc;

XMLData* XMLData::instance = NULL;

XMLData* XMLData::getInstance() {
	if(!instance) {
		instance = new XMLData();
	}
	return instance;
}

/* Method to call to initisalize the parsing */
int XMLData::parseXML(string filePath) {
	try {
		XMLPlatformUtils::Initialize();
	} catch (const XMLException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Error during initialization! :\n" << message << "\n";
		XMLString::release(&message);
		return 1;
	}

	XercesDOMParser* parser = new XercesDOMParser();
	parser->setValidationScheme(XercesDOMParser::Val_Always);
	parser->setDoNamespaces(true);

	ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
	parser->setErrorHandler(errHandler);

	try {
		parser->parse(filePath.c_str());
		DOMDocument* dom = parser->getDocument();
		XMLData::parseDOMNode(dom);
	} catch (const XMLException& e) {
		char* message = XMLString::transcode(e.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		return -1;
	} catch (const DOMException& e) {
		char* message = XMLString::transcode(e.msg);
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		return -1;
	} catch (const SAXException& e) {
		char* message = XMLString::transcode(e.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		return -1;
	} catch (...) {
		cout << "Unexpected Exception \n";
		return -1;
	}

	delete parser;
	delete errHandler;

	XMLPlatformUtils::Terminate();

	return 0;
}

void XMLData::parseDOMNode(DOMNode *node) {
	if (node) {
		switch (node->getNodeType()) {
			case DOMNode::ELEMENT_NODE:
			XMLData::parseDOMElement(static_cast<DOMElement*>(node));
			break;
			case DOMNode::TEXT_NODE:
			XMLData::parseDOMText(static_cast<DOMText*>(node));
			break;
			default:
			break;
		}

		DOMNode* child = node->getFirstChild();
		while (child) {
			DOMNode* next = child->getNextSibling();
			XMLData::parseDOMNode(child);
			child = next;
		}
	}
}

void XMLData::parseDOMElement(DOMElement* element) {
	char* name = XMLString::transcode(element->getTagName());
	cout << "tag    : " << name << endl;
	XMLString::release(&name);

	DOMNamedNodeMap* map = element->getAttributes();
	for (XMLSize_t i = 0; i < map->getLength(); i++) {
		DOMAttr* attr = static_cast<DOMAttr*>(map->item(i));
		char* attr_name  = XMLString::transcode(attr->getName());
		char* attr_value = XMLString::transcode(attr->getValue());
		cout << attr_name << ": "<< attr_value << endl;

		XMLString::release(&attr_name);
		XMLString::release(&attr_value);
	}
}

void XMLData::parseDOMText(DOMText *text) {
	XMLCh* buffer = new XMLCh[XMLString::stringLen(text->getData()) + 1];
	XMLString::copyString(buffer, text->getData());
	XMLString::trim(buffer);
	char* content=XMLString::transcode(buffer);
	delete[] buffer;

	cout << "content: " << content << endl;
	XMLString::release(&content);
}

/* Getters */

int XMLData::LIMB_NB_LENGTH() {
	return limbNbLength;
}
int XMLData::LIMB_SIZE_LENGTH() {
	return limbSizeLength;
}
int XMLData::LIMB_TYPE_LENGTH() {
	return limbTypeLength;
}

int XMLData::EAR_NB_LENGTH() {
	return earNbLength;
}

int XMLData::EYE_COLOR_LENGTH() {
	return eyeColorLength;
}
int XMLData::EYE_NB_LENGTH() {
	return eyeNbLength;
}

int XMLData::MOUTH_WIDTH_LENGTH() {
	return mouthWidthLength;
}
int XMLData::TEETH_NB_LENGTH() {
	return teethNbLength;
}
int XMLData::TEETH_TYPE_LENGTH() {
	return teethTypeLength;
}

int XMLData::NOSTRIL_NB_LENGTH() {
	return nostrilNbLength;
}
