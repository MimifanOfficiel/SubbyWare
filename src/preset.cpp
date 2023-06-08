#include "preset.hpp"

Preset::Preset(QString _name, QString _dirLocation, QString _domType, QString descOrDomName, bool isDesc)
    : name(_name), dirLocation(_dirLocation), domType(_domType) {
    if(isDesc) description = descOrDomName;
    else domName = descOrDomName;
}
