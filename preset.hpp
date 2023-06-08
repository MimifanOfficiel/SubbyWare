#ifndef PRESET_HPP
#define PRESET_HPP

#include <QString>

class Preset {

private:
    QString name, description, dirLocation, domType, domName;

public:
    inline Preset();
    inline Preset(QString _name, QString _dirLocation) : name(_name), dirLocation(_dirLocation) {}
    inline Preset(QString _name, QString _dirLocation, QString _domType) : name(_name), dirLocation(_dirLocation), domType(_domType) {}    
    inline Preset(QString _name, QString desc, QString _dirLocation, QString _domType, QString _domName) : name(_name), description(desc), dirLocation(_dirLocation), domType(_domType), domName(_domName) {}

    Preset(QString _name, QString _dirLocation, QString _domType, QString descOrDomName, bool isDesc);

    /* Getters */

    inline QString getName()        { return name; }
    inline QString getDescription() { return description; }
    inline QString getLocation()    { return dirLocation; }
    inline QString getDomType()     { return domType; }
    inline QString getDomName()     { return domName; }

    /* Setters */

    inline void setName(QString _name)            { name = _name; }
    inline void setDescription(QString desc)      { description = desc; }
    inline void setLocation(QString _dirLocation) { dirLocation = _dirLocation; }
    inline void setDomName(QString _name)         { domName = _name; }
    inline void setDomType(QString _type)         { domType = _type; }



};

#endif // PRESET_HPP
