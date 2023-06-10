#include "includes/preset.hpp"

Preset::Preset(QString _name, QString _dirLocation, QString _category, QString _domType, QString descOrDomName, bool isDesc)
    : name(_name), dirLocation(_dirLocation), category(_category), domType(_domType) {
    if(isDesc) description = descOrDomName;
    else domName = descOrDomName;
}


QJsonDocument Preset::toJSON(){
    QJsonObject jsonObj;

    jsonObj["Name"] = name;
    jsonObj["Description"] = description;
    jsonObj["DomType"] = domType;
    jsonObj["DomName"] = domName;
    jsonObj["Category"] = category;
    jsonObj["Location"] = dirLocation;

    return QJsonDocument(jsonObj);
}
