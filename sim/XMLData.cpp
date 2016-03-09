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

	hairTypeCount = 0; hairTypeCountMax = -1;
	limbTypeCount = 0; limbTypeCountMax = -1;
	mouthTypeCount = 0; mouthTypeCountMax = -1;
	teethTypeCount = 0; teethTypeCountMax = -1;

	skinColorLength = 24; hairTypeLength = -1;
	limbTypeLength = -1;
	eyeColorLength = 24;
	mouthWidthTypeLength = -1;
	teethTypeLength = -1;

	hairTypes.clear();
	limbTypes.clear();
	mouthWidthTypes.clear();
	teethTypes.clear();

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

	if(hairTypeLength == -1) {
		hairTypeLength = nbBitsMin(hairTypes.size()-1);
	}
	if(limbTypeLength == -1) {
		limbTypeLength = nbBitsMin(limbTypes.size()-1);
	}
	if(mouthWidthTypeLength == -1) {
		mouthWidthTypeLength = nbBitsMin(mouthWidthTypes.size()-1);
	}
	if(teethTypeLength == -1) {
		teethTypeLength = nbBitsMin(teethTypes.size()-1);
	}

	return 0;
}

/* First method called to parse data in XML (recursive) */
void XMLData::parseDOMNode(DOMNode *node) {
	if (node) {
		string nodeName(XMLString::transcode(node->getNodeName()));

		if(node->getNodeType() == DOMNode::ELEMENT_NODE) {
			XMLData::parseDOMElement(static_cast<DOMElement*>(node));
		}

		DOMNode* child = node->getFirstChild();

		while (child) {
			XMLData::parseDOMNode(child);
			child = child->getNextSibling();
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
		int value;
		try {
			value = stoi(attr_value);
			if(name == "hairiness") {
				if(attr_name == "typesMax") {
					hairTypeCountMax = value;
					hairTypeLength = nbBitsMin(value-1);
				}
			}
			else if(name == "limbs") {
				if(attr_name == "nbMax") {
					limbNbLength = nbBitsMin(value);
				}
				else if(attr_name == "sizeMax") {
					limbSizeLength = nbBitsMin(value);
				}
				else if(attr_name == "typesMax") {
					limbTypeCountMax = value;
					limbTypeLength = nbBitsMin(value-1);
				}
			}
			else if(name == "ears") {
				if(attr_name == "nbMax") {
					earNbLength = nbBitsMin(value);
				}
			}
			else if(name == "eyes") {
				if(attr_name == "nbMax") {
					eyeNbLength = nbBitsMin(value);
				}
			}
			else if(name == "nostrils") {
				if(attr_name == "nbMax") {
					nostrilNbLength = nbBitsMin(value);
				}
			}
			else if(name == "width") {
				if(attr_name == "typesMax") {
					mouthTypeCountMax = value;
					mouthWidthTypeLength = nbBitsMin(value-1);
				}
			}
			else if(name == "teeth") {
				if(attr_name == "nbMax") {
					teethNbLength = nbBitsMin(value);
				}
				else if(attr_name == "typesMax") {
					teethTypeCountMax = value;
					teethTypeLength = nbBitsMin(value-1);
				}
			}
		}
		catch(invalid_argument& e) {
			if(name == "type") {
				string parentName(XMLString::transcode(static_cast<DOMElement*>(element->getParentNode())->getTagName()));
				if(parentName == "hairiness" &&
					((hairTypeCountMax != -1 && hairTypeCount < hairTypeCountMax) || (hairTypeCountMax == -1))) {
					hairTypes.push_back(attr_value);
					hairTypeCount++;
				}
				else if(parentName == "limbs" &&
					((limbTypeCountMax != -1 && limbTypeCount < limbTypeCountMax) || (limbTypeCountMax == -1))) {
					limbTypes.push_back(attr_value);
					limbTypeCount++;
				}
				else if(parentName == "width" &&
					((mouthTypeCountMax != -1 && mouthTypeCount < mouthTypeCountMax) || (mouthTypeCountMax == -1))) {
					mouthWidthTypes.push_back(attr_value);
					mouthTypeCount++;
				}
				else if(parentName == "teeth" &&
					((teethTypeCountMax != -1 && teethTypeCount < teethTypeCountMax) || (teethTypeCountMax == -1))) {
					teethTypes.push_back(attr_value);
					teethTypeCount++;
				}
			}
		}
		/*
		cout << "\t" << attr_name << ": "<< attr_value << endl;
		*/
	}
}

/* Getters */
int XMLData::SKIN_COLOR_LENGTH() {
	return skinColorLength;
}
int XMLData::HAIR_TYPE_LENGTH() {
	return hairTypeLength;
}
vector<string> XMLData::getHairTypes() {
	int nbTypes = std::min((int) pow(2, hairTypeLength), (int) hairTypes.size());
	return vector<string>(hairTypes.begin(), hairTypes.begin()+nbTypes);
}
string XMLData::getHairType(std::vector<bool> input) {
	unsigned index = binaryToDec(input);
	if(index >= hairTypes.size()) {
		return NULL;
	}
	return hairTypes.at(index);
}

int XMLData::LIMB_NB_LENGTH() {
	return limbNbLength;
}
int XMLData::LIMB_SIZE_LENGTH() {
	return limbSizeLength;
}
int XMLData::LIMB_TYPE_LENGTH() {
	return limbTypeLength;
}
vector<string> XMLData::getLimbTypes() {
	int nbTypes = std::min((int) pow(2, limbTypeLength), (int) limbTypes.size());
	return vector<string>(limbTypes.begin(), limbTypes.begin()+nbTypes);
}
string XMLData::getLimbType(std::vector<bool> input) {
	unsigned index = binaryToDec(input);
	if(index >= limbTypes.size()) {
		return "";
	}
	return limbTypes.at(index);
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
	return mouthWidthTypeLength;
}
vector<string> XMLData::getMouthWidthTypes() {
	int nbTypes = std::min((int) pow(2, mouthWidthTypeLength), (int) mouthWidthTypes.size());
	return vector<string>(mouthWidthTypes.begin(), mouthWidthTypes.begin()+nbTypes);
}
string XMLData::getMouthWidthType(std::vector<bool> input) {
	unsigned index = binaryToDec(input);
	if(index >= mouthWidthTypes.size()) {
		return NULL;
	}
	return mouthWidthTypes.at(index);
}
int XMLData::TEETH_NB_LENGTH() {
	return teethNbLength;
}
int XMLData::TEETH_TYPE_LENGTH() {
	return teethTypeLength;
}
vector<string> XMLData::getTeethTypes() {
	int nbTypes = std::min((int) pow(2, teethTypeLength), (int) teethTypes.size());
	return vector<string>(teethTypes.begin(), teethTypes.begin()+nbTypes);
}
string XMLData::getTeethType(std::vector<bool> input) {
	unsigned index = binaryToDec(input);
	if(index >= teethTypes.size()) {
		return NULL;
	}
	return teethTypes.at(index);
}

int XMLData::NOSTRIL_NB_LENGTH() {
	return nostrilNbLength;
}
