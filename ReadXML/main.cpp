

#include "iostream"
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

#define cameraXML "Astra.xml"

int ReadXML()
{
    XMLDocument xmlDoc;
    XMLError rc = XML_SUCCESS;
    rc = xmlDoc.LoadFile(cameraXML);
    if (rc != XML_SUCCESS)
    {
        printf("\nNot find %s\n", cameraXML);
        return 0;
    }

    XMLElement *scene = xmlDoc.RootElement();
    XMLElement *surface = scene->FirstChildElement("node");
    while (surface)
    {
        XMLElement *surfaceChild = surface->FirstChildElement();
        const char* content;
        const XMLAttribute *attributeOfSurface = surface->FirstAttribute();
        cout << attributeOfSurface->Name() << ":" << attributeOfSurface->Value() << endl;
        while (surfaceChild)
        {
            content = surfaceChild->GetText();
            surfaceChild = surfaceChild->NextSiblingElement();
            cout << content << endl;
        }
        surface = surface->NextSiblingElement();
    }

}

int main()
{
    ReadXML();

    getchar();
    return 0;
}
