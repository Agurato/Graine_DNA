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
		cout << "XMLException is: \n\t" << message << "\n";
		XMLString::release(&message);
		return 2;
	} catch (const DOMException& e) {
		char* message = XMLString::transcode(e.msg);
		cout << "DOMException is: \n\t" << message << "\n";
		XMLString::release(&message);
		return 3;
	} catch (const SAXException& e) {
		char* message = XMLString::transcode(e.getMessage());
		cout << "SAXException is: \n\t" << message << "\n";
		XMLString::release(&message);
		return 4;
	} catch (...) {
		cout << "Unexpected Exception \n";
		return 5;
	}

	delete parser;
	delete errHandler;

	XMLPlatformUtils::Terminate();

	return 0;
}

/* First method called to parse data in XML (recursive) */
void XMLData::parseDOMNode(DOMNode *node) {
	if (node) {
		string nodeName(XMLString::transcode(node->getNodeName()));

		if(node->getNodeType() == DOMNode::ELEMENT_NODE) {
			/*
			path.push_back(nodeName);
			for (vector<string>::iterator it = path.begin() ; it != path.end() ; ++it) {
				cout << *it << " - ";
			}
			*/
			XMLData::parseDOMElement(static_cast<DOMElement*>(node));
		}

		int nbChilds = 0;
		DOMNode* child = node->getFirstChild();

		while (child) {
			if(child->getNodeType() == DOMNode::ELEMENT_NODE) {
				nbChilds ++;
			}
			XMLData::parseDOMNode(child);
			child = child->getNextSibling();
		}

		if(nodeName == "hairiness") {

		}
		else if(nodeName == "extremity") {
			limbTypeLength = nbBitsMin(nbChilds-1);
		}
		else if(nodeName == "width") {
			mouthWidthLength = nbBitsMin(nbChilds-1);
		}
		else if(nodeName == "food") {
			teethTypeLength = nbBitsMin(nbChilds-1);
		}
	}
}

void XMLData::parseDOMElement(DOMElement* element) {
	string name(XMLString::transcode(element->getTagName()));

	DOMNamedNodeMap* map = element->getAttributes();
	for (XMLSize_t i = 0; i < map->getLength(); i++) {
		DOMAttr* attr = static_cast<DOMAttr*>(map->item(i));
		string attr_name(XMLString::transcode(attr->getName()));
		string attr_value(XMLString::transcode(attr->getValue()));
		/*
		cout << "\t" << attr_name << ": "<< attr_value << endl;
		*/

		if(name == "limbs") {
			if(string(attr_name) == "nbMax") {
				limbNbLength = nbBitsMin(stoi(attr_value));
			}
			else if(string(attr_name) == "sizeMax") {
				limbSizeLength = nbBitsMin(stoi(attr_value));
			}
		}
		else if(name == "ears") {
			if(string(attr_name) == "nbMax") {
				earNbLength = nbBitsMin(stoi(attr_value));
			}
		}
		else if(name == "eyes") {
			if(string(attr_name) == "nbMax") {
				eyeNbLength = nbBitsMin(stoi(attr_value));
			}
		}
		else if(name == "nostrils") {
			if(string(attr_name) == "nbMax") {
				nostrilNbLength = nbBitsMin(stoi(attr_value));
			}
		}
		else if(name == "teeth") {
			if(string(attr_name) == "nbMax") {
				teethNbLength = nbBitsMin(stoi(attr_value));
			}
		}
	}
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
