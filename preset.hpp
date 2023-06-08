#ifndef PRESET_HPP
#define PRESET_HPP

#include <QString>

class Preset {

private:
    QString name, dirLocation, domType, domName;

public:
    inline Preset();
    inline Preset(QString _name, QString _dirLocation) : name(_name), dirLocation(_dirLocation) {}
    inline Preset(QString _name, QString _dirLocation, QString _domType) : name(_name), dirLocation(_dirLocation), domType(_domType) {}
    inline Preset(QString _name, QString _dirLocation, QString _domType, QString _domName) : name(_name), dirLocation(_dirLocation), domType(_domType), domName(_domName) {}

    /* Getters */

    inline QString getName()     { return name; }
    inline QString getLocation() { return dirLocation; }
    inline QString getDomType()  { return domType; }
    inline QString getDomName()  { return domName; }

    /* Setters */

    inline void setName(QString _name)            { name = _name; }
    inline void setLocation(QString _dirLocation) { dirLocation = _dirLocation; }
    inline void setDomName(QString _name)         { domName = _name; }
    inline void setDomType(QString _type)         { domType = _type; }



};

#endif // PRESET_HPP
